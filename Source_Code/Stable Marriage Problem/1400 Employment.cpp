/*
Author  : Rashedul Hasan Rijul.
Problem : Loj 1400 ( Employment).
Algo    : Stable Marriage problem.
*/

#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

#define maxm 250

vector<int>v[maxm];
int left[maxm],right[maxm],mat[maxm][maxm],matt[maxm][maxm],n,col[maxm];
// mat=left matrix , matt= right matrix ..
void match(int n);
bool dfs(int s);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=0;i<=n;i++){
			v[i].clear();
		}

		for(i=1;i<=n;i++){
			for(l=1;l<=n;l++){
				scanf("%d",&j);
				v[i].push_back(j);
				mat[i][j]=l;
			}
		}

		for(i=n+1;i<=2*n;i++){
			for(l=1;l<=n;l++){
				scanf("%d",&j);
				matt[i][j]=l;
			}
		}
		printf("Case %d:",t++);
		match(n);


	}

	return 0;
}

void match(int n){

	memset(col,0,sizeof(col));
	memset(left,-1,sizeof(left));
	memset(right,-1,sizeof(right));

	int i,j,k,done;


	do{
		memset(col,0,sizeof(col));
		done=1;

		for(i=1;i<=n;i++){
			if(right[i]==-1&&dfs(i)) done=0;
		}

	}while(!done);

	for(i=1;i<=n;i++){
		printf(" (%d %d)",i,right[i]);
	}
	printf("\n");


}

bool dfs(int s){

	if(col[s]) return 0;
	col[s]=1;

	int i,j,k;

	for(j=0;j<v[s].size();j++){

		i=v[s][j];

		if(left[i]==-1){
			left[i]=s;
			right[s]=i;
			return 1;
		}

		else{
			k=left[i];
			if(matt[i][k]>matt[i][s]){
				right[k]=-1;
				right[s]=i;
				left[i]=s;
				return 1;
			}
		}

	}

	return 0;
}
