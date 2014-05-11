#include<stdio.h>
#include<string.h>

#define maxm 500
#define maxn 60
#define ii long long int
#define mod 1000000007

ii dp1[maxm][maxm],dp[maxm][maxn];
int m,n,c,n1,n2;

ii ncr(int n,int r);
ii cal(int n,int c);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);
    memset(dp,-1,sizeof(dp));   memset(dp1,-1,sizeof(dp1));

    while(test--){

        scanf("%d %d %d",&m,&n,&c); m++;n++;
        n1=(m*n)/2; n2=(m*n)-n1;
        if(n2==0||n1==0){
            printf("Case %d: %d\n",t++,c);
            continue;
        }
        ii ans=0,ans1,ans2;
        for(i=1;i<c;i++){
            for(j=1;;j++){
                if(i+j>c) break;
                ans1=ncr(c,i)*cal(n1,i); ans1%=mod;
                ans2=ncr((c-i),j)*cal(n2,j); ans2%=mod;
                ans+=(ans1*ans2); ans%=mod;
            }
        }
        printf("Case %d: %lld\n",t++,ans);

    }

    return 0;

}

ii cal(int n,int c){

    if(n==0&&c==0) return 1;
    if(n==0||c==0) return 0;

    if(dp[n][c]!=-1) return dp[n][c];

    ii ret=0,ret1;
    int i;

    for(i=1;i<=n;i++){
        ret1=ncr(n,i)*cal(n-i,c-1);
        ret+=ret1; ret%=mod;
    }

    return dp[n][c]=ret;

}
ii ncr(int n,int r){

    if(n<r) return 0;
    if(n==0||r==0||n==r) return 1;
    if(dp1[n][r]!=-1) return dp1[n][r];
    dp1[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
    dp1[n][r]%=mod;
    return dp1[n][r];
}
