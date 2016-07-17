#ifndef LSBENCRYPT_H
#define LSBENCRYPT_H

#include <QObject>
#include <QDebug>
#include <QImage>
#include <QColor>

static const int byte = 128;

class LSBEncrypt : QObject
{
    QString englishAlphabet;

    int messageIndex;
    int maxMessageSize;
    int numbersOfPixels;

protected:

    int messageSize;
    QString message;
    QString binaryChar;
    int currentBit;     // 0..8

public:
    LSBEncrypt();

    QColor encrypt(QColor pixelColor);

    int getIndexByChar(QCharRef character);
    QString getCharByIndex(int index);

    void setMessage(QString newMessage);

    void setNumbersOfPixels(int number);
    int getMaxMessageSize();
    int getMessageIndexWhenStop();
};

#endif // LSBENCRYPT_H
