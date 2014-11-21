#include<stdio.h>

#define M 100
#define R 100

int q[M], b[R]={0},prev[R];
int head=0,tail=0,flag=0;

int a[1010][1010];
int n;
void BFS(int s);
void enqueue(int l);
int dequeue( );
void flood(int i,int j);

int main(){

	int i,j,k,l,t=0;
    char help[10];
	char board[100][100];
	while(scanf("%d",&n)&&n){
  
	gets(help);
    t++; 
	for(i=0;i<n;i++){
		scanf("%s",board[i]);
	}
	//adjacency matrix
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(board[i][j]=='w') a[i+1][j+1]=1;
		    else if(board[i][j]=='b') a[i+1][j+1]=2;
		}
	}
	//check for white to win
/*	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
	flag=0;
	for(i=1,j=1;i<=n;i++){		
		if(a[i][j]==1) flood(i,j);
	}
	if(flag==1) {
		printf("%d W\n",t);
		continue;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(a[i][j]==2) a[i][j]=1;
		}
	}
	flag=0;
	for(i=1,j=1;j<=n;j++){		
		if(a[i][j]==1) flood(i,j);
	}
	if(flag==1) {
		printf("%d B\n",t);
		continue;
	}

    }

	
	return 0;
}

void flood(int i,int j){
 	
	if((i<=0)||(j<=0)||i>n||j>n||a[i][j]==0) return ;
	if(j==n) {
	//	printf("you win\n");
		flag=1;
		return ;
	}
	a[i][j]=3;
	if(a[i+1][j]==1) flood(i+1,j);
	if(a[i][j+1]==1) flood(i,j+1);
	if(a[i-1][j]==1) flood(i-1,j);
    if(a[i][j-1]==1) flood(i,j-1);
	if(a[i+1][j+1]==1) flood(i+1,j+1);
	if(a[i-1][j-1]==1) flood(i-1,j-1);
	 
}	

void enqueue(int l)
{
		
	q[tail]=l;
	tail++;
}
int dequeue()
{
	int l;	
	l=q[head];	
	q[head]=0;
	head++;
return l;
}

	

	


