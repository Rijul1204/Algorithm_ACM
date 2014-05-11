#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


int mat[5000][5000],row,col;
char s[10000];
int dp[5000][5000],vis[5000][5000];

int run(int r,int c);

int main(){

	int i,j,k,l,i1,test,num,bl=0;
	char temp[1000];

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&row,&col);

		for(i=0;i<=row;i++){
			for(j=0;j<=col;j++){
				mat[i][j]=dp[i][j]=vis[i][j]=0;
			}
		}
		gets(s);

		for(i1=1;i1<=row;i1++){
			gets(s);
			k=-1;
			for(j=0;s[j];j++){
				if(isdigit(s[j])){
					l=0;
					while(isdigit(s[j])){
						temp[l++]=s[j++];
					}
					j--;
					temp[l]='\0';
					if(k==-1) k=atoi(temp);
					else{
						l=atoi(temp);
						mat[k][l]=1;
					}
				}
			}
		}
	//	for(i=1;i<=row;i++){
	//		for(j=1;j<=col;j++){
	//			printf("%2d ",mat[i][j]);
	//		}
	//		printf("\n");
	//	}
        if(bl) printf("\n");
		bl=1;
		printf("%d\n",run(1,1));


	}





	return 0;
}

int run(int r,int c){
	
	if(mat[r][c]==1) return 0;
	if(r>row||c>col) return 0;
	if(r==row&&c==col) return 1;
	if(vis[r][c]==1) return dp[r][c];
	vis[r][c]=1;
	dp[r][c]=run(r+1,c)+run(r,c+1);

	return dp[r][c];	

}