#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;

#define maxm 5000100

bool p[maxm+10];
int prime[maxm+10];
int flag[maxm+10],dp[maxm+10],sums[maxm+10];
int countp;

void gen(int n);
void take(int n);
void fact(int n);
//void calc(int n);
bool check(int n);

int main(){
	
	int i,j,k,l,a,b;
	
	gen(maxm); take(maxm);
	fact(maxm); 
	//calc(maxm);
	
	
	//	for(i=10;i<=21;i++){
	//		printf("PAISE ");
	//	}
	//	printf("\n");
	
	while(1){
		
		scanf("%d",&a);
		if(!a) break;
		scanf("%d",&b);
		printf("%d\n",dp[b]-dp[a-1]);
		
	}
	
	return 0;
	
}

bool check(int n){
	
	int i,j,k,l;
	double sq;
	int sqint;
	int sum=0;
	int num=n;
	
	k=0;
	if(n%2==0) k=1;
	
	while(n%2==0){
		n/=2;
		sum=2;
	}
	
	//k=0;
	if(k){
		sum+=sums[n];
		sums[num]=sum;
		if(p[sum]==0) return 1;
		return 0;
	}
	
	
	
	sq=(double) sqrt(n);
	sqint=sq;
	
	for(i=2;prime[i]<=sqint;i++){
		if(n==1) break;
		j=prime[i];
		if(n%j==0){
			sum+=j;
			k=1;
		}
		else continue;
		while(n%j==0){
			n/=j;
			if(!n) break;
		}
		if(n==1) break;
		sq=(double) sqrt(n);
		sqint=sq;
		if(k){
			sum+=sums[n];
			sums[num]=sum;
			if(p[sum]==0) return 1;
			return 0;
		}
		
	}
	
	if(n!=1) sum+=n;
	sums[num]=sum;
	
	if(p[sum]==0) return 1;
	return 0;
	
}

void fact(int n){
	
	int i,j,k,l;
	
	sums[1]=0;
	
	for(i=1;i<=n;i++){
		if(check(i)) dp[i]=dp[i-1]+1;
		else dp[i]=dp[i-1];
	}
	
}

void take(int n){
	
	int i,j,k,l;
	
	prime[1]=2;
	countp=2;
	
	for(i=3;i<=n;i+=2){
		if(p[i]==0) prime[countp++]=i;
	}
	
}

void gen(int n){
	
	int i,j,k,l;
	
	p[0]=p[1]=1;
	
	for(i=4;i<=n;i+=2) p[i]=1;
	
	double sq=(double)sqrt(n);
	int sqint;
	sqint=sq;
	
    for(i=3;i<=sq;i+=2){
		if(p[i]==1) continue;
		for(j=i*i;j<=n;j+=(2*i)){
			p[j]=1;
		}
	}
	
}