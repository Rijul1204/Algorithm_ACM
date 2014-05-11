#include<stdio.h>
#include<math.h>

#define maxm 1200000

bool p[maxm+20];
int euler[11000],correct[11000];
int prime[maxm],sqr,count1;

void gen(int n);
void geneuler(int n);
void takeprime(int n);
bool check(int n);

int main(){

	int i,j,k,l,a,b;

	gen(maxm+5);
	takeprime(maxm+5);
	geneuler(10000+5);

	//printf("%d %d\n",count1,prime[0]);


	while(scanf("%d %d",&a,&b)==2){
		
		int sum1=0;
		int sum2=0;
		for(i=a;i<=b;i++){
			if(correct[i]) sum2++;			
		}

		double ans;
		sum1=b-a+1;

		ans=(double)((double)sum2/(double)sum1);
		ans*=100.0;
		ans+=.000000001;

		printf("%.2lf\n",ans);


	}


	return 0;
}

void gen(int n){

	int i,j,k,l;

	int sq=sqrt(n);
	sqr=sq;

	p[0]=p[1]=1;

	for(i=4;i<=n;i+=2) p[i]=1;

	for(i=3;i<=sq;i++){
		if(p[i]) continue;
		for(j=i*i;j<=n;j+=2*i){
			p[j]=1;
		}
	}

}

void geneuler(int n){

	int i,j,k,l;

	for(i=0;i<=n;i++){
		euler[i]=i*i+i+41;
		if(check(euler[i])) correct[i]=1;
	}

}

void takeprime(int n){


	int i,j,k,l;
	count1=0;

	for(i=0;i<=n;i++){
		if(p[i]==0) prime[count1++]=i;
	}


}


bool check(int n){
	
	if(n<=maxm) return (!p[n]);
	int i,j,k,l,sq;
	sq=sqrt(n);

//	for(i=2;i<=sq;i++){
//		if((n%i)==0) return 0; 
//	}
	for(i=0;prime[i]*prime[i]<=n;i++){
		if(n%prime[i]==0) return 0;

	}

	return 1;

}