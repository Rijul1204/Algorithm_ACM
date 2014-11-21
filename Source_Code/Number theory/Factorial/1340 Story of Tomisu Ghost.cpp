#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 100100
#define ii long long int
#define mod 10000019

//flag for prime
bool p[maxm];
// prime numbers=prime , number of primes in factorization= nums
int prime[maxm],nums[maxm],n,tr,tot=0;

//prime generation
void gen(int n);
//factorization of factorial
void cal(int n);
//big mod
ii big_mod(int b,int p,int m);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	gen(maxm-10);
	for(i=2;i<=maxm-10;i++){
		if(p[i]) continue;
		prime[tot++]=i;
	}

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&tr);

		memset(nums,0,sizeof(nums));

		cal(n); ii ans=1;
		for(i=0;i<tot;i++){
			j=prime[i]; k=nums[j];
			if(k<tr) break;
		//	printf("%d %d\n",j,k);
			ans*=big_mod(j,k/tr,mod); ans%=mod;
		}
		if(i==0) printf("Case %d: -1\n",t++);
		else printf("Case %d: %lld\n",t++,ans);
	}

	return 0;
}

ii big_mod(int b,int p,int m){

    if(p==0) return 1;
    if(p==1) return b%m;

    ii ret;
    ret=big_mod(b,p/2,m);
    ret*=ret; ret%=m;
    if(p%2) ret*=b;
    ret%=m;
    return ret;

}

void cal(int n){

	int i,j,k,l;
	ii val;

	for(i=0;i<tot;i++){
		j=prime[i];
		l=1;
		while(1){
			val=pow(j,l);
			if(val>n) break;
			nums[j]+=(n/val);
			l++;
		}
		if(nums[j]<tr) break;
	}
}

void gen(int n){

	int i,j,k,l,sq;
	double sqd,nd=n;

	sqd=sqrt(nd); sq=sqd;

	p[0]=p[1]=1;

	for(i=4;i<=n;i+=2) p[i]=1;

	for(i=3;i<=sq;i+=2){
		if(p[i]) continue;
		for(j=i*i;j<=n;j+=(2*i)){
			p[j]=1;
		}
	}
}
