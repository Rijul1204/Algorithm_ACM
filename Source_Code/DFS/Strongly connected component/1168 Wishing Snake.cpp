#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 1100

vector<int>v[maxm],vt[maxm],topo,scc;
int col[maxm],n,flag[maxm],pre[maxm],par[maxm],in[maxm],out[maxm],mat[maxm][maxm];

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}
void dfs(int s);
void dfst(int s,int par);

int main(){
	
	int i,j,k,l,test,t=1,u,vd;
	
//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d",&n);

		for(i=0;i<=1010;i++){
			v[i].clear(); vt[i].clear();
			pre[i]=i;
		}
	
		topo.clear(); scc.clear();

		memset(col,0,sizeof(col));
		memset(flag,0,sizeof(flag));
		memset(mat,0,sizeof(mat));

		int c=0;

		for(i=1;i<=n;i++){
			scanf("%d",&k);
			for(j=1;j<=k;j++){
				scanf("%d %d",&u,&vd);
				flag[u]=flag[vd]=1;
				c++;
				v[u].push_back(vd);
				vt[vd].push_back(u);
				mat[u][vd]=1;
			}		
		}

		if(c&&!flag[0]){
			printf("Case %d: NO\n",t++);
			continue;
		}		
		
		dfs(0);
		
		int flags=0;
		for(i=0;i<=1010;i++){
			if(flag[i]==1){
				if(col[i]==0) flags=1;
			}
		}
		
		if(flags){
			printf("Case %d: NO\n",t++);
			continue;
		}

		memset(col,0,sizeof(col));

		for(j=topo.size()-1;j>=0;j--){
			i=topo[j];
			if(!col[i]){
				scc.push_back(i);
				dfst(i,i);
			}			
		}

		
		memset(flag,0,sizeof(flag));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));

		for(j=topo.size()-1;j>=0;j--){
			for(i=topo.size()-1;i>=0;i--){
				if(find(topo[i])==find(topo[j])) continue;
				if(mat[topo[j]][topo[i]]==1){
					in[find(topo[i])]++;
					out[find(topo[j])]++;
				}
			}
		}
	
/*
		for(i=0;i<scc.size();i++){
			k=scc[i];
			for(j=0;j<scc.size();j++){
				if(i==j) continue;
				l=scc[j];
				if(mat[k][l]==1){
					out[k]++;
					in[l]++;
				}
			}
		}
*/

		int fl=0;
		k=0; l=0;

		for(i=0;i<scc.size();i++){
			j=scc[i];
			if(in[j]==out[j] && in[j]==1){
				k++;
				//if(in[j]>out[j]&&in[j]-1==out[j]) k++;
			//	else if(in[j]<out[j]&&in[j]+1==out[j]&& find(0)==j) l++;
			//	else k=10;
			}
		}

		if(in[find(0)]||(scc.size()>1&&out[find(0)]!=1)){
			printf("Case %d: NO\n",t++);
		}

		else if(scc.size()<=1 || k==scc.size()-2){
			printf("Case %d: YES\n",t++);
		}
	
		
		else {
			printf("Case %d: NO\n",t++);
		}

		


	}

	return 0;
}

void dfst(int s,int par){

	col[s]=1;
	pre[s]=par;

	int i,j,k,l;

	for(i=0;i<vt[s].size();i++){
		k=vt[s][i];
		if(!col[k]) dfst(k,par);
	}

}

void dfs(int s){

	col[s]=1;

	int i,j,k;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		if(!col[k]) dfs(k);
	}

	topo.push_back(s);

}

