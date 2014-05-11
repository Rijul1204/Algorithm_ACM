#include<stdio.h>
#include<string.h>
#include<math.h>

#define inf 1<<28
#define maxm 1000100
#define maxn 65540

bool p[maxn],segment[maxm];
int primes[6554000];
int l,h;

void sieve(int n){
	int i,j,k,l;
	int sq;
	sq=sqrt(n);
	sq++;
	p[0]=1;
	for(i=4;i<=n;i+=2) p[i]=1;
	for(i=3;i<sq;i+=2){
		if(p[i]) continue;
		for(j=i*i;j<=n;j+=2*i){
			p[j]=1;
		}
	}
}

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
int f(int l,int i){
	if(l%i==0) return maxi(l,i*i);
	return maxi(l+(i-(l%i)),i*i);
}

int main(){

	int i,j,k,sq;
	
//	freopen("in.txt","r",stdin);
	sieve(maxn);

	while(scanf("%d %d",&l,&h)==2){
		
		memset(segment,0,sizeof(segment));

		if(l==1) segment[0]=1;
		sq=ceil(sqrt(h));
		

		for(i=2;i<=sq;i++){
			if(p[i]) continue;
			for(j=f(l,i);j>=l&&j<=h;j+=i){
				segment[j-l]=1;
			}
		}
		
		int c=0;
		for(i=0;i<=h-l;i++){
			if(segment[i]==1) continue;
			primes[c++]=i+l;
		}

		k=-1; j=inf;
		int ans1,ans2,ans3,ans4;

		for(i=1;i<c;i++){
			if(primes[i]-primes[i-1]>k){
				k=primes[i]-primes[i-1];
				ans1=primes[i]; ans2=primes[i-1];
			}
			if(primes[i]-primes[i-1]<j){
				j=primes[i]-primes[i-1];
				ans3=primes[i]; ans4=primes[i-1];
			}
		}

		if(k==-1||j==inf){
			printf("There are no adjacent primes.\n");
		}
		else {
			printf("%d,%d are closest, %d,%d are most distant.\n",ans4,ans3,ans2,ans1);
		}
	}

	return 0;
}