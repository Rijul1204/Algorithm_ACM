#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

#define maxe 31000
#define maxm 200
#define inf 1<<30

struct node{
	int no;
	int cost;
};

struct edge{
	int u,v,cap,cost,next;
};

edge edges[maxe];

struct path{
	int a,b,c;
};

path paths[maxe];
int prev[maxm],col[maxm],pre[maxm],d[maxm],n,m,e;
queue<int>q;
priority_queue<node>pq;

bool operator<(const node &a,const node &b){
	return a.cost>b.cost;
}

void add(int u,int v,int cost,int cap){
	edges[e].u=u; edges[e].v=v;
	edges[e].cost=cost; edges[e].cap=cap;
	edges[e].next=prev[u];
	prev[u]=e++;
}
int mini(int a,int b){
	if(a<b) return a;
	return b;
}
void ford(int s,int t);
bool bfs(int s);

int main(){

	int i,j,k,l;

   // freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		if(!n) break;
		scanf("%d",&m);
		e=0;
		memset(prev,-1,sizeof(prev));

		for(i=1;i<=m;i++){
			scanf("%d %d %d",&paths[i].a,&paths[i].b,&paths[i].c);
		}

		add(0,1,0,2);
		add(1,0,0,0);

		add(n,n+1,0,2);
		add(n+1,n,0,0);

		for(i=1;i<=m;i++){
			k=paths[i].a; l=paths[i].b; j=paths[i].c;
			add(k,l,j,1);
			add(l,k,-j,0);

			add(l,k,j,1);
			add(k,l,-j,0);
		}

		ford(0,n+1);
	}

	return 0;
}

bool bfs(int s){

	int i,j,k,l;
	node temp,temp1;

//	memset(col,0,sizeof(col));
	memset(pre,-1,sizeof(pre));

	for(i=0;i<=n+10;i++) d[i]=inf;

	temp.no=s;
	temp.cost=0;
//	col[s]=1;
	d[s]=0;
	pq.push(temp);
//	q.push(s);

	while(!pq.empty()){

		//j=q.front(); q.pop();
		temp=pq.top(); pq.pop();
		j=temp.no;

		for(i=prev[j];i!=-1;i=edges[i].next){
			k=edges[i].v;
			
			if(edges[i].cap>0 && d[k]>temp.cost+edges[i].cost){
				d[k]=temp.cost+edges[i].cost;
				pre[k]=i;
				temp1.cost=d[k];
				temp1.no=k;
				pq.push(temp1);

				/*
				if(!col[k]){
					col[k]=1; q.push(k);
				}
				*/

			}
		}

	}

	return d[n+1]!=inf;

}

void ford(int s,int t){

	int i,j,k,l;
	int wh,fl,ret,ans;

	fl=0; ans=0;

	while(bfs(s)){
		
		wh=pre[t];
		ret=inf;

		while(wh!=-1){
			ret=mini(ret,edges[wh].cap);
			wh=pre[edges[wh].u];
		}

		wh=pre[t];
		
		while(wh!=-1){
			edges[wh].cap-=ret;
			edges[wh^1].cap+=ret;
			wh=pre[edges[wh].u];
		}
		fl+=ret;
		ans+=(d[t]*ret);
	}

	if(fl==2){
		printf("%d\n",ans);
	}
	else printf("Back to jail\n");


}