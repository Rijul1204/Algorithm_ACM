#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

#define inf 1<<29
#define maxm 550

int n,w,tot,mat[maxm][maxm],cap[maxm][maxm],pre[maxm],col[maxm],p[maxm];
queue<int>q;

int in(int x){
	return 2*x-1;
}

int out(int x){
	return 2*x;
}

int ford(int s,int d);
int bfs(int s,int d);
int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1,b,d,m;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		memset(mat,0,sizeof(mat));
		
		for(i=1;i<=n;i++){
			scanf("%d",&p[i]);
			mat[in(i)][out(i)]+=p[i];
			//mat[out(i)][in(i)]=0;
		}

		scanf("%d",&m);
		
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			mat[out(k)][in(l)]+=j;
		}

		scanf("%d %d",&b,&d);

		for(i=1;i<=b;i++){
			scanf("%d",&j);
			mat[0][in(j)]=inf;
		}

		for(i=1;i<=d;i++){
			scanf("%d",&j);
			mat[out(j)][in(n+1)]=inf;
		}
		
		printf("Case %d: %d\n",t++,ford(0,in(n+1)));


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

		for(j=s;j<=d;j++){
			if(col[j]==0 && mat[i][j]>0){
				pre[j]=i;
				q.push(j);
				col[j]=1;
				
			}
		}
	}

	int wh,path,prev;
	path=inf;
	wh=d;

	while(pre[wh]!=-1){
		prev=pre[wh];
		path=mini(path,mat[prev][wh]);
		wh=prev;
	}
	wh=d;
	
	if(path==inf) return 0;
	
	while(pre[wh]!=-1){
		prev=pre[wh];
		mat[prev][wh]-=path;
		mat[wh][prev]+=path;
		wh=prev;
	}
	
	return path;
	return 0;
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
