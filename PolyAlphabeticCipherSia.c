#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
            int i,j=0;
            int temp1,temp2;
            int dataLength,keyLength,sum;
            char plainText[100],keyValue[100],cipher[100];

            printf("Enter Plain text : ");
            gets(plainText);
            printf("Enter Key Value : ");
            gets(keyValue);

            dataLength=strlen(plainText);
            keyLength=strlen(keyValue);
			
			//ENCRYPTION
            for(i=keyLength;i<dataLength;i++)
            {
                if(plainText[i]==32)
            	{
                    i++;
                }
                keyValue[i]=keyValue[j];
                j++;
            }

            for(i=0;i<dataLength;i++)
            {
                if(plainText[i]==32)
                {
                    cipher[i]=' ';
                    i++;
                }
                else if(plainText[i] <= 90 && plainText[i] >= 65)
                {
                    temp1= plainText[i] - 65;
                }
                else if(plainText[i] <= 123 && plainText[i] >= 97)
                {
                    temp1=plainText[i] - 97;
                }

                temp2=keyValue[i] - 64;
                sum = temp1 + temp2;

                if(sum > 26)
                {
                	sum -= 26;
                    cipher[i]= sum + 64;
                }
                else
                {
                    cipher[i] = sum + 64;
                }
            }
            cipher[i++]='\0';
             for(i=5; i !=0 ; i--){
            	printf("\nEncrypting in %d...\n", i);
			}
			printf("\n\n We have successfully encrypted your message...\n\n");
			printf("Encrypted Text: ");
            puts(cipher);
			getch();
			//DECRYPTION
            for(i=0;cipher[i]!='\0';i++)
            {
                temp1 = cipher[i] - 64;
                temp2 = keyValue[i] - 65;
                sum = temp1 - temp2;

                if(sum < 0)
                {
                    sum += 26;
                    cipher[i] = sum + 64;
                }
                else
                {
                    cipher[i] = sum + 64;
                }
            }
            cipher[i++]='\0';
            
            for(i=5; i !=0 ; i--){
            	printf("Decrypting in %d...\n", i);
			}
			printf("\n\nPERFECTO AMIGO! We have decoded the message...\b");
            printf("\n\nDecrypted Text: ");
            puts(cipher);
            
            getch();
}

