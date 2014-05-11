#include<stdio.h>
#include<string.h>

#define maxm 50
#define ii long long int

struct node{
	ii len,way;
	node(){}
	node(ii a,ii b){ len=a; way=b;}
};

char s1[maxm],s2[maxm];
node dp[maxm][maxm];
bool v[maxm][maxm];
ii mini(ii a,ii b){
	if(a<b) return a; return b;
}
node cal(int i,int j);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);
	gets(s1);

	while(test--){

		gets(s1);
		gets(s2);

		k=strlen(s1); l=strlen(s2);

		memset(v,0,sizeof(v));

		node ans=cal(k-1,l-1);

		printf("Case #%d: %lld %lld\n",t++,ans.len,ans.way);

	}

	return 0;
}

node cal(int i,int j){

	if(i<0&&j<0) return node(0,1);
	if(i<0) return node(j+1,1);
	if(j<0) return node(i+1,1);

	if(v[i][j]==1) return dp[i][j];
	v[i][j]=1;

	node ret,ret1;

	if(s1[i]==s2[j]){
		ret=cal(i-1,j-1);
	    ret.len++; return dp[i][j]=ret;
	}	

	ret=cal(i-1,j); ret1=cal(i,j-1);
	ret.len++; ret1.len++;

	if(ret.len<ret1.len) return dp[i][j]=ret;
	if(ret.len>ret1.len) return dp[i][j]=ret1;

	ret.way+=ret1.way;

	return dp[i][j]=ret;

}
