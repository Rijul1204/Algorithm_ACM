#include<stdio.h>
#include<string.h>

struct node{
	int a,b,c,val;
};
node comb[100];
int dp[100][2500],vis[100][2500];
int n;

int on(int n,int k){

	return (n|(1<<k));
}
int off(int n,int k){
	return (n-(1<<k));
}
bool check(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
int run(int ind,int num);

int main(){

	int i,j,k,l,t=1;
	//freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		if(!n) break;
		
		for(i=1;i<=n;i++){
			scanf("%d %d %d %d",&comb[i].a,&comb[i].b,&comb[i].c,&comb[i].val);
		}
		memset(dp,-1,sizeof(dp));
		memset(vis,-1,sizeof(vis));
		printf("Case %d: %d\n",t++,run(1,0));
	}


	return 0;
}

int run(int ind,int num){
	
	if(num==1022) return 0;
	if(ind>n) return 0;
	if(vis[ind][num]!=-1) return dp[n][num];
	vis[ind][num]=1;
	int i,j,k,ret;
	ret=-1;
	
	for(i=ind;i<=n;i++){
		
		if(check(num,comb[i].a)) continue;
		if(check(num,comb[i].b)) continue;
		if(check(num,comb[i].c)) continue;
		
		k=on(num,comb[i].a);
		k=on(k,comb[i].b);
		k=on(k,comb[i].c);
		
		j=run(i,k);
		if(j==-1) continue;
		
		dp[i][k]=j+comb[i].val;
		ret=maxi(ret,dp[i][k]);
	}

	dp[ind][num]=ret;
	return ret;

}

