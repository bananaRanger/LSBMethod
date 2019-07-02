#include "uiutils.h"

QPixmap UIUtils::pixmap(QString fileName, int imgWidth, int imgHeight)
{
    QPixmap pixmap;
    pixmap.load(fileName);
    pixmap = pixmap.scaled(imgWidth, imgHeight, Qt::KeepAspectRatio);
    return pixmap;
}

QPixmap UIUtils::defaultPixmap(QString fileName)
{
    return UIUtils::pixmap(fileName, imageWidth, imageHeight);
}

QPalette UIUtils::palette(QColor color)
{
    QPalette palette = QPalette();
    palette.setColor(QPalette::WindowText, color);
    return palette;
}

QList<QColor> UIUtils::pixColors(QImage image)
{
    QList<QColor> list = QList<QColor>();
    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            QColor color = image.pixel(i, j);
            list.append(color);
        }
    }
    return list;
}

void UIUtils::imageColors(QList<QColor> list, QImage &image)
{
    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            image.setPixelColor(i, j, list.first());
            list.removeFirst();
        }
    }
}
