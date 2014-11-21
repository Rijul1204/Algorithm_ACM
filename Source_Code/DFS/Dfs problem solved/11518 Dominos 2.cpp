#include<stdio.h>
#include<vector>
using namespace std;

vector<int>v[10000];
int col[10000];

void set(int n);
void dfs(int s);


int main(){

	int i,j,k,l,test,n,m,fall;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d %d",&n,&m,&fall);
		set(n);

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
		}

		for(i=1;i<=fall;i++){
			scanf("%d",&j);
			if(col[j]==0) dfs(j);
		}
		int  count1=0;

		for(i=1;i<=n;i++){
			if(col[i]) count1++;
		}

		printf("%d\n",count1);

	}



	return 0;

}

void set(int n){

	for(int i=0;i<=n;i++){
		col[i]=0;
		v[i].clear();
	}

}

void dfs(int s){

	col[s]=1;

	int i,j;

	for(i=0;i<v[s].size();i++){
		if(col[v[s][i]]==0){
			dfs(v[s][i]);
		}
	}

}


