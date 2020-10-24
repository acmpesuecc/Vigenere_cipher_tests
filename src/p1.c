#include<stdio.h>
#include<string.h>

int main()
{
        char msg[300], key[300];
        char temp;
        printf("Enter the message to encrypt in caps: \n");
        scanf("%[^\n]",msg);

        scanf("%c",&temp); // temp statement to clear buffer

        printf("Enter the key in caps: \n");
        scanf("%[^\n]",key);

        char new_msg[300];
        int c = 0, d = 0;
        while (msg[c] != '\0')
        {

          if ((msg[c] != ' ')) {
            new_msg[d] = msg[c];
            d++;
          }
          c++;
        }
        new_msg[d] = '\0';

        char new_key[300];
        c = 0; d = 0;
        while (key[c] != '\0')
        {

          if ((key[c] != ' ')) {
            new_key[d] = key[c];
            d++;
          }
          c++;
        }
        new_key[d] = '\0';

    	int msgLen = strlen(new_msg), keyLen = strlen(new_key), i, j;
    	char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
    	//generating new key
    	for(i = 0, j = 0; i < msgLen;i++)
        {
        	newKey[i] = new_key[j];
        	j++;
        	if(j == keyLen)
                j=0;
    	}
    	newKey[msgLen]='\0';
    	//encryption
    	for(i = 0; i < strlen(newKey); ++i)
        	encryptedMsg[i] = ((new_msg[i] + newKey[i]) % 26) + 'A';

        encryptedMsg[msgLen]='\0';
    	//decryption
    	for(i = 0; i < strlen(newKey); ++i)
        	decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
        decryptedMsg[msgLen]='\0';
    	printf("Original Message: %s", msg);
    	printf("\nKey: %s", key);
    	printf("\nNew Generated Key: %s", newKey);
    	printf("\nEncrypted Message: %s", encryptedMsg);
    	printf("\nDecrypted Message: %s\n", decryptedMsg);
	return 0;
}
