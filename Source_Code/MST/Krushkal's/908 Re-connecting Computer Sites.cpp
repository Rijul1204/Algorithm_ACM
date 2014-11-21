/*
Author : Rashedul Hasan Rijul
Algo   : Minimum Spanning Tree
problem : uva 908 (re-connecting Computer Sites)
*/

#include<stdio.h>
#include<algorithm>
using namespace std;

#define maxe 1001100
#define maxm 1001100

struct edge{
	int u;
	int v;
	int w;
};

edge edges[maxe];
int pre[maxm];

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









