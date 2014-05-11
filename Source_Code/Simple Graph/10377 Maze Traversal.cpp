#include<stdio.h>

#define pi acos(-1.0)
#define inf (1<<28)
#define eps 1e-9
#define area(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define sqr(x) ((x)*(x))
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define spDist(lat1,long1,lat2,long2,r) ( r * acos( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1-long2) ) )
#define isEq(a,b) (fabs(a-b)<eps)
#define  ii __int64


int row,col;

char grid[1000][1000];

int main(){

	int i,j,k,l,ret,ans,flag,e,n,test,flagdir,x,y;
	int blank=0;
	char s[1000],dum;

	scanf("%d",&test);

	while(test--){

		scanf("%d %d%c",&row,&col,&dum);

		for(i=0;i<row;i++){
			gets(grid[i]);
		}
		scanf("%d %d%c",&x,&y,&dum);
		x--;y--;
		flag=0;
		flagdir=1;

		while(1){
			if(flag) break;
			gets(s);
			for(i=0;s[i];i++){
				if(s[i]=='R'){
					flagdir++;
					if(flagdir>4) flagdir=1;
				}
				else if(s[i]=='L'){
					flagdir--;
					if(flagdir<1) flagdir=4;
				}
				else if(s[i]=='F'){
					
					if(flagdir==1){
						if(grid[x-1][y]==' ') x--; 

					}
					else if(flagdir==2){
						if(grid[x][y+1]==' ') y++;
					}
					else if(flagdir==3){
						if(grid[x+1][y]==' ') x++;

					}
					else if(flagdir==4){
						if(grid[x][y-1]==' ') y--;

					}
				}
				else if(s[i]=='Q'){
					flag=1;
					break;
				}

			}

		}
		if(blank) printf("\n");
		blank=1;
		printf("%d %d",x+1,y+1,flagdir);
		if(flagdir==1) printf(" N\n");
		else if(flagdir==2) printf(" E\n");
		else if(flagdir==3) printf(" S\n");
		else if(flagdir==4) printf(" W\n");

	}


	return 0;

}
