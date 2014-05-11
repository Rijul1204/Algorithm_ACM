#include<stdio.h>
#include<string.h>

#define maxm 1010
#define mod 1000007


struct node{
	int len,way;
	node(){}
	node(int a,int b){len=a; way=b;}
};


char s1[maxm],s2[maxm];
int pre1[30][maxm],pre2[30][maxm];
node dp[maxm][maxm];
bool v[maxm][maxm];

node cal(int i,int j);
void init();

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--){

		scanf("%s",s1+1);
		scanf("%s",s2+1);

		init();
		k=strlen(s1+1); l=strlen(s2+1);
		memset(v,0,sizeof(v));
		node ans=cal(k,l);
		printf("Case %d: %d\n",t++,ans.way);

	}

	return 0;
}

node cal(int i,int j){
	
	if(i<=0||j<=0) return node(0,1);

	if(v[i][j]) return dp[i][j];
	v[i][j]=1;
	node ret,ret1;

	int i1;

	if(s1[i]==s2[j]){
		ret=cal(i-1,j-1);
		ret.len++; return dp[i][j]=ret;
	}

	for(i1=0;i1<26;i1++){
		ret1=cal(pre1[i1][i],pre2[i1][j]);		
		if(i1==0){
			ret=ret1; continue;
		}
		if(ret1.len==0) continue;
		if(ret1.len>ret.len) ret=ret1;
		else if(ret1.len==ret.len){
			ret.way+=ret1.way; ret.way%=mod;
		}		
	}

	return dp[i][j]=ret;
}

void init(){

	int i,j,k,l;

	k=strlen(s1+1); l=strlen(s2+1);

	for(i=0;i<=26;i++){
		pre1[i][0]=0; pre2[i][0]=0;
	}

	for(i=0;i<=26;i++){
		for(j=1;j<=k;j++){
			if(s1[j]==(i+'a')) pre1[i][j]=j;
			else pre1[i][j]=pre1[i][j-1];
		}
	}

	for(i=0;i<=26;i++){
		for(j=1;j<=l;j++){
			if(s2[j]==(i+'a')) pre2[i][j]=j;
			else pre2[i][j]=pre2[i][j-1];
		}
	}


}