#include<stdio.h>
#include<vector>
#include<set>
#include<string.h>
using namespace std;

#define maxm 20110

vector<int>v[maxm],vt[maxm],topo,scc;
set<int>set1[maxm];
int col[maxm],flag[maxm],pre[maxm],in[maxm],out[maxm];
int source,dest,n,m,c;

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}
void reset(int n);
void dfs(int s);
void dfst(int s,int p);

int main(){

	int i,j,k,l,test,t=1;

  //freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);
		reset(n);
		

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
			vt[l].push_back(k);
		}			
		
		for(i=1;i<=n;i++){
			if(!col[i]) dfs(i);
		}

		for(i=topo.size()-1;i>=0;i--){
			j=topo[i];
			if(col[j]){
				dfst(j,j);
				scc.push_back(j);
			}
		}

		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));

		/*
		for(i=topo.size()-1;i>=0;i--){
			for(j=topo.size()-1;j>=0;j--){
				if(find(topo[i])==find(topo[j])) continue;
				if(set1[topo[i]].find(topo[j])==set1[topo[i]].end()) continue;
				in[find(topo[j])]++;
				out[find(topo[i])]++;				
			}
		}
		*/

		for(i=topo.size()-1;i>=0;i--){
			k=topo[i];
			for(j=0;j<v[k].size();j++){
				l=v[k][j];
				if(find(k)==find(l)) continue;
				in[find(l)]++;
				out[find(k)]++;
			}
		}

		k=0; l=0;

		for(i=0;i<scc.size();i++){
			j=scc[i];
			if(in[j]==0) k++;
			if(out[j]==0) l++;
		}

		if(k>l) c=k;
		else c=l;
		
		if(scc.size()==1) c=0;
		printf("Case %d: %d\n",t++,c);


	}

	return 0;
}

void reset(int n){

	for(int i=0;i<=n+10;i++){
		v[i].clear();
		vt[i].clear();
		col[i]=0;
		flag[i]=0;
		pre[i]=i;
	}
	topo.clear();
	scc.clear();
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

void dfst(int s,int p){
	
	col[s]=0;
	pre[s]=p;
	int i,j,k,l;

	for(i=0;i<vt[s].size();i++){
		k=vt[s][i];
		if(col[k])	dfst(k,p);
	}

}