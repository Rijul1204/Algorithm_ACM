#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 40

vector<int>v[maxm],vt[maxm],topo,scc[maxm];
char s1[5],s2[5],s3[5],s4[5],s5[5],s[5];
int col[maxm],flag[maxm],pre[maxm];
void dfs(int s);
void dfst(int s,int par);

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}


int main(){

	int i,j,k,l,test,n,bl=0;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		if(!n) break;

		for(i=0;i<=30;i++){
			v[i].clear(); vt[i].clear();
			scc[i].clear();
			pre[i]=i;
		}
		topo.clear();
		memset(col,0,sizeof(col));
		memset(flag,0,sizeof(flag));

		for(i=1;i<=n;i++){
			scanf("%s %s %s %s %s %s",s1,s2,s3,s4,s5,s);
			flag[s1[0]-'A']=flag[s2[0]-'A']=flag[s3[0]-'A']=flag[s4[0]-'A']=flag[s5[0]-'A']=flag[s[0]-'A']=1;
			v[s[0]-'A'].push_back(s1[0]-'A');
			v[s[0]-'A'].push_back(s2[0]-'A');
			v[s[0]-'A'].push_back(s3[0]-'A');
			v[s[0]-'A'].push_back(s4[0]-'A');
			v[s[0]-'A'].push_back(s5[0]-'A');
			vt[s1[0]-'A'].push_back(s[0]-'A');
			vt[s2[0]-'A'].push_back(s[0]-'A');
			vt[s3[0]-'A'].push_back(s[0]-'A');
			vt[s4[0]-'A'].push_back(s[0]-'A');
			vt[s5[0]-'A'].push_back(s[0]-'A');
		}

		for(i=0;i<30;i++){
			sort(v[i].begin(),v[i].end());
		}

		for(i=0;i<=30;i++){
			if(flag[i]&&!col[i]){
				dfs(i);
			}
		}

		memset(col,0,sizeof(col));

		for(j=topo.size()-1;j>=0;j--){
			if(!col[topo[j]]){
				dfst(topo[j],topo[j]);
				sort(scc[topo[j]].begin(),scc[topo[j]].end());
			}
		}
		if(bl) printf("\n");
		bl=1;
		memset(col,0,sizeof(col));
		for(i=0;i<=30;i++){
			if(flag[i]){
				if(col[find(i)]==0){
					for(j=0;j<scc[find(i)].size();j++){
						if(j) printf(" ");
						printf("%c",scc[find(i)][j]+'A');
					}
					printf("\n");
					col[find(i)]=1;
				}
			}
		}


	}


	return 0;
}

void dfs(int s){

	col[s]=1;

	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		if(!col[k]) dfs(k);
	}

	topo.push_back(s);
}

void dfst(int s,int par){
	
	
	scc[par].push_back(s);
	pre[s]=par;
	col[s]=1;

	int i,j,k,l;

	for(i=0;i<vt[s].size();i++){
		k=vt[s][i];
		if(!col[k]) dfst(k,par);
	}

}