#include<stdio.h>
#include<string.h>

#define maxm 1010

int dp[maxm][maxm][4],n;


int cal(int n,int pos,int turn);

int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

	memset(dp,-1,sizeof(dp));

//	freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1){

		if(!n) break;

		if(cal(n,n-1,1)==1) printf("Alicia\n");
		else printf("Roberto\n");

	}

	return 0;
}

int cal(int n,int pos,int turn){

	if(n<=pos) return turn;
	if(n==1) return 3-turn;
	
	if(dp[n][pos][turn]!=-1) return dp[n][pos][turn];

	int i,j;

	for(i=1;i<=pos;i++){
		j=cal(n-i,2*i,3-turn);
		if(j==turn) return dp[n][pos][turn]=turn;
	}
	
	return dp[n][pos][turn]=3-turn;
}