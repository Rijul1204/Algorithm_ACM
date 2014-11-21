#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){

	int l,test;
	char s[25],dum;

	scanf("%d%c",&test,&dum);

	while(test--){

		gets(s);
		l=strlen(s);
		sort(s,s+l);

		do{
			puts(s);

		}while(next_permutation(s,s+l));

		printf("\n");

	}


	return 0;

}



