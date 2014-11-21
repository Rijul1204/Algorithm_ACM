#include<stdio.h>
#include<string.h>

#define maxm 1010

char s[maxm],s1[maxm];
int dp[maxm][maxm],pre[maxm][maxm],tot;

int cal(int i,int j);
void print(int i,int j);

int main(){

	int i,j,k,l,test,t=1;
 
    //freopen("in.txt","r",stdin);

	while(scanf("%s",s)==1){

		l=strlen(s); memset(dp,-1,sizeof(dp));

		printf("%d ",cal(0,l-1));
		tot=0;
		print(0,l-1);
		for(i=0;i<tot;i++){
			if(i%2==0) printf("%c",s1[i]);
		}
		for(i=tot-1;i>=0;i--){
			if(i%2) printf("%c",s1[i]);
		}
		printf("\n");

	}

	return 0;
}

void print(int i,int j){
	
	if(i>j) return ;
	if(i==j){
		s1[tot++]=s[i]; return;
	}

	if(pre[i][j]==0){
		s1[tot++]=s[i]; s1[tot++]=s[j];
		print(i+1,j-1);
	}
	else if(pre[i][j]==1){
		s1[tot++]=s[i];s1[tot++]=s[i];
		print(i+1,j);
	}
	else if(pre[i][j]==2){
		s1[tot++]=s[j];s1[tot++]=s[j];
		print(i,j-1);
	}
}

int cal(int i,int j){

	if(i>=j) return 0;

	if(dp[i][j]!=-1) return dp[i][j];

	if(s[i]==s[j]){
		pre[i][j]=0;
		return dp[i][j]=cal(i+1,j-1);
	}

	int ret=cal(i+1,j)+1,ret1=cal(i,j-1)+1;

	if(ret<ret1){
		pre[i][j]=1; dp[i][j]=ret;
	}
	else{
		pre[i][j]=2; dp[i][j]=ret1;
	}

	return dp[i][j];

}