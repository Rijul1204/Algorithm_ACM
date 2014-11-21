#include<stdio.h>
#include<queue>
using namespace std;

#define inf 999999

queue<int>q;

int d[10000],mat[1000][1000],col[10000],n;

void set(int n){
	int i,j;

	for(i=0;i<=n;i++){
		d[i]=inf;
		col[i]=0;
		for(j=0;j<=n;j++){
			mat[i][j]=0;
		}
	}
}

void bfs(int s);

int main(){

	int i,j,k,l,m,test,blank=0;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		set(n);

		for(i=0;i<m;i++){
			scanf("%d %d",&k,&l);
			mat[k][l]=mat[l][k]=1;
		}

		bfs(0);

		if(blank) printf("\n");
		blank=1;

		for(i=1;i<n;i++){
			printf("%d\n",d[i]);
		}

	}


}

void bfs(int s){

	d[s]=0;
	q.push(s);
	col[s]=1;
	int i,temp;

	while(!q.empty()){

		temp=q.front();
		col[temp]=2;
		q.pop();
		for(i=1;i<n;i++){
			if(mat[temp][i]&&col[i]==0){
				d[i]=d[temp]+1;
				col[i]=1;
				q.push(i);
			}
		}
	}
}


		

	















