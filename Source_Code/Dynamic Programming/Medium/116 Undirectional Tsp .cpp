#include<stdio.h>

int matrix[50][200];

int max(int a,int b,int c);
int getp1(int a,int b,int c);
int getp2(int a,int b,int c);
int getp(int a,int b,int c);


int main(){

	int i,j,row,col;
	int soln[200],min,mark,pre[50][200];

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&row,&col)==2){

		for(i=1;i<=row;i++){
			for(j=1;j<=col;j++){
				scanf("%d",&matrix[i][j]);
			}
		}

		if(row==1){
			
			min=0;
			for(j=1;j<=col;j++){
				soln[j]=1;
				min+=matrix[1][j];
			}
			for(j=1;j<col;j++){
				printf("%d ",soln[j]);
			}
			printf("%d\n",soln[col]);
			printf("%d\n",min);

			

		}

		else if(col==1){

			min=matrix[1][1];
			mark=1;
			for(i=1;i<=row;i++){
				if(matrix[i][1]<min){
					min=matrix[i][1];
					mark=i;
				}
			}
			soln[1]=mark;

			printf("%d\n",soln[1]);
			printf("%d\n",min);
		}

		else {

			for(j=col-1;j>=1;j--){
				for(i=1;i<=row;i++){
					if(i==1){
						matrix[i][j]+=max(matrix[row][j+1],matrix[i][j+1],matrix[i+1][j+1]);
						pre[i][j]=getp1(matrix[i][j+1],matrix[i+1][j+1],matrix[row][j+1]);
					}
					else if(i==row){
						matrix[i][j]+=max(matrix[1][j+1],matrix[i][j+1],matrix[i-1][j+1]);
						pre[i][j]=getp2(matrix[1][j+1],matrix[i-1][j+1],matrix[i][j+1]);
					}
					else {
						matrix[i][j]+=max(matrix[i-1][j+1],matrix[i][j+1],matrix[i+1][j+1]);
						pre[i][j]=getp(matrix[i-1][j+1],matrix[i][j+1],matrix[i+1][j+1]);
					}
				}
			}

			

			min=matrix[1][1];
			mark=1;

			for(i=1;i<=row;i++){
				if(matrix[i][1]<min){
					min=matrix[i][1];
					mark=i;
				}
			}

			soln[1]=mark;

			for(j=1;j<col;j++){
				if(pre[mark][j]==2){
					mark=mark;
				}
				else if(pre[mark][j]==1){
					mark--;
					if(mark<1) mark=row;
				}
				else if(pre[mark][j]==3){
					mark++;
					if(mark>row) mark=1;
				}
				soln[j+1]=mark;
			}

			for(i=1;i<col;i++){
				printf("%d ",soln[i]);
			}
			printf("%d\n",soln[col]);

			printf("%d\n",min);				

		}

	}

	return 0;

}

int max(int a,int b,int c){

	int max=a;

	if(b<max) max=b;
	if(c<max) max=c;

	return max;

}

int getp(int a,int b,int c){

	int max=a;
	int mark=1;

	if(b<max){
		max=b;
		mark=2;
	}
	if(c<max){
		max=c;
		mark=3;
	}

	return mark;
}

int getp1(int a,int b,int c){

	int max=a;
	int mark=2;

	if(b<max){
		max=b;
		mark=3;
	}
	if(c<max){
		max=c;
		mark=1;
	}

	return mark;
}

int getp2(int a,int b,int c){

	int max=a;
	int mark=3;

	if(b<max){
		max=b;
		mark=1;
	}
	if(c<max){
		max=c;
		mark=2;
	}

	return mark;
}








