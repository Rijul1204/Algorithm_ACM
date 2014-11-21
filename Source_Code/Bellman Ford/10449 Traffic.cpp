#include<stdio.h>

#define inf 1<<30
#define low 1<<29

struct edge{
	int u;
	int v;
	int cost;
};

edge edges[80000];
int d[1000],b[1000],flag[1000];

void bellman(int n,int e);

int main(){

	int i,j,k,l,test,n,e,c,t=1;

	while(scanf("%d",&n)==1){

		for(i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		scanf("%d",&e);
		for(i=0;i<e;i++){
			scanf("%d %d",&k,&l);
			edges[i].u=k;
			edges[i].v=l;
			c=b[l]-b[k];
			c=c*c*c;
			//printf("%d %d %d\n",k,l,c);
			edges[i].cost=c;
		}

		bellman(n,e);

	//	for(i=1;i<=n;i++){
	//		printf("%d\n",d[i]);
	//	}

		scanf("%d",&k);
		printf("Set #%d\n",t++);
		for(i=1;i<=k;i++){
			scanf("%d",&l);
			if(flag[l]||d[l]<3||d[l]>low){
				printf("?\n");
			}
			else printf("%d\n",d[l]);
		}


	}

	return 0;

}

void bellman(int n,int e){

	int i,j,k,l,u,v;

	for(i=1;i<=n;i++){
		flag[i]=0;
		d[i]=inf;
	}
	d[1]=0;

	for(i=1;i<=n+5;i++){
		for(j=0;j<e;j++){
			u=edges[j].u;
			v=edges[j].v;
			if(d[v]>d[u]+edges[j].cost){
				d[v]=d[u]+edges[j].cost;
				if(i>n) flag[v]=1;
			}
		}
	}




}
