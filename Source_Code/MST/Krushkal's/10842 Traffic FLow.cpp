#include<stdio.h>
#include<algorithm>
using namespace std;

struct edge{
	int u;
	int v;
	int w;
};

edge edges[11100];
bool comp(edge a,edge b){
	return a.w>b.w;
}
int pre[11000];

int find(int x){
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}



int main(){

	int i,j,k,l,test,n,m,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		for(i=0;i<=n;i++) pre[i]=i;

		for(i=0;i<m;i++){
			scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
		}

		sort(edges,edges+m,comp);

		int res=edges[0].w;

		for(i=0;i<m;i++){
			int a=find(edges[i].u);
			int b=find(edges[i].v);
			if(a!=b){
				pre[a]=b;
				if(res>edges[i].w){
					res=edges[i].w;
				}

			}
		}

		printf("Case #%d: %d\n",t++,res);

			

	}

	return 0;

}
