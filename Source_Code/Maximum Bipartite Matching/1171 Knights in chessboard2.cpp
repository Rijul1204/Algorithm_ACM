#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 205
#define maxe 40050

int mark[maxm][maxm],flag[maxm][maxm],r,c,q,left[maxe],right[maxe],col[maxe];
vector<int>v[maxe];

int dir[2][8]={-1,-1,1,1,-2,-2,2,2,-2,2,-2,2,-1,1,-1,1};
int match(int n);
bool dfs(int s);

int main(){
	
	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		memset(flag,0,sizeof(flag));
		memset(mark,0,sizeof(mark));

		scanf("%d %d %d",&r,&c,&q);

		for(i=0;i<=r*c;i++){
			v[i].clear();
		}

		k=1;
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				mark[i][j]=k++;
			}
		}
		for(i=1;i<=q;i++){
			scanf("%d %d",&k,&l);
			flag[k][l]=1;
		}
		int i1=0,j1=0;
		int k1,l1;

		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				k1=mark[i][j];
				if(flag[i][j]) continue;
				for(k=0;k<8;k++){
					i1=i+dir[0][k]; j1=j+dir[1][k];
					if(i1>=1&&j1>=1&&i1<=r&&j1<=c&&flag[i1][j1]==0){
						l1=mark[i1][j1];
						v[k1].push_back(l1);						
					}
				}
			}
		}

		printf("Case %d: %d\n",t++,match(r*c));

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
		for(i=1;i<=n;i++){
			if(right[i]==-1&&dfs(i)) done=0;
		}

	}while(!done);

	k=0;

	for(i=1;i<=n;i++){
		if(right[i]!=-1) k++;
	}

	k/=2;

	return n-k-q;

}

bool dfs(int s){

	if(col[s]) return 0;

	col[s]=1;
	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];

		if(left[k]==-1){
			left[k]=s;
			right[s]=k;
			right[k]=s;
			left[s]=k;
			col[k]=1;
			return true;
		}
	}

	for(i=0;i<v[s].size();i++){
		k=v[s][i];

		if(dfs(left[k])){
			left[k]=s;
			right[s]=k;
			right[k]=s;
			left[s]=k;
			col[k]=1;
			return true;
		}
	}

	return 0;
}