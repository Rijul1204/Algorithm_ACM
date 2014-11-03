/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-11-03
complexity  : O(N logN, O(logN)
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

#define maxm    5100
#define lgmaxm  20
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
int T[maxm],P[maxm][lgmaxm],L[maxm]; // T = immediate parent, P= Sparse table , L =level

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

int find_kth(int p,int q,int lc,int k){

    int dist_from_p=L[p]-L[lc];
    if(k>dist_from_p){
        k-=dist_from_p;
        int dist_from_q=L[q]-L[lc];
        return find_kth(q,p,lc,dist_from_q-k);
    }

    int log,i;

    //we compute the value of [log(L[p)]
    for (log = 1; 1 << log <= L[p]; log++);
    log--;

    //we find the ancestor of node p situated on the same level
    //with q using the values in P
    for (i = log; i >= 0; i--)
      if ( (1 << i) <=k){
          p = P[p][i];
          k-=(1<<i);
      }

      return p;
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

        for(i=1;i<n;i++){
            scanf("%d %d",&k,&l);
            G[k].push_back(l);
            G[l].push_back(k);
        }

        // pre-processing
        dfs(1,1,0);
        init_sparse();

        scanf("%d",&q);

        for(i=1;i<=q;i++){
            scanf("%d %d",&k,&l);
            int lc=lca(k,l);
            int dist=L[k]+L[l]-2*L[lc];
            int ind1=0,ind2=0;
            if(dist%2==0){
                ind1=find_kth(k,l,lc,dist/2);
                printf("The fleas meet at %d.\n",ind1);
            }
            else{
                ind1=find_kth(k,l,lc,dist/2);
                ind2=find_kth(k,l,lc,(dist/2)+1);
                if(ind1>ind2){
                    swap(ind1,ind2);
                }
                printf("The fleas jump forever between %d and %d.\n",ind1,ind2);
            }
        }

    }

    return 0;
}

