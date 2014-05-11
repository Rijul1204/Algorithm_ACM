#include<stdio.h>
#include<math.h>

#define maxm 1000100


bool p[maxm+5];


void gen(int n);

int main(){

	int i,j,k,l,n,flag;

//	freopen("in.txt","r",stdin);

	gen(maxm-10);

	while(scanf("%d",&n)&&n){

		printf("%d:\n",n);
		flag=0;

		if(n%2) k=n-2;
		else k=n-1;

		if(p[n-2]==0){
			printf("%d+%d\n",2,n-2);
			flag=1;
		}

		while(n-k<=k){
			if(flag) break;
			if(!p[k]&&!p[n-k]){
				printf("%d+%d\n",n-k,k);
				flag=1;
				break;
			}
			k-=2;
		}

		if(!flag) printf("NO WAY!\n");
		


	}	


	return 0;
}


void gen(int n){

	int i,j,k,l;
	int sq;
	sq=sqrt(n);

	p[0]=p[1]=1;
	
	for(i=4;i<=n;i+=2) p[i]=1;

	for(i=3;i<=sq;i++){
		if(p[i]) continue;
		for(j=i*i;j<=n;j+=2*i){
			p[j]=1;
		}
	}

}