/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-09-25
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

#define maxm 2010
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

struct elephant{
    int ind,w,s;
    elephant(){}
    elephant(int _ind,int _w,int _s){
        ind=_ind,w=_w,s=_s;
    }
};
elephant elphs[maxm];

bool comp(elephant a,elephant b){
    return a.w<b.w;
}

int n,tot=1;

int dp[maxm][maxm];
int pre[maxm][maxm];

int cal(int now,int prev){

    if(now==tot) return 0;

    if(dp[now][prev]!=-1) return dp[now][prev];

    int ret=cal(now+1,prev);
    pre[now][prev]=0;

    if(elphs[now].w>elphs[prev].w && elphs[now].s<elphs[prev].s){
        int ret1=cal(now+1,now)+1;
        if(ret1>ret){
            ret=ret1;
            pre[now][prev]=1;
        }
    }

    return dp[now][prev]=ret;
}

void print(int now,int prev){

    if(now==tot) return ;

    if(pre[now][prev]==0){
        print(now+1,prev);
    }
    else{
        printf("%d\n",elphs[now].ind);
        print(now+1,now);
    }
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    memset(dp,-1,sizeof(dp));

    while(scanf("%d %d",&elphs[tot].w,&elphs[tot].s)==2){
        elphs[tot].ind=tot;
        tot++;
    }
    elphs[0]=elephant(0,-1,inf);

    sort(elphs,elphs+tot,comp);

    printf("%d\n",cal(1,0));
    print(1,0);

    return 0;
}

