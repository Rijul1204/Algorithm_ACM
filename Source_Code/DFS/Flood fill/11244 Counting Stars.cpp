#include<stdio.h>
#include<string.h>

char grid[1000][1000];
int row,col,color[1000][1000];
int flag[1000][1000];

void flood(int x,int y,int val);


int main(){

	int i,j,k,l;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&row,&col)==2){
		if(!row&&!col) break;
		
		memset(grid,0,sizeof(grid));
		for(i=1;i<=row;i++){
			scanf("%s",grid[i]+1);
		}
		memset(flag,0,sizeof(flag));
		memset(color,0,sizeof(color));

		for(i=1;i<=row;i++){
			for(j=1;j<=col;j++){
				if(grid[i][j]=='*') flood(i,j,1);
			}
			//printf("\n");
		}
		k=0;
		for(i=1;i<=row;i++){
			for(j=1;j<=col;j++){
				if(flag[i][j]) k++;
			}
		}
		printf("%d\n",k);


	}	



	return 0;
}

void flood(int x,int y,int val){

	if(x<=0||y<=0||x>row||y>col) return ;
	if(color[x][y]) return ;
	
	color[x][y]=1;
	
	flag[x][y]=val;

	if(grid[x+1][y]=='*'){
		flag[x][y]=0;
		flood(x+1,y,0);
	}
	else if(grid[x-1][y]=='*'){
		flag[x][y]=0;
		flood(x-1,y,0);
	}
	else if(grid[x-1][y-1]=='*'){
		flag[x][y]=0;
		flood(x-1,y-1,0);
	}
	else if(grid[x][y-1]=='*'){
		flag[x][y]=0;
		flood(x,y-1,0);
	}
	else if(grid[x][y+1]=='*'){
		flag[x][y]=0;
		flood(x,y+1,0);
	}
	else if(grid[x+1][y+1]=='*'){
		flag[x][y]=0;
		flood(x+1,y+1,0);
	}
	else if(grid[x-1][y+1]=='*'){
		flag[x][y]=0;
		flood(x-1,y+1,0);
	}
	else if(grid[x+1][y-1]=='*'){
		flag[x][y]=0;
		flood(x+1,y-1,0);
	}


}