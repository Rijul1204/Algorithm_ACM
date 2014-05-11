#include<stdio.h>
#include<string.h>

#define ii long long int

ii dp[2005][2005];

ii maxi(ii a,ii b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1,n,m,num;
	ii ans;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		ans=-1;

		memset(dp,-1,sizeof(dp));

		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
			   scanf("%d",&num);
			   if(i==1&&j==1) dp[i][j]=num;
			   else{
				   dp[i][j]=num+maxi(dp[i-1][j-1],dp[i-1][j]);
			   }
			   if(dp[i][j]>ans) ans=dp[i][j];
			}			
		}
		for(k=n-1;k>=1;k--,i++){
			for(j=1;j<=k;j++){
				scanf("%d",&num);
				dp[i][j]=num+maxi(dp[i-1][j],dp[i-1][j+1]);
				if(dp[i][j]>ans) ans=dp[i][j];
			}
		}

		printf("Case %d: %lld\n",t++,ans);


	}



	return 0;
}