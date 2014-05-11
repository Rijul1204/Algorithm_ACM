#include<stdio.h>
#include<string.h>

#define maxm 1010
#define ii __int64
#define mod 10056

ii dp[maxm][maxm],fact[maxm];
ii f(int n,int k);
ii gen(int n);

int main(){

	int i,j,k,l,test,t=1,n;

	//freopen("in.txt","r",stdin);
	memset(dp,-1,sizeof(dp)); memset(fact,-1,sizeof(fact));

	scanf("%d",&test);

	while(test--){
		
		scanf("%d",&n);
		ii ans=0;

		for(i=1;i<=n;i++){
			ans+=((gen(i)*f(n,i))%mod);
			ans%=mod;
		}
		printf("Case %d: %lld\n",t++,ans);

	}

	return 0;
}
ii gen(int n){

	if(n==0||n==1) return 1;
	if(fact[n]!=-1) return fact[n];
	return fact[n]=((n*gen(n-1))%mod);
}

ii f(int n,int k){

	if(n<k) return 0;
	if(n==k||k==1) return 1;
	if(dp[n][k]!=-1) return dp[n][k];
	
	ii ret=0;
	ret+=f(n-1,k-1);
	ret+=((k*f(n-1,k))%mod);
	ret%=mod;
	
	return dp[n][k]=ret;
}