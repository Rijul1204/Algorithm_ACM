#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 110

struct node{
	int tim,pr,st;
};
node nodes[maxm];
int dp[maxm][maxm],n,lim,tim;

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
int cal(int ind,int st);
bool comp(node a,node b){
	return a.tim<b.tim;
}

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);
	int blank=0;

	while(test--){

		scanf("%d %d %d",&n,&lim,&tim);

		for(i=1;i<=n;i++){
			scanf("%d",&nodes[i].tim);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&nodes[i].pr);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&nodes[i].st);
		}
		sort(nodes+1,nodes+1+n,comp);
		
		nodes[0].pr=0; nodes[0].tim=0; nodes[0].st=0;
		memset(dp,-1,sizeof(dp));
		if(blank) printf("\n");
		blank=1;
		printf("%d\n",cal(0,0));

	}

	return 0;
}

int cal(int ind,int st){

	if(ind>n) return 0;

	if(dp[ind][st]!=-1) return dp[ind][st];

	int ret=0,i,j,k,l;

	for(i=ind+1;i<=n;i++){
		j=nodes[i].tim;
		k=nodes[i].tim-nodes[ind].tim; if(k<0) k*=-1;
		l=nodes[i].st-nodes[ind].st; if(l<0) l*=-1;
		if(k<l) continue;
		ret=maxi(ret,cal(i,nodes[i].st));
	}

	return dp[ind][st]=ret+nodes[ind].pr;

}