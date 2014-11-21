#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

#define maxm 10100

int col[maxm],low[maxm],d[maxm],tim,n;
vector<int>v[maxm];
int dfs(int s);

int main(){
	
	int i,j,k,l,test,t=1,m;
	
	//freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		tim=0;
		
		for(i=0;i<=n;i++) v[i].clear();
	
		memset(col,0,sizeof(col));
		memset(d,0,sizeof(d));
		memset(low,0,sizeof(low));

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			if(!k&&!l) break;
			v[k].push_back(l);
		}
		
		if(!dfs(0)){
			printf("NO\n");
			continue;
		}

		int flag=0;

		for(i=0;i<n;i++) if(!col[i]) flag=1;

		if(flag) printf("NO\n");
		else printf("YES\n");

	}


	return 0;
}


int dfs(int s){

	col[s]=1;
	d[s]=tim;
	low[s]=tim++;

	int count1=0;

	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		if(col[k]==2) return 0;
		if(col[k]==1){
			if(low[s]>d[k]) low[s]=d[k];
			count1++;
			if(count1>1) return 0;
		}
		else if(col[k]==0){
			if(!dfs(k)) return 0;
			if(low[k]>d[s]) return 0;
			if(low[k]<d[s]) count1++;
			if(count1>1) return 0;
			if(low[k]<low[s]){
				low[s]=low[k];
			}
		}
	}

	col[s]=2;
	return 1;

}