#include<stdio.h>
#include<string.h>

#define inf 1<<30
#define ii long long int
#define maxm 110

ii dp[maxm][maxm];
bool vis[maxm][maxm];
int n,k,p[maxm];

ii maxi(ii a,ii b){
	if(a>b) return a;
	return b;	
}

ii cal(int b,int e);

int main(){
	
	int i,j,l;
	
	//freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1){
		
		if(!n) break;
		
		for(i=1;i<=n;i++){
			scanf("%d",&p[i]);
		}
		
		memset(dp,-1,sizeof(dp));
		memset(vis,0,sizeof(vis));
				
		printf("%lld\n",cal(1,n));
		
	}
	
	return 0;
}

ii cal(int b,int e){
	
	if(b==e) return p[b];
	if(b>=e) return 0;
	
	if(vis[b][e]) return dp[b][e];
	vis[b][e]=1;
	
	int i,j,k,l;
	ii ret,sum,sumb;
	
	sum=0; sumb=0;
	ret=-inf;
	
	for(i=b;i<=e;i++){
		sum+=p[i];
		ret=maxi(ret,sum-cal(i+1,e));
		//if(b==1&&e==4) printf("ret- > %d %d %d %lld\n",b,e,i,ret);		
	}
	
	for(j=e;j>=b;j--){
		sumb+=p[j];
		ret=maxi(ret,sumb-cal(b,j-1));		
	}
	
	return dp[b][e]=ret;	
	
}
