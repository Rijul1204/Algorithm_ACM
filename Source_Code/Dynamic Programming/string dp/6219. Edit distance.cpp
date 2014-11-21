#include<stdio.h>
#include<string.h>

#define maxm 2500

int dp[maxm][maxm];
bool v[maxm][maxm];
char s1[maxm],s2[maxm];

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

		memset(v,0,sizeof(v));

		scanf("%s",s1);
		scanf("%s",s2);

		k=strlen(s1);
		l=strlen(s2);

		printf("%d\n",cal(k-1,l-1));

	}

	return 0;
}

int cal(int i,int j){

	if(i<0&&j<0) return 0;
	if(i<0) return j+1;
	if(j<0) return i+1;

	if(v[i][j]) return dp[i][j];
	v[i][j]=1;

	if(s1[i]==s2[j]){
		return dp[i][j]=cal(i-1,j-1);
	}

	return 	dp[i][j]=mini(cal(i-1,j-1)+1,mini(cal(i-1,j)+1,cal(i,j-1)+1));

}