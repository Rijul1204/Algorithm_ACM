#include<stdio.h>

char board[30][30];
int count,n;

void flood(int x,int y);

int main(){

	int i,j,k,l,test=0;
    char dum;

	while(scanf("%d",&n)==1){
        
		count=0;

		for(i=0;i<n;i++){
			scanf("%s%c",board[i],&dum);
		}
        
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(board[i][j]=='1'){
					count++;
					flood(i,j);
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n",++test,count);

	}

	return 0;
}

void flood(int x,int y){

	if(board[x][y]=='1'){
		board[x][y]='0';
		if((x+1<n)){
			if(board[x+1][y]=='1') flood(x+1,y);
		}
		if(y+1<n){
			if(board[x][y+1]=='1') flood(x,y+1);
		}
		if((x-1>=0)){
			if(board[x-1][y]=='1') flood(x-1,y);
		}
		if((y-1>=0)){
			if(board[x][y-1]=='1') flood(x,y-1);
		}
		if((x+1<n)&&(y+1<n)){
			if(board[x+1][y+1]=='1') flood(x+1,y+1);
		}
		if((x+1<n)&&(y-1>=0)){
			if(board[x+1][y-1]=='1') flood(x+1,y-1);
		}
		if((x-1>=0)&&(y+1<n)){
			if(board[x-1][y+1]=='1') flood(x-1,y+1);
		}
		if((x-1>=0)&&(y-1>=0)){
			if(board[x-1][y-1]=='1') flood(x-1,y-1);
		}



	}
}







	

	