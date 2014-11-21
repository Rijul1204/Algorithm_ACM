#include<stdio.h>
#include<string.h>

#define maxm 30

int dp[50][maxm][maxm][8],n,r,p;

int cal(int i,int j,int k,int fl);

int main(){

	int i,j,k,l;

//	freopen("in.txt","r",stdin);

	

	while(scanf("%d %d %d",&n,&r,&p)==3){
		
		memset(dp,-1,sizeof(dp));
		printf("%d\n",cal(0,0,0,0));
	}

	return 0;
}

int cal(int i,int j,int k,int fl){

	if(k>r) return 0;

	if(i==2*n&&j==0&&k==r){
		return 1;
	}
	if(i==2*n) return 0;

	if(dp[i][j][k][fl]!=-1) return dp[i][j][k][fl];

	int ret=0;

	if(j>n) return 0;
	if(j==0) return dp[i][j][k][fl]=cal(i+1,j+1,k,1);
	
	
	if(j==p&&fl==1){
		ret=cal(i+1,j+1,k,1);
		ret+=cal(i+1,j-1,k+1,2);		
		return dp[i][j][k][fl]=ret;
	}	
	
/*	if(j+1==p){
		ret=cal(i+1,j+1,k+1,1);
		ret+=cal(i+1,j-1,k,2);
		//ret+=cal(i+1,j+1,k,2);
		return dp[i][j][k][fl]=ret;
	}
*/	
	ret=cal(i+1,j+1,k,1);
    ret+=cal(i+1,j-1,k,2);
	
	return dp[i][j][k][fl]=ret;

}