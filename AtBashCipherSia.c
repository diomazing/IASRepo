#include<stdio.h>
#include<string.h>

char* encrypt(char encpt[]);
char* decrypt(char decpt[]);

int main(void){
	
	char plainText[100], encptArr[100], decptArr[100];
	printf("Enter plaintext:");
	gets(plainText);
	strupr(plainText);
	strcpy(encptArr, encrypt(plainText));
	printf("\n\nEncrypted text: %s\n", encptArr);
	printf("\n\nWe successfully Encrypted your message..\n\n");
	strcpy(decptArr, decrypt(encptArr));
	printf("Decrypted text: %s\n", decptArr);
	printf("\n\nPERFECTO AMIGO! WE DECRYPTED YOUR MESSAGE...");
	return 0;
}

char* encrypt(char encpt[]){
	int i, a;
	char characterToChange, encpt1[100];
	for(i=0; i < strlen(encpt); i++){
		a = encpt[i];
		a = 91 - (a-64);
		characterToChange = a;
		encpt[i] = characterToChange;
	}
	return encpt;
}
char* decrypt(char decpt[]){
	int i, a;
	char characterToChange, decpt1[100];
	for(i=0; i < strlen(decpt); i++){
		a = decpt[i];
		a = 91 - (a-64);
		characterToChange = a;
		decpt[i] = characterToChange;
	}
	return decpt;
}
