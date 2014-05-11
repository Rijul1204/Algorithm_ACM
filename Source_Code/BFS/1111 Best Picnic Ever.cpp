#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

int mat[1200][1200],s[1200],col[1200],n,m,k,flag[1200];
vector<int>v[1200];
queue<int>q;

void bfs(int s);
void set(int n);
void reset(int n);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d %d",&k,&n,&m);
		for(i=1;i<=k;i++){
			scanf("%d",&s[i]);
		}
		reset(n);
		for(i=1;i<=m;i++){
			scanf("%d %d",&j,&l);
			mat[j][l]=1;
			v[j].push_back(l);
		}

		for(i=1;i<=k;i++){
			set(n);
			bfs(s[i]);
			for(l=1;l<=n;l++){
				if(s[i]==l) continue;
				if(mat[s[i]][l]==0) flag[l]=0;
			}
		}

		k=0;
		
		for(i=1;i<=n;i++){
			if(flag[i]==1) k++;
		}
		printf("Case %d: %d\n",t++,k);
		
	}


	return 0;
}
void reset(int n){

	for(int i=0;i<=n;i++){
		flag[i]=1;
		v[i].clear();
		for(int j=0;j<=n;j++){
			mat[i][j]=0;
		}
	}
}

void set(int n){

	int i,j;

	for(i=0;i<=n;i++){
		col[i]=0;
	}

}

void bfs(int s){

	int i,j,k,l;

	q.push(s);
	col[s]=1;

	while(!q.empty()){

		i=q.front(); q.pop();

		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(col[k]==0){
				mat[s][k]=1;
				col[k]=1;
				q.push(k);
			}
		}

	}

}