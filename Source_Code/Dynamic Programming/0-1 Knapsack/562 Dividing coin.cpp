#include<stdio.h>

int dp[110][50000];
int coin[110];

int max(int a,int b);

int main(){

	int i,j,test,n,sum,mid,num1,diff;

	scanf("%d",&test);

	while(test--){
		scanf("%d",&n);
		sum=0;

		for(i=1;i<=n;i++){
			scanf("%d",&coin[i]);
			sum+=coin[i];
		}
		mid=sum/2;

		for(i=0;i<=n;i++) dp[i][0]=0;
		for(j=0;j<=mid;j++) dp[0][j]=0;

		for(i=1;i<=n;i++){
			for(j=1;j<=mid;j++){
				if(coin[i]>j){
					dp[i][j]=dp[i-1][j];
				}
				else {
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-coin[i]]+coin[i]);
				}
			}
		}
        num1=sum-dp[n][mid];
		diff=dp[n][mid]-num1;
		if(diff<0) diff*=-1;
		printf("%d\n",diff);

	}

	return 0;
}

int max(int a,int b){

	if(a>b) return a;
	else return b;
}





