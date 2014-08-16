#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

#define maxm 2010010
#define ii long long int
#define lim 1000020

//flag for prime
bool p[maxm];

// prime numbers=prime , number of primes in factorization= nums
ii prime[maxm/2];
int tot;

bool flag[maxm];
int fact[maxm];
//prime generation
void gen(int n);
//factorization
void cal(int n);

int n,m;

int main(){

	int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	gen(lim);

	prime[tot++]=2;
	for(i=3;i<=lim;i+=2){
		if(p[i]) continue;
		prime[tot++]=i;
	}

	for(i=2;i<=lim;i++){
	    cal(i);
	}

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);
		if(n>m) swap(n,m);

		if(n==0 && m==0){
            printf("Case %d: 0\n",t++);
            continue;
		}

		if(n<=0){
            printf("Case %d: 1\n",t++);
            continue;
		}

		ii ans=(ii)((ii)n*(ii)m);

		for(i=2;i<=n;i++){

		    if(flag[i]){
		      continue;
		    }

		    if(fact[i]%2){
		        k=1;
		    }
		    else{
		        k=-1;
		    }

		    ii piv=m/i;
		    piv*=(ii)k;

		    ii now=((n-i)/i)+1;
		    ans-=(now*piv);
		}

		ans+=(ii)2;

        printf("Case %d: %lld\n",t++,ans);
	}

	return 0;
}

void cal(int n){

	int i,c,ori=n;

	for(i=0;prime[i]*prime[i]<=n;i++){
		if(n%prime[i]==0){
		    c=0; fact[ori]++;
		    while(n%prime[i]==0){
		        c++; n/=prime[i];
                if(c>1){
                    flag[ori]=1;
                    return ;
                }
		    }
		}
	}

	if(n>1){
	    fact[ori]++;
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
		for(j=(i*i);j<=n;j+=(2*i)){
			p[j]=1;
		}
	}
}
