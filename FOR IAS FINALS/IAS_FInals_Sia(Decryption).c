#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdint.h>
#include<time.h> 


int OTPDecrypt(FILE* OTPDecryption);
void terms(FILE *decryption, int OTPRetrieved, char alphabet[]);
void fileRetrieval(FILE* decryption, int OTPRetrieved, char alphabet[]);
void fileCertVerification(FILE* certificate, FILE *comparison);
void fileVerificationMessage(FILE* certificate, FILE *comparison);

int main(void){
	
	FILE *decryption, *OTPDecryption, *retrievedFileContent, *certificate, *comparison;
	char alphabet[28] = {'-','a','b','c','d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n','o','p','q','r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z','\0'};  
	int OTPRetrieved, arr[25],i;
	char *content;	
	char textMessage[25];
	
	
	fileVerificationMessage(certificate, comparison); /*verify the integerity of the file*/
	OTPRetrieved = OTPDecrypt(OTPDecryption); /*READING THE OTP FROM FILE*/
	terms(decryption,OTPRetrieved,alphabet); /*printing the decryption part*/
	
	
}


int OTPDecrypt(FILE* OTPDecryption){
	int myOTP, OTPRetrieved;
	OTPDecryption = fopen("OTP", "r");
	if(OTPDecryption != NULL){
		while ( (OTPRetrieved = getw(OTPDecryption)) != EOF ) {
			myOTP = OTPRetrieved;
    		//printf("Your One time Pin: %d\n", OTPRetrieved);
 		}
	}else{
		printf("File not found.");
	}
	fclose(OTPDecryption);
	
	return myOTP;
}
void terms(FILE *decryption, int OTPRetrieved, char alphabet[]){

		printf("We have successfully decrypted your message.\n");
		printf("\n");
		printf("We have also retrieved the one time PIN(OTP) from the other user who sent you this message.\n");
		printf("\n");
		printf("----------------------------------\n");
		printf("|This is the retrieved OTP---> %d |\n", OTPRetrieved);
		printf("----------------------------------\n");
		printf("\n\n");
		printf("\n");
		printf("----------------------------------\n");
		printf("|This is the decrypted message---> ");
		fileRetrieval(decryption, OTPRetrieved,alphabet);
		printf("\n----------------------------------\n");
		printf("\n\n");
		printf("Do not disclose this information to non-legal participants.\n");
		printf("Failure to do so will result to information leaks and the program is not reliable for any damages.\n");
		printf("This will also be usef for file integrity verfication.\n");
		
		printf("\n\nAll Rights are Reserverd for Copyrights @SiaJamesKarl ©2021\n\n");
}

void fileRetrieval(FILE* decryption, int OTPRetrieved, char alphabet[]){
	decryption = fopen("textMessage.txt", "r");
	
	if (decryption == NULL)
      printf("FATAL ERROR File not found...");
 
    do
    {
        char c = fgetc(decryption); /*We are getting every character inside the text file and storing it to a char variable*/

        if (feof(decryption))
            break ;
 
        printf("%c", c^alphabet[OTPRetrieved]); /*Dire na part we are trying to decrypt and print immediately after decrypting the letter para dili */
    }  while(1);								/*na ma override ang value nga gi hold ni variable C*/
    
 
    fclose(decryption);
}
void fileCertVerification(FILE* certificate, FILE *comparison){
	char c[64],d[64];
	int retVal,i =0,j =0;;
	certificate = fopen("fileCertificate.txt", "r");
	comparison = fopen("fileCertificationAndIntegrity.txt", "r");
	if(certificate == NULL || comparison == NULL ){
		printf("FATAL ERROR File not found...\n");
	}else{
		do{
			c[i] = fgetc(certificate);
			d[i] = fgetc(comparison);
			if(feof(certificate) || feof(comparison))
				break;
			printf("%c", d[i]);
			i++;
		}while(1);
		
		if(strncmp(d,c,64) > 0){
			printf("\n\nCertificate incorrect!\nPlease get a digital license to continue decryption...");
			getch();
			exit(0);
		}
	}
	printf("\n");
	fclose(certificate);
}
void fileVerificationMessage(FILE* certificate, FILE *comparison){
		printf("\n----------------------------------\n\n\n");
		printf("The file has been successfully retrieved..\n");
		printf("\n");
		printf("We have also verified the 64-bit code for the verification of the file integrity.\n");
		printf("\n");
		printf("----------------------------------\n");
		printf("|Retrieved 64-bit code--->");
		fileCertVerification(certificate,comparison);
		printf("\nFULLY VERIFIED!");
		printf("\n----------------------------------\n");
		printf("File verification is an integral step to make sure that communication and the files\n");
		printf("being retrieved are correct and not faulty. This is also to ensure that the file being retrieved\n");
		printf("is not corrupted. The program does not take any fault if any of the files are already corrupted after decryption.\n\n");
}
