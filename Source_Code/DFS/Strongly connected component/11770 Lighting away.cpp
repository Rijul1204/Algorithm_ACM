#include<stdio.h>
#include<vector>
using namespace std;

vector<int>v[200000],top;

int col[200000];
void set(int n);
void dfs(int s);
void dfs2(int s);

int main(){

	int i,j,k,l,n,m,test,x,y,count,t=1;

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		for(i=0;i<=n;i++){
			v[i].clear();
		}
		top.clear();

		for(i=1;i<=m;i++){
			scanf("%d %d",&x,&y);
			v[x].push_back(y);
		}

		set(n);

		for(i=1;i<=n;i++){
			if(col[i]==0) dfs(i);
		}

		set(n);
		count=0;

		for(i=top.size()-1;i>=0;i--){
			//printf("%d -> ",top[i]);
			if(col[top[i]]==0){
				count++;
				dfs2(top[i]);
			}
		}

		printf("Case %d: %d\n",t++,count);

		

	}

	return 0;

}

void set(int n){

	for(int i=0;i<=n;i++){
		col[i]=0;
	}
}

void dfs(int s){

	col[s]=2;
	int i;

	for(i=0;i<v[s].size();i++){
		if(col[v[s][i]]==0) dfs(v[s][i]);
	}

	top.push_back(s);

}

void dfs2(int s){
	
	col[s]=2;

	for(int i=0;i<v[s].size();i++){
		if(col[v[s][i]]==0) dfs2(v[s][i]);
	}


}












	