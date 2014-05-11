#include<stdio.h>
#include<string.h>

#define maxm 1200

int dp[maxm][maxm];
int cal(int i,int j);

int mini(int a,int b){
	if(a<b) return a;
	return b;
}
char s[maxm];

int main(){

	int i,j,k,l,test,t=1;
	
	freopen("in.txt","r",stdin);
	scanf("%d",&test); 
	
	while(test--){

		scanf("%s",s);
		memset(dp,-1,sizeof(dp));
		l=strlen(s);
		printf("Case %d: %d\n",t++,cal(0,l-1));

	}

	return 0;
}

int cal(int i,int j){

	if(i==j) return 0;
	if(i>j) return 0;

	if(dp[i][j]!=-1) return dp[i][j];

	int ret;

	if(s[i]==s[j]){
		ret=cal(i+1,j-1);
		return dp[i][j]=ret;
	}

	ret=mini(cal(i+1,j)+1,cal(i,j-1)+1);
	ret=mini(ret,cal(i+1,j-1)+1);
	
	return dp[i][j]=ret;

}