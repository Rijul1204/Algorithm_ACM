#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct{
	char word[10];
	char sorted[10];
}dictionary;
dictionary dict[110];

bool compare(dictionary a,dictionary b);

int main(){

	int i=0,j;
	bool flag;
	char s[10];

	freopen("in.txt","r",stdin);
	
	while(gets(s)){

		if(!strcmp(s,"XXXXXX")) break;

		else {
			strcpy(dict[i].word,s);
			sort(s,s+strlen(s));
			strcpy(dict[i].sorted,s);
			i++;
		}
	}

	sort(dict,dict+i,compare);

	while(gets(s)){
		if(!strcmp(s,"XXXXXX")) break;

		else {
			flag=0;
             sort(s,s+strlen(s));
			 for(j=0;j<i;j++){
				if(!strcmp(s,dict[j].sorted)){
					puts(dict[j].word);
					flag=1;					
				}
			}
			if(!flag) printf("NOT A VALID WORD\n");
			printf("******\n");
		}
	}

	return 0;
}

bool compare(dictionary a,dictionary b){
	int k;
	k=strcmp(a.word,b.word);
	if(k<0) return 1;
	return 0;
}

	


		