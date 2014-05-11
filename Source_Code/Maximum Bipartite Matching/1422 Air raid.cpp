#include<stdio.h>
#include<vector>
using namespace std;

#define maxm 400

vector<int>v[maxm];
int right[maxm],col[maxm];

int match(int n);
bool dfs(int s);

int main(){

	int i,j,k,l,test,m,n;

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		for(i=0;i<=n;i++) v[i].clear();

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
		}

		printf("%d\n",n-match(n));


	}

	return 0;
}

int match(int n){

	memset(right,-1,sizeof(right));
	memset(col,0,sizeof(col));

	int i,j,k,l;
	
	k=0;
	for(i=1;i<=n;i++){
		memset(col,0,sizeof(col));
		if(dfs(i)) k++;
	}

	return k;
}

bool dfs(int s){

	if(col[s]) return 0;
	col[s]=1;

	int i,j,k;

	for(j=0;j<v[s].size();j++){
		i=v[s][j];
		
		if(right[i]==-1){
			right[i]=s;
			return 1;
		}
		if(dfs(right[i])){
			right[i]=s;
			return 1;
		}

	}
	
	return 0;

}