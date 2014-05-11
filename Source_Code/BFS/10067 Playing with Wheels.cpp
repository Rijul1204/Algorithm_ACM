#include<stdio.h>
#include<queue>
using namespace std;

#define inf 999999999

struct node{
	int u;
	int v;
	int w;
	int x;
};

queue<node>q;

int dis[15][15][15][15],d1,d2,d3,d4;

void set();
void bfs(int a,int b,int c,int d);

int main(){

	int i,j,k,l,test,n,m,a,b,c,d;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		set();
		
		scanf("%d %d %d %d",&a,&b,&c,&d);
		dis[a][b][c][d]=0;
		scanf("%d %d %d %d",&d1,&d2,&d3,&d4);

		scanf("%d",&n);

		for(m=1;m<=n;m++){
			scanf("%d %d %d %d",&i,&j,&k,&l);
			dis[i][j][k][l]=-1;
		}
		
		
		bfs(a,b,c,d);

		if(dis[d1][d2][d3][d4]==inf||dis[d1][d2][d3][d4]==-1){
			printf("-1\n");	
		}
		else printf("%d\n",dis[d1][d2][d3][d4]);

	}

	return 0;

}

void bfs(int a,int b,int c,int d){

	while(!q.empty()) q.pop();
	
	dis[a][b][c][d]=0;

	int i,j,k,l,t;

	node temp,temp1;
	temp.u=a;temp.v=b;temp.w=c;temp.x=d;
	q.push(temp);

	while(!q.empty()){

		temp=q.front(); q.pop();
		i=temp.u;j=temp.v;k=temp.w;l=temp.x;
		//printf("%d %d %d %d\n",i,j,k,l);

		//i+1

		if(dis[(i+1)%10][j][k][l]>dis[i][j][k][l]+1 && dis[(i+1)%10][j][k][l]!=-1){
			temp.u=(i+1)%10;
			temp.v=j;
			temp.w=k;
			temp.x=l;
			
			dis[(i+1)%10][j][k][l]=dis[i][j][k][l]+1;
			q.push(temp);
		}
		// J+1
		if(dis[i][(j+1)%10][k][l]>dis[i][j][k][l]+1 && dis[i][(j+1)%10][k][l]!=-1){
			temp.u=i;
			temp.v=(j+1)%10;
			temp.w=k;
			temp.x=l;
			
			dis[i][(j+1)%10][k][l]=dis[i][j][k][l]+1;
			q.push(temp);
		}
		//K+1
		if(dis[i][j][(k+1)%10][l]>dis[i][j][k][l]+1 && dis[i][j][(k+1)%10][l]!=-1){
			temp.u=i;
			temp.v=j;
			temp.w=(k+1)%10;
			temp.x=l;
			
			dis[i][j][(k+1)%10][l]=dis[i][j][k][l]+1;
			q.push(temp);
		}

		//l+1
		if(dis[i][j][k][(l+1)%10]>dis[i][j][k][l]+1 && dis[i][j][k][(l+1)%10]!=-1){
			temp.u=i;
			temp.v=j;
			temp.w=k;
			temp.x=(l+1)%10;
			
			dis[i][j][k][(l+1)%10]=dis[i][j][k][l]+1;
			q.push(temp);
		}
		//i-1
		if(i==0) t=10;
		else t=i;
		
		if(dis[t-1][j][k][l]>dis[i][j][k][l]+1 && dis[t-1][j][k][l]!=-1){
			temp.u=t-1;
			temp.v=j;
			temp.w=k;
			temp.x=l;
			
			dis[t-1][j][k][l]=dis[i][j][k][l]+1;
			q.push(temp);
		}

		
		//j-1
		if(j==0) t=10;
		else t=j;

		if(dis[i][t-1][k][l]>dis[i][j][k][l]+1 && dis[i][t-1][k][l]!=-1){
			temp.u=i;
			temp.v=t-1;
			temp.w=k;
			temp.x=l;
			
			dis[i][t-1][k][l]=dis[i][j][k][l]+1;
			q.push(temp);
		}
		
		//k-1
		if(k==0) t=10;
		else t=k;
		
		if(dis[i][j][t-1][l]>dis[i][j][k][l]+1 && dis[i][j][t-1][l]!=-1){
			temp.u=i;
			temp.v=j;
			temp.w=t-1;
			temp.x=l;
			
			dis[i][j][t-1][l]=dis[i][j][k][l]+1;
			q.push(temp);
		}
		
		//l-1
		if(l==0) t=10;
		else t=l;	
		
		if(dis[i][j][k][t-1]>dis[i][j][k][l]+1 && dis[i][j][k][t-1]!=-1){
			temp.u=i;
			temp.v=j;
			temp.w=k;
			temp.x=t-1;
			
			dis[i][j][k][t-1]=dis[i][j][k][l]+1;
			q.push(temp);
		}



	}



}


void set(){

	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			for(int k=0;k<=10;k++){
				for(int l=0;l<=10;l++){
					dis[i][j][k][l]=inf;
				}
			}
		}
	}

}


