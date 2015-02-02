
/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2015-01-30
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

int n,q;

vector<int>G[maxm];

int col[maxm];

void dfs(int s,int par){

    if(col[s]) return ;

    if(par!=-1){
        col[s]=1;
    }

    for(int i=0;i<G[s].size();i++){
        dfs(G[s][i],s);
    }
}

void answer_query(int u){

    memset(col,0,sizeof(col));
    dfs(u,-1);

    int cnt=0;
    for(int j=1;j<=n;j++){
        if(col[j]==0) cnt++;
    }
    printf("%d",cnt);

    for(int j=1;j<=n;j++){
        if(col[j]==0){
            printf(" %d",j);
        }
    }
    puts("");

}


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(scanf("%d",&n)==1){

        if(!n) break;

        for(i=0;i<=n;i++){
            G[i].clear();
        }

        int u,v;

        while(1){
            scanf("%d",&u);

            if(!u) break;

            while(1){
                scanf("%d",&v);
                if(!v) break;
                if(u>=1 && u<=n && v>=1 && v<=n)
                G[u].push_back(v);
            }
        }

        scanf("%d",&q);

        for(i=1;i<=q;i++){
            scanf("%d",&u);

            answer_query(u);
        }
    }

    return 0;
}

