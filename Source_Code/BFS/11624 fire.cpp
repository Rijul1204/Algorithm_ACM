#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

#define inf 12345678

struct node{
	int i;
	int j;
};

int dis[2000][2000],col[2000][2000],disf[2000][2000],perm[2000][2000];
int row,colo;
char grid[2000][2000];

void bfs(node s);
void bfsf();
void assign();
void set(){
	for(int i=0;i<=row;i++){
		for(int j=0;j<=colo;j++){
			col[i][j]=0;
		}
	}
}

queue<node>q;

int main(){

	int i,j,k,l,test;
	node joe,fire;
	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&row,&colo);

		//memset(col,0,sizeof(col));
		
		for(i=0;i<=row;i++){
			for(j=0;j<=colo;j++){
				dis[i][j]=inf;
				disf[i][j]=inf;
				perm[i][j]=inf;
			}
		}
		
		for(i=1;i<=row;i++){
			scanf("%s",grid[i]+1);
		}		
	
		for(i=1;i<=row;i++){
			for(j=1;j<=colo;j++){
				if(grid[i][j]=='J'){
					joe.i=i;
					joe.j=j;

				}
				//if(grid[i][j]=='F'){
				//	fire.i=i;
				//	fire.j=j;
				//	set();
		            
				//	assign();
				//	grid[i][j]='.';
			//	}
			}
		}
		
		set();
		bfs(joe);
		set();
		bfsf();

//		for(i=1;i<=row;i++){
//			for(j=1;j<=colo;j++){
				//printf("%d %d",dis[i][j],perm[i][j]);
//			}
//			printf("\n");
//		}
		
		int mini=inf;
		for(i=1;i<=row;i++){
			if(grid[i][1]!='#'){
				if(dis[i][1]<disf[i][1]){
					if(dis[i][1]<mini) mini=dis[i][1];
				}

			}
			j=colo;
			if(grid[i][colo]!='#'){
				
				if(dis[i][j]<disf[i][j]){
					if(dis[i][j]<mini) mini=dis[i][j];
				}
			}
		}
		for(j=1;j<=colo;j++){
			i=1;
			if(grid[1][j]!='#'){
				if(dis[i][j]<disf[i][j]){
					if(dis[i][j]<mini) mini=dis[i][j];
				}

			}
			i=row;
			if(grid[row][j]!='#'){
				if(dis[i][j]<disf[i][j]){
					if(dis[i][j]<mini) mini=dis[i][j];
				}
			}

		}

		if(mini==inf) printf("IMPOSSIBLE\n");
		else printf("%d\n",mini+1);

	}


	return 0;
}



void bfs(node s){

	dis[s.i][s.j]=0;
	int i,j,k,l;
	q.push(s);
	col[s.i][s.j]=1;
	node temp,temp1;

	while(!q.empty()){
		temp=q.front();
		q.pop();
		i=temp.i; j=temp.j;

		// up..........
		k=i-1;
		l=j;
		if(k>0&&grid[k][l]!='#'&&col[k][l]==0){
			temp1.i=k;
			temp1.j=l;
			col[k][l]=1;
			dis[k][l]=dis[i][j]+1;
			q.push(temp1);
		}
		//down...........
		k=i+1;
		l=j;
		if(k<=row&&grid[k][l]!='#'&&col[k][l]==0){
			temp1.i=k;
			temp1.j=l;
			col[k][l]=1;
			dis[k][l]=dis[i][j]+1;
			q.push(temp1);
		}
		// left.........
		k=i;
		l=j-1;
		if(l>0&&grid[k][l]!='#'&&col[k][l]==0){
			temp1.i=k;
			temp1.j=l;
			col[k][l]=1;
			dis[k][l]=dis[i][j]+1;
			q.push(temp1);
		}
		//right.........
		k=i;
		l=j+1;
		if(l<=colo&&grid[k][l]!='#'&&col[k][l]==0){
			temp1.i=k;
			temp1.j=l;
			col[k][l]=1;
			dis[k][l]=dis[i][j]+1;
			q.push(temp1);
		}	


	}

}

void bfsf(){

	node fire,s;
    int i,j,k,l;	
	node temp,temp1;
	
	for(i=1;i<=row;i++){
		for(j=1;j<=colo;j++){
			if(grid[i][j]=='F'){
				s.i=i;
				s.j=j;
				disf[s.i][s.j]=0;
				col[s.i][s.j]=1;
				q.push(s);
			}	
		}
	}



	while(!q.empty()){
		temp=q.front();
		q.pop();
		i=temp.i; j=temp.j;

		// up..........
		k=i-1;
		l=j;
		if(k>0&&grid[k][l]!='#'&&col[k][l]==0){
			temp1.i=k;
			temp1.j=l;
			col[k][l]=1;
			if(disf[k][l]>disf[i][j]+1) disf[k][l]=disf[i][j]+1;
			q.push(temp1);
		}
		//down...........
		k=i+1;
		l=j;
		if(k<=row&&grid[k][l]!='#'&&col[k][l]==0){
			temp1.i=k;
			temp1.j=l;
			col[k][l]=1;
			if(disf[k][l]>disf[i][j]+1) disf[k][l]=disf[i][j]+1;
			q.push(temp1);
		}
		// left.........
		k=i;
		l=j-1;
		if(l>0&&grid[k][l]!='#'&&col[k][l]==0){
			temp1.i=k;
			temp1.j=l;
			col[k][l]=1;
			if(disf[k][l]>disf[i][j]+1) disf[k][l]=disf[i][j]+1;
			q.push(temp1);
		}
		//right.........
		k=i;
		l=j+1;
		if(l<=colo&&grid[k][l]!='#'&&col[k][l]==0){
			temp1.i=k;
			temp1.j=l;
			col[k][l]=1;
			if(disf[k][l]>disf[i][j]+1) disf[k][l]=disf[i][j]+1;
			q.push(temp1);
		}	


	}

}