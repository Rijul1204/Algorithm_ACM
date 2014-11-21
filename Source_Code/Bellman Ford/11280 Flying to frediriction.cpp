#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

#define inf 11474368


struct edge{
	int u;
	int v;
	int w;
};

edge edges[20000];

string a,b;
map<string,int>city;

int d[20000],dis[20000];

void set(int n);
void Bellman(int n,int m);
bool comp(edge a,edge b){
	if(a.u>b.u) return 0;
	if(a.u==b.u){
		if(a.v>b.v) return 0;
		else if(a.v==b.v){
			if(a.w>b.w) return 0;
			return 1;
		}
		return 1;
	}
	return 1;
}


int main(){

	int i,j,k,l,test,n,m,count,cost,stop,q,t=1,blank=false;
	
	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		city.clear();
		count=0;

		for(i=1;i<=n;i++){

			cin>>a;
			city[a]=i;

		}

		set(n);
		scanf("%d",&m);

		for(i=1;i<=m;i++){

			cin>>a>>b>>cost;
			//mat[city[a]][city[b]]=cost;			
			edges[i].u=city[a];
			edges[i].v=city[b];
			edges[i].w=cost;
		}

//		for(i=1;i<=m;i++){
//			printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].w);
//		}
		
//		printf("\n\n");
		sort(edges+1,edges+m+1,comp);
		
	//	for(i=1;i<=m;i++){
		//	printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].w);
	//	}

		scanf("%d",&q);

		if(blank) printf("\n");
		blank=true;

		printf("Scenario #%d\n",t++);

		for(i=1;i<=q;i++){
			scanf("%d",&stop);
			if(stop<0){
				printf("No satisfactory flights\n");
				continue;
			}

			set(n);
			Bellman(stop,m);
			if(d[n]<inf) printf("Total cost of flight(s) is $%d\n",d[n]);
			else printf("No satisfactory flights\n");

		}
		


	}

	return 0;

}

void Bellman(int n,int m){

	int i,j;
	d[1]=0;

	for(i=1;i<=n+1;i++){
		for(j=m;j>=1;j--){
			//if(dis[edges[j].u]>i) continue;
			if(d[edges[j].v]>d[edges[j].u]+edges[j].w){
				d[edges[j].v]=d[edges[j].u]+edges[j].w;
				
			}
		}
	}


}



void set(int n){

	for(int i=0;i<=n;i++){
		d[i]=inf;		
	}
}

