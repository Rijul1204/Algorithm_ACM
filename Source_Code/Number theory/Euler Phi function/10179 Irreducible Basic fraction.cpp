#include<stdio.h>
#include<math.h>

double geteuler(long long int n);

int main(){

	long long int i,n;

	while(scanf("%lld",&n)&&n){
        if(n<=1){
			printf("0\n");
			continue;
		}
		
		printf("%.0lf\n",geteuler(n));
	}

	return 0;

}

double geteuler(long long int n){

	double num=n;
	long long int sq=sqrt(num);
	double result=num;
	double temp;

	if(!(n%2)){
		result*=.5;
		while(n%2==0) n/=2; 
	}

	for(long long int i=3;i<=sq;i+=2){
		if(!(n%i)){
			temp=i;
			result*=((temp-1)/temp);
			while(!(n%i)) n/=i;
		}
	}
	if(n!=1){
		temp=n;
		result*=((temp-1)/temp);
	}

	return result;

}













