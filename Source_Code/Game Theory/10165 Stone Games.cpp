/*
Author  : Rashedul Hasan Rijul .
problem : Uva - 10165 ( stone Games) .
Algo    : Nim .
*/

#include<stdio.h>
#include<string.h>

#define ii long long int

int n;

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		if(!n) break;

		ii ans=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			ans=ans^k;
		}
		if(ans){
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}

	}

	return 0;
}
