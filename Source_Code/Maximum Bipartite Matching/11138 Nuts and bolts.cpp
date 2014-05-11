#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

int mat[1000][1000];
vector<int>v[1000];
int col[1000],lefts[1000],rights[1000];

bool dfs(int s);
int bipartite(int n);

int main(){

	int i,j,k,l,test,nuts,bolts,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&bolts,&nuts);

		for(i=1;i<=bolts;i++){
			v[i].clear();
			for(j=1;j<=nuts;j++){
				scanf("%d",&mat[i][j]);
				if(mat[i][j]==1){
					v[i].push_back(j);				
				}
			}
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",t++,bipartite(bolts));

	}
	

	return 0;
}



int bipartite(int n){

	int i,j,k,l;
	bool done;
	memset(lefts,-1,sizeof(lefts));
	memset(rights,-1,sizeof(rights));

	do{
		done=true;
		memset(col,0,sizeof(col));
		for(i=1;i<=n;i++){
			if(rights[i]==-1&&dfs(i)) done=false;
		}

	}while(!done);
	
	k=0;
	for(i=1;i<=n;i++) if(rights[i]!=-1) k++; 

	return k;

}

bool dfs(int s){

	if(col[s]) return false;
	col[s]=1;
	int i,j,k,l,t;

	for(i=0;i<v[s].size();i++){
		t=v[s][i];
		if(lefts[t]==-1){
			lefts[t]=s;
			rights[s]=t;
			return true;
		}		
	}

	for(i=0;i<v[s].size();i++){
		t=v[s][i];
		if(dfs(lefts[t])){
			lefts[t]=s;
			rights[s]=t;
			return true;
		}
	}

	return false;

}