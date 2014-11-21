#include<stdio.h>
#include<string.h>

#define maxm 1100

int dp[maxm][maxm],dp1[maxm][maxm],n,lim,l1,l2,dp2[maxm][maxm];
bool v[maxm][maxm],v1[maxm][maxm];
char s1[maxm],s2[maxm];

int cal(int i,int j);
int cal1(int i,int j);
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&lim)==1){

		if(!lim) break;

	//	memset(v,0,sizeof(v));
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		//memset(v1,0,sizeof(v1));

		scanf("%s",s1);
		scanf("%s",s2);
		l1=strlen(s1); l2=strlen(s2);

		int ret=0;

		for(i=1;i<=l1;i++){
			for(j=1;j<=l2;j++){
				if(s1[i-1]==s2[j-1]) dp2[i][j]=dp2[i-1][j-1]+1;
				else dp2[i][j]=0;
				//k=cal1(i-1,j-1);
				k=dp2[i][j];
				ret=0;
				for(l=k;l>=lim;l--){
					dp[i][j]=maxi(dp[i][j],dp[i-l][j-l]+l);
				}
				dp[i][j]=maxi(dp[i][j],maxi(dp[i-1][j],dp[i][j-1]));
			}
		}

	//	dp[l1][l2]=cal(l1-1,l2-1);

		printf("%d\n",dp[l1][l2]);
	}

	return 0;
}

int cal1(int i,int j){

	if(i<0||j<0) return 0;

	if(v1[i][j]) return dp1[i][j];
	v1[i][j]=1;

	if(s1[i]!=s2[j]) return dp1[i][j]=0;
	return dp1[i][j]=cal1(i-1,j-1)+1;

}

int cal(int i,int j){

	if(i<0||j<0) return 0;

	if(v[i][j]) return dp[i][j];
	v[i][j]=1;

	int k,l;
	int ret=0;

	k=cal1(i,j);
	//if(k>=lim) ret=cal(i-k,j-k)+k;

	for(l=k;l>=lim;l--){
		ret=maxi(ret,cal(i-l,j-l)+l);
	}
	ret=maxi(ret,maxi(cal(i-1,j),cal(i,j-1)));

	return dp[i][j]=ret;
}
