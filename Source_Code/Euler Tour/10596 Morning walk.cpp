#include<stdio.h>


int mat[1000][1000];
int in[1000];

int main(){

	int i,j,k,l,n,m;

	while(scanf("%d %d",&n,&m)==2){

		for(i=1;i<=n;i++) in[i]=0;
		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			mat[k][l]=1;
			mat[l][k]=1;
			in[k]++;
			in[l]++;
		}
		if(m<n){
			printf("Not Possible\n");
			continue;
		}
		
        k=1; 
		for(i=1;i<=n;i++){
			if(in[i]%2){
				k=0;
				break;
			}
		}
		if(k) printf("Possible\n");
		else printf("Not Possible\n");

	}


	return 0;
}

