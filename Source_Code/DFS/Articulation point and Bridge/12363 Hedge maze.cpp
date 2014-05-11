#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 10100

vector<int>v[maxm];
int pre[maxm],r,c,q,low[maxm],d[maxm],time,col[maxm];

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}
void dfs(int s,int pre);
void Union(int a,int b){
	if(a!=b){
		pre[a]=b;
	}
}

int main(){

	int i,j,k,l,r,c,q;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d %d",&r,&c,&q)==3){
		
		if(!r&&!c&&!q) break;

		for(i=0;i<=r+5;i++){
			pre[i]=i;
			v[i].clear();
		}

		for(i=1;i<=c;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
			v[l].push_back(k);
		}

		memset(col,0,sizeof(col));
		
		time=0;
		for(i=1;i<=r;i++){
			if(!col[i]) dfs(i,i);
		}

		for(i=1;i<=q;i++){
			scanf("%d %d",&k,&l);
			if(find(k)==find(l)) printf("Y\n");
			else printf("N\n");
		}

		printf("-\n");


	}

	return 0;
}

void dfs(int s,int pre){

	col[s]=1;
	d[s]=time++;
	low[s]=d[s];

	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		if(col[k]==1&&k!=pre){
			if(d[k]<low[s]) low[s]=d[k];
		}
		if(col[k]==0){
			dfs(k,s);
			if(low[k]>d[s]){
				Union(find(k),find(s));
			}
			if(low[k]<low[s]){
				low[s]=low[k];
			}
		}
	}

}