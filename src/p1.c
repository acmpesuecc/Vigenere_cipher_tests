#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
        //char msg[300], key[300]
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
        }
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
      
      for(k=0;k<n;k++)
      {
    	int msgLen = strlen(new_msg), keyLen = strlen(key), i, j;
    	char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
    	//generating new key
    	for(i = 0, j = 0; i < msgLen;i++)
        {
        	newKey[i] = key[j];
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
      }
	return 0;
        
}
