#include<stdio.h>
#include<algorithm>
using namespace std;

struct edge{
	int u;
	int v;
	int w;
};

edge edges[1001100];
int pre[1001100];

bool comp(edge a,edge b){
	return a.w>b.w;
}

int find(int x){
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}

int main(){


	int i,j,k,l,n,m,a,b,c,cost;

	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){

        for(i=0;i<m;i++){
            scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
        }
        sort(edges,edges+m,comp);

        int sum=0;
        for(i=0;i<m;i++){
            k=find(edges[i].u); l=find(edges[i].v);
            if(k==l) continue;
            sum+=edges[i].w;
        }
        printf("%d\n",sum);

	}

	return 0;


}









