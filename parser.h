#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include <QColor>
#include "messagewrapper.h"

class Parser
{
private:
    static QColor encodeColor(QColor color, MWItem item);
    static MWItem decodeColor(QColor color);

public:

    static QList<QColor> encode(QString message, QList<QColor> colors);
    static QString decode(QList<QColor> colors);

};

#endif // PARSER_H
