#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

#define maxm 150
#define inf 1<<28

int n,m,mat[maxm][maxm],pre[maxm],source,sink,col[maxm];

queue<int>q;

int flow(int s,int d);
int bfs(int s,int d);
int min(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l,t=1;
	
//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		if(!n) break;
		
		for(i=0;i<=n;i++){
			for(j=0;j<=n;j++){
				mat[i][j]=0;
			}
		}

		scanf("%d %d %d",&source,&sink,&m);
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			mat[k][l]+=j;
			mat[l][k]+=j;
		}

		printf("Network %d\n",t++);
		printf("The bandwidth is %d.\n\n",flow(source,sink));

		
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
		
		i=q.front(); q.pop();

		for(j=1;j<=n;j++){
			if(col[j]==0&&mat[i][j]>0){
				pre[j]=i;
				q.push(j);
				col[j]=1;
				if(j==d) break;
			}
		}
	}

	int wh,path,prev;
	path=inf;
	wh=d;

	while(pre[wh]!=-1){
		prev=pre[wh];
		path=min(path,mat[prev][wh]);
		wh=prev;
	}
	wh=d;

	while(pre[wh]!=-1){
		prev=pre[wh];
		mat[prev][wh]-=path;
		mat[wh][prev]+=path;
		wh=prev;
	}
	
	if(path==inf) return 0;
	return path;



	return 0;

}

int flow(int s,int d){

	int ret=0;

	while(1){
		
	//	printf("%d\n",ret);
		int fl=bfs(s,d);
		if(fl) ret+=fl;
		else break;		
	}
	
	return ret;

}