#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct node{
	double x;
	double y;
};

node nodes[100000];

struct edge{
	int u;
	int v;
	double cost;
};

edge edges[100000];
int pre[100000];

bool comp(edge a,edge b);
int find(int x);
void set(int n){
	for(int i=0;i<=n;i++) pre[i]=i;
}

int main(){

	int i,j,k,l,n,test;
	int a,b;
	bool blank=false;
	double dis,tempx,tempy,total;

	scanf("%d",&test);

	while(test--){
		scanf("%d",&n);

		l=0;

		for(i=1;i<=n;i++){
			scanf("%lf %lf",&nodes[i].x,&nodes[i].y);
			for(j=1;j<i;j++){
				tempx=nodes[i].x-nodes[j].x;
				tempx*=tempx;
				tempy=nodes[i].y-nodes[j].y;
				tempy*=tempy;
				dis=tempx+tempy;
				edges[l].u=i;
				edges[l].v=j;
				edges[l++].cost=dis;
			}
		}
		sort(edges,edges+l,comp);
		set(n);

		total=0;

		

		for(i=0;i<l;i++){
			 a=find(edges[i].u);
			 b=find(edges[i].v);
			 if(a!=b){
				 pre[a]=b;
				 total+=sqrt(edges[i].cost);
			 }
		}

		if(blank) printf("\n");
		blank=true;

		printf("%.2lf\n",total);
			 



	}

	return 0;

}

bool comp(edge a,edge b){
	if(a.cost<b.cost) return 1;
	return 0;
}

int find(int x){
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}

				


	
