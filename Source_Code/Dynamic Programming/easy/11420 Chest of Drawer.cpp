#include<stdio.h>
#include<string.h>

#define maxm 100
//#define ii __int64
#define ii long long int

ii dp[maxm][maxm][3];
int n1,m1;
ii cal(int n,int s,int fl); 

int main(){

	int i,j,k,l;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n1,&m1)==2){

		if(n1<0&&m1<0) break;
		memset(dp,-1,sizeof(dp));
			
		ii ans=cal(n1,0,1);

		printf("%lld\n",ans);

	}

	return 0;
}

ii cal(int n,int s,int fl){

	if(n==0&&s==m1) return 1;
	if(n==0) return 0;
	
	if(dp[n][s][fl]!=-1) return dp[n][s][fl];

	ii ret=0;

	ret+=cal(n-1,s,0);
	if(fl==1) ret+=cal(n-1,s+1,1);
	else ret+=cal(n-1,s,1);

	return dp[n][s][fl]=ret;

}