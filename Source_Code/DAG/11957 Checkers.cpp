#include<stdio.h>
#include<string.h>

#define maxm 110
#define ii long long int
#define mod 1000007

char s[maxm][maxm];
ii dp[maxm][maxm],n;

ii cal(int i,int j);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		for(i=0;i<=n+2;i++){
			for(j=0;j<=n+2;j++){
				s[i][j]='.';
			}
		}

		for(i=1;i<=n;i++){
			scanf("%s",s[i]+1);
		}
		memset(dp,-1,sizeof(dp));
		ii ans=-1;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(s[i][j]=='W'){
					ans=cal(i,j);
					break;
				}
			}
			if(ans!=-1) break;

		}
		printf("Case %d: %lld\n",t++,ans);

	}

	return 0;
}

ii cal(int i,int j){

	if(i>n||j>n||i<1||j<1) return 0;
	if(s[i][j]=='B') return 0;
	if(i==1) return 1;

	if(dp[i][j]!=-1) return dp[i][j];
	
	ii ret=0;
	if(s[i-1][j+1]=='.') ret=cal(i-1,j+1);
	if(s[i-1][j-1]=='.') ret=ret+cal(i-1,j-1)%mod;
	ret%=mod;
	if(s[i-1][j+1]=='B') ret=ret+cal(i-2,j+2)%mod;
	ret%=mod;	
	if(s[i-1][j-1]=='B') ret=ret+cal(i-2,j-2)%mod;
	ret%=mod;

	return dp[i][j]=ret;
	

}