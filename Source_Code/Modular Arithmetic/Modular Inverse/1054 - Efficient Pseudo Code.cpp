/*
Author  : Rashedul Hasan Rijul (Silent_coder).
Problem : LOJ 1054 ( Efficient Pseudo Code).
Algo    : Modular Inverse,Extended Euclid.
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

#define ii long long int
#define maxm 100100
#define mod 1000000007

// p= boolean flag for prime, p[i]=0(i is a prime), p[i]=1(i is not a prime)
bool p[maxm];
//prime= prime number in sorted order.....
int prime[maxm/2];
//prime generation
void gen(int n);
//prime take...
void take(int n);
//prime factoriztion....
void cal(int n);
// big_mod ....b=base, m=mod ,p=power, big_mod=(b^p)%m
ii big_mod(ii b,ii p,ii m);
// modular_inverse .....n=number, m=mod , n*mod_inv(n,m)=1(mod m)
ii mod_inv(ii n,ii m);
// Extended Euclid .....  for  finding  Modular inverse
struct node{
	ii x,y,g;
	node(){};
	node(ii xx,ii yy,ii gg){ x=xx; y=yy; g=gg;};
};
//  ax+by=g where g=gcd(a,b)....
node euclid(ii a,ii b);
////////////////*******\\\\\\\\\\\\\\\\\\
// num= prime factorize number, power= power of the prime..
vector<int>num,power;
//tot= total number of prime;
int tot;

int main(){

    int i,test,t=1;
    ii n,m,k,j;

    printf("%d\n",mod_inv(2,mod));

    gen(maxm-10);
    take(maxm-10);

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);
    while(test--){

        scanf("%lld %lld",&n,&m);
        num.clear(); power.clear();
        cal(n);
        ii ans=1,ans1;
        for(i=0;i<num.size();i++){
            j=num[i]; k=power[i];
            k*=m; k++;
            ans1=big_mod(j,k,mod); ans1--;
            if(ans1<0) ans1+=mod;
            ans1*=(mod_inv(j-1,mod)); ans1%=mod;
            ans*=ans1; ans%=mod;
        }
        printf("Case %d: %lld\n",t++,ans);

    }

	return 0;
}

node euclid(ii a,ii b){

	if(!b) return node(1,0,a);
	node r=euclid(b,a%b);
	return node(r.y,r.x-(a/b)*r.y,r.g);
}

ii mod_inv(ii n,ii m){

    node t=euclid(n,m);
    if(t.g>1) return 0;
    ii ret=t.x%m;
    if(ret<0) ret+=m;
    return ret;
}

ii big_mod(ii b,ii p,ii m){

    if(p==0) return 1; if(p==1) return (b%m);
    ii ret=big_mod(b,p/2,m);
    ret*=ret; ret%=m;
    if(p%2){ ret*=b; ret%=m; }
    return ret;
}

void cal(int n){

    int i,j,sq;
    double nd=n,sqd;
    sqd=sqrt(nd); sq=sqd;

    for(i=0;prime[i]<=sq;i++){
        if(n%prime[i]==0){
            j=0;
            while(n%prime[i]==0){
                n/=prime[i]; j++;
            }
            num.push_back(prime[i]); power.push_back(j);
            nd=n; sqd=sqrt(nd); sq=sqd;
        }
    }

    if(n!=1){
        num.push_back(n); power.push_back(1);
    }
}

void take(int n){

    int i;
    prime[tot++]=2;
    for(i=3;i<=n;i+=2){
        if(!p[i]){
			prime[tot++]=i;
		}
    }
}

void gen(int n){

    int i,j,sq;
    double nd=n,sqd;
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
