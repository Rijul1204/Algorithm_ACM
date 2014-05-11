#include<stdio.h>
#include<algorithm>
using namespace std;

#define maxm  10100
#define maxe 100100

struct edge{
	int u;
	int v;
	int cost;
};
edge edges[maxe];
int pre[maxm];

bool comp(edge a,edge b){
	return a.cost>b.cost;
}

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

int main(){

	int i,j,k,l,test,n,m;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		for(i=1;i<=n;i++) pre[i]=i;

		int sum=0;int  total=0;

		for(i=0;i<m;i++){
			scanf("%d %d %d",&k,&l,&j);
			edges[i].u=k; edges[i].v=l; edges[i].cost=j;
			sum+=j;	
		}

		sort(edges,edges+m,comp);

		for(i=0;i<m;i++){

			k=find(edges[i].u);
			l=find(edges[i].v);

			if(k!=l){
				total+=edges[i].cost; 
				pre[k]=l;
			}

		}

		printf("%d\n",sum-total);

		



	}

	return 0;
}