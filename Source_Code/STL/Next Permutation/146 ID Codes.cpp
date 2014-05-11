#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
	int i,len;
	char s[100];

	while(1){
		gets(s);

		if(s[0]=='#') break;

        len=strlen(s);  
		if(next_permutation(s,s+len)){
			puts(s);
		}
		else printf("No Successor\n");
	}

	return 0;
}

		