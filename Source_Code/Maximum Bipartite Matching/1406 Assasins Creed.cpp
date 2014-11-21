#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
using namespace std;

#define maxm 40100

int l[maxm],r[maxm],col[maxm],pre[maxm],n,m;
vector<int>v[maxm],vt[maxm],topo,v1[maxm],v2;
set<int>ss[maxm];
void dfs(int s);
void dfst(int s,int par);
bool dfss(int s);
int match();

int main(){
	
	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d %d",&n,&m);
		
		for(i=0;i<=n;i++){
			v[i].clear();
			vt[i].clear();
			v1[i].clear();
			pre[i]=i;
	//		ss[i].clear();
		}
		topo.clear(); v2.clear();
		
		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
			vt[l].push_back(k);
		}
		
		memset(col,0,sizeof(col));
		
		for(i=1;i<=n;i++){
			if(!col[i]) dfs(i);
		}
		
		for(j=topo.size()-1;j>=0;j--){
			i=topo[j];
			if(col[i]){
				v2.push_back(i);
				dfst(i,i);
			}
		}
		
		for(i=1;i<=n;i++){
			k=pre[i];	
			for(j=0;j<v[i].size();j++){
				l=pre[v[i][j]];
				if(k==l) continue;
		//		if(ss[k].find(l)!=ss[k].end()) continue;
		//		ss[k].insert(l);
				v1[k].push_back(l+n);
			}
		}
		printf("Case %d: %d\n",t++,match());
		
		
		
	}
	
	return 0;
}

int match() {
	int ret = 0;
	
	memset(r,-1,sizeof(r));
	memset(l,-1,sizeof(l));
	
	int i,j,k;
	bool done;
	do{
		done = 1;
		memset(col,0,sizeof(col));
		
		for(j=0;j<v2.size();j++)
		{
			i=v2[j];
			if(l[i]==-1 && dfss(i)) 	done = 0;
		}
		
	}while(!done);
	
	for(j=0;j<v2.size();j++){
		i=v2[j];
		ret += (r[i+n]==-1);
	}
	return ret;
}

bool dfss(int u) {
	
	if(col[u]) return false;
	col[u] = true;
	int v,i,j,k;
	for(i=0;i<v1[u].size();i++)
	{
		v = v1[u][i];
		if(r[v]==-1) 
		{
			r[v] = u, l[u] = v;
			return true;
		}
	}
	for(i=0;i<v1[u].size();i++)
	{
		v = v1[u][i];
		if(dfss(r[v])) 
		{r[v] = u, l[u] = v;
		return true;
		}
	}
	return false;
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
void dfst(int s,int par){
	
	pre[s]=par;
	
	col[s]=0;
	int i,j,k;
	
	for(i=0;i<vt[s].size();i++){
		k=vt[s][i];
		if(col[k]){
			dfst(k,par);
		}
	}
}