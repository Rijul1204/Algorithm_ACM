#include<stdio.h>
#include<string.h>

#define ii long long int
#define maxm 100

ii dp[maxm][maxm],vis[maxm][maxm];
int n,t,p;

ii calc(int i,int j);

int main(){

	int i,j,k,l,test;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d %d",&n,&t,&p);
		memset(vis,0,sizeof(vis));

		printf("%lld\n",calc(n,t));

	}


	return 0;
}

ii calc(int i,int j){

	if(j==i*p) return 1;
	if(j<i*p) return 0;
	if(i==1) return 1;
	if(vis[i][j]) return dp[i][j];
	vis[i][j]=1;

	dp[i][j]=calc(i-1,j-p)+calc(i,j-1);

	return dp[i][j];
	

}