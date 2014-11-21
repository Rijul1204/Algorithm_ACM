#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

//#define ii __int64
#define ii long long int
#define inf 1<<30

#define maxe 20100
#define maxm 200

struct edge{
	int u;
	int v;
	int next;
	ii cost,cap;
};
edge edges[maxe];

struct path{
	int a,b,c;
};
path paths[maxe];
int pre[maxm],prev[maxm],n,m,tot,e,capa,col[maxm];
ii d[maxm];

ii mini(ii a,ii b){
	if(a<b) return a;
	return b;
}

queue<int>q;

void ford(int s,int t);
bool bfs(int s);

void add(int u,int v,int cost,int cap){
	edges[e].u=u;
	edges[e].v=v;
	edges[e].cost=cost;
	edges[e].cap=cap;
	edges[e].next=prev[u];
	prev[u]=e++;
}

int main(){

	int i,j,k,l;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){

		e=0;
		memset(prev,-1,sizeof(prev));
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&paths[i].a,&paths[i].b,&paths[i].c);
		}

		scanf("%d %d",&tot,&capa);

		add(0,1,0,tot);
		add(1,0,0,0);

		add(n,n+1,0,tot);
		add(n+1,n,0,0);

		for(i=1;i<=m;i++){
			k=paths[i].a; l=paths[i].b; j=paths[i].c;

			add(k,l,j,capa);
			add(l,k,-j,0);

			add(l,k,j,capa);
			add(k,l,-j,0);
		
		}

		ford(0,n+1);

	}

	return 0;
}

bool bfs(int s){

	int i,j,k,l;

	memset(pre,-1,sizeof(pre));
	memset(col,0,sizeof(col));
	
	for(i=0;i<=n+10;i++) d[i]=inf;
	d[s]=0;
	col[s]=1;

	q.push(s);

	while(!q.empty()){
		
		j=q.front(); q.pop();

		for(i=prev[j];i!=-1;i=edges[i].next){
			k=edges[i].v;

			if(edges[i].cap>0 && d[k]>d[j]+edges[i].cost){
				d[k]=d[j]+edges[i].cost;
				pre[k]=i;

				if(!col[k]){
					col[k]=1;
					q.push(k);
				}
			}

		}

		col[j]=0;


	}


	return d[n+1]!=inf;

}

void ford(int s,int t){

	int i,j,k,l,prev,wh;
	ii fl,ret,ans;

	fl=0;
	ans=0;

	while(bfs(s)){

		ii ret=inf;

		wh=pre[t];

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
		ans+=(ret*d[t]);

	}

	if(fl==tot){
		//printf("%I64d\n",ans);
		printf("%lld\n",ans);
	}
	else {
		printf("Impossible.\n");
	}

}