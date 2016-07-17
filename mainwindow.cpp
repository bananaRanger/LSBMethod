#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->encryptOpenButton, SIGNAL(clicked(bool)), this, SLOT(openImageSlot()));
    connect(ui->goEncryptButton,   SIGNAL(clicked(bool)), this, SLOT(goEncryptSlot()));

    connect(ui->decryptOpenButton, SIGNAL(clicked(bool)), this, SLOT(openImageSlot()));
    connect(ui->goDecryptButton,   SIGNAL(clicked(bool)), this, SLOT(goDecryptSlot()));

    connect(ui->encryptTextBrowser, SIGNAL(textChanged()), this, SLOT(whenEcryptTextChanged()));

    encrypt = new LSBEncrypt();
    decrypt = new LSBDecrypt();

    ui->goEncryptButton->setEnabled(false);
    ui->goDecryptButton->setEnabled(false);

    ui->encryptTextBrowser->setReadOnly(true);
    ui->decryptTextBrowser->setReadOnly(true);
}

void MainWindow::whenEcryptTextChanged() {
    encryptTextSize = ui->encryptTextBrowser->toPlainText().size();

    if (encryptTextSize > 0) {
        ui->goEncryptButton->setEnabled(true);
    } else {
        ui->goEncryptButton->setEnabled(false);
    }

    if (encryptTextSize < encrypt->getMaxMessageSize()) {
        QPalette* palette = new QPalette();
        palette->setColor(QPalette::WindowText,Qt::green);
        ui->imageSizeLabel->setPalette(*palette);
        ui->goEncryptButton->setEnabled(true);
    } else {
        QPalette* palette = new QPalette();
        palette->setColor(QPalette::WindowText,Qt::red);
        ui->imageSizeLabel->setPalette(*palette);
        ui->goEncryptButton->setEnabled(false);
    }
    ui->imageSizeLabel->setText(QString::number(encryptTextSize)
                                +" / "+QString::number(encrypt->getMaxMessageSize()));
}

void MainWindow::openImageSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Открыть..."), ".",
            tr("BMP (*.bmp)"));

    image.load(fileName);

    if (!image.isNull() == true) {

        QPixmap pixmap;
        pixmap.load(fileName);

        if (ui->tabWidget->currentIndex() == encrypTabIndex) {
            encrypt = new LSBEncrypt();
            encrypt->setNumbersOfPixels(image.width() * image.height());
            ui->imgEncryptLabel->setPixmap(pixmap.scaled(imageWidth, imageHeight, Qt::KeepAspectRatio));
            ui->encryptTextBrowser->setReadOnly(false);
        } else if (ui->tabWidget->currentIndex() == decryptTabIndex) {
            decrypt = new LSBDecrypt();
            ui->imgDecryptLabel->setPixmap(pixmap.scaled(imageWidth, imageHeight, Qt::KeepAspectRatio));
            ui->goDecryptButton->setEnabled(true);
        }
    }
}

bool MainWindow::checkMessageToEncrypt()
{
    int length = ui->encryptTextBrowser->toPlainText().length();
    if (length > 0) {
        return true;
    } else {
        return false;
    }
}

void MainWindow::goEncryptSlot()
{
    encrypt->setMessage(ui->encryptTextBrowser->toPlainText());

    if(checkMessageToEncrypt() == true) {
        for (int i = 0; i < image.width(); i++) {
            for (int j = 0; j < image.height(); j++) {
                QPoint point(i, j);
                QColor pixelColor = QColor(image.pixel(point));
                image.setPixel(point, (encrypt->encrypt(pixelColor)).rgba());
                if (encrypt->getMessageIndexWhenStop() == ((image.height() * i) + j)) {
                    saveImage();
                    saveSize("size.txt");
                    qDebug() << (image.height() * i) + j << endl;
                    return;
                }
            }
        }
    } else {
        QMessageBox::information(this, "Error", "Text", QMessageBox::Ok);
    }
}

void MainWindow::goDecryptSlot()
{
    loadSize("size.txt");
    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            QPoint point(i, j);
            QColor pixelColor = QColor(image.pixel(point));
            decrypt->decrypt(pixelColor);
            if (decrypt->getMessageIndexWhenStop() == ((image.height() * i) + j)) {
                ui->decryptTextBrowser->setText(decrypt->getMessage());
                return;
            }
        }
    }
}

void MainWindow::saveImage()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Сохранить..."), ".",
            tr("BMP (*.bmp)"));
    image.save(fileName);
}

void MainWindow::saveSize(QString fileName)
{
    QFile nameOfFile(fileName);
    if(!nameOfFile.open(QIODevice::WriteOnly)) {
        qDebug() << "DON`T SAVE";
        return;
    }

    QDataStream stream(&nameOfFile);
    stream << QString::number(ui->encryptTextBrowser->toPlainText().size());
    nameOfFile.close();
}

void MainWindow::loadSize(QString fileName)
{
    QString size;
    QFile nameOfFile(fileName);
    if(!nameOfFile.open(QIODevice::ReadOnly)) {
        qDebug() << "DON`T LOAD";
        return;
    }

    QDataStream stream(&nameOfFile);

    stream >> size;
    qDebug() << "SIZE : " << size;
    decrypt->setMessageSize(size.toInt());
    nameOfFile.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
