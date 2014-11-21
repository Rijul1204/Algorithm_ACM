#include<stdio.h>
#include<string.h>

#define maxm 100
#define ii long long int

char s[maxm];

ii dp[maxm][maxm];

ii cal(int i,int j);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%s",s);
		l=strlen(s);

		memset(dp,-1,sizeof(dp));

		printf("%lld\n",cal(0,l-1));

	}

	return 0;
}

ii cal(int i,int j){

	if(i>j) return 0;
	if(i==j) return 1;

	if(dp[i][j]!=-1) return dp[i][j];

	ii ret=0;

	if(s[i]==s[j]){
		ret=cal(i+1,j-1)+1;
	}

	ret+=cal(i+1,j); ret+=cal(i,j-1);

	ret-=cal(i+1,j-1);

	return dp[i][j]=ret;

}