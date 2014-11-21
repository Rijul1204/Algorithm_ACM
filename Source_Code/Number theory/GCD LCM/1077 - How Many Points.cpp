#include<stdio.h>
#include<string.h>
#include<math.h>

#define ii long long int

ii gcd(ii a,ii b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
ii ax,ay,bx,by,ans;

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%lld %lld %lld %lld",&ax,&ay,&bx,&by);
        ax-=bx; ay-=by;
        if(ax<0) ax*=-1; if(ay<0) ay*=-1;
        if(ax==0){
            ans=ay+1;
            printf("Case %d: %lld\n",t++,ans); continue;
        }
        if(ay==0){
            ans=ax+1;
            printf("Case %d: %lld\n",t++,ans); continue;
        }

        ans=gcd(ax,ay);
        if(ans<0) ans*=-1;
        ans++;
        printf("Case %d: %lld\n",t++,ans);

    }

    return 0;
}
