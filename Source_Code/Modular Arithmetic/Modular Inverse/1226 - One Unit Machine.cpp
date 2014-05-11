#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 1100
#define maxn 1001000
#define mod 1000000007
#define ii long long int

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
//generate  Factorial
void gen(int n);
//factorial array
ii fact[maxn],fact_inv[maxn];

int main(){

    int i,j,k,l,n,test,t=1;

    //freopen("in.txt","r",stdin);
    gen(maxn-995);

    scanf("%d",&test);

    while(test--){

        ii sum=0,v,ans=1,v1;

        scanf("%d",&n);

        for(i=1;i<=n;i++){
            scanf("%lld",&v);
            if(v==0) continue;
            v1=fact[sum+v-1];
            v1*=fact_inv[sum]; v1%=mod;
            v1*=fact_inv[v-1]; v1%=mod;
            ans*=v1; ans%=mod;
            sum+=v;
        }
        printf("Case %d: %lld\n",t++,ans);

    }

    return 0;
}

void gen(int n){

    fact[0]=fact[1]=1;
    fact_inv[0]=mod_inv(fact[0],mod);
    fact_inv[1]=mod_inv(fact[1],mod);

    ii i;

    for(i=2;i<=n;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
        fact_inv[i]=mod_inv(fact[i],mod);
    }

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
