/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-10-05
*/

#pragma warning (disable: 4786)
#pragma comment (linker, "/STACK:0x800000")

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

#define maxm 20
#define maxn ((1<<15)+1)
#define inf (1<<29)
#define ii int

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

int n,m;
int mat[maxm][maxm];
int sum[maxn];
int dp[maxn];
int vis[maxn],kas=1;

int get_sum(int mask){

    int ret=0;

    for(int i=0;i<14;i++){
        if(chck(mask,i)){
            for(int j=0;j<14;j++){
                if(chck(mask,j)){
                    ret+=mat[i][j];
                }
            }
        }
    }

    return ret;
}

int cal(int mask){

    if(mask==0) return 0;

    if(vis[mask]==kas) return dp[mask];
    vis[mask]=kas;

    int ret=inf;

    for(int i=mask;i>0;i=(mask&(i-1))){
        ret=mini(ret,sum[i]+cal(mask^i));
    }

    return dp[mask]=ret;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&mat[i][j]);
            }
        }

        for(i=0;i<(1<<n);i++){
            sum[i]=get_sum(i);
        }

        kas++;
        printf("Case %d: %d\n",t++,cal((1<<n)-1));

    }

    return 0;
}


