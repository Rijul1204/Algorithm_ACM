#include<stdio.h>
#include<math.h>

int dp[35];

void gen(int n);

int main(){
	
	int i,j,k,l,n;

	gen(30);
	
	while(scanf("%d",&n)==1){
		
		if(!n) break;
		k=pow(2,n);

		printf("%d\n",k-dp[n]);	
		
	
	}
	
	
	return 0;
	
}

void gen(int n){
	
	dp[1]=2;
	dp[2]=4;
	dp[3]=7;

	for(int i=4;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	
}