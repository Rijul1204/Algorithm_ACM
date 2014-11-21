#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 100100
#define inf 1<<29

vector<int>v[maxm];
int n,lim,val[maxm],next[maxm],d[maxm],d1[maxm],tim,dp[maxm][110];
bool vis[maxm][110];

void dfs(int s);
int cal(int n,int k);
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);
	
	while(scanf("%d %d",&n,&lim)==2){

		if(!n&&!lim) break;

		for(i=0;i<=n;i++){
			v[i].clear();
		}
		for(i=0;i<n;i++){
			scanf("%d",&val[i]);
		}
		for(i=1;i<n;i++){
			scanf("%d",&k);
			v[k].push_back(i);			
		}

		memset(vis,0,sizeof(vis));

		tim=0;
		dfs(0);
		d1[next[0]]=n;
		printf("%d\n",cal(0,lim));

	}

	return 0;
}

int cal(int ind,int k){

	if(k==0) return 0;
	if(ind>=n&&k!=lim) return 0;
	if(ind>=n) return -inf;

	if(vis[ind][k]) return dp[ind][k];
	vis[ind][k]=1;

	int ret=maxi(cal(d1[d[ind]+1],k),cal(d1[next[ind]],k-1)+val[ind]);

	return dp[ind][k]=ret;

}

void dfs(int s){
	
	d1[tim]=s;
	d[s]=tim++;

	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		dfs(k);
	}
	next[s]=tim;

}