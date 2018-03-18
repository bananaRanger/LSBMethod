#include "parser.h"
#include "messagewrapper.h"

QList<QColor> Parser::encode(QString message, QList<QColor> list)
{
    QList<QColor> colors = list;
    MessageWrapper wrapper = MessageWrapper(message);
    QList<MWItem> occupyLengthItems = MessageWrapper::getItems(wrapper.getOccupyLengthInBynary());
    QList<MWItem> lengthItems = MessageWrapper::getItems(wrapper.getLengthInBynary());
    QList<MWItem> messageItems = wrapper.getMessageAsItems();

    int start = 0;

    for (int i = start; i < lengthOfSizeBlock; i++) {
        colors[i] = encodeColor(colors[i], occupyLengthItems[i]);
    }

    start += lengthOfSizeBlock;

    for (int i = start; i < start + wrapper.getOccupyLength(); i++) {
        colors[i] = encodeColor(colors[i], lengthItems[i - start]);
    }

    start += wrapper.getOccupyLength();

    for (int i = start; i < start + wrapper.getLength(); i++) {
        colors[i] = encodeColor(colors[i], messageItems[i - start]);
    }

    return colors;
}

QString Parser::decode(QList<QColor> colors)
{
    QList<MWItem> occupyLengthItems = QList<MWItem>();
    QList<MWItem> lengthItems = QList<MWItem>();
    QList<MWItem> messageItems = QList<MWItem>();

    int start = 0;

    for (int i = start; i < lengthOfSizeBlock; i++) {
        occupyLengthItems.append(decodeColor(colors[i]));
    }

    int occupyLength = MessageWrapper::binaryToNumber(MessageWrapper::binary(occupyLengthItems));
    start += lengthOfSizeBlock;

    if (colors.size() > occupyLength) {

        for (int i = start; i < start + occupyLength; i++) {
            lengthItems.append(decodeColor(colors[i]));
        }

        int length = MessageWrapper::binaryToNumber(MessageWrapper::binary(lengthItems));
        start += occupyLength;

        for (int i = start; i < start + (length); i++) {
            messageItems.append(decodeColor(colors[i]));
        }

        return MessageWrapper::getMessageFromItems(messageItems);
    }
    return QString();
}


QColor Parser::encodeColor(QColor color, MWItem item)
{
    QString red = QString("%1").arg(color.red(), 0, 2);
    QString green = QString("%1").arg(color.green(), 0, 2);
    QString blue = QString("%1").arg(color.blue(), 0, 2);

    red.replace(red.length()-1, 1, item.r);
    green.replace(green.length()-1, 1, item.g);
    blue.replace(blue.length()-1, 1, item.b);

    int redColor = QString::number(red.toInt(0, 2), 10).toInt();
    int greenColor = QString::number(green.toInt(0, 2), 10).toInt();
    int blueColor = QString::number(blue.toInt(0, 2), 10).toInt();

    return QColor(redColor, greenColor, blueColor);
}

MWItem Parser::decodeColor(QColor color)
{
    QString red = QString("%1").arg(color.red(), 0, 2);
    QString green = QString("%1").arg(color.green(), 0, 2);
    QString blue = QString("%1").arg(color.blue(), 0, 2);

    MWItem item = MWItem(red.right(1), green.right(1), blue.right(1));

    return item;
}
