#include<stdio.h>
#include<math.h>
#define N 42768

bool p[42768];
int primes[10000];
int goldbach[42768];

void buildprime(int );
void takeprime(int );
void addprime();

int main(){

	int i,j,k,l,test,t=1,num;

	buildprime(42768-100);
	takeprime(N-100);
	addprime();
	scanf("%d",&test);
	while(test--){
	    scanf("%d",&num);
		printf("%d\n",goldbach[num]);
	}

	return 0;
}

void buildprime(int num){

	int i,j;

	int sq=sqrt(double(num));


	p[0]=1;
	p[1]=1;

    for(i=4;i<=num;i+=2){
		p[i]=1;
	}

	for(i=3;i<=sq;i+=2){
		if(p[i]==1) continue;
		for(j=i*i;j<=num;j+=(2*i)){
			p[j]=1;
		}
	}

}

void takeprime(int num){

	int i,j=0;

	for(i=1;i<num;i++){
		if(p[i]==0){
			primes[j++]=i;
			//printf("%d ->",primes[j-1]);
		}
	}
//	printf("j->%d\n",j);

}

void addprime(){

	int i,j,num;

	for(i=0;i<=4450;i++){
		for(j=i;j<=4450;j++){
			num=primes[i]+primes[j];
			if(num<42700) goldbach[num]++;
		}
	}
}













