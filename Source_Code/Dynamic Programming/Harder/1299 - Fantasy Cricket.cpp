#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 1005
#define mod 1000000007
#define ii long long int

ii dp[maxm][maxm];
bool fl[maxm][maxm];
char s[maxm];
ii cal(int ind,int rem);

int main(){

    int i,j,k,l,test,t=1;

   // freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%s",s);
        memset(fl,0,sizeof(fl));
        printf("Case %d: %lld\n",t++,cal(strlen(s)-1,0));

    }

    return 0;
}

ii cal(int ind,int rem){

    if(rem<0) return 0;
    if(ind<0&&!rem) return 1;
    if(ind<0) return 0;

    if(fl[ind][rem]) return dp[ind][rem];
    fl[ind][rem]=1;

    if(s[ind]=='E') return dp[ind][rem]=cal(ind-1,rem);
    if(s[ind]=='D') return dp[ind][rem]=(cal(ind-1,rem+1)+(ii)rem*cal(ind-1,rem))%mod;
    if(s[ind]=='U') return dp[ind][rem]=((ii)rem*((ii)rem*cal(ind-1,rem-1)+cal(ind-1,rem)))%mod;
}
