#include<stdio.h>

//long long 
int fact[11000];

void genf();

int main(){

	int i,num;

     genf();

	while(scanf("%d",&num)==1){

		printf("%5d -> %lld\n",num,fact[num]%10);

	}

	return 0;

}

void genf(){

	int i;
	fact[0]=1;

	for(i=1;i<=10000;i++){

		if(!(i%10)){
			fact[i]=fact[i-1]*i;
			fact[i]/=10;
			while(fact[i]%10==0){
				fact[i]/=10;
			}
			continue;
		}
		if(!(i%5)){
			fact[i]=fact[i-1]*i;
			while(fact[i]%10==0){
				fact[i]/=10;
			}
		}
		else {
			fact[i]=fact[i-1]*i;
		}
		while(fact[i]%10==0){
				fact[i]/=10;
		}
		
		if(fact[i]>10000000){
			fact[i]=fact[i]%1000000;
		}

	}

}

		



