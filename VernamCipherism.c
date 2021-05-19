#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h> 


char* encryptedMessage(char *, int , char [] );
char* decryptedMessage(char *, int , char [] );

int main(void){
	char alphabet[28] = {'-','a','b','c','d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n','o','p','q','r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z','\0'};      
	char enteredMessage[255], *receivedEncryptedMessage, *receivedDecryptedMessage;
	int OTP, i , j, chk;
	srand(time(0));
	OTP = (rand() %26) + 1;
	
	printf("This is your OTP: %d \n", OTP);
	printf("\nPlease input your message: ");
	gets(enteredMessage);
	fflush(stdin);
	while(enteredMessage[i]!='\0')	/*gagamit ko ani kay kung mu input ang user nga naay space ang first word ra ang ma encrypt so ato na lang pang tangtangon ang spaces para mahusay*/
    {								/*kapoy na debug waratatata*/
        chk=0;
        if(enteredMessage[i]==' ')
        {
            j=i;
            while(enteredMessage[j-1]!='\0')
            {
                enteredMessage[j] = enteredMessage[j+1];
                j++;
            }
            chk = 1;
        }
        if(chk==0)
            i++;
    }
    printf("\nString (without spaces): %s", enteredMessage);
    getch();
	receivedEncryptedMessage = encryptedMessage(enteredMessage, OTP, alphabet);
	printf("Encrypted Message: %i", receivedEncryptedMessage);
	receivedDecryptedMessage = decryptedMessage(receivedEncryptedMessage,OTP,alphabet); 
	printf("\nDecrypted Message: %s", receivedDecryptedMessage);
	return 0;   
}
char* encryptedMessage(char *enteredMessage, int OTP, char alphabet[]){
	char *encrypted;
	int i;
	encrypted = (char*)malloc(sizeof(char)* 255);
	if(encrypted == NULL){
		printf("Error allocating memory!\n");
	}else{
		for(i = 0; i != strlen(enteredMessage) ; i++){		
			encrypted[i] = enteredMessage[i] ^ alphabet[OTP];
		}
		printf("\n");
	}
	
	
	return encrypted;
}
char* decryptedMessage(char *enteredMessage, int OTP, char alphabet[]){
	int i;
	char *decrypted;
		decrypted= (char*)malloc(sizeof(char)*255);
		if (decrypted==NULL) {
			printf("Error allocating memory!\n"); 
		}else{
			for(i = 0; i != strlen(enteredMessage); i++){
				decrypted[i] = enteredMessage[i] ^ alphabet[OTP];
			}
		}
	return decrypted;
}
