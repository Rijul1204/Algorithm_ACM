#include<stdio.h>
#include<string.h>

#define ii __int64
#define maxm 60

ii dp[maxm][maxm][maxm];
ii dp1[maxm][maxm][maxm][5];
int vis[maxm][maxm][maxm],n,m,kk;
ii cal(int n,int k,int m);
ii cal1(int ind,int k,int m,int fl);

int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);
    memset(dp1,-1,sizeof(dp1));
	scanf("%d",&test);	

	while(test--){

		
		scanf("%d %d %d",&n,&m,&k);		
		
		ii ans=0;
		for(i=1;i<=k;i++){
			ans+=cal1(n-i,m-1,k,1);
		}
		
		printf("Case %d: %I64d\n",t++,ans);

	}


	return 0;
}

ii cal1(int ind,int k,int m,int fl){

	if(ind==0&&k==0) return 1;
	if(ind<=0||k<0) return 0;

	if(dp1[ind][k][m][fl]!=-1) return dp1[ind][k][m][fl];

	ii ret=0;
	int i;

	for(i=1;i<=m;i++){
		ret+=cal1(ind-i,k-1,m,!fl);
	}
	
	return dp1[ind][k][m][fl]=ret;
}

/*
ii cal(int n,int k,int m,int fl){


	if(n==0&&k==0) return 1;
	if(n<0||k<0||m<0) return 0;
	if(m==0) return 0;
	if(n<k) return 0;
	
	if(dp[n][k][m]!=-1) return dp[n][k][m];
	
	ret+=cal(n-1,k-1,m,!fl);
	for(i=1;i<=m;i++){
		ret+=cal(n-i,k,m-i,fl);
	}
	ret+=cal(n-i,k-1,m,!fl);
/*
	ii ret=0;

	ret+=cal(n-1,k,m-1,fl);
	ret+=cal(n-m-1,k-1,m-1,!fl);
	ret+=cal(n,k,m-1,fl);
	

	return dp[n][k][m]=ret;




}
*/
ii cal(int n,int k,int m){


	if(n==0&&k==0&&m==0) return 1;
	if(n<0||k<0||m<0) return 0;
	//if(m==0) return 0;
	if(n<k) return 0;
	
	if(dp[n][k][m]!=-1) return dp[n][k][m];
	
	ii ret=0;
	
	//ret+=cal(n-m-1,k-1,m-1);
	ret+=cal(n-1,k-1,m);
    ret+=cal(n-1,k,m-1);
	ret+=cal(n,k,m-1);
	

	return dp[n][k][m]=ret;



}