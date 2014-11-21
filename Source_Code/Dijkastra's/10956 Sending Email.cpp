#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define inf 873741824

vector<int>edge[51000],cost[51000];

struct data{

	int city,dist;
	bool operator < (const data& p) const{
		return dist>p.dist;
	}
};

int d[21000];

void dijkastra(int source,int destination);

int main(){
	
	int i,j,k,l,test,n,m,s,t,tt=1;

	//freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d %d %d %d",&n,&m,&s,&t);

		for(i=0;i<=n;i++){
			d[i]=inf;
			edge[i].clear();
			cost[i].clear();
		}
		
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			edge[k].push_back(l);
			edge[l].push_back(k);
			cost[k].push_back(j);
			cost[l].push_back(j);
		}

		dijkastra(s,t);
		
		printf("Case #%d: ",tt++);

		if(d[t]<inf) printf("%d\n",d[t]);
		else printf("unreachable\n");




		
	}
	
	
	return 0;
	
}

void  dijkastra(int source,int destination){

	d[source]=0;

	data u,v;
	int i;

	priority_queue<data>q;

	u.city=source;
	u.dist=0;
	q.push(u);

	while(!q.empty()){

		u=q.top(); q.pop();		

		for(i=0;i<edge[u.city].size();i++){
			v.city=edge[u.city][i];
			v.dist=d[u.city]+cost[u.city][i];

			if(d[v.city]>v.dist){
				d[v.city]=v.dist;
				q.push(v);
		
			}
		}

	}

}



