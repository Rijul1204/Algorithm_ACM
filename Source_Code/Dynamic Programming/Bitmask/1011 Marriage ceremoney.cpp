#include<stdio.h>
#include<string.h>

int mat[1000][1000];
int dp[50][75536],num;

int on(int n,int k){
	return (n|1<<k);
}
int off(int n,int k){
	return (n-(1<<k));
}
bool check(int n,int k){
	return ((n&(1<<k))==(1<<k));
}

int run(int n,int no);
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,test,t=1,n;

	//freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d",&num);
		
		for(i=1;i<=num;i++){
			for(j=1;j<=num;j++){
				scanf("%d",&mat[i][j]);
			}
		}

		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",t++,run(1,0));

	}

	return 0;
}

int run(int n,int no){
	
	if(n>num) return 0;
	
	if(dp[n][no]!=-1) return dp[n][no];
	int i,j,k,l,ret;
	
	ret=-1;
	for(i=1;i<=num;i++){
	     if(check(no,i-1)) continue;
		 k=on(no,i-1);
		 dp[n][k]=run(n+1,k)+mat[n][i];
		 ret=maxi(ret,dp[n][k]);
	}
	dp[n][no]=ret;
	return ret;
}