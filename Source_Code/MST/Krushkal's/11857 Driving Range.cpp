#include<stdio.h>
#include<algorithm>
using namespace std;

struct edge{
	int u;
	int v;
	int cost;
};

edge edges[1010000];

int pre[1001000];

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

bool comp(edge a,edge b){
	return a.cost<b.cost;
}


int main(){

	int i,j,k,l,n,m;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){
		if(!n&&!m) break;

		for(i=0;i<=n;i++) pre[i]=i;

		for(i=0;i<m;i++){
			scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].cost);
		}

		sort(edges,edges+m,comp);

		int max=-1;

		for(i=0;i<m;i++){
			k=find(edges[i].u);
			l=find(edges[i].v);
			if(k!=l){
				pre[k]=l;
				if(max<edges[i].cost) max=edges[i].cost;					
			}

		}
		int c1=0;
		for(i=0;i<n;i++){
			if(pre[i]==i) c1++;
		}

		if(c1>1) printf("IMPOSSIBLE\n");
		else printf("%d\n",max);

	}


	return 0;
}
