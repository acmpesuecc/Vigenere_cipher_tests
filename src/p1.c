#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    //char msg[300], key[300]; 
	char *msg = NULL;
	char *key = NULL;
	int n, k;
	printf("Enter the number of messages you want to encrypt\n");
	scanf("%d",&n);
	msg = (char*)malloc(n*sizeof(char));
	key = (char*)malloc(n*sizeof(char));
	for (k=0; k<n; ++k){
		printf("Enter the message to encrypt\n");
		scanf("%s",&msg[k]);
		printf("Enter the key to use in caps and no spaces:\n");
		scanf("%s",&key[k]);
		//answer(*msg, *key);
	}

	/*printf("Enter the message to encrypt in caps and no spaces:\n");
	scanf("%[^\n]",msg);
	
	scanf("%s",key); */
		
		for(k=0;k<n;k++)
		{
    	int msgLen = strlen(msg), keyLen = strlen(key), i, j;
    	char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
    	//generating new key
    	for(i = 0, j = 0; i < msgLen; ++i, ++j)
		{
        	if(j == keyLen)
            		j = 0;
        	newKey[i] = key[j];
    	}
    	//encryption
    	for(i = 0; i < msgLen; ++i)
        	encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
    	//decryption
    	for(i = 0; i < msgLen; ++i)
        	decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
    	printf("Original Message: %s", msg);
    	printf("\nKey: %s", key);
    	printf("\nNew Generated Key: %s", newKey);
    	printf("\nEncrypted Message: %s", encryptedMsg);
    	printf("\nDecrypted Message: %s\n", decryptedMsg);
		}
	return 0;
	
}
