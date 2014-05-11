#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

#define inf 1<<27
#define maxm 100
#define maxe 1000

struct node{
	int no;
	double cost;
};

struct edge{
	int u,v,cap,next;
	double cost;
};

edge edges[maxe];

struct path{
	int u,v;
	double cost;
};

path paths[maxe];

bool operator<(const node &a,const node &b){
	return a.cost<b.cost;
}


int n,m,pre[maxe],prev[maxm],e;
double mat[maxm][maxm];
double d[maxm];


priority_queue<node>pq;
void add(int u,int v,int cap,double cost){
	edges[e].u=u; edges[e].v=v; edges[e].cap=cap;
	edges[e].cost=cost; edges[e].next=prev[u];
	prev[u]=e++;
}

int mini(int a,int b){
	if(a<b) return a;
	return b;
}

bool dij(int s);
void ford(int s,int t);

int main(){

	int i,j,k,l;
	double kd;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){
		
		if(!n&&!m) break;

		e=0;
		k=1;
		memset(prev,-1,sizeof(prev));

		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%lf",&kd);
				paths[k].u=i; paths[k].v=n+j;
				paths[k].cost=kd;
				k++;
			}
		}

		

		for(i=1;i<=n;i++){
			add(0,i,1,0);
			add(i,0,0,0);
		}

		for(j=1;j<=m;j++){
			add(n+j,m+n+1,1,0);
			add(m+n+1,n+j,0,0);
		}

		for(i=1;i<k;i++){			
			add(paths[i].u,paths[i].v,1,paths[i].cost);
			add(paths[i].v,paths[i].u,0,-paths[i].cost);
		}

		ford(0,m+n+1);		

	}

	return 0;
}

bool dij(int s){

	int i,j,k,l;
	node temp,temp1;
	memset(pre,-1,sizeof(pre));
	
	for(i=0;i<=n+m+2;i++){
		d[i]=inf;
	}
	d[s]=0;
	temp.cost=0; temp.no=s;
	pq.push(temp);

	while(!pq.empty()){
		temp=pq.top(); pq.pop();
		j=temp.no;
		for(i=prev[j];i!=-1; i=edges[i].next){
			k=edges[i].v;
			if(edges[i].cap>0 && d[k]>d[j]+edges[i].cost){
				d[k]=d[j]+edges[i].cost;
				temp1.cost=d[k];
				temp1.no=k;
				pre[k]=i;
				pq.push(temp1);
			}
		}
	}

	return d[n+m+1]!=inf;
	
}

void ford(int s,int t){

	int i,j,k,l,fl,wh;
	double ans;
	int ret;

	ans=0; fl=0;

	while(dij(s)){

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
		ans+=((double) ret* d[t]);

	}
	//ans*=-1;
	ans/=(double)n;
	ans+=.00000001;

	printf("%.2lf\n",ans);



}