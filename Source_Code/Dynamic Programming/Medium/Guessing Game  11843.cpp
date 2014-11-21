/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-11-20
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

#define maxm 1010
#define maxn 21
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

int n,s;

bool vis[maxm][maxn];
int dp[maxm][maxn];

int cal(int rem,int s){

    if(rem<=0) return 0;
    if(s<=0) return inf;
    if(rem<=1) return 1;

    if(vis[rem][s]) return dp[rem][s];
    vis[rem][s]=1;

    int ret=inf;

    for(int i=1;i<=rem;i++){
        ret=mini(ret,maxi(cal(i-1,s-1),cal(rem-i,s)));
    }

    ret++;

    return dp[rem][s]=ret;
}



int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&s);

        printf("%d\n",cal(n,s));
    }

    return 0;
}

