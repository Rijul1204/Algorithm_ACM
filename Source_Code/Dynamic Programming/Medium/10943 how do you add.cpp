#include<stdio.h>
#include<string.h>

#define ii long long int
#define maxm 150

ii dp[maxm][maxm];
int n,k;

ii cal(int n,int k);

int main(){
	
	int i,j,l;
	
//	freopen("in.txt","r",stdin);
		
	while(scanf("%d %d",&n,&k)==2){
		
		if(!n&&!k) break;
		memset(dp,-1,sizeof(dp));		
		printf("%lld\n",(cal(n,k))%1000000);
		
	}	
	
	return 0;
}

ii cal(int n,int k){
	
	if(n<0||k<0) return 0;
	if(n==0&&k==0) return 1;
	//else if(k==0||n==0) return 0;
	
	if(dp[n][k]!=-1) return dp[n][k];
	
	//printf("%d %d %d\n",n,k,sum);
	
	int i;
	ii ret;
	ret=0;
	
	for(i=0;i<=n;i++){
		ret+=cal(n-i,k-1);
		ret%=1000000;				
	}
	ret%=1000000;
	
	return dp[n][k]=ret;	
}
