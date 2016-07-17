# LSBMethod 

### Least Significant Bit algorithm for image steganography on C++

Steganography is one of the most powerful techniques to conceal the existence of hidden secret data inside a some object.
Types of object for hide information:

* audio files
* video files
* images
* text files
* and etc.

In this project I use image as object for hide information.

### How it work

#### Encrypt

To start we must upload .BMP file, and enter a some text to encrypt.
Amount of chars depend by amount of pixel in image. Because 8 pixel contains 1 char.
For example we have char 'Q' its index is equal to 144(128(constant) + 16(index in array of symbols)).
In binary this number equals 10010000.
Our 8 pixels have white color:
- 1 pixel 255 (in binary 11111111)
- 2 pixel 255 (in binary 11111111)
- ...
- 8 pixel 255 (in binary 11111111)

In step of encrypting least significant bit of pixel change on respective bit from char.

- 1 pixel: **1 1 1 1 1 1 1** ~~1~~ **1**
- 2 pixel: **1 1 1 1 1 1 1** ~~1~~ **0**
- 3 pixel: **1 1 1 1 1 1 1** ~~1~~ **0**
- 4 pixel: **1 1 1 1 1 1 1** ~~1~~ **1**
- 5 pixel: **1 1 1 1 1 1 1** ~~1~~ **0**
- 6 pixel: **1 1 1 1 1 1 1** ~~1~~ **0**
- 7 pixel: **1 1 1 1 1 1 1** ~~1~~ **0**
- 8 pixel: **1 1 1 1 1 1 1** ~~1~~ **0**

When text entering is finished we can encrypt message and save the file.

#### Decrypt

To decrypt we open image in decrypt tab. And click button "Decrypt".

##### It's all!

### Screenshots

#### Encrypting
![](https://psv4.vk.me/c615319/u12148050/docs/01cd08140704/lsb1.png?extra=wcoFRkCWEL4JpUNx2S13ubDxV519feVk2tMhKs7x44gKps_vdCkSA9Q-kvgFDNunT_sVHUOMB2Cxwv7UGFanhUWzR57GTYzEECn8CBjYpm6InfJzzMXX9Q)

#### Decrypting
![](https://psv4.vk.me/c615319/u12148050/docs/678e13f04222/lsb2.png?extra=klopaMXJfdB6Ay92OyhriEOul3ceR7V3dRMJy-c4awk7Ndi_6fKncaxXCLEB-PnYC1ml8SAw-nT-gkg5D63RPt8yXHoJCiS4IgC8KCOHeelDv27c2cFsEQ)
