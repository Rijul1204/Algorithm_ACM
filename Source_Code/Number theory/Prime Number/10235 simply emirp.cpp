#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define s 1000110

bool p[s];

void buildprime(int num);

int main(){

	int n,n1;
	char nam[15];
	
	buildprime(s-10);
	
	while(scanf("%d",&n)==1){
		
		if(p[n]==1){
			printf("%d is not prime.\n",n);
			continue;
		}
		
		sprintf(nam,"%d",n);
	
		reverse(nam,nam+strlen(nam));
		n1=atoi(nam);

		
		if((p[n1]==1)||n1==n){
			printf("%d is prime.\n",n);
			continue;
		}
		
		printf("%d is emirp.\n",n);
	
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
