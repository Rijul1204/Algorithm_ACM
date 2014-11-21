#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

#define inf 1<<30
#define maxm 1000

int n,w,tot;
int mat[maxm][maxm],c[maxm][maxm],pre[maxm],col[maxm];


queue<int>q;

int in(int p) {return 2*p-1;}
int out(int p) {return 2*p;}

int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int ford(int s,int t);
int bfs(int s,int t);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

//	scanf("%d",&test);

	while(scanf("%d %d",&n,&w)==2){
	
		if(!n&&!w) break;
		
		
		int m;
		memset(mat,0,sizeof(mat));

		for(j=2;j<n;j++){
			scanf("%d %d",&i,&k);
			mat[in(i)][out(i)]=k;
			
		}

		for(i=1;i<=w;i++){
			scanf("%d %d %d",&k,&l,&j);
			mat[out(k)][in(l)]=mat[out(l)][in(k)]=j;
		}

		m=n;
		n*=2;
		printf("%d\n",ford(out(1),in(m)));



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
		path=mini(path,mat[prev][wh]);
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

int ford(int s,int d){

	int ret=0;

	while(1){
		
	//	printf("%d\n",ret);
		int fl=bfs(s,d);
		if(fl) ret+=fl;
		else break;		
	}
	
	return ret;

}

