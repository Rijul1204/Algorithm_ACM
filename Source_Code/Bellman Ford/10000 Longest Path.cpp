#include<stdio.h>

struct edge{
	int u;
	int v;
	int cost;
};

edge edges[20000];
int d[10000];

int main(){

	int i,j,k,l,dis,e,u,v,c,t=1,n;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
	
		if(!n) break;

		for(i=0;i<=n;i++) d[i]=-1;

		scanf("%d",&dis);
		d[dis]=0;
		i=0;
		while(1){
			scanf("%d %d",&k,&l);
			if(!k&&!l) break;
			edges[i].u=k;
			edges[i].v=l;
			edges[i].cost=1;
			i++;
		}
		e=i;
		for(j=0;j<=n;j++){
			for(i=0;i<e;i++){
			u=edges[i].u;
			v=edges[i].v;
			if(d[u]==-1) continue;
			if(d[v]<d[u]+1){
				d[v]=d[u]+1;
			}

		}
		}
		int max=-2; int  mark=0;

		for(i=1;i<=n;i++){
			if(i==dis||d[i]==-1) continue;
			if(d[i]>max){
				max=d[i];
				mark=i;
			}

		}

		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",t++,dis,max,mark);

		
		


	}

	return 0;
}
