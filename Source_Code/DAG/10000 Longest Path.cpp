#include<stdio.h>
#include<vector>
using namespace std;


int d[10000],col[10000];
vector<int>v[1000];
vector<int>topo;

void dfs(int s);

int main(){

	int i,j,k,l,dis,e,c,t=1,n;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
	
		if(!n) break;

		for(i=0;i<=n;i++){
			d[i]=-1;
			col[i]=0;
			v[i].clear();
		}
		topo.clear();

		scanf("%d",&dis);
		d[dis]=0;
		while(1){
			scanf("%d %d",&k,&l);
			if(!k&&!l) break;
			v[k].push_back(l);
		}

		for(i=1;i<=n;i++){
			if(!col[i]) dfs(i);
		}

		for(i=topo.size()-1;i>=0;i--){
			k=topo[i];
			if(d[k]==-1) continue;
			for(j=0;j<v[k].size();j++){
				l=v[k][j];
				if(d[l]<d[k]+1){
					d[l]=d[k]+1;
				}
			}
		}
	

		int max=-2; int  mark=0;

		for(i=1;i<=n;i++){
			if(i==dis||d[i]==-1) continue;
			if(d[i]>max){
				max=d[i];
				mark=i;
			}

		}

		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",t++,dis,max,mark);

		
		


	}

	return 0;
}

void dfs(int s){

	col[s]=1;

	for(int i=0;i<v[s].size();i++){
		if(!col[v[s][i]]) dfs(v[s][i]);
	}

	topo.push_back(s);
}
