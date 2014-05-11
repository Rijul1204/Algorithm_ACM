#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct{
	int u;
	int v;
	int w;
}edge;

edge edges[200110];
bool comp(edge a,edge b);
void set(int n);
int find(int x);


int pre[200110];


int main(){

	int i,j,k,l,n,m,cost,total;

	//freopen("in.txt","r",stdin);

	while((scanf("%d %d",&n,&m)==2)&&n&&m){

		cost=0;
		total=0;

		for(i=0;i<m;i++){
			scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
			total+=edges[i].w;
		}

		sort(edges,edges+m,comp);

		set(n);		
		
		for(i=0;i<m;i++){
			int a=find(edges[i].u);
			int b=find(edges[i].v);
			if(a!=b){
				cost+=edges[i].w;
				pre[a]=b;
			}
				
		}

		printf("%d\n",total-cost);
	}

	return 0;

}

bool comp(edge a,edge b){

	return (a.w<b.w); 

}

int find(int x){
	if(pre[x]==x) return x;
   return pre[x]=find(pre[x]);
}


void set(int n){

	for(int i=0;i<=n;i++){
		pre[i]=i;
	}

}







