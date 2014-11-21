#include<stdio.h>
#include<string.h>
#include<math.h>

#define ii long long int
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

double cal1(ii b,ii p);
//big mod
ii big_mod(ii b,ii p,ii m);

int main(){

    int i,j,k,l,test,t=1,n;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&k);

        double ans=cal1(n,k);
        double v=1000;
        if(ans<v) ans=ans*v;
        ii ans1=ans;
        while(ans1>=1000) ans1/=10;
        printf("Case %d: %03lld",t++,ans1);
        printf(" %03lld\n",big_mod(n,k,1000));


    }

    return 0;
}

ii big_mod(ii b,ii p,ii m){

    if(p==0) return 1;
    if(p==1) return b%m;

    ii ret;
    ret=big_mod(b,p/2,m);
    ret*=ret; ret%=m;
    if(p%2) ret*=b;
    ret%=m;
    return ret;

}

double cal1(ii b,ii p){

    if(p==1) return b;
    if(p==0) return 1;

    double v=100000000,bd=b;
    double ret1=cal1(b,p/2);
    while(ret1>v) ret1/=v;
    ret1*=ret1;
    while(ret1>v) ret1/=v;
    if(p%2) ret1*=bd;
    while(ret1>v) ret1/=v;

    return ret1;

}
