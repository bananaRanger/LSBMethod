#include "lsbdecrypt.h"

LSBDecrypt::LSBDecrypt()
{
    message = "";
    currentBit = 0;
    binaryChar = "";
}

void LSBDecrypt::decrypt(QColor pixelColor)
{
    if (currentBit == 8) {
        int charIndex = QString::number(binaryChar.toInt(0, 2), 10).toInt();
        message += getCharByIndex(charIndex);
        binaryChar = QString();
        currentBit = 0;
    }
    QString binaryRedColor = QString("%1").arg(pixelColor.red(),0,2);
    binaryChar += binaryRedColor.right(1);
    currentBit++;
}

void LSBDecrypt::setMessageSize(int size)
{
    messageSize = size;
}

QString LSBDecrypt::getMessage()
{
    return message;
}
