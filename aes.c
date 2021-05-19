#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
 
int firstPrime,secondPrime,totalOfPrime,composite,flag,e[100],d[100],temp[100],j,m[100],en[100],i;
char enteredMessage[100];

int prime(int);
void possibleValues();
 
int cd(int);
void encrypt();
void decrypt();
 
void main() {
 	int checker;
 	
printf("\nPlease Enter the first prime number: \n");
	scanf("%d",&firstPrime);
	
	flag=prime(firstPrime); 	/*ATO I CHECK IF ANG FIRST INPUT PRIME BA GYUD*/
	if(flag==0) {
 		printf("\nOops... that doesn't match up'\n");
 		getch();
		exit(1);
	}
 
	printf("\nPlease Enter the secondary prime number: \n");
	scanf("%d",&secondPrime);
	
	flag=prime(secondPrime);			/*ATO I CHECK IF ANG SECOND INPUT PRIME BA GYUD*/
	if(flag==0||firstPrime==secondPrime) {
		printf("\nOops... that doesn't match up'\n");
		getch();
		exit(1);
	}
 
	printf("\nPlease enter the message to be encrypted: \n");
 
	fflush(stdin);
 
	gets(enteredMessage);
	
	while(enteredMessage[i]!='\0')	/*gagamit ko ani kay kung mu input ang user nga naay spapossibleValues ang first word ra ang ma encrypt so ato na lang pang tangtangon ang spapossibleValuess para mahusay*/
    {								/*kapoy na debug waratatata*/
        checker=0;
        if(enteredMessage[i]==' ')
        {
            j=i;
            while(enteredMessage[j-1]!='\0')
            {
                enteredMessage[j] = enteredMessage[j+1];
                j++;
            }
            checker = 1;
        }
        if(checker==0)
            i++;
    }
 
	for (i=0;enteredMessage[i]!= '\0';i++){
		m[i]=enteredMessage[i];
 
		totalOfPrime = firstPrime * secondPrime;
	 
		composite = (firstPrime-1) * (secondPrime-1);
	}
	
	possibleValues();
 
	printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
 
	for (i=0;i<j-1;i++){
		printf("\n%ld\t%ld",e[i],d[i]);
	}
 
	encrypt();
 
	decrypt();
 
	getch();
 
}
 
int prime(int pr) {
 
	int i;
 
	j=sqrt(pr);
 
	for (i=2;i<=j;i++) {
		if(pr%i==0)
		    return 0;
	}
	return 1;
 
}
 
void possibleValues() {
 
	int k;
 
	k=0;
 
	for (i=2;i<composite;i++) {
 
		if(composite%i==0)
		    continue;
 
		flag=prime(i);
 
		if(flag == 1 && i != firstPrime && i != secondPrime) {
			e[k] = i;
			flag = cd(e[k]);
			if(flag > 0){
				d[k] = flag;
				k++;
			}
			if(k == 99)
				break;
		}
	}
}
 
int cd(int x) {
 
	int k=1;
 
	while(1) {
		k += composite;
 
		if(k % x == 0){
			return(k / x);
		}
	}
}
 
void encrypt() {
 
	long int pt,ct,key=e[0],k,len;
 
	i=0;
 
	len=strlen(enteredMessage);
 
	while(i!=len) {
 
		pt=m[i];
 
		pt=pt-96;
 
		k=1;
 
		for (j=0;j<key;j++) {
			k=k*pt;
			k=k%totalOfPrime;
		}
		temp[i]=k;
 
		ct=k+96;
 
		en[i]=ct;
 
		i++;
	}
 
	en[i]=-1;
 
	printf("\nTHE ENCRYPTED MESSAGE IS\n");
 
	for (i=0;en[i]!=-1;i++)
 
	printf("%c",en[i]);
 
}
 
void decrypt() {
 
	long int pt,ct,key=d[0],k;
 
	i=0;
 
	while(en[i]!=-1) {
 
		ct=temp[i];
 
		k = 1;
 
		for ( j = 0; j < key; j++) {
 
			k = k * ct;
 
			k = k % totalOfPrime;
 
		}
 
		pt = k + 96;
 
		m[i]=pt;
 
		i++;
 
	}
 
	m[i] = -1;
 
	printf("\nThe decrypted message is:\n");
 
	for (i=0;m[i]!=-1;i++)
 
	printf("%c",m[i]);
 
}
 
