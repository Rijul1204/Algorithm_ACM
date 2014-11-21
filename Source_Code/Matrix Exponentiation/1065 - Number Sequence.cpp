#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 1000
#define ii long long int

ii a,b,n,m,mod;
ii base[2][2]={{1,1},{1,0}},unit[2][2]={{1,0},{0,1}},res[2][2];

void cal(ii a[2][2],ii b[2][2]){

    int i,j,k,l;
    ii ret[2][2]; memset(ret,0,sizeof(ret));

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                ret[i][j]+=(a[i][k]*b[k][j]);
                ret[i][j]%=mod;
            }
        }
    }
    memcpy(a,ret,sizeof(ret));

}

void exp(ii r[2][2],ii n){

    ii b[2][2];
    memcpy(r,unit,sizeof(unit));
    memcpy(b,base,sizeof(base));

    while(n>0){
        if(n%2) cal(r,b);
        n/=2;
        cal(b,b);
    }
}

int main(){

    int i,j,k,l,test,t=1;

   // freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%lld %lld %lld %lld",&a,&b,&n,&m);
        mod=pow(10,m);

        ii ans=0;
        if(n==0){
            ans=a%mod;
            printf("Case %d: %lld\n",t++,ans);
            continue;
        }
        if(n==1){
            ans=b%mod;
            printf("Case %d: %lld\n",t++,ans);
            continue;
        }

        exp(res,n-1);

        ans=res[0][0]*b; ans%=mod;
        ans+=(res[0][1]*a); ans%=mod;

        printf("Case %d: %lld\n",t++,ans);

    }

    return 0;
}
