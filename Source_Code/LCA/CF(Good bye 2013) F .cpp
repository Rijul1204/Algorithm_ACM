/*
Problem : CF(good bye 2013) F. New Year Tree
Algo    : LCA (Sparse Table).
Author  : Rashedul Hasan Rijul (Silent_coder).
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define maxm 1000100
#define maxc 40
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

int Q,N,now;
int L[maxm],T[maxm],P[maxm][maxc];

void pre_process(){

   int i,j;

    // pre-processing
    for(i=1;i<=N;i++){
        P[i][0]=T[i];
    }

    for(j=1;(1<<j)<N;j++){
        for(i=1;i<=N;i++){
            P[i][j]=P[P[i][j-1]][j-1];
        }
    }
}

int find_lca(int u,int v){

    int i,log;

    if(L[u]<L[v]) swap(u,v);

    for(log=1;(1<<log)<=L[u];log++);
    log--;

    for(i=log;i>=0;i--){
        if (L[u] - (1 << i) >= L[v])
              u = P[u][i];
	}

      if (u == v)
          return u;

  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[u][i] != -1 && P[u][i] != P[v][i])
              u = P[u][i], v = P[v][i];

      return T[u];
}

int find_dist(int u,int v){

    int lc=find_lca(u,v);
    int ret=L[u]+L[v]-(2*L[lc]);
    return ret;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&Q);

    L[1]=0,L[2]=L[3]=L[4]=1;
    T[1]=T[2]=T[3]=T[4]=1;

    N=Q*2 + 4;

    for(i=0;i<N;i++){
        for(j=0;(1<<j)<N;j++){
            P[i][j]=-1;
        }
    }

    now=5;
    int p;
    for(i=1;i<=Q;i++){
        scanf("%d",&p);
        L[now]=L[p]+1;  T[now++]=p;
        L[now]=L[p]+1;  T[now++]=p;
    }

    pre_process();

    int ans=2,d1=2,d2=4;

    for(i=1,now=5;i<=Q;i++,now+=2){
        int ans1=find_dist(d1,now);
        if(ans1>ans){
            ans=ans1;
            d2=now;
        }
        else{
            ans1=find_dist(d2,now);
            if(ans1>ans){
                ans=ans1,d1=now;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

