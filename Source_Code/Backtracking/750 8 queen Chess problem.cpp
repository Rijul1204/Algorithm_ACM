#include<stdio.h>

int chess[10][10];
int soln[10];
int priority,r,c,high,solnn;

void init();
void backtracking(int count);
void set(int row,int col);
void reset(int row,int col);
void floodleftup(int row,int col,int val);
void floodleftdown(int row,int col,int val);
void floodrightup(int row,int col,int val);
void floodrightdown(int row,int col,int val);

int main(){
	
	int i,j,test,row,col;
	bool flag=false,flag1=false;
    
//	freopen("in.txt","r",stdin);
    
	

	scanf("%d",&test);
//	printf("\n");
	while(test--){
		
		init();
		
	//	if(flag1) printf("\n");
	  //  flag1=true;
		scanf("%d %d",&r,&c);
		
		r--;
		c--;
		
		chess[r][c]=priority;
		set(r,c);
		
		priority--;
		
		soln[c]=r;
		if(flag) printf("\n");
		flag=true;
		
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");


		backtracking(0);
		
	}
	
	return 0;
}

void backtracking(int count){
	
	if(count==8){
		printf("%2d      ",solnn++);
		for(int i=0;i<8;i++){
			if(i>0) printf(" ");
			printf("%d",soln[i]+1);
		}
		printf("\n");
		
		return;
	}
	
	
	for(int i=0;i<=7;i++){
	    
		if(count==c&&r==i){
			soln[c]=r;
			backtracking(count+1);
			//continue;
		}
		
		if(chess[i][count]==0){
			soln[count]=i;
			chess[i][count]=2;
			set(i,count);
			priority--;
			backtracking(count+1);
			priority++;
			reset(i,count);		
			
		}		
		
	}
	
	
}




void init(){
	
	int i,j;
	
	for(i=0;i<=8;i++){
		for(j=0;j<=8;j++){
			chess[i][j]=0;
		}
	}
	
	solnn=1;
	priority=10;
	
}

void set(int row,int col){
	
	int i;
	
	for(i=0;i<8;i++){
		
		if(priority>chess[row][i]) chess[row][i]=priority;
		if(priority>chess[row][i]) chess[i][row]=priority;
		
	}
	
	floodleftup(row-1,col-1,priority);
	floodleftdown(row+1,col-1,priority);
	floodrightup(row-1,col+1,priority);
	floodrightdown(row+1,col+1,priority);
	
}



void floodrightdown(int row,int col,int val){
	
	if(row>7||col>7) return;
	if(priority>=chess[row][col]) chess[row][col]=val;
	floodrightdown(row+1,col+1,val);
}

void floodrightup(int row,int col,int val){
	
	if(row<0||col>7) return;
	if(priority>=chess[row][col])chess[row][col]=val;
	floodrightup(row-1,col+1,val);
}

void floodleftdown(int row,int col,int val){
	
	if(row>7||col<0) return;
	if(priority>=chess[row][col])chess[row][col]=val;
	floodleftdown(row+1,col-1,val);
}

void floodleftup(int row,int col,int val){
	
	if(row<0||col<0) return;
	if(priority>=chess[row][col]) chess[row][col]=val;
	floodleftup(row-1,col-1,val);
}

void reset(int row,int col){
	
	int i;
	
	for(i=0;i<8;i++){
		if(priority==chess[row][i]) chess[row][i]=0;
		if(priority==chess[row][i]) chess[i][row]=0;
	}
	
	floodleftup(row-1,col-1,0);
	floodleftdown(row+1,col-1,0);
	floodrightup(row-1,col+1,0);
	floodrightdown(row+1,col+1,0);
}
