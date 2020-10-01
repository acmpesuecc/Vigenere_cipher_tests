# The Vigenere Cipher

## An Introduction
The [Vigenere Cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher) is a method of cipher encryption that was created in 1553 by Giovan Battista Bellaso. It is a combination of all the possible [Caesar Shift Ciphers](https://en.wikipedia.org/wiki/Caesar_cipher) in the English alphabet, and was considered to be almost impossible to break for around 300 years, until Charles Babbage broke the code in 1854. Since it uses a combination of multiple sets of letters, it is considered to be a [Polyalphabetic Cipher](https://en.wikipedia.org/wiki/Polyalphabetic_cipher)

## What is it?
The Vigenere Cipher is Simply a 26x26 matrix, where the rows and columns consist of the 26 letters written in order as shown in the link to the polyalphabetic cipher above. If we are given a [Plaintext](https://en.wikipedia.org/wiki/Plaintext) (Not to be confused with [Plain Text](https://en.wikipedia.org/wiki/Plain_text), we simply determine a key to encrypt it and decrypt it. It is crucial that both parties, one of whom encrypts and the other decrypts, are made aware of the key being used. 

## How it works
Assume we have a text **"WELCOME TO HACKTOBER"** and we decide to use a random key **"FEST"**, we first consider the entire plaintext with **NO SPACES**, and write the key below it
                                                                WELCOMETOHACKTOBER
                                                                FESTFESTFESTFESTFE
This looks a little complicated, but as we can see we have simply repeated the key four and a half times. This is done to make the lengths of the plaintext and the key equal. Why you ask? Here comes the fun part.
The first letter of the plaintext corresponds to your row, and the first letter in your extended key corresponds to your column in the alphabet matrix, or vice versa. The corresponding letter in the matrix is the first letter of your [Ciphertext](https://en.wikipedia.org/wiki/Ciphertext). So we get our ciphertext as: **BIDVLRILHEFGCMLGIJ**. 
The decryption process follows the same procedure, only here, we have the Ciphertext and the key. To decrypt our hidden message, we simply check for the letter corresponding to the cipher in the matrix, and the letter corresponding to the key in the matrix row or column, and continue it till we obtain our plaintext!

## The program
In the program, we follow the given steps: 
* We first initialize the plaintext string as well as the key string. 
* Take inputs from the user 
* Generate the entire key 
* Compare it with the the plaintext and generate the ciphertext encryption
* We perform the decryption process in a similar way and display our original message.
Feel free to add in any extra functions to make this a better working code!

## The formula
### Encryption
We have the code: `encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A'`
This is one of the methods used to encrypt it. Not too hard, but all it does is it takes a plaintext letter, and the corresponding key alphabet and adds their ASCII values. ON doing so we get the remainder using the **mod** operator, modding it with 26 (number of english alphabets obviously!), the remainder is then added to the ascii value of A (i.e, 65) to obtain our ciphered letter.

### Decryption
We have the code: `decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A'`
Fairly simple like encryption, it takes the ciphertext letter and the corresponding key letter and subtracts the two. The difference in the two gives us the **position** of the letter in the alphabet, such as if we get 12, it is the letter L! But how do we show this? We simply add 26 to the difference (As it may be a negative value too) and hence mod it with 26 to get the remainder. Add it to the ascii value of 'A' and bam! you have your plaintext letter. 
