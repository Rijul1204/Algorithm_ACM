#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

#define maxm 200
#define maxe 400000
#define inf 1<<28

struct node{
	int no,cost;
};
struct edge{
	int u,v,cost,cap,next;
};
edge edges[maxe];

priority_queue<node>pq;
int prev[maxm],pre[maxm],d[maxm],n,m,e,cas=1;
int mat[3][maxm];

bool operator<(const node &a,const node &b){
	return a.cost>b.cost;
}

void add(int u,int v,int cost,int cap){
	edges[e].u=u; edges[e].v=v; edges[e].cost=cost; edges[e].cap=cap;
	edges[e].next=prev[u]; prev[u]=e++;
}

int mini(int a,int b){
	if(a<b) return a; return b;
}
bool dij(int s);
void ford(int s,int t);

int main(){

	int i,j,k,l,test;

	//freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		
		memset(prev,-1,sizeof(prev));
		e=0;

		for(i=1;i<=n;i++){
			scanf("%d",&mat[1][i]);
		}

		for(j=1;j<=n;j++){
			scanf("%d",&mat[2][j]);
		}

		for(i=1;i<=n;i++){
			add(0,i,0,1);
			add(i,0,0,0);
			for(j=1;j<=n;j++){
				if(mat[1][i]>mat[2][j]){
					add(i,n+j,-2,1);
					add(n+j,i,2,0);
				}
				else if(mat[1][i]==mat[2][j]){
					add(i,n+j,-1,1);
					add(n+j,i,1,0);
				}
				else {
					add(i,n+j,0,1);
					add(n+j,i,0,0);
				}
			}

			add(n+i,2*n+1,0,1);
			add(2*n+1,n+i,0,0);
		}

		ford(0,2*n+1);

	}
	
	return 0;
}

bool dij(int s){

	int i,j,k,l;
	node temp,temp1;
	memset(pre,-1,sizeof(pre));

	for(i=0;i<=2*n+10;i++){
		d[i]=inf;
	}
	d[s]=0; 
	temp.cost=0; temp.no=s;
	pq.push(temp);
	while(!pq.empty()){

		temp=pq.top(); pq.pop();
		j=temp.no;
		for(i=prev[j];i!=-1;i=edges[i].next){
			k=edges[i].v;
			if(edges[i].cap>0 && d[k]>d[j]+edges[i].cost){
				d[k]=d[j]+edges[i].cost;
				pre[k]=i;
				temp1.cost=d[k]; temp1.no=k;
				pq.push(temp1);

			}

		}

	}

	return d[2*n+1]!=inf;

}

void ford(int s,int t){
	
	int i,j,k,l,wh,fl,ret,ans;

	fl=0; ans=0;

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
		
		ans+=(ret*d[t]);

	}

	printf("Case %d: %d\n",cas++,ans*-1);
}