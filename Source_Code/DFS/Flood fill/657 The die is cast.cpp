#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

void flood(int x,int y);
void flood2(int x,int y);

char s[2999][2999];
int counte,w,h,res[4440];


int main(){

	int i,j,k,l,t=1;
	bool space;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&w,&h)==2){

		if(!w&&!h) break;

		space=false;

		for(i=0;i<h;i++){
			scanf("%s",s[i]);
		}
        k=0;  
	
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(s[i][j]=='*'){
					counte=0;
					flood(i,j);
					res[k++]=counte;
					
				}
			}
		}
		sort(res,res+k);
		printf("Throw %d\n",t++);
		for(i=0;i<k;i++){
			if(space) printf(" ");
			space=true;
			printf("%d",res[i]);
		}
		printf("\n\n");

	}

	return 0;

}

void flood(int x,int y){

	if(s[x][y]=='.') return ;
	
	if(s[x][y]=='X'){
		s[x][y]='.';
		counte++;
		flood2(x,y);
		flood(x,y);
	}
	
	if(s[x][y]=='*') s[x][y]='.';


	if(s[x][y+1]=='*'||s[x][y+1]=='X'&&y+1<w){
		flood(x,y+1);
	}
	if(s[x][y-1]=='*'||s[x][y-1]=='X'&&y>0){
		flood(x,y-1);
	}
	if(s[x+1][y]=='*'||s[x+1][y]=='X'&&x+1<h){
		flood(x+1,y);
	}
	if(s[x-1][y]=='*'||s[x-1][y]=='X'&&x>0){
		flood(x-1,y);
	}
	
}

void flood2(int x,int y){
	
	if(s[x][y]=='*') return ;

	if(s[x][y]=='X') s[x][y]='*';
	
	if(s[x][y+1]=='X'&&y+1<w){
	//	s[x][y]='*';
		flood2(x,y+1);
	}
	if(s[x][y-1]=='X'&&y>0){
		//s[x][y]='*';
		flood2(x,y-1);
	}
	if(s[x+1][y]=='X'&&x+1<h){
	//	s[x][y]='*';
		flood2(x+1,y);
	}
	if(s[x-1][y]=='X'&&x>0){
	//	s[x][y]='*';
		flood2(x-1,y);
	}

}