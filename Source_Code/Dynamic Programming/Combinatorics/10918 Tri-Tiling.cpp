#include<stdio.h>
#include<string.h>

//#define ii __int64
#define maxm 35

int dp[maxm],sum[maxm];

int main(){

	int i,j,k,l;

	dp[0]=1;
	sum[0]=1;
	dp[2]=3;
	sum[2]=4;
	
	for(i=4;i<=30;i+=2){
		dp[i]=3*dp[i-2];
		dp[i]+=2*(sum[i-4]);
		sum[i]=(sum[i-2]+dp[i]);
	}

	while(scanf("%d",&i)==1){
		if(i<0||i>30) break;
		printf("%d\n",dp[i]);
	}



	return 0;
}