#include<stdio.h>
#include<string.h>

#define ii long long int
#define maxm 60

ii dp[maxm][maxm][maxm];
int vis[maxm][maxm][maxm];

int most;
ii cal(int n,int k,int m);

int main(){

	int i,j,k,l;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d %d",&i,&j,&k)==3){

		memset(vis,0,sizeof(vis));
		most=k;
		printf("%lld\n",cal(i,j,k));

	}


	return 0;
}


ii cal(int n,int k,int m){

	if(n<0||k<0||m<0) return 0;
	if(m==0) return 0;
	if(n<k) return 0;
	if(n==1&&k==1) return 1;

	if(vis[n][k][m]) return dp[n][k][m];
	vis[n][k][m]=1;

	dp[n][k][m]=cal(n-1,k-1,most)+cal(n-1,k,m-1);

	return dp[n][k][m];



}