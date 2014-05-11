#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int dix[]={-1,0,1,0};
int diy[]={0,1,0,-1};
int row,col;
char grid[1000][1000];

struct position{
	
	int i,j,c,d,w;
    bool cor;
	position(){}
	position(int x,int y,int C,int D,int W){
		i=x; j=y; c=C; d=D; w=W;
	}
	bool valid(){
		return (i<row&&j<col&&i>=0&&j>=0);
	}
	bool equal(position ob){
		return (i==ob.i&& j==ob.j && c==ob.c);
	}

	position* forward(){
		return new position(i+dix[d],j+diy[d],(c+1)%5,d,w+1);
	}

	position* left(int dir){
		dir--;
		if(dir<0) dir=3;
		return new position(i,j,c,dir,w+1);
	}
	position* right(int dir){
		dir++;
		if(dir>3) dir=0;
		return new position(i,j,c,dir,w+1);
	}
	


};

position start;
position end;
position ans;

queue<position>q;

int flag[1000][1000][10][10];

void BFS(position s);

int main(){

	int i,j,k,l,t=1;
	bool blank=false;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&row,&col)&&row&&col){

		
		for(i=0;i<=row+2;i++){
			for(j=0;j<=col+2;j++){
				for(k=0;k<=7;k++){
					for(l=0;l<=6;l++){
						flag[i][j][k][l]=0;
					}
				}
			}
		}

		for(i=0;i<row;i++){
			scanf("%s",grid[i]);
		}
	

//		ans=NULL;
		ans.cor=false;
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(grid[i][j]=='S'){
					start=position(i,j,0,0,0);
				}
				else if(grid[i][j]=='T'){
					end=position(i,j,0,0,0);
				}
			}
		}

		while(!q.empty()) q.pop();

		BFS(start);
		
		if(blank) printf("\n");
		blank=1;
		printf("Case #%d\n",t++);
		if(ans.cor) printf("minimum time = %d sec\n",ans.w);
		else printf("destination not reachable\n");



	}




	return 0;
}

void BFS(position s){

	q.push(s);

	int i,j,c,d;

	while(!q.empty()){

		position u=q.front(); q.pop();

		i=u.i; j=u.j; c=u.c; d=u.d;
		int dir=d;
	//	printf("%d %d %d %d %c\n",i,j,c,d,grid[i][j]);
		
		if(u.equal(end)){
			ans=u;
			ans.cor=true;
			break;
		}

			
		flag[i][j][c][d]=1;

		position v;

		v=*u.right(dir); i=v.i; j=v.j; c=v.c; d=v.d;
		if(v.valid()&&flag[i][j][c][d]==0&&grid[i][j]!='#'){
			flag[i][j][c][d]=1;
			q.push(v);
		}
		
		v=*u.left(dir); i=v.i; j=v.j; c=v.c; d=v.d;
		if(v.valid()&&flag[i][j][c][d]==0&&grid[i][j]!='#'){
			flag[i][j][c][d]=1;
			q.push(v);
		}
		
		v=*u.forward(); i=v.i; j=v.j; c=v.c; d=v.d;
		if(v.valid()&&flag[i][j][c][d]==0&&grid[i][j]!='#'){
			flag[i][j][c][d]=1;
			q.push(v);
		}
		
	
	}



}