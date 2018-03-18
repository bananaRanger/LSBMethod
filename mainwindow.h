#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QImage>
#include <QFile>

#define encrypTabIndex 0
#define decryptTabIndex 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    QImage image;

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void openImageForEncryptionSlot();
    void openImageForDecryptionSlot();
    void encryptSlot();
    void encryptTextChangedSlot();

};

#endif // MAINWINDOW_H
