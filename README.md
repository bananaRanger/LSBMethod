# LSBMethod 

### Least Significant Bit algorithm for image steganography on C++

Steganography is one of the most powerful techniques to conceal the existence of hidden secret data inside a some object.
Types of object for hide information:

* audio files
* video files
* images
* text files
* and etc.

In this project I use .bmp image as object for hide information.

### How it work

#### Data representation

Image is array of pixels. Every pixel have color. Every color is obtained by mixing red, green and blue.
Pixel contain part of every of three colors(red, green, blue).
Totaly black pixel means that all of this colors are equal to 0.
Totaly white pixel means that all of this colors are equal to 255.

Simple (image 2x2 pixels):

| black (0, 0, 0)       | black (0, 0, 0)       |
| --------------------- | --------------------- |
| white (255, 255, 255) | white (255, 255, 255) |

To keep text data in this array of numbers I use next structure:

| size of length |     length     |      text      |
|--------------- | -------------- | -------------- |
| 3 pixels       | occupyLength   | length         |

#### Encrypt

To start we must upload .BMP file, and enter a some text to encrypt.
Amount of chars depend by amount of pixel in image. It's calculate in the following way:

acmount = (numbers of pixels - size of length - occupyLength) / 3

For example we have char 'Q' its index is equal to 144(128(constant) + 16(index in array of symbols)).
In binary this number equals 01010001.
Our 8 pixels have white color:
- 1 pixel 255 (in binary 11111111)
- 2 pixel 255 (in binary 11111111)
- ...
- 8 pixel 255 (in binary 11111111)

In step of encrypting least significant bit of pixel change on respective bit from char.

- 1 pixel: **1 1 1 1 1 1 1** ~~1~~ **0**
- 2 pixel: **1 1 1 1 1 1 1** ~~1~~ **1**
- 3 pixel: **1 1 1 1 1 1 1** ~~1~~ **0**
- 4 pixel: **1 1 1 1 1 1 1** ~~1~~ **1**
- 5 pixel: **1 1 1 1 1 1 1** ~~1~~ **0**
- 6 pixel: **1 1 1 1 1 1 1** ~~1~~ **0**
- 7 pixel: **1 1 1 1 1 1 1** ~~1~~ **0**
- 8 pixel: **1 1 1 1 1 1 1** ~~1~~ **1**

When text entered is finished we can encrypt the message and save the file.

#### Decrypt

To decrypt we open image in decrypt tab.
At first, we need to get the size of length. Then we read length of the message. And finally, read the message.

##### It's all!

### Screenshots

#### Encrypting 
![](https://github.com/bananaRanger/LSBMethod/blob/master/Screenshots/encryption.png?raw=true)

#### Decrypting
![](https://github.com/bananaRanger/LSBMethod/blob/master/Screenshots/decryption.png?raw=true)

#### Image loading without encryption
![](https://github.com/bananaRanger/LSBMethod/blob/master/Screenshots/errorHandler.png?raw=true)

