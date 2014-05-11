#include<stdio.h>

long long int fibo[80];

void fibonacci(int n);

int main(){

	int n;

	fibo[0]=1;
	fibo[1]=1;
	fibonacci(52);
	
	while(scanf("%d",&n)&&n){
		printf("%lld\n",fibo[n]);
	}

	return 0;

}

void fibonacci(int n){
	if(n==0||n==1) fibo[n]=1;
	else {
		fibonacci(n-1);
		fibo[n]=(fibo[n-1]+fibo[n-2]);
	 }
	
}


