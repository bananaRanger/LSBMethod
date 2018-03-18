#include "messagewrapper.h"
#include <QtMath>

MessageWrapper::MessageWrapper(QString message)
{
    this->message = message;

    this->length = message.length() * 3;

    int bitLength = QString("%1").arg(this->length, 0, 2).length();
    this->occupyLength = ceil(bitLength / 3.0);
}

int MessageWrapper::countOfAllowsSymbols(int size)
{
    return (size - lengthOfSizeBlock - this->occupyLength) / 3;
}

int MessageWrapper::getLength()
{
    return this->length;
}

QString MessageWrapper::getLengthInBynary()
{
    QString lengthBinary = QString("%1").arg(this->length, 0, 2);

    int diff = (this->occupyLength * 3) - lengthBinary.length();

    if (diff != 0) {
        QString prefix = QString(diff, '0');
        return prefix.append(lengthBinary);
    }

    return lengthBinary;
}

int MessageWrapper::getOccupyLength()
{
    return this->occupyLength;
}

QString MessageWrapper::getOccupyLengthInBynary()
{
    QString occupyLengthBinary = QString("%1").arg(this->occupyLength, 0, 2);

    int diff = lengthBitsOfSize - occupyLengthBinary.length();

    if (diff != 0) {
        QString prefix = QString(diff, '0');
        return prefix.append(occupyLengthBinary);
    }

    return occupyLengthBinary;
}

QString MessageWrapper::getMessage()
{
    return this->message;
}

QList<MWItem> MessageWrapper::getMessageAsItems()
{
    QList<MWItem> list = QList<MWItem>();
    for (int i = 0; i < this->message.length(); i++) {
        int symbolId = (int)this->message.at(i).toLatin1();
        QString symbolIdBinary = QString("%1").arg(symbolId, 0, 2);

        int diff = lengthBitsOfSize - symbolIdBinary.length();

        if (diff != 0) {
            QString prefix = QString(diff, '0');
            symbolIdBinary = prefix.append(symbolIdBinary);
        }

        list.append(MessageWrapper::getItems(symbolIdBinary));
    }
    return list;
}

QList<MWItem> MessageWrapper::getItems(QString binary)
{
    QList<MWItem> list = QList<MWItem>();
    for (int i = 0; i < binary.length(); i += 3) {
        MWItem item = MWItem();
        item.r = binary[i];
        item.g = binary[i + 1];
        item.b = binary[i + 2];
        list.append(item);
    }

    return list;
}

QString MessageWrapper::binary(QList<MWItem> items)
{
    QString binary = QString();
    for (int i = 0; i < items.length(); i++) {
        MWItem item = items.at(i);
        binary.append(item.r);
        binary.append(item.g);
        binary.append(item.b);
    }

    return binary;
}

int MessageWrapper::binaryToNumber(QString binary)
{
    return QString::number(binary.toInt(0, 2), 10).toInt();
}

QString MessageWrapper::getMessageFromItems(QList<MWItem> items)
{
    QString message = QString();
    for (int i = 0; i < items.size(); i += 3) {
        QString character = QString();
        for (int j = 0; j < lengthOfSizeBlock; j++) {
            MWItem item = items[i + j];
            character.append(item.toString());
        }
        int symbolId = MessageWrapper::binaryToNumber(character);
        message.append(QChar(symbolId));
        character.clear();
    }
    return message;
}

