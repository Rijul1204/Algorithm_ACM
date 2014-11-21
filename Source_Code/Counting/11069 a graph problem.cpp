#include<stdio.h>

int dp[1000];

int main(){

	int i,j,k,l,n;

	dp[0]=0;dp[1]=1;dp[2]=2;dp[3]=2;dp[4]=3;

	for(i=5;i<=76;i++) dp[i]=dp[i-2]+dp[i-3];

	while(scanf("%d",&n)==1){

		printf("%d\n",dp[n]);


	}


}