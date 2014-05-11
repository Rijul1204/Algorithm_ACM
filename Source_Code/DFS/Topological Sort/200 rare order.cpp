#include<stdio.h>
#include<string.h>
#include<queue>
#include<ctype.h>
using namespace std;

char s[10000][25];
bool ch[26];
queue<char>rijul;

int main(){

	int i=0,j,n;
	char temp;

	while(1){
		gets(s[i]);
		if(s[i][0]=='#') break;
		i++;
	}
	n=i;
       
	for(i=0;i<n;i++){
		for(j=0;s[j][i];j++){
			if(isalpha(s[j][i])){
				if(ch[s[j][i]-'A']==0){
					rijul.push(s[j][i]);
					ch[s[j][i]-'A']=1;
				}
			}
		}
	}
	while(!rijul.empty()){
		printf("%c",rijul.front());
		rijul.pop();
	}
	printf("\n");

	return 0;
}



	


		
		



