#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "header.h"
 
int main(void)
{
	char msg[300],  key[300], ch;
	int i, j;
	printf("Enter the message (only letters):\n");
	fgets(msg, 300, stdin);
	printf("Enter the key: \n");
	fgets(key, 300, stdin);
	remove_spaces(msg);
	remove_spaces(key);
	allupper(msg);
	allupper(key);
	int msgLen = strlen(msg), keyLen = strlen(key);
	if(keyLen >= msgLen)
	{
		printf("Not a valid execution, try again!\n");
		exit(0);
	}
    	char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
    	//generating new key
    	for(i=0, j=0; i<msgLen; i++, j++)
	{
       		if(j == keyLen)
       			j = 0;
       		newKey[i] = key[j];
  	}
    	newKey[i] = '\0';
    	//encryption
    	for(i = 0; i < msgLen-1; i++)
	{
    		encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
   	}
	encryptedMsg[i] = '\0';
    	//decryption
    	for(i = 0; i < msgLen-1; i++)
	{
        	decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
	}
	decryptedMsg[i] = '\0';
    	printf("Original Message: %s \n", msg);
    	printf("Key: %s \n", key);
   	printf("New Generated Key: %s", newKey);
    	printf("\nEncrypted Message: %s \n", encryptedMsg);
    	printf("Decrypted Message: %s\n", decryptedMsg);
	return 0;
}
