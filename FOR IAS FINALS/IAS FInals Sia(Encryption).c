#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdint.h>
#include<time.h> 


void encryptedText(char textMessage[], int OTP, FILE* encryption,char alphabet[]);
void OTPCreation(FILE* OTPCreationptr, int OTP);
char randomLetterGenerator();
void fileCertification(char randomletterArr[],FILE* fileCertification,FILE *fileCertificationptrCheck);
void fileVerificationMessage(char randomletterArr[], FILE* fileCertification,FILE *fileCertificationptrCheck);
void terms(int OTP);

int main(void){
	
	FILE *encryption, *OTPCreationptr, *fileCertificationptr, *fileCertificationptrCheck;
	char alphabet[28] = {'-','a','b','c','d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n','o','p','q','r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z','\0'};  //GAMITON NATO NI PANG ENCRYPT//    
	char randomletterArr[64];
	char textMessage[255];
	char* receivedTextfromEncryptFunction;
	int OTP,i;
	char c;
	int OTPRetrieved;
	
	printf("Please input text message: ");
	gets(textMessage);
	fflush(stdin);
	
	srand(time(0));				/*CREATION of OTP*/
	OTP = (rand() %26) + 1;		/* NA NI DIRE */
	OTPCreation(OTPCreationptr, OTP);
	
	for(i = 0; i != 64; i++){
		randomletterArr[i] = randomLetterGenerator();
	}
	
	fileVerificationMessage(randomletterArr, fileCertificationptr, fileCertificationptrCheck);
	printf("\n----------------------------------\n");
	printf("|This is the encrypted message--->  ");
	encryptedText(textMessage, OTP,encryption,alphabet);
	
}

void encryptedText(char textMessage[], int OTP, FILE* encryption, char alphabet[]){

	int i;
	char encrypted[255];
	encryption = fopen("textMessage.txt", "w");
	if(encryption != NULL){	
		for(i = 0; i != strlen(textMessage) ; i++){		
			encrypted[i] = textMessage[i] ^ alphabet[OTP];
			fputc(encrypted[i], encryption);
			printf("%1d", encrypted[i]);
		}
		terms(OTP);
	}else{
		printf("File not found.");
	}
}

void OTPCreation(FILE* OTPCreation,int OTP){
	/*CREATION OF OTP IF WALA GA EXIST*/
	OTPCreation = fopen("OTP", "w");
	if(OTPCreation!= NULL){
		 putw(OTP, OTPCreation);
	}else{
		printf("File not found.");
	}
	
	fclose(OTPCreation);
}
char randomLetterGenerator(){
	char randomletter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand () % 26]; // GAMITON NATO NI PARA SA FILE INTEGRITY//
	
	return randomletter;
}
void terms(int OTP){
		printf("\n----------------------------------\n\n\n");
		printf("We have successfully encrypted your message.\n");
		printf("\n");
		printf("We have also added a one time PIN(OTP) for the other user who will receive the message.\n");
		printf("\n");
		printf("----------------------------------\n");
		printf("|This is the generated OTP---> %d |\n", OTP);
		printf("----------------------------------\n");
		printf("\n\n");
		printf("Do not disclose this information to non-legal participants.\n");
		printf("Failure to do so will result to information leaks and the program is not reliable for any damages.\n");
		printf("This will also be usef for file integrity verfication.\n");
		
		printf("\n\nAll Rights are Reserverd for Copyrights @SiaJamesKarl ©2021\n\n");
}
void fileVerificationMessage(char randomletterArr[], FILE* fileCertificationptr, FILE *fileCertificationptrCheck){
		printf("\n----------------------------------\n\n\n");
		printf("The file has been successfully verified.\n");
		printf("\n");
		printf("We have also added a the 64-bit code for the verification of the file integrity.\n");
		printf("\n");
		printf("----------------------------------\n");
		printf("|This is the generated 64-bit code--->");
		fileCertification(randomletterArr,fileCertificationptr, fileCertificationptrCheck);
		printf("\n----------------------------------\n");
		printf("\n\n");
		printf("File verification is an integral step to make sure that communication and the files \n");
		printf("being sent are correct and not faulty. This is also to ensure that the file being sent\n");
		printf("is not corrupted. The program does not take any fault if any of the files are already corrupted after encryption.\n");
}
void fileCertification(char randomletterArr[], FILE* fileCertificationptr, FILE *fileCertificationptrCheck){
	int i;
	fileCertificationptr = fopen("fileCertificate.txt", "w");
	fileCertificationptrCheck = fopen("fileCertificationAndIntegrity.txt", "w");
	if(fileCertificationptr != NULL && fileCertificationptrCheck != NULL){
		for(i = 0; i != 64 ; i++){	
			fputc(randomletterArr[i], fileCertificationptr);
			fputc(randomletterArr[i], fileCertificationptrCheck);
			printf("%c", randomletterArr[i]);
		}
	}else{
		printf("File not found.");
	}
	
}
