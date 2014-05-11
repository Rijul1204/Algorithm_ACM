#include<stdio.h>
#include<math.h>

#define N 20001000

bool p[N+10];
int prime1[100100];
int prime2[100100];

void buildprime(int n );
void takeprime(int );


int main(){

	int num;

	buildprime(N);
	takeprime(100010);
		
	while(scanf("%d",&num)==1){
		printf("(%d, %d)\n",prime1[num],prime2[num]);
		
	
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

void takeprime(int n){

	int i,j=0;

	for(i=1,j=3;i<=n;j+=2){
		if(p[j]==0&&p[j+2]==0){
			prime1[i]=j;
			prime2[i]=j+2;
			i++;
		}
	}	


}







