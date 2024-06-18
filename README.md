# 103cipher
Epitech Project, MATHS 103

Subject:

Cryptography is a very old science, whose goal is to secure communication, so that only its recipient could read it.
There are a lot of methods to encrypt a message, from the simplest (like the 2000-year-old Cesar’s code) to the
most complex (like the World War 2 Enigma code) ; they all need both encryption and decryption keys (sometimes
identical).
In some cases (such as the Hill cipher), the key is represented by a matrix.
You have to carry out such a matrix-based ciphering software, using the following process to encrypt :
1. transcript the key into numbers using the ASCII table,
2. convert the numbered key into a square matrix, the smallest possible size, and filling the lines first,
3. transcript the clear message into numbers using the ASCII table,
4. convert the numbered message into a matrix ; its number of columns should fit the key matrix size, and its
number of lines should be as small as possible,
5. multiply the 2 matrices, and write the answer linearly to get the encrypted message.

Usage:

./103cipher message key flag
message: a message, made of ASCII characters
key: the encryption key, made of ASCII characters
flag: 0 for the message to be encrypted, 1 to be decrypted

Example:

![alt text](https://raw.githubusercontent.com/alexandre10044/103cipher/master/example.png)
