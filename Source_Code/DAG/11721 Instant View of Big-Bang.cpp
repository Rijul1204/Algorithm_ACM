#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

#define inf 1<<26
#define maxm 2500
#define maxe 2500

struct edge{
	int u;
	int v;
	int cost;
};

edge edges[maxe];
vector<int>v[maxm],vt[maxm],topo;
int n,m,col[maxm],pre[maxm],d[maxm],cycle[maxm],c=0;

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

void dfs(int s);
void dfst(int s,int par);
bool dfss(int s,int par);
void bellman(int s);

int main(){
	
	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&n,&m);

		memset(cycle,0,sizeof(cycle));
		for(i=0;i<=n+2;i++){
			pre[i]=i; v[i].clear();
			vt[i].clear();
		}
		topo.clear();

		for(i=0;i<m;i++){
			scanf("%d %d %d",&k,&l,&j);
			v[k].push_back(l); vt[l].push_back(k);
			edges[i].u=k; edges[i].v=l; edges[i].cost=j;
		}

		memset(col,0,sizeof(col));

		for(i=0;i<n;i++) if(!col[i]) dfs(i);

		for(j=topo.size()-1;j>=0;j--){
			i=topo[j];
			if(col[i]){
				c=0;
				dfst(i,i);
				bellman(i);				
			}			
		}
		
		memset(col,0,sizeof(col));
	
		for(j=topo.size()-1;j>=0;j--){
		
			i=topo[j];
			
			if(cycle[find(i)]==1) continue;
			
			if(!col[i]){
				col[i]=1;
				if(dfss(i,i)) cycle[find(i)]=1;
			}
		
		}

	/*	
		for(i=0;i<n;i++){
			
			if(cycle[find(i)]==1) continue;
			if(!col[find(i)]){
				col[find(i)]=1;
				dfss(find(i),find(i));
			}
		}
	*/	
		int fl=0;
		printf("Case %d:",t++);
		for(i=0;i<n;i++){
			if(cycle[find(i)]==1){
				fl=1;
				printf(" %d",i);
			}
		}
		if(!fl) printf(" impossible");
		printf("\n");

	}

	return 0;
}

bool dfss(int s,int par){
	
	int i,j,k,l;
	col[s]=1;
	
	
	for(i=0;i<v[s].size();i++){
		
		j=v[s][i]; 

		if(cycle[find(j)]==1){
			cycle[find(s)]=1;
			return 1;
		}

		if(!col[j]){
			if(dfss(j,par)){
				cycle[find(s)]=1;
				return 1;
			}
		}
	}
	
	return 0;

}

void bellman(int s){

	int i,j,k,l;

	for(i=0;i<=n;i++){
		d[i]=inf;
	}

	d[s]=0;

	for(i=0;i<=c+2;i++){
		//if(find(i)!=s) continue;
		for(j=0;j<m;j++){
			k=edges[j].u; l=edges[j].v;
			if(d[k]==inf) continue;
			if(find(k)!=s) continue; 
			if(find(l)!=s) continue;
			if(d[l]>d[k]+edges[j].cost){
				d[l]=d[k]+edges[j].cost;
			}
		}
	}

	for(j=0;j<m;j++){
		k=edges[j].u; l=edges[j].v;
		if(d[k]==inf) continue;
		if(find(k)!=s) continue; 
		if(find(l)!=s) continue;
		if(d[l]>d[k]+edges[j].cost){
			cycle[s]=1;
			break;
		}
	}
}

void dfst(int s,int par){
	
	col[s]=0;
	pre[s]=par;
	c++;

	int i,j,k,l;

	for(i=0;i<vt[s].size();i++){
		j=vt[s][i];
		if(col[j]){
			dfst(j,par);
		}
	}

}

void dfs(int s){
	col[s]=1;

	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		j=v[s][i];
		if(!col[j]){
			dfs(j);
		}
	}
	topo.push_back(s);
}