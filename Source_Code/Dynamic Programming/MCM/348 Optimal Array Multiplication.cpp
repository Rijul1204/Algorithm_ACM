#include<stdio.h>

#define inf 1047483647

int p[20],path[20][20],dp[20][20];

void set(int n);
int MCM(int i,int j);
void Print(int i,int j);

int main(){

	int i,j,k,l,n,t=1,a,b;

	while(scanf("%d",&n)&&n){

		for(i=1;i<=n;i++){
			scanf("%d %d",&p[i-1],&p[i]);
		
		}
		set(n);
		MCM(1,n);
		printf("Case %d: ",t++);
		Print(1,n);
		printf("\n");

	}

	return 0;
}

void set(int n){

	int i,j;

	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			dp[i][j]=inf;
			path[i][j]=0;
		}
	}

}

int MCM(int i,int j){

	if(i==j){
		dp[i][j]=0;
		return dp[i][j];
	}

	else if(dp[i][j]<inf) return dp[i][j];

	int ret;
	for(int k=i;k<j;k++){
		ret=MCM(i,k)+MCM(k+1,j)+p[i-1]*p[k]*p[j];
		if(ret<dp[i][j]){
			dp[i][j]=ret;
			path[i][j]=k;
		}
	}

	return dp[i][j];
}

void Print(int i,int j){

	if(i==j){
		printf("A%d",i);
		return;
	}
	printf("(");
	Print(i,path[i][j]);
	printf(" x ");
	Print(path[i][j]+1,j);
	printf(")");

}









