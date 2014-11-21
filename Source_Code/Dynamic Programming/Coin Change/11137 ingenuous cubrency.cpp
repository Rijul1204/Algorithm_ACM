#include<stdio.h>
#include<math.h>

long long int nway[10000];

int main(){

	int i,j,n,c,coin[50];

	for(i=1;i<=22;i++){
		coin[i]=pow(i,3);
	}
	nway[0]=1;

	for(i=1;i<=21;i++){
		c=coin[i];
		for(j=c;j<=10000;j++){
			nway[j]+=nway[j-c];
		}
	}
	while(scanf("%d",&n)==1){

		printf("%lld\n",nway[n]);
	}

	return 0;

}

	

	

	



