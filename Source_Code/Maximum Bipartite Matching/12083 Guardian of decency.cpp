#include<stdio.h>
#include<vector>
#include<string.h>
#include<string>
#include<map>
using namespace std;

#define maxm 600
#define maxl 150

vector<int>v[maxm];
int age[maxm],col[maxm],lefts[maxm],rights[maxm];
char music[maxm][maxl],sport[maxm][maxl],sex[maxm][maxl];

int match(int n);
bool dfs(int s);

int main(){

	int i,j,k,l,test,t=1,n;

//freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=0;i<=n+10;i++){
			v[i].clear();
		}

		for(i=1;i<=n;i++){
			scanf("%d %s %s %s",&age[i],sex[i],music[i],sport[i]);
		}

		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				k=age[i]-age[j];
				if(k<0) k*=-1;
				if(k>40) continue;
				if(strcmp(sex[i],sex[j])==0) continue;
				if(strcmp(sport[i],sport[j])==0) continue;
				if(strcmp(music[i],music[j])!=0) continue;
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}

		printf("%d\n",n-match(n));

	}


	return 0;
}

int match(int n){

	memset(lefts,-1,sizeof(lefts));
	memset(rights,-1,sizeof(rights));

	int i,j,k,l,done;

	do{

		done=1;
		
		memset(col,0,sizeof(col));
		
		for(i=1;i<=n;i++){
			if(rights[i]==-1&&dfs(i)) done=0;		
		}

	}while(!done);

	k=0;

	for(i=1;i<=n;i++){
		if(rights[i]!=-1) k++;
	}

	return k/2;

}

bool dfs(int s){

	if(col[s]) return false;
	col[s]=1;

	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];

		if(lefts[k]==-1) {
			lefts[k]=s;
			rights[s]=k;
			rights[k]=s;
			lefts[s]=k;
			col[k]=1;
			return 1;
		}
		if(dfs(lefts[k])){
			lefts[k]=s;
			rights[s]=k;
			rights[k]=s;
			lefts[s]=k;
			col[k]=1;
			return 1;
		}

	}

	return 0;

}