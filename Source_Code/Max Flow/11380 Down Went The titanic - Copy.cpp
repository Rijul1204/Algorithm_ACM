#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

#define maxm 2500
#define maxl 60
#define inf 1<<28

int in(int x){ return 2*x-1;}
int out(int x){ return 2*x;}

struct edge{
	int u,v,cap,next;
};

edge edges[maxm*9];

queue<int>q;
vector<int>vt[maxm];
int cap[maxm][maxm],r,c,p,d,pre[maxm],col[maxm],e,prev[maxm];
char grid[maxl][maxl];

int dir[2][4]={0,1,0,-1,1,0,-1,0};

void add(int u,int v,int cap){
	edges[e].u=u; edges[e].v=v; edges[e].cap=cap; edges[e].next=prev[u];
	prev[u]=e++;
}
int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int ford(int s,int d);
int bfs(int s,int d);

int main(){

	int i,j,k,l,test,u,v,i1,j1;
	
//	freopen("in.txt","r",stdin);


	while(scanf("%d %d %d",&r,&c,&p)==3){	
		
		memset(cap,0,sizeof(cap));
		memset(prev,-1,sizeof(prev));

		d=r*c+1;
		for(i=0;i<=maxm-10;i++) vt[i].clear();
		e=0;

		for(i=1;i<=r;i++) scanf("%s",grid[i]+1);

		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				u=(i-1)*c+j;
				if(grid[i][j]=='*'){
					cap[0][in(u)]=1;
					cap[in(u)][out(u)]=1;
				}
				if(grid[i][j]=='#'){
					cap[out(u)][in(d)]=p;
					cap[in(u)][out(u)]=inf;
				}
				if(grid[i][j]=='@'){
					cap[in(u)][out(u)]=inf;
				}
				if(grid[i][j]=='.'){
					cap[in(u)][out(u)]=1;
				}			

				for(k=0;k<4;k++){
					i1=i+dir[0][k]; j1=j+dir[1][k];
					if(i1>0&&j1>0&&i1<=r&&j1<=c&&grid[i1][j1]!='~'&&grid[i1][j1]!='*'){
						v=(i1-1)*c+j1;
						cap[out(u)][in(v)]=inf;
					}
				}
			}
		}
		e=0;

		for(i=0;i<=in(d);i++){
			for(j=0;j<=in(d);j++){
				if(cap[i][j]>0){
					add(i,j,cap[i][j]);
					add(j,i,0);
				}
			}
		}

		printf("%d\n",ford(0,in(d)));
	}

	return 0;
}

int bfs(int s,int d){

	memset(pre,-1,sizeof(pre));
	memset(col,0,sizeof(col));

	int i,j,k,l,ret;

	while(!q.empty()) q.pop();
	q.push(s);
	col[s]=1;

	while(!q.empty()){
		j=q.front(); q.pop();

		for(i=prev[j];i!=-1;i=edges[i].next){
			k=edges[i].v;
			if(col[k]==0&&edges[i].cap>0){
				pre[k]=i;
				q.push(k);
				col[k]=1;
				if(k==d) break;
			}
		}
	}

	int wh,path,prev;

	path=inf;
	wh=pre[d];

	while(wh!=-1){
		path=mini(path,edges[wh].cap);
		wh=pre[edges[wh].u];
	}

	wh=pre[d];
	if(path==inf) return 0;

	while(wh!=-1){
		edges[wh].cap-=path;
		edges[wh^1].cap+=path;
		wh=pre[edges[wh].u];
	}

	return path;

}

int ford(int s,int d){

	int ret=0;
	while(1){
		int fl=bfs(s,d);
		if(fl) ret+=fl;
		else break;
	}

	return ret;
}