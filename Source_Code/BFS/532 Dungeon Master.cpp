#include<stdio.h>
#include<queue>
using namespace std;

typedef struct{
	int dis;
	int color;
	int row,col,level;
}node;
node ar[50][50][50],temp,nodes[50][50][50];


int a[50][50][50];
int pd[50][50][50];

queue<node>rijul;

void bfs(void);
void set(int l,int r,int c);

int main(){

	int i,j,k,l,r,c,startl,startr,startc,endl,endr,endc;
	char ch,dum[50],dummy;

//	freopen("in.txt","r",stdin);
	

	while(scanf("%d %d %d",&l,&r,&c)==3&&(l||r||c)){

		scanf("%c",&dummy);
		set(l,r,c);
		
		for(i=0;i<l;i++){
			for(j=0;j<r;j++){
	     		for(k=0;k<c;k++){
					scanf("%c",&ch);
					if(ch=='.') a[i][j][k]=1;
					else if(ch=='#') a[i][j][k]=0;
					else if(ch=='S'){
						a[i][j][k]=1;
						startl=i;
						startr=j;
						startc=k;
					}
					else if(ch=='E'){
						a[i][j][k]=1;
						endl=i;
						endr=j;
						endc=k;
					}
				}
				scanf("%c",&dummy);
			}
			gets(dum);
		}

	/*	for(i=0;i<l;i++){
			for(j=0;j<r;j++){
				for(k=0;k<c;k++){
					printf("%d",a[i][j][k]);
				}
				printf("\n");
			}
			printf("\n\n");
		}
*/
		rijul.push(ar[startl][startr][startc]);
		ar[startl][startr][startc].dis=0;

		while(!rijul.empty()){
			temp=rijul.front();
			rijul.pop();
			if(ar[temp.level][temp.row][temp.col].color!=2){
				bfs();
				ar[temp.level][temp.row][temp.col].color=2;
			}
		}
        
		if(ar[endl][endr][endc].dis>0)printf("Escaped in %d minute(s).\n",ar[endl][endr][endc].dis);
		else printf("Trapped!\n");

	}

	return 0;

}

void bfs(void){

	int i,j,k;

	i=temp.level+1;
	j=temp.row;
	k=temp.col;
  
	if(a[i][j][k]==1&&ar[i][j][k].color==0){
		rijul.push(ar[i][j][k]);
		ar[i][j][k].color=1;
		ar[i][j][k].dis=ar[temp.level][temp.row][temp.col].dis+1;
	}

	i=temp.level-1;
	j=temp.row;
	k=temp.col;

	if(i>=0) if(a[i][j][k]==1&&ar[i][j][k].color==0){
		rijul.push(ar[i][j][k]);
		ar[i][j][k].color=1;
		ar[i][j][k].dis=ar[temp.level][temp.row][temp.col].dis+1;
	}

	i=temp.level;
	j=temp.row+1;
	k=temp.col;

	if(a[i][j][k]==1&&ar[i][j][k].color==0){
		rijul.push(ar[i][j][k]);
		ar[i][j][k].color=1;
		ar[i][j][k].dis=ar[temp.level][temp.row][temp.col].dis+1;
	}


	i=temp.level;
	j=temp.row-1;
	k=temp.col;

	if(j>=0)if(a[i][j][k]==1&&ar[i][j][k].color==0){
		rijul.push(ar[i][j][k]);
		ar[i][j][k].color=1;
		ar[i][j][k].dis=ar[temp.level][temp.row][temp.col].dis+1;
	}


	i=temp.level;
	j=temp.row;
	k=temp.col+1;

	if(a[i][j][k]==1&&ar[i][j][k].color==0){
		rijul.push(ar[i][j][k]);
		ar[i][j][k].color=1;
		ar[i][j][k].dis=ar[temp.level][temp.row][temp.col].dis+1;
	}

	i=temp.level;
	j=temp.row;
	k=temp.col-1;

	if(k>=0)
		if(a[i][j][k]==1&&ar[i][j][k].color==0){
		rijul.push(ar[i][j][k]);
		ar[i][j][k].color=1;
		ar[i][j][k].dis=ar[temp.level][temp.row][temp.col].dis+1;
	}

}

void set(int l,int r,int c){

	int i,j,k;

	for(i=0;i<l;i++){
		for(j=0;j<r;j++){
			for(k=0;k<c;k++){
				a[i][j][k]=0;
				ar[i][j][k].dis=0;
				ar[i][j][k].color=0;
				ar[i][j][k].level=i;
				ar[i][j][k].row=j;
				ar[i][j][k].col=k;
			}
				
		}
	}
		
}