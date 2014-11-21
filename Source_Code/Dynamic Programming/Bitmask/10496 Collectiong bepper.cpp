#include<stdio.h>
#include<string.h>

#define maxm 25
#define inf 1<<26

struct node{
	int x;
	int y;
};

node nodes[1000];
int dp[1000][9000],vis[1000][9000];
int d[maxm][maxm][maxm][maxm];

int on(int n,int k){
	return (n|(1<<k));
}
bool check(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}

int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int dx,dy,n;
int run(int ind,int num);

int main(){

	int i,j,k,l,x,y,test;

//	freopen("in.txt","r",stdin);

	for(i=1;i<=22;i++){
		for(j=1;j<=22;j++){
			for(k=1;k<=22;k++){
				for(l=1;l<=22;l++){
					x=k-i; y=l-j;
					if(x<0) x*=-1;
					if(y<0) y*=-1;
					d[i][j][k][l]=x+y;
				}
			}
		}
	}

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&dx,&dy);
		scanf("%d %d",&x,&y);

		nodes[0].x=x; nodes[0].y=y;

		scanf("%d",&n);

		for(i=1;i<=n;i++){
			scanf("%d %d",&nodes[i].x,&nodes[i].y);
		}
		
		memset(vis,0,sizeof(vis));
		int ret=inf;

		for(i=1;i<=n;i++){
			k=on(0,i);
			ret=mini(ret,run(i,k)+d[nodes[0].x][nodes[0].y][nodes[i].x][nodes[i].y]);
		}

		printf("The shortest path has length %d\n",ret);

		
		
	}


	return 0;
}

int run(int ind,int num){

	if(num==((1<<(n+1))-2)){
		return d[nodes[ind].x][nodes[ind].y][nodes[0].x][nodes[0].y];
	}

	if(vis[ind][num]) return dp[ind][num];
	vis[ind][num]=1;

	int i,j,k;
	int ret=inf;

	for(i=1;i<=n;i++){
		if(check(num,i)) continue;
		k=on(num,i);
		ret=mini(ret,run(i,k)+d[nodes[ind].x][nodes[ind].y][nodes[i].x][nodes[i].y]);
	}

	return dp[ind][num]=ret;



}