#include<stdio.h>
#include<string.h>

#define maxm 1000
//#define ii __int64
#define ii unsigned long long int

int n,mod;
ii dp[70][70][110];
bool vis[70][70][110];

ii cal(int i,int zero,int m);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);
	
	while(test--){

		//memset(dp,-1,sizeof(dp));
		memset(vis,0,sizeof(vis));
	    scanf("%d %d",&n,&mod);
		if(mod==0){
			printf("Case %d: 0\n",t++);
			continue;
		}
		printf("Case %d: %llu\n",t++,cal(1,0,1%mod));

	}

	return 0;
}

ii cal(int i,int zero,int m){
	

	if(zero>n/2) return 0;
	if(i>n) return 0;

	if(i==n){
		if(zero*2==n&&m==0){
			return 1;
		}
		return 0;
	}

	if(vis[i][zero][m]) return dp[i][zero][m];
	vis[i][zero][m]=1;

	ii ret=0;

	ret=cal(i+1,zero+1,(m<<1)%mod);
	ret+=cal(i+1,zero,((m<<1)+1)%mod);
	
	return dp[i][zero][m]=ret;

}