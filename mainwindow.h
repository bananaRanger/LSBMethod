#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "lsbencrypt.h"
#include "lsbdecrypt.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QImage>
#include <QFile>

#define imageWidth 100
#define imageHeight 100

#define encrypTabIndex 0
#define decryptTabIndex 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QImage image;

    LSBEncrypt *encrypt;
    LSBDecrypt *decrypt;

    int encryptTextSize;

public:
    bool checkMessageToEncrypt();
    void saveImage();
    void saveSize(QString fileName);
    void loadSize(QString fileName);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openImageSlot();

    void goEncryptSlot();
    void goDecryptSlot();

    void whenEcryptTextChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
