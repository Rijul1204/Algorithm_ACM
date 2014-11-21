#include<stdio.h>
#include<string.h>

#define maxm 90
#define inf 1<<28
#define ii int

int n,k;
ii dp[maxm][maxm][5][10];
int mat[maxm][maxm];

ii cal(int i,int j,int dir,int k);
ii maxi(ii a,ii b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&k)==2){
		
		if(!n&&!k) break;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&mat[i][j]);
			}
		}
		memset(dp,-1,sizeof(dp));
		int ans=cal(1,1,0,k);
		if(ans<=-inf){
			printf("Case %d: impossible\n",t++);
			continue;
		}
		printf("Case %d: %d\n",t++,ans);
		
	}

	return 0;
}

ii cal(int i,int j,int dir,int k){

	if(i<1||j<1||i>n||j>n) return -inf;
	if(k==0&&mat[i][j]<0) return -inf;
	if(i==n&&j==n) return mat[i][j];
	
	if(dp[i][j][dir][k]!=-1) return dp[i][j][dir][k];
	
	ii ret=0; int l=0;
	if(mat[i][j]<0) l=1;
	if(dir==0){
		ret=cal(i+1,j,0,k-l);
		ret=maxi(ret,cal(i,j-1,1,k-l));
		ret=maxi(ret,cal(i,j+1,2,k-l));
		if(ret<=-inf) return dp[i][j][dir][k]=-inf;
		return dp[i][j][dir][k]=ret+mat[i][j];
	}
	if(dir==1){
		ret=cal(i+1,j,0,k-l);
		ret=maxi(ret,cal(i,j-1,1,k-l));
		if(ret<=-inf) return dp[i][j][dir][k]=-inf;
		return dp[i][j][dir][k]=ret+mat[i][j];
	}
	if(dir==2){
		ret=cal(i+1,j,0,k-l);
		ret=maxi(ret,cal(i,j+1,2,k-l));
		if(ret<=-inf) return dp[i][j][dir][k]=-inf;
		return dp[i][j][dir][k]=ret+mat[i][j];
	}
	return ret;
}