#include<stdio.h>
#include<string.h>

#define maxm 1060

int dp[maxm][maxm];

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

char s[maxm];
int cal(int i,int j);

int main(){

	int i,j,k,l,test,t=1;

 //   freopen("in.txt","r",stdin);

	scanf("%d",&test);
	gets(s);

	while(test--){

		gets(s);

		l=strlen(s);
		memset(dp,-1,sizeof(dp));

		int ans=cal(0,l-1);

		printf("%d\n",ans);

	}


	return 0;
}


int cal(int i,int j){

	if(i>j) return 0;
	if(i==j) return 1;

	if(dp[i][j]!=-1) return dp[i][j];
	
	if(s[i]==s[j]){
		return dp[i][j]=cal(i+1,j-1)+2;
	}

	dp[i][j]=maxi(cal(i+1,j),cal(i,j-1));
	
	return dp[i][j];
}
