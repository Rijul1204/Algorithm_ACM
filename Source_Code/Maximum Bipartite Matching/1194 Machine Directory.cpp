#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

#define maxm 110

vector<int>v[maxm];
int col[maxm],left[maxm],right[maxm],n,m,tot;

int match(int n);
bool dfs(int s);

int main(){
	
	int i,j,k,l,test;
	
	//freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1){
		if(!n) break;
		
		for(i=0;i<=n;i++){
			v[i].clear();
		}
		
		scanf("%d %d",&m,&tot);
		
		for(i=1;i<=tot;i++){
			scanf("%d %d %d",&j,&k,&l);
			if(!k||!l) continue;
			v[k].push_back(l);
		}
		
		printf("%d\n",match(n));
		
	}
	
	
	return 0;
}

int match(int n){
	
	memset(left,-1,sizeof(left));
	memset(right,-1,sizeof(right));
	
	int i,j,k,l,done;
	
	do{
		
		done=1;
		memset(col,0,sizeof(col));
		
		for(i=1;i<n;i++){
			if(right[i]==-1&&dfs(i)){
				done=0;
			}
		}
		
	}while(!done);
	
	k=0;
	
	for(i=1;i<n;i++){
		if(right[i]!=-1) k++;
	}
	
	return k;
}


bool dfs(int s){
	
	if(col[s]) return false;
	
	col[s]=1;
	
	int i,j,k,l;
	
	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		
		if(left[k]==-1){
			left[k]=s;
			right[s]=k;
			return true;
		}
		
		
	}
	
	for(i=0;i<v[s].size();i++){
		k=v[s][i];		
		
		if(dfs(left[k])){
			left[k]=s;
			right[s]=k;
			return true;
		}
		
	}
	
	return false;
}