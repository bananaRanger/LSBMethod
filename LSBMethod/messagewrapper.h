#ifndef MESSAGEWRAPPER_H
#define MESSAGEWRAPPER_H

#include <QString>
#include <QDebug>

#define lengthBitsOfSize 9
#define lengthOfSizeBlock 3

struct MWItem {
    QString r;
    QString g;
    QString b;

    MWItem() {}
    MWItem(QString r, QString g, QString b) { this->r = r; this->g = g; this->b = b; }
    QString toString() { return r + g + b; }
};

class MessageWrapper
{
private:
    QString message;

    int length;
    int occupyLength;

public:
    MessageWrapper(QString message);

    int countOfAllowsSymbols(int size);

    int getLength();
    QString getLengthInBynary();
    int getOccupyLength();
    QString getOccupyLengthInBynary();

    QString getMessage();
    QList<MWItem> getMessageAsItems();

    static QList<MWItem> getItems(QString binary);
    static QString binary(QList<MWItem> items);
    static int binaryToNumber(QString binary);

    static QString getMessageFromItems(QList<MWItem> items);

};

#endif // MESSAGEWRAPPER_H
