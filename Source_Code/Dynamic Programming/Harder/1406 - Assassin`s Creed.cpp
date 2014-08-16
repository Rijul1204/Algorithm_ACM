/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-07-24
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

#define maxm 15
#define maxn ((1<<maxm)+10)
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

int n,m,ans;
vector<int>G[maxm];

bool can[maxn];
bool col[maxm][maxn];

int dp[maxn],vis[maxn],kas=1;

void dfs(int s,int mask){

    if(col[s][mask]) return ;
    col[s][mask]=1;
    can[mask]=1;

    for(int i=0;i<G[s].size();i++){
        dfs(G[s][i],on(mask,G[s][i]));
    }
}

int cal(int mask){

    if(!mask) return 0;
    if(vis[mask]==kas) return dp[mask];
    vis[mask]=kas;

    int ret=inf;
    for(int i=mask;i>0;i=(mask&(i-1))){
        if(can[i]) ret=mini(ret,cal(mask^i)+1);
    }

    return dp[mask]=ret;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&m);

        for(i=0;i<n;i++){
            G[i].clear();
        }

        int u,v;
        for(i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            u--,v--;
            G[u].push_back(v);
        }

        memset(can,0,sizeof(can));
        memset(col,0,sizeof(col));
        for(i=0;i<n;i++){
            dfs(i,(1<<i));
        }

        kas++;
        printf("Case %d: %d\n",t++,cal((1<<n)-1));

    }

    return 0;
}

