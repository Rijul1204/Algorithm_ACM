#include<stdio.h>
#include<string.h>

#define maxm 1000
#define ii long long int

ii n,K;

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%lld %lld",&n,&K);

        ii mul=1,ans=0,now=K;
        for(i=1;;i++){
            if(n<now) break;
            ans+=(mul*(n/now));
            mul=-mul;
            now*=K;
        }

        ans=n-ans;

        printf("%lld\n",ans);
    }

    return 0;
}
