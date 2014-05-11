#include<stdio.h>

#define inf 1<<25

int len,n,dp[1000][1000],p[1000];

void set(int n);
int back(int s,int e);

int main(){

	int i,j;

	while(scanf("%d",&len)==1){

		if(!len) break;

		scanf("%d",&n);

		p[0]=0;
		for(i=1;i<=n;i++){
			scanf("%d",&p[i]);
		}
		p[n+1]=len;

		set(n+1);

		printf("The minimum cutting is %d.\n",back(0,n+1));

	}	


	return 0;

}

int  back(int s,int e){

	if(s+1==e) return 0;

	if(dp[s][e]!=inf) return dp[s][e];

	int ret,min=inf;
	for(int i=s+1;i<e;i++){
		ret=back(s,i)+back(i,e)+p[e]-p[s];
		if(ret<min) min=ret;
	}

	return dp[s][e]=min;


}

void set(int n){

	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=inf;
		}
	}

}

