#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uiutils.h"
#include "parser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->encryptOpenButton, SIGNAL(clicked(bool)), this, SLOT(openImageForEncryptionSlot()));
    connect(ui->encryptButton, SIGNAL(clicked(bool)), this, SLOT(encryptSlot()));
    connect(ui->encryptTextBrowser, SIGNAL(textChanged()), this, SLOT(encryptTextChangedSlot()));
    connect(ui->decryptOpenButton, SIGNAL(clicked(bool)), this, SLOT(openImageForDecryptionSlot()));

    ui->encryptButton->setEnabled(false);
    ui->encryptTextBrowser->setReadOnly(true);
    ui->decryptTextBrowser->setReadOnly(true);
}

void MainWindow::openImageForEncryptionSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть..."), ".", tr("BMP (*.bmp)"));

    this->image.load(fileName);

    ui->encryptTextBrowser->setReadOnly(false);
    ui->encryptImageLabel->setPixmap(UIUtils::defaultPixmap(fileName));
    ui->encryptButton->setEnabled(true);
    ui->encryptMessageLabel->setText(NULL);
}

void MainWindow::openImageForDecryptionSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть..."), ".", tr("BMP (*.bmp)"));

    this->image.load(fileName);

    ui->decryptImageLabel->setPixmap(UIUtils::defaultPixmap(fileName));

    QList<QColor> colors = UIUtils::pixColors(this->image);

    QString message = Parser::decode(colors);
    ui->decryptTextBrowser->setText(message);

    if (message.isEmpty()) {
        ui->decryptMessageLabel->setText("There is no data for decryption.");
    } else {
        ui->decryptMessageLabel->setText(NULL);
    }
}

void MainWindow::encryptSlot()
{
    QString symbols = ui->encryptTextBrowser->toPlainText();
    QList<QColor> colors = UIUtils::pixColors(this->image);

    QList<QColor> encodedColors = Parser::encode(symbols, colors);

    UIUtils::imageColors(encodedColors, this->image);

    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить..."), ".", tr("BMP (*.bmp)"));
    this->image.save(fileName);
}

void MainWindow::encryptTextChangedSlot()
{
    QString symbols = ui->encryptTextBrowser->toPlainText();
    int size = symbols.length();

    MessageWrapper essageWrapper = MessageWrapper(symbols);
    int count = essageWrapper.countOfAllowsSymbols(this->image.width() * this->image.height());

    if (size > 0 && size <= count) {
        ui->encryptButton->setEnabled(true);
        ui->encryptMessageLabel->setPalette(UIUtils::palette(Qt::black));
    } else {
        ui->encryptButton->setEnabled(false);
        ui->encryptMessageLabel->setPalette(UIUtils::palette(Qt::red));
    }

    ui->encryptMessageLabel->setText(QString::number(size)+" / "+QString::number(count));
}

MainWindow::~MainWindow()
{
    delete ui;
}
