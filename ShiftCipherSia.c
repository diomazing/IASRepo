#include<stdio.h>
#include<string.h>
char* shiftCipherEncrypt(char message[], int key);
char* shiftCipherDecrypt(char message[], int key);
int main()
{
	char message[500];
	char *encryptedMessage, *decryptedMessage;
	int i, key;
	
	printf("Enter a message to encrypt: ");
	gets(message);
	strlwr(message);
	printf("Enter key (Shifts to make, REMINDER: this is an integral value ): ");
	scanf("%d", &key); 																//MAGUBA ANG CODE PAG IPAABOT UG 7 ANG KEY DAPAT 6 AND BELOW LANG XD
	for(i = 5; i != 0; i--){
		printf("Encrypting in %d...\n", i);
	}
	encryptedMessage = shiftCipherEncrypt(message,key);
	printf("\nEncrypted message: %s\n\n", encryptedMessage);
	getch();
	for(i = 5; i != 0; i--){
		printf("Decrypting in %d...\n", i);
	}
	decryptedMessage = shiftCipherDecrypt(encryptedMessage,key);
	printf("\nDecrypted message: %s", decryptedMessage);
	
	return 0;
}

char* shiftCipherEncrypt(char message[], int key){
	int i = 0;
	char characterToChange;
	for(i = 0; message[i] != '\0'; ++i){
		characterToChange = message[i];
		
		if(characterToChange >= 'a' && characterToChange <= 'z'){
			characterToChange += key;
			
			if(characterToChange > 'z'){
				characterToChange = characterToChange - 'z' + 'a' - 1;
			}
			message[i] = characterToChange;
		}
	}
	return message;
}
char* shiftCipherDecrypt(char message[], int key){
	int i = 0;
	char characterToChange;
	for(i = 0; message[i] != '\0'; ++i){
		characterToChange = message[i];
		
		if(characterToChange >= 'a' && characterToChange <= 'z'){
			characterToChange -= key;
			if(characterToChange > 'z'){
				characterToChange = characterToChange + 'z' - 'a' + 1;
			}else if(characterToChange < 'a'){
				characterToChange = characterToChange + 26; //sometimes it will be brought back below the aplhabetical value in the ANSCII table so we need to add 26 in order to bring it back to the alphabetical part of the ANSCII
															//kung wala ni nga code if you type 'y' or any characters that will result to a greater value than z it will output non alphabetical characters.
			}
			message[i] = characterToChange;
		}
	}
	return message;
}
