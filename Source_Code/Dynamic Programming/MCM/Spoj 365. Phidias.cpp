#include<stdio.h>
#include<string.h>

#define maxm 650

struct node{
	int wd,hgt;
};
node nodes[maxm];
int dp[maxm][maxm],w,h,n;
bool v[maxm][maxm];

int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int cal(int width,int height);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&w,&h);

		scanf("%d",&n);
		
		for(i=1;i<=n;i++){
			scanf("%d %d",&nodes[i].wd,&nodes[i].hgt);
		}
		memset(v,0,sizeof(v));
		printf("%d\n",cal(w,h));
	}

	return 0;

}

int cal(int w,int h){
	

	if(v[w][h]) return dp[w][h];
	v[w][h]=1;
	int i,j,k,l,ret=w*h;

	for(i=1;i<=n;i++){
		if(nodes[i].wd>w||nodes[i].hgt>h) continue;
		ret=mini(ret,cal(w-nodes[i].wd,nodes[i].hgt)+cal(w,h-nodes[i].hgt));
		ret=mini(ret,cal(nodes[i].wd,h-nodes[i].hgt)+cal(w-nodes[i].wd,h));
	}

	return dp[w][h]=ret;

}