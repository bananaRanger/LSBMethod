# LSBMethod 

### Least Significant Bit algorithm for image steganography on C++

Steganography is one of the most powerful techniques to conceal the existence of hidden secret data inside a some object.
Types of object for hide information:

* audio files
* video files
* images
* text files
* and etc.

But images are the most popular cover objects for Steganography and in this work image steganography is adopted. Embedding secret information inside images requires intensive computations, and therefore, designing Steganography in hardware speeds up Steganography. 

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

###It's all!
