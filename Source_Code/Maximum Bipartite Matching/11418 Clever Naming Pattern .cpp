#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

struct node{
	char lets[50][1000];
	int flag[30];
};
node nodes[100];

map<string,int>name;
vector<int>v[1000];
int lefts[100],rights[100],col[100];
char temp[10000];
void match(int n);
bool dfs(int s);

int main(){

	int i,j,k,l,test,t=1,n;
	
	
	//freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			for(j=1;j<=k;j++){
				scanf("%s",temp);
				if(temp[0]>='a') temp[0]=temp[0]-('a'-'A');
				nodes[i].flag[temp[0]-'A'+1];
				strcpy(nodes[i].lets[temp[0]-'A'+1],temp);
				v[temp[0]-'A'+1].push_back(i);
			}
		}

		match(n);
		printf("Case #%d:\n",t++);
		for(i=1;i<=n;i++){
			strcpy(temp,nodes[rights[i]].lets[i]);
			for(j=0;temp[j];j++){
				if(j>0) if(temp[j]<'a') temp[j]=temp[j]+('a'-'A');
				//printf("%s\n",nodes[rights[i]].lets[i]);
				printf("%c",temp[j]);
			}
			printf("\n");
		}
	}

	return 0;
}

void match(int n){

	memset(lefts,-1,sizeof(lefts));
	memset(rights,-1,sizeof(rights));
	int i,j,l,done;

	do{
		done=1;
		memset(col,0,sizeof(col));
		for(i=1;i<=n;i++){
	    	if(rights[i]==-1&&dfs(i)) done=0;
		}
	}while(!done);


}

bool dfs(int s){

	if(col[s]) return false;
	col[s]=1;
	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		j=v[s][i];
		if(lefts[j]==-1){
			lefts[j]=s;
			rights[s]=j;
			return true;
		}
		else if(dfs(lefts[j])){
			lefts[j]=s;
			rights[s]=j;
			return true;
		}

	}
	
	return false;
}