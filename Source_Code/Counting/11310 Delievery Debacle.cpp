#include<stdio.h>
#include<string.h>

#define maxm 50
//#define ii __int64
#define ii long long int

ii dp[maxm];
void cal(int n);

int main(){

	int i,j,k,l,test,n;

	cal(40);
	scanf("%d",&test);
	

	while(test--){
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}

	return 0;
}

void cal(int n){
	
	
	dp[0]=1;
	dp[1]=1;
	dp[2]=5;

	int i,j;
	ii ret=0;

	for(i=3;i<=n;i++){
		dp[i]=dp[i-1]+4*dp[i-2]+2*dp[i-3];
	}


}