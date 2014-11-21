#include<stdio.h>
#include<vector>
using namespace std;

#define maxm 1000010


vector<int>v[maxm],topo;
int col[maxm],flag;
void dfs(int s);
void dfst(int s);

int main(){

	int i,j,k,l,n,m;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){

		if(!n&&!m) break;

		for(i=0;i<=n;i++){
			col[i]=0; v[i].clear();
		}

		topo.clear();

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
		}

		for(i=1;i<=n;i++){
			if(!col[i]) dfs(i);
		}

		for(i=0;i<topo.size();i++){
			if(col[topo[i]]){
				flag=1;
				dfst(topo[i]);
				if(!flag) break;
			}
		}

		if(flag){
			for(i=topo.size()-1;i>=0;i--){
				printf("%d\n",topo[i]);
			}

		}
		else printf("IMPOSSIBLE\n");


	}



	return 0;
}


void dfs(int s){
	
	col[s]=1;

	for(int i=0;i<v[s].size();i++){
		int j=v[s][i];
		if(!col[j]) dfs(v[s][i]);
	}

	col[s]=2;
	topo.push_back(s);
}

void dfst(int s){

	col[s]=0;

	for(int i=0;i<v[s].size();i++){
		int k=v[s][i];

		if(col[v[s][i]]){
			flag=0;
			return ;
		}

	}

}
