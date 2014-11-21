#include<stdio.h>
#include<string.h>

#define maxm 6110

int dp[maxm][maxm];
bool v[maxm][maxm];
char s[maxm];

int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int cal(int i,int j);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--){
		
		scanf("%s",s);
		l=strlen(s);
		
		memset(v,0,sizeof(v));
		printf("%d\n",cal(0,l-1));

	}

	return 0;
}

int cal(int i,int j){

	if(i>=j) return 0;

	if(v[i][j]) return dp[i][j];
	v[i][j]=1;

	if(s[i]==s[j]){
		return dp[i][j]=cal(i+1,j-1);
	}

	return dp[i][j]=mini(cal(i+1,j)+1,cal(i,j-1)+1);


}