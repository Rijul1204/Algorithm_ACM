#include<stdio.h>

int sum[200][200],mat[200][200];

int main(){

	int i,j,k,l,n,m;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){

		if(!n&&!m) break;

		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d",&mat[i][j]);
				if(mat[i][j]==1) mat[i][j]=-1111111;
				else mat[i][j]=1;
				sum[i][j]=sum[i-1][j]+mat[i][j];
			}
		}
		int max=0,res;

		for(k=1;k<=n;k++){
			for(i=0;i<=n-k;i++){
				res=0;
				for(j=1;j<=m;j++){
					res+=(sum[i+k][j]-sum[i][j]);
					if(res>max) max=res;
					if(res<0){
						res=0;
					}
				}
				
			}
		}

		printf("%d\n",max);




	}

	return 0;

}

