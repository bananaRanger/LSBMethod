#ifndef LSBDECRYPT_H
#define LSBDECRYPT_H

#include "lsbencrypt.h"

class LSBDecrypt : public LSBEncrypt
{
public:
    LSBDecrypt();

    void setMessageSize(int size);
    void decrypt(QColor pixelColor);
    QString getMessage();
};

#endif // LSBDECRYPT_H
