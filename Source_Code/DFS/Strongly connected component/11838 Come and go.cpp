#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 2500

vector<int>v[maxm],vt[maxm],topo;
int col[maxm];

void dfs(int s);
void dfst(int s);

int main(){

	int i,j,k,l,n,m;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){

		if(!n&&!m) break;
		
		memset(col,0,sizeof(col));
		
		for(i=0;i<=n+2;i++){
			v[i].clear(); vt[i].clear();
		}
		topo.clear();

		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			v[k].push_back(l);
			vt[l].push_back(k);
			if(j==2){
				v[l].push_back(k);
	    		vt[k].push_back(l);
			}
		}

		for(i=1;i<=n;i++){
			if(!col[i]){
				dfs(i);
			}
		}

		memset(col,0,sizeof(col));

		dfst(topo[topo.size()-1]);

		int flag=0;

		for(j=topo.size()-2;j>=0;j--){
			if(col[topo[j]]==0){
				flag=1;
				break;
			}
		}

		if(flag) printf("0\n");
		else printf("1\n");

	}

	return 0;
}

void dfs(int s){

	col[s]=1;

	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		if(!col[k]){
			dfs(k);
		}
	}

	topo.push_back(s);

}


void dfst(int s){

	col[s]=1;

	int i,j,k,l;

	for(i=0;i<vt[s].size();i++){
		k=vt[s][i];
		if(!col[k]){
			dfst(k);
		}
	}
}