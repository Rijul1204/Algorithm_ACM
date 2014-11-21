#include<stdio.h>
#include<algorithm>
using namespace std;

struct edge{
	int u;
	int v;
	int w;
};

edge edges[31000],select1[31000];
int pre[11000],n,m;

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

bool comp(edge a,edge b){
	return a.w<b.w;
}

void set(int n){

	for(int i=0;i<=n;i++){
		pre[i]=i;
	}
}

int main(){

	int i,j,k,l;

	//freopen("in.txt","r",stdin);
	
	while(scanf("%d %d",&n,&m)==2){
		if(!n&&!m) break;

		set(n);

		for(i=0;i<m;i++){
			scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
		}

		sort(edges,edges+m,comp);
		
		j=0;
		for(i=0;i<m;i++){
			k=find(edges[i].u); l=find(edges[i].v);
			if(k!=l){
				pre[k]=l;
			}
			else select1[j++]=edges[i];
		}

		sort(select1,select1+j,comp);

		if(j==0){
			printf("forest\n");
			continue;
		}

		for(i=0;i<j;i++){
			if(i>0) printf(" ");
			printf("%d",select1[i].w); 
		}
		printf("\n");	

	}

	return 0;

}