#include<stdio.h>

int flag[1000][1000],mat[1000][1000],sum[1000];

int main(){

	int i,j,k,l,test,row,col;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&row,&col);

		for(i=0;i<=row;i++){
			for(j=0;j<=row;j++){
				flag[i][j]=0;
				
			}
		}
		int gr=1;


		for(j=0;j<=col;j++) sum[j]=0;

		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				scanf("%d",&mat[i][j]);
				if(mat[i][j])sum[j]++;
			}
					
		}

		for(j=0;j<col;j++){
			if(sum[j]!=2){
				gr=0;
				break;
			}
		}

		if(!gr){
			printf("No\n");
			continue;
		}

		for(j=0;j<col;j++){
			k=-1; l=-1;
			for(i=0;i<row;i++){
				if(mat[i][j]){
					if(k==-1) k=i;
					else l=i;
				}
			}
			if(flag[k][l]==1){
				gr=0;
				break;
			}
			flag[k][l]=flag[l][k]=1;

		}

		if(!gr){
			printf("No\n");
			continue;
		}

		printf("Yes\n");



		
	}


	return 0;
}

