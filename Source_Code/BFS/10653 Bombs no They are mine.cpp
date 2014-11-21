#include<stdio.h>
#include<queue>
using namespace std;

struct node{
	int i;
	int j;
	int cost;
};



queue<node>q;
int col[1100][1100],dis[1100][1100];
int r,c;

void bfs(node s);

int main(){

	int i,j,k,l;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&r,&c)==2){

		if(!r &&!c) break;

		for(i=0;i<=r;i++){
			for(j=0;j<=c;j++){
				col[i][j]=0;
				dis[i][j]=-1;
			}
		}
		int n,m;

		scanf("%d",&n);

		for(i=1;i<=n;i++){
			scanf("%d %d",&k,&m);
			for(j=1;j<=m;j++){
				scanf("%d",&l);
				col[k][l]=1;
			}
		}

		scanf("%d %d",&k,&l);
		node s;
		s.i=k; s.j=l; s.cost=0;
		dis[k][l]=0;
		bfs(s);
		scanf("%d %d",&k,&l);

		printf("%d\n",dis[k][l]);

		


	}


	return 0;
}

void bfs(node s){

	int i,j,k,l;
	node temp,temp1;
	q.push(s);

	while(!q.empty()){

		temp=q.front(); q.pop();

		i=temp.i; j=temp.j;

		k=i+1;
		l=j;
		if(k<r&&col[k][l]==0){
			if(dis[k][l]==-1){
				temp1.i=k;
			    temp1.j=l;
				dis[k][l]=dis[i][j]+1;
				temp1.cost=dis[k][l];
				q.push(temp1);
			}
			else if(dis[k][l]>dis[i][j]+1){
				temp1.i=k;
			    temp1.j=l;
				dis[k][l]=dis[i][j]+1;
				temp1.cost=dis[k][l];
				q.push(temp1);
			}

		}

		k=i-1;
		l=j;

		if(k>=0&&col[k][l]==0){
			if(dis[k][l]==-1){
				temp1.i=k;
			    temp1.j=l;
				dis[k][l]=dis[i][j]+1;
				temp1.cost=dis[k][l];
				q.push(temp1);
			}
			else if(dis[k][l]>dis[i][j]+1){
				temp1.i=k;
			    temp1.j=l;
				dis[k][l]=dis[i][j]+1;
				temp1.cost=dis[k][l];
				q.push(temp1);
			}

		}

		k=i;
		l=j-1;

		if(l>=0&&col[k][l]==0){
			if(dis[k][l]==-1){
				temp1.i=k;
			    temp1.j=l;
				dis[k][l]=dis[i][j]+1;
				temp1.cost=dis[k][l];
				q.push(temp1);
			}
			else if(dis[k][l]>dis[i][j]+1){
				temp1.i=k;
			    temp1.j=l;
				dis[k][l]=dis[i][j]+1;
				temp1.cost=dis[k][l];
				q.push(temp1);
			}

		}

		k=i;
		l=j+1;

		if(l<c&&col[k][l]==0){
			if(dis[k][l]==-1){
				temp1.i=k;
			    temp1.j=l;
				dis[k][l]=dis[i][j]+1;
				temp1.cost=dis[k][l];
				q.push(temp1);
			}
			else if(dis[k][l]>dis[i][j]+1){
				temp1.i=k;
			    temp1.j=l;
				dis[k][l]=dis[i][j]+1;
				temp1.cost=dis[k][l];
				q.push(temp1);
			}

		}

		

	}



}