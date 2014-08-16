/*
Author  : Rashedul Hasan Rijul.
Problem : Uva 10480 Sabotage  .
Algo    : Max-flow/Min-cut .
*/

#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

#define inf 1000000000
#define maxm 110

struct node{
	int no;
	int cost;
};
int n,m,tot,mat[maxm][maxm],pre[maxm],cap[maxm][maxm],col[maxm];
queue<int>q;

int in(int x){
	return 2*x-1;
}

int out(int x){
	return 2*x;
}
int comp(int x){
	if(x%2) return ((x+1)/2);
	else return x/2;
}

void ford(int s,int t);
int bfs(int s,int t);
int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){
		if(!n&&!m) break;
		memset(mat,0,sizeof(mat));
		memset(cap,0,sizeof(cap));

		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			//mat[out(k)][in(l)]=mat[out(l)][in(k)]=j;
			//cap[out(k)][in(l)]=cap[out(l)][in(k)]=1;
			mat[k][l]=mat[l][k]=j;
			cap[k][l]=cap[l][k]=1;
		}

		mat[2][n+1]=inf;
		mat[n+1][2]=inf;

		ford(1,n+1);
		printf("\n");

	}

	return 0;
}

int bfs(int s,int t){

	memset(pre,-1,sizeof(pre));
	memset(col,0,sizeof(col));
	int i,j,k,l;

	while(!q.empty()) q.pop();

	q.push(s);
	col[s]=1;

	while(!q.empty()){
		i=q.front(); q.pop();
		if(i==t) break;
		for(j=s;j<=t;j++){
			if(col[j]==0&&mat[i][j]>0){
				pre[j]=i;
				q.push(j);
				col[j]=1;
				if(j==t) break;
			}
		}
	}

	int wh,path,prev;
	path=inf;
	wh=t;
	while(pre[wh]!=-1){
		prev=pre[wh];
		path=mini(path,mat[prev][wh]);
		wh=prev;
	}

	wh=t;
	while(pre[wh]!=-1){
		prev=pre[wh];
		mat[prev][wh]-=path;
		mat[wh][prev]+=path;
		wh=prev;
	}

	if(path==inf )return 0;
	return path;

}

void ford(int s,int t){

	int ret=0,i,j;
	while(1){
		int fl=bfs(s,t);
		if(fl) ret+=fl;
		else break;
	}
//	printf("ret - %d\n",ret);

	int flag[maxm][maxm];
	memset(flag,0,sizeof(flag));

	for(i=1;i<=n;i++){
		if(!col[i]) continue;
		for(j=1;j<=n;j++){
			if(col[j]) continue;
			if(cap[i][j])printf("%d %d\n",i,j);
		}
	}


}
