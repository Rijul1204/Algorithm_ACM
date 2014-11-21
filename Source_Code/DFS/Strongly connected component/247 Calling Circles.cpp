#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

map<string,int>name;
map<int,string>name1;

vector<int>v[10000];
vector<int>vt[10000];
vector<int>topo;
int col[10000];

void set(int n);
void dfs(int n);
void dfst(int n);


int main(){

	int i,j,k,l,mark,n,m,blank=0,t=1;
	char s1[11000],s2[11000];

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){
		if(!n&&!m) break;
		mark=1;
		for(i=1;i<=n;i++){
			v[i].clear();
			vt[i].clear();

		}
		topo.clear(); name.clear();name1.clear();
		set(n);
		for(i=1;i<=m;i++){
			scanf("%s %s",s1,s2);
			if(!name[s1]){
				name1[mark]=s1;
				name[s1]=mark++;
			}
			if(!name[s2]){
				name1[mark]=s2;
				name[s2]=mark++;
			}
			v[name[s1]].push_back(name[s2]);
			vt[name[s2]].push_back(name[s1]);
		}
		for(i=1;i<=n;i++){
			if(!col[i]) dfs(i);
		}
		if(blank) printf("\n");
		blank=1;
		printf("Calling circles for data set %d:\n",t++);

		for(i=topo.size()-1;i>=0;i--){
			if(col[topo[i]]){
				cout<<name1[topo[i]];
				dfst(topo[i]);
			    printf("\n");
			}
		}

	}

	return 0;
}

void set(int n){

	for(int i=0;i<=n;i++) col[i]=0;
}

void dfs(int s){

	col[s]=1;

	for(int i=0;i<v[s].size();i++){
		if(!col[v[s][i]]) dfs(v[s][i]);
	}

	topo.push_back(s);

}

void dfst(int s){

	col[s]=0;
	
	for(int i=0;i<vt[s].size();i++){
		if(col[vt[s][i]]){
			cout<<", "<<name1[vt[s][i]];
			dfst(vt[s][i]);
		}
	}

}




