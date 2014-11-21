#include<stdio.h>
#include<queue>
using namespace std;

struct node{
	int i;
	int j;
};

char grid[100][100];
queue<node>q;
int row,col,n,time;
int dis[100][100],flag[100][100];

void bfs(node s);

int main(){

	int i,j,k,l;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d %d",&row,&col,&n)==3){

		if(!row&&!col&&!n) break;

		for(i=0;i<=row;i++){
			for(j=0;j<=col;j++){
				dis[i][j]=0;
				flag[i][j]=0;
			}
		}

		for(i=0;i<row;i++){
			scanf("%s",grid[i]);
		}

		node temp;
		temp.i=0;
		temp.j=n-1;
		time=1;
		bfs(temp);

	}

	return 0;
}

void bfs(node s){

	dis[s.i][s.j]=time++;
	int i,j,k,l;
	node temp,temp1;

	q.push(s);

	while(!q.empty()){
		temp=q.front(); q.pop();
		flag[temp.i][temp.j]=1;
		i=temp.i; j=temp.j;
		
		if(grid[i][j]=='N') i--;
		else if(grid[i][j]=='S') i++;
		else if(grid[i][j]=='E') j++;
		else if(grid[i][j]=='W') j--;

		if(i<0||j<0||i>=row||j>=col){
			printf("%d step(s) to exit\n",time-1);
		}
		else if(flag[i][j]==1){
			printf("%d step(s) before a loop of %d step(s)\n",dis[i][j]-1,dis[temp.i][temp.j]-dis[i][j]+1);
		}
		else{
			dis[i][j]=time++;
			temp1.i=i; temp1.j=j;
			q.push(temp1);
		}

	}


}