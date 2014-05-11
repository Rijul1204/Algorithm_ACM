#include<stdio.h>
#include<string.h>

#define maxm 1110
#define inf 1<<27

int dp[maxm][maxm],vis[maxm][maxm];
int a[maxm][maxm],n;

int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int cal(int i,int j);

int main(){

	int i,j,k,l,test;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		memset(vis,0,sizeof(vis));

		n/=100;

		for(i=1;i<=10;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
				dp[i][j]=inf;
			}
		}

		printf("%d\n\n",cal(10,1));


	}


	return 0;
}

int cal(int i,int j){

	if(i<1||i>10) return inf;
	
	if(i==10&&j==n){
		return (30-a[i][j]);
	}
	if(j==n&&i==9){
		return (20-a[i][j]);
	}
	
	if(j==n) return inf;

	if(vis[i][j]) return dp[i][j];
	vis[i][j]=1;

	int k,l,ret;
	ret=inf;

	ret=mini(cal(i-1,j+1)+60,cal(i,j+1)+30);
	ret=mini(ret,cal(i+1,j+1)+20);
	
	dp[i][j]=ret-a[i][j];

	return dp[i][j];



}