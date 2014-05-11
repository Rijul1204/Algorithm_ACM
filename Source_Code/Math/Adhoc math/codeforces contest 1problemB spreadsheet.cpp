#include<stdio.h>
#include<string.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define maxm 100

int n;
char s[maxm];

bool excel(char s[]);
void convert1(char s[]);
void convert2(char s[]);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		
		for(i=1;i<=n;i++){
			scanf("%s",s);
			if(excel(s)){
				convert1(s);
			}
			else convert2(s);
		}

	}

	return 0;
}


bool excel(char s[]){

	if(s[0]!='R') return 1;
	if(isalpha(s[1])) return 1;
	int k=0,l=0,i;
	for(i=2;s[i];i++){
		if(isalpha(s[i])) return 0;
	}
	return 1;

}

void convert1(char s[]){

	int i,j,k,l; char temp[100];
	k=0;	
	for(i=0;s[i];i++){
		if(isdigit(s[i])) break; 
		l=s[i]-'A'; l++;
		k*=26; k+=l;
		
	}
	strcpy(temp,s+i);
	printf("R%sC%d\n",temp,k);	
	
}

void convert2(char s[]){

	int i,j,k,l;

	char temp[100],temp1[100];
	k=0;
	for(i=1;s[i];i++){
		if(s[i]=='C') break;
		temp[k++]=s[i];		
	}
	temp[k]='\0';

	strcpy(temp1,s+i+1);
	l=atoi(temp1);
	temp1[0]='A';
	l--;
	k=0; j=0;
	while(l>=0){
		temp1[k++]=l%26;
		temp1[k-1]=temp1[k-1]+'A';		
		l/=26;
		l--;
	}
	temp1[k]='\0';
	for(i=k-1;i>=0;i--){
		printf("%c",temp1[i]);
	}
	printf("%s\n",temp);
	
}