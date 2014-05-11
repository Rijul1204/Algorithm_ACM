#include<stdio.h>

long long int com[100][100];

void itgen(int n,int r);

int main(){

	int i,j,l,n,k,t=1;

	com[1][0]=1;
	com[1][1]=1;
	itgen(70,70);

	while(scanf("%d %d",&n,&k)==2){

		if(!n&&!k) break;
	    printf("Case %d: Choco finds %lld way",t++,com[n][k]);
		if(com[n][k]<=1) printf(".\n");
		else printf("s.\n");
	}

	return 0;

}

void itgen(int n,int r){
	int i,j;
	com[0][0]=1;
	com[1][0]=1;
	com[1][1]=1;

	for(i=2;i<n;i++){
		com[i][0]=1;
		for(j=1;j<=i;j++){
			com[i][j]=com[i-1][j]+com[i-1][j-1];
		}
	}

}

