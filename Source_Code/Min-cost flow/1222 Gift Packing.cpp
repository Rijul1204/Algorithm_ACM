/*
Author  :  Rashedul Hasan Rijul  .
Problem :  Loj 1222 Gift Packing .
Algo    :  Min-cost Flow         .
*/

#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

#define maxe 80100
#define maxm 200
#define inf 1<<29

int in(int x){
	if(x%2) return x+1;
	return x-1;
};

struct node{
	int no;
	int cost;
};

struct edge{
	int u,v,cost,cap,next;
};
edge edges[maxe];

struct path{
	int a,b,c;
};
path paths[maxe];


priority_queue<node>pq;
int prev[maxm],pre[maxm],d[maxm],n,m,e,cas=1;
int mat[maxm][maxm];

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

bool dij(int s);
void ford(int s,int t);

int main(){

	int i,j,k,l,t=1,test,tot;

	//freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		memset(prev,-1,sizeof(prev));
		scanf("%d",&n);
		tot=1;
		k=1;
		e=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&mat[i][j]);
				paths[k].a=i; paths[k].b=n+j; paths[k].c=mat[i][j];
				k++;
			}
		}
		tot=k;

		for(i=1;i<=n;i++){
			add(0,i,0,1);
		    add(i,0,0,0);

			add(n+i,2*n+1,0,1);
	    	add(2*n+1,n+i,0,0);
		}



		for(i=1;i<tot;i++){
			k=paths[i].a; l=paths[i].b; j=paths[i].c;
			add(k,l,-j,1);
			add(l,k,j,0);
		}

		ford(0,2*n+1);


	}




	return 0;
}

bool dij(int s){

	int i,j,k,l;
	node temp,temp1;

	memset(pre,-1,sizeof(pre));
	//memset(d,-1,sizeof(d));
	for(i=0;i<=2*n+10;i++){
		d[i]=inf;
	}

	d[s]=0;
	temp.cost=0;
	temp.no=s;
	pq.push(temp);

	while(!pq.empty()){
		temp=pq.top(); pq.pop();
		j=temp.no;

		for(i=prev[j];i!=-1;i=edges[i].next){
			k=edges[i].v;
			if(edges[i].cap>0 && d[k]>d[j]+edges[i].cost){
				d[k]=d[j]+edges[i].cost;
				temp1.cost=d[k]; temp1.no=k;
				pre[k]=i;
				pq.push(temp1);
			}

		}
	}

	return d[2*n+1]!=inf;



}

void ford(int s,int t){

	int i,j,k,l,wh,fl,ret,ans;

	fl=0;ans=0;

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
