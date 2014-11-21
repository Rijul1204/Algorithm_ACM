#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define ii long long int
#define maxm 30

char s[maxm],s1[maxm];

int main(){

	int i,j,k,l;
	ii n1,n2;

	//freopen("in.txt","r",stdin);

	while(scanf("%s",&s)==1){

		l=strlen(s);	
		sort(s,s+l);
		reverse(s,s+l); strcpy(s1,s);
		reverse(s,s+l);
		
		while(s[0]=='0'){
			next_permutation(s,s+l);
		}

		sscanf(s,"%lld",&n1);
		
		sscanf(s1,"%lld",&n2);
		

	//	printf("%I64d %I64d\n",n1,n2);

		printf("%lld - %lld = %lld = 9 * %lld\n",n2,n1,n2-n1,(n2-n1)/9);
		


	}


	return 0;
}