#include<stdio.h>

int sq[20][20];
int sum,n,num;

int main(){

	int i,j,k,l=0;

	while(scanf("%d",&n)==1){
		
		for(i=0;i<=n;i++){
			for(j=0;j<=n;j++){
				sq[i][j]=0;
			}
		}
		
		sum=0;
		num=1;
        i=1;
		j=n/2;
		j++;
		while(num<=(n*n)){
			sq[i][j]=num++;
			
			i--;
			j++;
			if(i<1) i=n;
			if(j>n) j=1;

			if(sq[i][j]!=0){
				if(i==n) i=1;
				else i++;
				if(j==1) j=n;
				else j--;
				i++;			
			}
		}
		if(l) printf("\n");
		l=1;
		for(i=1;i<=n;i++) sum+=sq[i][1];
		printf("n=%d, sum=%d\n",n,sum);
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(n<4) printf(" %d",sq[i][j]);
				else if(n<10) printf(" %2d",sq[i][j]);
				else printf(" %3d",sq[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}