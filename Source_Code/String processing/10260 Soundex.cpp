#include<stdio.h>

int main(){

	int i,j,flag,flagm;
	char s[50];

	//freopen("in.txt","r",stdin);

	while(gets(s)){

		flag=0;
	

		for(i=0;s[i];i++){

			if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='H'||s[i]=='W'||s[i]=='Y'){
				flag=0;
				continue;
			}

			if(flag!=1){
				if(s[i]=='B'||s[i]=='F'||s[i]=='P'||s[i]=='V'){
					printf("1");
					flag=1;
					flagm=1;
				}
			}
			if(flag!=2){
				if(s[i]=='C'||s[i]=='G'||s[i]=='J'||s[i]=='K'||s[i]=='Q'||s[i]=='S'||s[i]=='X'||s[i]=='Z'){
					printf("2");
					flag=2;flagm=1;
				}
			}
			if(flag!=3){
				if(s[i]=='D'||s[i]=='T'){
					printf("3");
					flag=3;flagm=1;
				}
			}
			if(flag!=4){
				if(s[i]=='L'){
					printf("4");
					flag=4;flagm=1;
				}
			}
			if(flag!=5){
				if(s[i]=='M'||s[i]=='N'){
					printf("5");
					flag=5;flagm=1;
				}
			}
			if(flag!=6){
				if(s[i]=='R'){
					printf("6");
					flag=6;flagm=1;
				}
			}			

			

		}

		printf("\n");	

	}

	return 0;
}

