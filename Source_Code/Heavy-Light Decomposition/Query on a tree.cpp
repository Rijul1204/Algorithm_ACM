/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-11-11
Algo        : Heavy-Light Decomposition.
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

#define maxm 200100
#define lg_maxm 20
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

struct tree{
    int mx_cost;
};
tree seg_T[4*maxm];

int n,m;
vector<int>G[maxm],W[maxm],edge_ind[maxm];
int L[maxm],T[maxm],P[maxm][lg_maxm],subtree_size[maxm];
int edge[maxm],ptr;

int chain_head[maxm],chain_ind[maxm],chain_no;
int pos_in_base[maxm],base_arr[maxm];

// fixing parent,size and level
void dfs(int s,int pre,int lev){

    T[s]=pre;
    L[s]=lev;
    subtree_size[s]=1;

    for(int i=0;i<G[s].size();i++){
        if(G[s][i]==pre) continue;
        edge[edge_ind[s][i]]=G[s][i];
        dfs(G[s][i],s,lev+1);
        subtree_size[s]+=subtree_size[G[s][i]];
    }

}

// Updating sparse table for lca . . .
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

/*
* Actual HL-Decomposition part
* Initially all entries of chainHead[] are set to -1.
* So when ever a new chain is started, chain head is correctly assigned.
* As we add a new node to chain, we will note its position in the baseArray.
* In the first for loop we find the child node which has maximum sub-tree size.
* The following if condition is failed for leaf nodes.
* When the if condition passes, we expand the chain to special child.
* In the second for loop we recursively call the function on all normal nodes.
* chainNo++ ensures that we are creating a new chain for each normal child.
*/
void heavy_light(int s,int pre,int curr_cost){

    if(chain_head[chain_no]==-1){
        chain_head[chain_no]=s; // Assign chain head
    }

    chain_ind[s]=chain_no;
    pos_in_base[s]=++ptr; // Position of this node in baseArray which we will use in Segtree
    base_arr[ptr]=curr_cost;

    int heavy_child=-1,heavy_cost=0,heavy_size=0,i;

    // Loop to find heavy child
    for(i=0;i<G[s].size();i++){
        if(G[s][i]==pre) continue;
        if(subtree_size[G[s][i]]>heavy_size){
            heavy_size=subtree_size[G[s][i]];
            heavy_child=G[s][i];
            heavy_cost=W[s][i];
        }
    }

    if(heavy_child!=-1){
        // Expand the chain
        heavy_light(heavy_child,s,heavy_cost);
    }

    for(i=0;i<G[s].size();i++){
        if(G[s][i]==pre || G[s][i]==heavy_child) continue;
        // light node . . . .
        chain_no++;
        heavy_light(G[s][i],s,W[s][i]);
    }

}

void init_segtree(int node,int b,int e){

    if(b>e) return ;
    if(b==e){
        seg_T[node].mx_cost=base_arr[b];
        return ;
    }

    int left=node<<1,right=left+1,mid=b+e;
    mid/=2;

    init_segtree(left,b,mid);
    init_segtree(right,mid+1,e);

    seg_T[node].mx_cost=maxi(seg_T[left].mx_cost,seg_T[right].mx_cost);
}

int seg_query(int node,int b,int e,int k,int l){

    if(b>e) return 0;

    if(b==k && e==l) return seg_T[node].mx_cost;

    int left=node<<1,right=left+1,mid=b+e;
    mid/=2;

    if(l<=mid) return seg_query(left,b,mid,k,l);
    else if(k>mid) return seg_query(right,mid+1,e,k,l);
    else{
        return maxi(seg_query(left,b,mid,k,mid),seg_query(right,mid+1,e,mid+1,l));
    }
}

void seg_update(int node,int b,int e,int ind,int v){

    if(b>e) return ;

    if(b==e){
        seg_T[node].mx_cost=v;
        return ;
    }

    int left=node<<1,right=left+1,mid=b+e;
    mid/=2;

    if(ind<=mid)  seg_update(left,b,mid,ind,v);
    else        seg_update(right,mid+1,e,ind,v);

    seg_T[node].mx_cost=maxi(seg_T[left].mx_cost,seg_T[right].mx_cost);
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

/*
* query_up:
* It takes two nodes u and lc, condition is that lc is an ancestor of u
* We query the chain in which u is present till chain head, then move to next chain up
* We do that way till u and lc are in the same chain, we query for that part of chain and break
*/
int query_up(int u,int lc){

    if(u==lc) return 0;
    int u_chain,lc_chain,ret=-1;

    lc_chain=chain_ind[lc];
    while(1){

        if(u==lc) break;

        u_chain=chain_ind[u];

        if(u_chain==lc_chain){
           // Both u and lc are in the same chain, so we need to query from u to lc, update ret and break.
           // We break because we came from u up till v, we are done
            ret=maxi(ret,seg_query(1,1,ptr,pos_in_base[lc]+1,pos_in_base[u]));

            return ret;
        }

        ret=maxi(ret,seg_query(1,1,ptr,pos_in_base[chain_head[u_chain]],pos_in_base[u]));
        // Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
        // start till head. We then update the answer

        u=chain_head[u_chain]; // move u to u's chainHead
        u=T[u]; //Then move to its parent, that means we changed chains
    }

    return ret;
}


int query(int u,int v){

    int lc=lca(u,v);

    int ret=maxi(query_up(u,lc),query_up(v,lc));

    return ret;
}

void update(int u,int v){

    seg_update(1,1,ptr,pos_in_base[u],v);
}


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        // init_all
        ptr=0,chain_no=1;
        for(i=0;i<=n;i++){
            G[i].clear();
            W[i].clear();
            edge_ind[i].clear();
            chain_head[i]=-1;
        }


        for(i=1;i<n;i++){
            scanf("%d %d %d",&k,&l,&j);

            G[k].push_back(l);
            W[k].push_back(j);
            edge_ind[k].push_back(i);

            G[l].push_back(k);
            W[l].push_back(j);
            edge_ind[l].push_back(i);
        }

        // init . . .
        dfs(1,1,1);
        init_sparse();
        heavy_light(1,1,0);

        // seg-tree
        init_segtree(1,1,ptr);

        char qs[10];
        int u,v;
        while(1){
            scanf("%s",qs);
            if(qs[0]=='D') break;

            scanf("%d %d",&u,&v);
            if(qs[0]=='Q'){
                printf("%d\n",query(u,v));
            }
            else{
                u=edge[u];
                update(u,v);
            }
        }

    }

    return 0;
}

