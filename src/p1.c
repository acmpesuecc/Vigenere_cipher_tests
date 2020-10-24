#include<stdio.h>
#include<string.h>

int main()
{
        char msg[300], key[300];
        printf("Enter the message to encrypt in caps: \n");
        scanf("%[^\n]",msg);

        char new_msg[300];
        int c = 0, d = 0;
        int arr[300];
        while (msg[c] != '\0')
        {
          if ((msg[c] != ' ')) {
            new_msg[d] = msg[c];
            d++;
          }
          c++;
        }
        new_msg[d] = '\0';

        printf("Enter the key to use in caps and no spaces:\n");
        scanf("%s",key);

    	int msgLen = strlen(new_msg), keyLen = strlen(key), i, j;
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
        	encryptedMsg[i] = ((new_msg[i] + newKey[i]) % 26) + 'A';
    	//decryption
    	for(i = 0; i < msgLen; ++i)
        	decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
    	printf("Original Message: %s", msg);
    	printf("\nKey: %s", key);
    	printf("\nNew Generated Key: %s", newKey);
    	printf("\nEncrypted Message: %s", encryptedMsg);
    	printf("\nDecrypted Message: %s\n", decryptedMsg);
	return 0;
}
