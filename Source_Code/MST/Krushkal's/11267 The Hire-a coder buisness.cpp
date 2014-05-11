#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define maxm 250
#define inf 1<<28
#define maxl 11100

struct edge{
	int u,v,cost;
};

edge edges[maxl];
int pre[maxm],state[maxm],col[maxm],n,m;
queue<int>q;
vector<int>v[maxm];
int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}
bool bfs(int s);
bool comp(edge a,edge b){
	return a.cost<b.cost;
}

int main(){
	
	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1){
		if(!n) break;
		
		for(i=0;i<=n;i++){
			 pre[i]=i;
			 v[i].clear();
		 }
		
		scanf("%d",&m);
		
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			v[k].push_back(l);
			v[l].push_back(k);
			edges[i-1].u=k; edges[i-1].v=l; edges[i-1].cost=j;
		}
		
		if(!bfs(1)){
			printf("Invalid data, Idiot!\n");
			continue;			
		}
		
		int sum=0;
		sort(edges,edges+m,comp);
		
		for(i=0;i<m;i++){
			k=edges[i].u; l=edges[i].v;
			k=find(k); l=find(l);
			if(k==l&&edges[i].cost<0) sum+=edges[i].cost;
			else if(k!=l){
				pre[k]=l;
				sum+=edges[i].cost;
			}		
		}
		
		printf("%d\n",sum);
		
		
	}
	
	
	return 0;
}

bool bfs(int s){
	
	int i,j,k,l;
	
	memset(col,0,sizeof(col));
	
	while(!q.empty()) q.pop();
	col[s]=1;
	q.push(s);
	
	while(!q.empty()){
		
		i=q.front(); q.pop();
		
		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(col[k]==col[i]) return false;
			if(col[k]==0){
				col[k]=3-col[i];
				q.push(k);			
			}			
		}
		
	}
	
	return true;
	
	
}
