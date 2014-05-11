#include<stdio.h>
#include<string.h>

#define maxm 5100
#define ii long long int

const ii inf=(ii) 100000000000;
int n,req,a[maxm];

ii dp[maxm][1200];
ii cal(int ind,int k);
ii mini(ii a,ii b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

	//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&req,&n);
		req+=8;

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		memset(dp,-1,sizeof(dp));
		printf("%lld\n",cal(1,req));

	}

	return 0;
}

ii cal(int ind,int k){

	if(k==0) return 0;
	if(n-ind+1<3*k){
		return inf;
	}
	
	if(dp[ind][k]!=-1) return dp[ind][k];

	ii val=a[ind]-a[ind+1];
	val*=val;
	ii ret=cal(ind+1,k);
	ii ret1=cal(ind+2,k-1)+val;
	
	return dp[ind][k]=mini(ret,ret1);
}