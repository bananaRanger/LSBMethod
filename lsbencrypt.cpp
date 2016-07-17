#include "lsbencrypt.h"

LSBEncrypt::LSBEncrypt()
{
    message = QString();
    messageSize = 0;
    messageIndex = 0;
    maxMessageSize = 0;
    numbersOfPixels = 0;

    currentBit = 8;
    binaryChar = QString();

    englishAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+=-|/.,`~'';:{}[] \n";
}

QColor LSBEncrypt::encrypt(QColor pixelColor)
{
    if (currentBit == 8) {
        int binaryIndex = getIndexByChar(message[messageIndex]) + byte;
        binaryChar = QString("%1").arg(binaryIndex, 0, 2);
        messageIndex++;
        currentBit = 0;
    }

    QString binaryRedColor = QString("%1").arg(pixelColor.red(), 0, 2);

    binaryRedColor.replace(binaryRedColor.length()-1, 1, binaryChar[currentBit]);
    int redColor = QString::number(binaryRedColor.toInt(0, 2), 10).toInt();

    currentBit++;

    return QColor(redColor, pixelColor.green(), pixelColor.blue());
}

int LSBEncrypt::getIndexByChar(QCharRef character)
{
    for (int i = 0; i < englishAlphabet.size(); i++) {
        if (englishAlphabet[i] == character) {
            return i;
        }
    }
}

QString LSBEncrypt::getCharByIndex(int index)
{
     return englishAlphabet.at(index - byte);
}

int LSBEncrypt::getMessageIndexWhenStop()
{
    int stopIndex = messageSize * 8;
    return stopIndex;
}

void LSBEncrypt::setMessage(QString newMessage)
{
    message = newMessage;
    messageSize = message.length();
}

void LSBEncrypt::setNumbersOfPixels(int number)
{
    numbersOfPixels = number;
}

int LSBEncrypt::getMaxMessageSize()
{
    maxMessageSize = numbersOfPixels / 8;
    return maxMessageSize;
}
