#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 1010
#define ii long long int


ii sum;
int n,k,m;
ii big_mod(int b,int p,int m);

int main(){

    int i,j,l,test,t=1;

  //  freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d %d",&n,&k,&m);
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%d",&l);
            sum+=l;
        }
        ii ans=(((big_mod(n,k-1,m)*k)%m)*sum)%m;
        printf("Case %d: %lld\n",t++,ans);

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
