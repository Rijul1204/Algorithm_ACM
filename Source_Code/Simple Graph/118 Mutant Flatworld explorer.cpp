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

int row,col;
int board[1000][1000];

int main(){

	int i,j,k,l,ret,ans,flagdir,e,n,x,y;
	int lost;

	char s1[10000],dir;

	while(scanf("%d %d",&row,&col)==2){

		if(row>col) n=row;
		else n=col;
		for(i=0;i<=50;i++){
			for(j=0;j<=50;j++){
				board[i][j]=0;
			}
		}
			
		while(scanf("%d %d %c",&x,&y,&dir)==3){
			
		    scanf("%s",s1);
			
			if(dir=='W') flagdir=1;
			else if(dir=='N') flagdir=2;
			else if(dir=='E') flagdir=3;
			else if(dir=='S') flagdir=4;

			
			lost=1;
			for(i=0;s1[i];i++){
				if(!lost) break;
				if(s1[i]=='R'){
					flagdir++;
					if(flagdir>4) flagdir=1;					
				}
				else if(s1[i]=='L'){
					flagdir--;
					if(flagdir<1) flagdir=4;
				}
				else if(s1[i]=='F'){
					if(flagdir==1){
						x--;
						if(x<0){
							x++;
							if(board[x][y]==0){
								board[x][y]=1;
								lost=0;
							}
						}

					}
					else if(flagdir==2){
						y++;
						if(y>col){
							y--;
							if(board[x][y]==0){
								board[x][y]=1;
								lost=0;
							}

						}
					}
					else if(flagdir==3){
						x++;
						if(x>row){
							x--;
							if(board[x][y]==0){
								board[x][y]=1;
								lost=0;
							}
						}
					}
					else if(flagdir==4){
						y--;
						if(y<0){
							y++;
							if(board[x][y]==0){
								board[x][y]=1;
								lost=0;
								
							}
						}


					}
					//if(x<0||y<0||x>row||y>col) lost=0;					
				}
			}

			printf("%d %d",x,y);
			if(flagdir==1) printf(" W");
			else if(flagdir==2) printf(" N");
			else if(flagdir==3) printf(" E");
			else if(flagdir==4) printf(" S");

			if(!lost) printf(" LOST\n");
			else printf("\n");



		}



	}


	return 0;

}
