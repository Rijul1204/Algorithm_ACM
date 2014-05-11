#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;

#define pi acos(-1.0)
#define inf (1<<28)
#define eps 1e-9
#define area(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define sqr(x) ((x)*(x))
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define spDist(lat1,long1,lat2,long2,r) ( r * acos( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1-long2) ) )
#define isEq(a,b) (fabs(a-b)<eps)
#define  ii __int64

int diru[] = {-1,-1,-1,0,0,1,1,1};
int dirv[] = {-1,0,1,-1,1,-1,0,1};

struct node{
	int x;
	int y;
	int flag;
	int val;
};

queue<node>q;

int row,col;
int color[500][500][4],dist[1000][1000],visit[500][500][4];
char grid[1000][1000];
node source,dest;

void bfs(node s);
void set(int n,int m);

int main(){
	
	int i,j,k,l,ret,ans,test,e,n;

	freopen("in.txt","r",stdin);
	scanf("%d",&test);
	
	
	while(test--){
		
		scanf("%d %d",&row,&col);
		for(i=0;i<row;i++){
			scanf("%s",grid[i]);
		}
		set(row,col);

		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(grid[i][j]=='#'){
					color[i][j][0]=color[i][j][1]=color[i][j][2]=color[i][j][3]=1;
				}
				else if(grid[i][j]=='S'){
					source.x=i;
					source.y=j;
				}
				else if(grid[i][j]=='E'){
					dest.x=i;
					dest.y=j;
				}
			}
			
		}

		bfs(source);
/*
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				printf("%7d ",dist[i][j]);
			}
			printf("\n");
		}

		printf("\n\n");
*/		
	
		if(dist[dest.x][dest.y]!=inf) printf("%d\n",dist[dest.x][dest.y]);
		else printf("NO\n");


	
	}
	
	return 0;
	
}

void set(int n,int m){

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			color[i][j][0]=color[i][j][1]=color[i][j][2]=color[i][j][3]=0;
			dist[i][j]=inf;
		}
	}

}

void bfs(node s){

	int x1=s.x;
	int y1=s.y;
	int x2,y2,i,j,num;
	dist[x1][y1]=0;
	color[x1][y1][1]=0;
	s.flag=3;
	s.val=0;
	int step;
	q.push(s);

	while(!q.empty()){
	
		node temp=q.front();q.pop(); 
		if(temp.flag==3) step=1; else if(temp.flag==1) step=2; else if(temp.flag==2) step=3;
		x1=temp.x;y1=temp.y;num=temp.val;

		//if(color[x1][y1][step]==1) continue;

		//down....
		x2=x1+step;y2=y1;
		if(x2<row){
			int flag=0;
			for(i=x1;i<=x2;i++) if(grid[i][y2]=='#') flag=1;
			if(flag==0&&color[x2][y2][step]==0){
				
				if(dist[x2][y2]>num+1) dist[x2][y2]=num+1;
				color[x2][y2][step]=1;
				temp.x=x2;temp.y=y2;temp.flag=step;temp.val=num+1;
				q.push(temp);
			}
		}	

		//up....
		x2=x1-step;y2=y1;
		if(x2>=0){
			int flag=0;
		//	if(x2==0&&y2==5){
		//		printf("aase\n");
		//	}
			for(i=x1;i>=x2;i--){
				if(grid[i][y2]=='#') flag=1;
			}
			if(flag==0&&color[x2][y2][step]==0){
				
				if(dist[x2][y2]>num+1) dist[x2][y2]=num+1;
				color[x2][y2][step]=1;
				temp.x=x2;temp.y=y2;temp.flag=step;temp.val=num+1;
				q.push(temp);
			} 

		}
		//right....
		y2=y1+step;x2=x1;
		
		if(y2<col){
			int flag=0;
			for(i=y1;i<=y2;i++) if(grid[x2][i]=='#') flag=1;
			if(flag==0&&color[x2][y2][step]==0){
				
				if(dist[x2][y2]>num+1) dist[x2][y2]=num+1;
				color[x2][y2][step]=1;
				temp.x=x2;temp.y=y2;temp.flag=step;temp.val=num+1;
				q.push(temp);
			} 

		}
		//left
		y2=y1-step;x2=x1;

		if(y2>=0){
			int flag=0;
			for(i=y1;i>=y2;i--) if(grid[x2][i]=='#') flag=1;
			if(flag==0&&color[x2][y2][step]==0){
				
				if(dist[x2][y2]>num+1) dist[x2][y2]=num+1;
				color[x2][y2][step]=1;
				temp.x=x2;temp.y=y2;temp.flag=step;temp.val=num+1;
				q.push(temp);
			}


		}

		color[x1][y1][step]==1;




	}




}
