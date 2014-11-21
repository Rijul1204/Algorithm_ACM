#include<stdio.h>

int board[105][105];
int r,c,col[105][105];
int max;

void back(int i,int j,int cnt);
void set(int r,int c);

int main(){

	int i,j,k,l,test;
	char name[1000];

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%s %d %d",name,&r,&c);
		set(r,c);

		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				scanf("%d",&board[i][j]);
			}
		}
		
		max=0;
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				back(i,j,1);
			}
		}

		printf("%s: %d\n",name,max);

	}



	return 0;

}

void back(int i,int j,int cnt){

	col[i][j]=0;	
	if(i>r||j>c||i<1||j<1){
		col[i][j]=1;
		return ;
	}
	if(cnt>max) max=cnt;
	
	
	if(board[i+1][j]>board[i][j]&&col[i+1][j]){
		back(i+1,j,cnt+1);
	}
	if(board[i-1][j]>board[i][j]&&col[i-1][j]){
		back(i-1,j,cnt+1);
	}
	if(board[i][j+1]>board[i][j]&&col[i][j+1]){
		back(i,j+1,cnt+1);
	}
	if(board[i][j-1]>board[i][j]&&col[i][j-1]){
		back(i,j-1,cnt+1);
	}

//	if(col[i+1][j]) back(i+1,j,cnt);
//	if(col[i-1][j]) back(i-1,j,cnt);
//	if(col[i][j+1]) back(i,j+1,cnt);
//	if(col[i][j-1]) back(i,j-1,cnt);


	col[i][j]=1;

}


void set(int r,int c){

	int i,j;

	for(i=0;i<=r+1;i++){
		for(j=0;j<=c+1;j++){
			col[i][j]=1;
			board[i][j]=100000;
		}
	}

}
