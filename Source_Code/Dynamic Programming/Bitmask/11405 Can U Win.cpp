#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

#define maxm 15
#define inf 1<<25

int on(int n,int k){
	return (n|(1<<k));
}

bool check(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}

struct node{
	int x;
	int y;
	int dist;
};

int vis[maxm][5000],dp[maxm][5000];
int d[maxm][maxm][maxm],col[maxm][maxm][maxm],tot;
node nodes[20];
char grid[maxm][maxm],n;
queue<node>q;

int mini(int a,int b){
	if(a<b) return a;
	return b;
}
void bfs(node s,int ind);
int run(int ind,int n);

int main(){

	int i,j,k,l,test;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		memset(col,0,sizeof(col));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=10;i++){
			for(j=0;j<=10;j++){
				for(k=0;k<=10;k++){
					d[i][j][k]=inf;
				}
			}
		}

		scanf("%d",&n);

		for(i=0;i<8;i++) scanf("%s",grid[i]);
		
		k=1;
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				if(grid[i][j]=='P'){
					nodes[++k].x=i;
					nodes[k].y=j;
				}
				else if(grid[i][j]=='k'){
					nodes[1].x=i;
					nodes[1].y=j;
				}
			}
		}

		tot=k;

		

		for(i=1;i<=k;i++){
			nodes[i].dist=0;
			bfs(nodes[i],i);
		}

		if(run(1,1)<=n) printf("Yes\n");
		else printf("No\n");

	}


	return 0;
}

int run(int ind,int n){

	if(n==((1<<tot)-1)) return 0;

	if(vis[ind][n]==1) return dp[ind][n];

	int i,j,k,l,ret;
	
	ret=inf;
	for(i=1;i<=tot;i++){
		if(check(n,(i-1))) continue;
		k=on(n,i-1);
		ret=mini(ret,run(i,k)+d[ind][nodes[i].x][nodes[i].y]);
	}

	return dp[ind][n]=ret;


}

void bfs(node s,int ind){

	int i,j,k,l;
	node temp,temp1;
	d[ind][s.x][s.y]=0;
	col[ind][s.x][s.y]=1;
	q.push(s);

	while(!q.empty()){

		temp=q.front(); q.pop();

		i=temp.x; j=temp.y;

		//up-left>>>>>>>
		k=i-2; l=j-1;

		if(k>=0&&l>=0){
			if(col[ind][k][l]==0&&(grid[k][l]=='P'||grid[k][l]=='.')){
				col[ind][k][l]=1;
				d[ind][k][l]=temp.dist+1;
				temp1.x=k; temp1.y=l; temp1.dist=temp.dist+1;
				q.push(temp1);
			}
		}

		//up-right>>>>>>

		k=i-2; l=j+1;

		if(k>=0&&l<8){
			if(col[ind][k][l]==0&&(grid[k][l]=='P'||grid[k][l]=='.')){
				col[ind][k][l]=1;
				d[ind][k][l]=temp.dist+1;
				temp1.x=k; temp1.y=l; temp1.dist=temp.dist+1;
				q.push(temp1);
			}
		}

		//down-left>>>>

		k=i+2; l=j-1;

		if(k<8&&l>=0){
			if(col[ind][k][l]==0&&(grid[k][l]=='P'||grid[k][l]=='.')){
				col[ind][k][l]=1;
				d[ind][k][l]=temp.dist+1;
				temp1.x=k; temp1.y=l; temp1.dist=temp.dist+1;
				q.push(temp1);
			}
		}

		//down-right>>>>>>>>>>

		k=i+2; l=j+1;

		if(k<8&&l<8){
			if(col[ind][k][l]==0&&(grid[k][l]=='P'||grid[k][l]=='.')){
				col[ind][k][l]=1;
				d[ind][k][l]=temp.dist+1;
				temp1.x=k; temp1.y=l; temp1.dist=temp.dist+1;
				q.push(temp1);
			}
		}

		//left-up>>>>>>>
		k=i-1; l=j-2;

		if(k>=0&&l>=0){
			if(col[ind][k][l]==0&&(grid[k][l]=='P'||grid[k][l]=='.')){
				col[ind][k][l]=1;
				d[ind][k][l]=temp.dist+1;
				temp1.x=k; temp1.y=l; temp1.dist=temp.dist+1;
				q.push(temp1);
			}
		}

		//left-down>>>>>>>>

		k=i+1; l=j-2;

		if(k<8&&l>=0){
			if(col[ind][k][l]==0&&(grid[k][l]=='P'||grid[k][l]=='.')){
				col[ind][k][l]=1;
				d[ind][k][l]=temp.dist+1;
				temp1.x=k; temp1.y=l; temp1.dist=temp.dist+1;
				q.push(temp1);
			}
		}

		//right-up>>>>>>>

		k=i-1; l=j+2;

		if(k>=0&&l<8){
			if(col[ind][k][l]==0&&(grid[k][l]=='P'||grid[k][l]=='.')){
				col[ind][k][l]=1;
				d[ind][k][l]=temp.dist+1;
				temp1.x=k; temp1.y=l; temp1.dist=temp.dist+1;
				q.push(temp1);
			}
		}

		//right-down>>>>>>>>>>

		k=i+1; l=j+2;

		if(k<8&&l<8){
			if(col[ind][k][l]==0&&(grid[k][l]=='P'||grid[k][l]=='.')){
				col[ind][k][l]=1;
				d[ind][k][l]=temp.dist+1;
				temp1.x=k; temp1.y=l; temp1.dist=temp.dist+1;
				q.push(temp1);
			}
		}

	}
	

}