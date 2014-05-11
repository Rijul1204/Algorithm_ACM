#include<stdio.h>
#include<algorithm>
using namespace std;

struct edge{
	int u;
	int v;
	int cost;
};

edge edges[640000],ans[640000];
int x[1000],y[1000],pre[1000];
int count1;

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

bool comp(edge a,edge b){
	return a.cost<b.cost;
}

int main(){

	int i,j,k,l,test,n,m,ind,bl=0;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=1;i<=n;i++){
			pre[i]=i;
			scanf("%d %d",&x[i],&y[i]);
		}
		count1=0;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				k=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				edges[count1].u=i;
				edges[count1].v=j;
				edges[count1++].cost=k;
			}
		}

		scanf("%d",&m);
		
		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			k=find(k); l=find(l);
			if(k!=l){
				pre[k]=l;
			}
		}

		sort(edges,edges+count1,comp);

		ind=0;

		for(i=0;i<count1;i++){
			k=edges[i].u; l=edges[i].v;

			k=find(k);  l=find(l);
			if(k!=l){
				pre[k]=l;
				ans[ind].u=edges[i].u; 
				ans[ind++].v=edges[i].v;
			}
		}

		if(bl) printf("\n");
		bl=1;

		if(ind==0) printf("No new highways need\n");
		else{
			for(i=0;i<ind;i++){
				printf("%d %d\n",ans[i].u,ans[i].v);

			}
		}




	}	


	return 0;
}