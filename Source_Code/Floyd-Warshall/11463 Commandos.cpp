#include<stdio.h>

#define inf 1000000

int mat[500][500];

void set(int n);
void floyd(int n);

int main(){
	
	int i,j,k,l,s,e,t=1,res,test,n,m;

	//freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d %d",&n,&m);
		set(n);
		
		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			mat[k][l]=mat[l][k]=1;
		}

		floyd(n);

		scanf("%d %d",&s,&e);
		
		res=0;
		int max=-1;

		for(i=0;i<n;i++){
			
			if(max<(mat[s][i]+mat[i][e])){
				max=mat[s][i]+mat[i][e];
				res=max;
			}
		}
		
		printf("Case %d: %d\n",t++,res);
		
		
		
		
	}
	
	return 0;
	
}

void floyd(int n){
	
	int i,j,k,l;
	
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(mat[i][j]>mat[i][k]+mat[k][j]){
					mat[i][j]=mat[i][k]+mat[k][j];
				}
			}
		}
	}
}



void set(int n){
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			mat[i][j]=inf;
			if(i==j) mat[i][j]=0;
		}
	}
	
}

