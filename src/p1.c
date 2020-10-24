#include<stdio.h>
#include<string.h>
 
int main()
{
    char msg[300], key[300]; 
	label: printf("Enter the message to encrypt in caps :\n");
	scanf("%[^\n]%*c",msg);
	int status = 0;
	int status_arr[strlen(msg)];
	for(int i = 0; i < strlen(msg); i++)
	{
		if((msg[i] > 'a' && msg[i] < 'z') || (msg[i] > 'A' && msg[i] < 'Z') || msg[i] == ' ')
		{
			status_arr[i] = 1;
		}
		else{
			status_arr[i] = 0;
		}
	}

	for(int i = 0; i < strlen(msg); i++)
	{
		if(status_arr[i] == 0)
		{
			status = 0; // a character other than a letter is found
			printf("Warning: Type only letters!\n");
			goto label;
		}
		else
		{
			status = 1;
		}
	}	

	if(status == 1)
	{
		printf("Enter the key to use in caps :\n");
		scanf("%[^\n]%*c",key);
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
	return 0;
	}
}
