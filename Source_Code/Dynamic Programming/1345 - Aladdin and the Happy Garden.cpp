/*
Author : Rashedul Hasan Rijul ( Silent_coder ).
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define maxm 51
#define cn 15
#define lim 15
#define inf (1<<29)
#define ii int
#define mod 1000000007

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

ii on(ii n,ii k){ return (n|(1<<k)); }
ii off(ii n,ii k){ return (n-(n&(1<<k))); }
bool chck(ii n,ii k){ return (n&(1<<k)); }

ii mini(ii a,ii b){ if(a<b) return a;  return b;  }
ii maxi(ii a,ii b){ if(a>b) return a;  return b;  }

int n,K;
int dp[maxm-1][maxm][maxm][maxm-cn][2];
short vis[maxm-1][maxm][maxm][maxm-cn][2],kas=1;

ii cal(int ind,int taller,int rem,int K,bool found,int smaller){

    if(rem<0) return 0;
    if(!rem) found=true;

    if(!ind && found) return 1;
    if(!ind)          return 0;

    int mem_K;
    if(K<=lim){
        mem_K=0;
    }
    else mem_K=K-cn;

    if(vis[smaller][taller][rem][mem_K][found]==kas) return dp[smaller][taller][rem][mem_K][found];
    vis[smaller][taller][rem][mem_K][found]=kas;

    ii ret=0;
    int i;

    for(i=1;i<=smaller;i++){
        ret+=cal(ind-1,taller+(smaller-i),K-1,K,found,i-1);
        if(ret>=mod) ret%=mod;
    }

    for(i=1;i<=taller;i++){
        ret+=cal(ind-1,taller-i,rem-1,K,found,smaller+(i-1));
        if(ret>=mod) ret%=mod;
    }

    return dp[smaller][taller][rem][mem_K][found]=ret;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    for(t=1;t<=test;t++){

        scanf("%d %d",&n,&K);

        if(K<=lim){
            kas=t;
        }
        else{
            kas=1;
        }

        printf("Case %d: %d\n",t,cal(n,n,K,K,0,0));
    }


    return 0;
}

