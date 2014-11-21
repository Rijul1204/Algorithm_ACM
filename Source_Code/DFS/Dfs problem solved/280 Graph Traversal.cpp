#include<stdio.h>

void set(int n);
void  dfs(int s,int n);
void reset(int n);

int mat[1000][1000],col[1000];

int main(){
	
	int i,j,k,l,n,m,count1;
	int out[1000];

	//freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1){
		if(!n) break;
		reset(n);
		
		while(1){
			scanf("%d",&k);
			if(!k) break;
			
			for(;;){
				scanf("%d",&l) ;
				if(!l) break;
				mat[k][l]=1;
			}
		}
		
		scanf("%d",&m);
		
		for(k=1;k<=m;k++){
			set(n);
			scanf("%d",&i);
			for(j=1;j<=n;j++){
				if(mat[i][j]&&col[j]){
					dfs(j,n);
				}				
			}
			count1=1;
			for(j=1;j<=n;j++){
				if(col[j]){
					out[count1++]=j;
				}
			}
			printf("%d",count1-1);
			for(l=1;l<count1;l++){
				printf(" %d",out[l]);
			}
			printf("\n");
			
			
		}
		
		
		
	}
	
	
	
	return 0;
	
}

void dfs(int s,int n){

	col[s]=0;

	for(int i=1;i<=n;i++){
		if(mat[s][i]&&col[i]){
			dfs(i,n);
		}

	}


}



void set(int n){

	for(int i=0;i<=n;i++) col[i]=1;
}

void reset(int n){

	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			mat[i][j]=0;
		}
	}
}


