#include<stdio.h>
#include<string.h>
#include<ctype.h>

char s[110000],sin[110000];

int main(){

	int i,j,k,l;

//	freopen("in.txt","r",stdin);

	while(gets(s)){
		if(strcmp(s,"DONE")==0) break;
		l=strlen(s);
		j=0;
		for(i=l-1;i>=0;i--){
			if(isalpha(s[i])){
				if(s[i]>=90){
					sin[j]=s[i]-'a'+'A';
				}
				else sin[j]=s[i];
				j++;
			}
		}
		sin[j]='\0';
		l=strlen(sin);
		j=0;
		for(i=l-1;i>=0;i--){
			s[j++]=sin[i];			
		}
		s[j]='\0';
		if(strcmp(s,sin)==0) printf("You won't be eaten!\n");
		else printf("Uh oh..\n");



	}



	return 0;
}