#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<map>
#include<string>
using namespace std;

#define maxm 2500

map<string,char>word;
char s[maxm],temp[maxm];

int main(){

	int i,j,k,l,test,t=1,bl=0;

	word[".-"]='A';
	word["-..."]='B';
	word["-.-."]='C';
	word["-.."]='D';
	word["."]='E';
	word["..-."]='F';
	word["--."]='G';
	word["...."]='H';
	word[".."]='I';
	word[".---"]='J';
	word["-.-"]='K';
	word[".-.."]='L';
	word["--"]='M';
	word["-."]='N';
	word["---"]='O';
	word[".--."]='P';
	word["--.-"]='Q';
	word[".-."]='R';
	word["..."]='S';
	word["-"]='T';
	word["..-"]='U';
	word["...-"]='V';
	word[".--"]='W';
	word["-..-"]='X';
	word["-.--"]='Y';
	word["--.."]='Z';
	word["-----"]='0';
	word["..---"]='2';
	word["...--"]='3';
	word["....-"]='4';
	word["....."]='5';
	word["-...."]='6';
	word["--..."]='7';
	word["---.."]='8';
	word["----."]='9';
	word[".----"]='1';
	word[".-.-.-"]='.';
	word["--..--"]=',';
	word["..--.."]='?';
	word[".----."]='\'';
	word["-.-.--"]='!';
	word["-..-."]='/';
	word["-.--."]='(';
	word["-.--.-"]=')';
	word[".-..."]='&';
	word["---..."]=':';
	word["-.-.-."]=';';
	word["-...-"]='=';
	word[".-.-."]='+';
	word["-....-"]='-';
	word["..--.-"]='_';
	word[".-..-."]='"';
	word[".--.-."]='@';

//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	scanf("%d",&test);
	gets(s);
	
	while(test--){
		
		gets(s);
		
		if(bl) printf("\n");
		bl=1;
		printf("Message #%d\n",t++);

		for(i=0;s[i];i++){
			if(s[i]==' '){
				if(s[i+1]){
					if(s[i+1]==' '){
						printf(" ");
						i++;
					}
				}
			}
			else{
				l=0;
				while(s[i]!=' '&&s[i]){
					temp[l++]=s[i++];
				}
				temp[l]='\0';
				printf("%c",word[temp]);
				i--;
			}
		}
		printf("\n");
		

	}

	return 0;
}