#include<stdio.h>

int col[1000],mat[1000][1000],count,n;

void set(int n);
void dfs(int s);

int main(){

	int i,j,k,l,m,max,mark;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)&&n){

		set(n);
		for(i=1;i<=n;i++){
			scanf("%d",&m);
			for(j=1;j<=m;j++){
				scanf("%d",&l);
				mat[i][l]=1;
			}
		}
		max=-1;

		for(i=1;i<=n;i++){
			
			for(j=0;j<=n;j++) col[j]=0;
			
			count=0;
			dfs(i);
			
			if(count>max){
			
				max=count;
				mark=i;
			
			}
			
			
		}
		printf("%d\n",mark);

	}

	return 0;

}


void set(int n){

	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			mat[i][j]=0;
		}
	}

}

void dfs(int s){

	count++;
	col[s]=1;

	int i;

	for(i=1;i<=n;i++){
		if(!col[i]&&mat[s][i]){
			dfs(i);
		}
	}

}





