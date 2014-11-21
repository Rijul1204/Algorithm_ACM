#include<stdio.h>
#include<queue>
#include<map>
#include <bitset>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;
 
map<string,int>my;
vector<int>v[2000],vt[2000],topo;

int col[2000];

void set(int n);
void dfs1(int s);
void dfs2(int s);


int main(){

	int i,j,k,l,n,m;

	//freopen("in.txt","r",stdin);
	

	char s[1000],s1[1000];

	while(scanf("%d %d",&n,&m)==2){

		if(!n&&!m) break;
		
		my.clear();
		getchar();

		for(i=1;i<=n;i++){
			v[i].clear();
			vt[i].clear();
			gets(s);
			my[s]=i;
		}

		topo.clear();

		for(i=1;i<=m;i++){
			gets(s);
			gets(s1);
			v[my[s]].push_back(my[s1]);
			vt[my[s1]].push_back(my[s]);
		}
		set(n);

		for(i=1;i<=n;i++){
			if(!col[i]) dfs1(i);
		}
		int count1=0;

		for(i=topo.size()-1;i>=0;i--){
			//printf("topo[i]-> %d\n",topo[i]);
			if(col[topo[i]]){
				count1++;
				dfs2(topo[i]);
			}
		}

		printf("%d\n",count1);

  


	}
	

	return 0;

}

void dfs1(int s){

	col[s]=1;

	for(int i=0;i<v[s].size();i++){
		if(!col[v[s][i]]) dfs1(v[s][i]);
	}

	topo.push_back(s);

}


void dfs2(int s){

	col[s]=0;

	for(int i=0;i<vt[s].size();i++){
		if(col[vt[s][i]]) dfs2(vt[s][i]);
	}	

}



void set(int n){

	for(int i=0;i<=n;i++){
		col[i]=0;
		
	}
}
