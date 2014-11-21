#include<stdio.h>
#include<string.h>

//#define ii __int64
#define ii long long int
#define maxm 60

ii dp[maxm];

int main(){

	int i,j,k,l,n,test,t=1;

	dp[0]=1; dp[1]=2;

	for(i=2;i<=51;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		printf("Scenario #%d:\n%lld\n\n",t++,dp[n]);
		//printf("%I64d\n",dp[n]);
	}

	return 0;
}