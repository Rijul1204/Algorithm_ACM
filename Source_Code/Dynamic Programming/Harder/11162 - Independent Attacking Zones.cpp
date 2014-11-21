#include<stdio.h>
#include<string.h>

#define maxm 80
#define ii long long int

ii dp[maxm][maxm];
char s[maxm];
int n;
ii cal(int b,int e);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){
        scanf("%d",&n);
        scanf("%s",s+1);
        n=strlen(s+1);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",t++,cal(1,n));
    }

    return 0;
}

ii cal(int b,int e){

    if(b>e) return 1;
    if(b==e-2){
        int r=0,bl=0;
        if(s[b]=='R') r++; else bl++;
        if(s[b+1]=='R') r++; else bl++;
        if(s[b+2]=='R') r++; else bl++;
        if(bl>1) return 1; return 0;
    }
    if(dp[b][e]!=-1) return dp[b][e];
    int i,j,r,bl; ii ret=0,ret1;

    for(i=b+1;i<e;i+=3){
        for(j=i+1;j<=e;j+=3){
            r=0,bl=0;
            if(s[b]=='R') r++; else bl++;
            if(s[i]=='R') r++; else bl++;
            if(s[j]=='R') r++; else bl++;
            if(r>1) continue;

			ret1=cal(b+1,i-1)*cal(i+1,j-1)*cal(j+1,e);
            ret+=ret1;
        }
    }
    return dp[b][e]=ret;

}
