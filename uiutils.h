#ifndef UIUTILS_H
#define UIUTILS_H

#include <QObject>
#include <QPixmap>
#include <QPalette>
#include <QList>

#define imageWidth 100
#define imageHeight 100

class UIUtils
{
public:

    static QPixmap pixmap(QString fileName, int imgWidth, int imgHeight);
    static QPixmap defaultPixmap(QString fileName);

    static QPalette palette(QColor color);

    static QList<QColor> pixColors(QImage image);
    static void imageColors(QList<QColor> list, QImage &image);
};

#endif // UIUTILS_H
