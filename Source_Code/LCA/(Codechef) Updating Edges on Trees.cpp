/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-11-04
Algo        : Lca.
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

#define maxm    200010
#define lgmaxm  30
#define inf (1<<29)
#define ii long long int

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

vector<int>G[maxm];
int n,m1,m2;
int a,b,c,d;
int T[maxm],P[maxm][lgmaxm],L[maxm]; // T = immediate parent, P= Sparse table , L =level

ii cost[maxm],prefix_sum[maxm],sum[maxm];

void dfs(int s,int pre,int lev){

    T[s]=pre;
    L[s]=lev;

    for(int i=0;i<G[s].size();i++){
        if(G[s][i]==pre) continue;
        dfs(G[s][i],s,lev+1);
    }
}

void init_sparse(){

    int i,j;

    for(i=0;i<=n;i++){
        for(j=0;(1<<j)<n;j++){
            P[i][j]=-1;
        }
    }

    // the first ancestor ..
    for(i=1;i<=n;i++){
        P[i][0]=T[i];
    }

    // sparse table ..
    for(j=1;(1<<j)<n;j++){
        for(i=1;i<=n;i++){
            if(P[i][j-1]!=-1){
                P[i][j]=P[P[i][j-1]][j-1];
            }
        }
    }
}

int lca(int p,int q){

     int log, i;

     //if p is situated on a higher level than q then we swap them
     if (L[p] < L[q])
         swap(p,q);

      //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= L[p]; log++);
      log--;

      //we find the ancestor of node p situated on the same level
      //with q using the values in P
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

      //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
}

void update(int a,int b,ii v){
    cost[a]+=v;
    cost[b]-=v;
}

void sub_update(int a,int lca_a,int b,int lca_b){

    if(lca(lca_a,b)==b) return ;
    if(lca(a,lca_b)==a) return ;

    int lca_ab=lca(lca_a,lca_b);
    if(lca_ab!=lca_a && lca_ab!=lca_b) return ;

    int c,d;

    c=lca(a,b);

    if(lca_ab==lca_a) d=lca_b;
    else              d=lca_a;

    if(lca(c,d)==c) return ;

    update(c,d,-1);
}

void update(int a,int b,int c,int d){

    int lcab=lca(a,b);

    update(a,lcab,1);
    update(b,lcab,1);

    int lccd=lca(c,d);

    sub_update(a,lcab,c,lccd);
    sub_update(a,lcab,d,lccd);

    sub_update(b,lcab,c,lccd);
    sub_update(b,lcab,d,lccd);
}

ii cal_prefix(int s,int pre){

    ii ret=cost[s];

    for(int i=0;i<G[s].size();i++){
        if(G[s][i]==pre) continue;
        ret+=cal_prefix(G[s][i],s);
    }
    prefix_sum[s]=ret;

    return ret;
}

void cal_sum(int s,int pre,ii curr_sum){

    sum[s]=curr_sum;
    for(int i=0;i<G[s].size();i++){
        if(G[s][i]==pre) continue;
        cal_sum(G[s][i],s,curr_sum+prefix_sum[G[s][i]]);
    }
}



int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d %d %d",&n,&m1,&m2);

    for(i=1;i<n;i++){
        scanf("%d %d",&k,&l);
        G[k].push_back(l);
        G[l].push_back(k);
    }

    // pre-processing
    dfs(1,1,0);
    init_sparse();


    for(i=1;i<=m1;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        update(a,b,c,d);
    }

//    for(i=1;i<=n;i++){
//        printf("%3d ",cost[i]);
//    }
//    puts("");

    // prefix_sum
    cal_prefix(1,1);

//    for(i=1;i<=n;i++){
//        printf("%3d ",prefix_sum[i]);
//    }
//    puts("");

    cal_sum(1,1,prefix_sum[1]);

//    for(i=1;i<=n;i++){
//        printf("%3d ",sum[i]);
//    }
//    puts("");

    for(i=1;i<=m2;i++){
        scanf("%d %d",&k,&l);
        int lc=lca(k,l);
        ii ans=sum[k]+sum[l]-2*sum[lc];

        printf("%lld\n",ans);
    }


    return 0;
}

