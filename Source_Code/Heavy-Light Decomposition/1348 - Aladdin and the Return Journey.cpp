/*
Author  : Rashedul Hasan Rijul(silent_coder).
Problem : Aladdin and the Return Journey .
OJ      : Light OJ .
Algo    : Heavy-Light Decomposition.
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
using namespace std;

#define maxm 30030

//  Heavy - Light Decomposition ................................

#define ii int
//  segment tree..
struct Tree{
    ii sum;
};

// Chain of heavy edge....
struct Chain{
    int n;
    ii *a;     // array..
    Tree *T;   // Segment tree.....
    Chain(){
    }
    Chain(int tmp[],int cn){
        a=new int[n=cn];
        T=new Tree[n<<2];
        memcpy(a,tmp,sizeof(ii)*n);
        init(1,0,n-1);
    }
    void init(int node,int b,int e){
        if(b==e){
            T[node].sum=a[b]; return ;
        }
        int left,right,mid;
        left=node<<1; right=left+1;  mid=b+e; mid/=2;

        init(left,b,mid);
        init(right,mid+1,e);

        T[node].sum=T[left].sum+T[right].sum;
    }
    void update(int node,int b,int e,int ind,int val){
        if(b==e){
            T[node].sum=val; return ;
        }
        int left,right,mid;
        left=node<<1; right=left+1;  mid=b+e; mid/=2;

        if(ind<=mid) update(left,b,mid,ind,val);
        else update(right,mid+1,e,ind,val);

        T[node].sum=T[left].sum+T[right].sum;
    }
    ii query(int node,int b,int e,int idb,int ide){

        if(b==idb && e==ide) return T[node].sum;

        int left,right,mid;
        left=node<<1; right=left+1; mid=b+e; mid/=2;

        if(ide<=mid) return query(left,b,mid,idb,ide);
        else if(idb>mid) return query(right,mid+1,e,idb,ide);
        else return (query(left,b,mid,idb,mid)+query(right,mid+1,e,mid+1,ide));
    }
};

int n,q;
// cost =cost of node , lvl =depth of node , parent = immediate parent
int cost[maxm],lvl[maxm],parent[maxm];
// head = root of chain ,cnext= next heavy edge in chain ,chainid= chain id of node,
// chainpos = position of current node in it's respective chain.
int head[maxm],cnext[maxm],chainid[maxm],chainpos[maxm];
int nchain;
vector<Chain *>chains;

//  Graph.. (tree)
vector<int>G[maxm];

// lebel the graph.....
int temp[maxm];
int dfs(int u,int p,int d){

    int i,v;
    int sz,ret=1,mxid,mx=0;
    lvl[u]=d;
    for(i=0;i<G[u].size();i++){
        v=G[u][i];
        if(v==p) continue;
        parent[v]=u;
        sz=dfs(v,u,d+1);
        ret+=sz;
        if(sz>mx){
            mx=sz; mxid=v;
        }
    }
    if(ret==1) cnext[u]=-1;
    else cnext[u]=mxid;

    int hd,k;
    for(i=0;i<G[u].size();i++){
        v=G[u][i];
        if(v==p || v==mxid) continue;
        for(hd=v,k=0;v!=-1;v=cnext[v],k++){
            head[v]=hd;
            temp[k]=cost[v];
            chainpos[v]=k;
            chainid[v]=nchain;
        }
        chains.push_back(new Chain(temp,k));
        nchain++;
    }

    return ret;
}
// heavy - light decompose.............
void hld(int s){

    // Initializing chains......
    chains.clear();

    nchain=0; lvl[0]=-1;
    dfs(s,0,0);
    int v=s,hd,k;
    for(hd=v,k=0;v!=-1;v=cnext[v],k++){
        head[v]=hd;
        temp[k]=cost[v];
        chainpos[v]=k;
        chainid[v]=nchain;
    }
    chains.push_back(new Chain(temp,k));
    nchain++;

}

int lca(int a,int b){

    while(chainid[a]!=chainid[b]){
        if(lvl[head[a]]<lvl[head[b]]){
            b=parent[head[b]];
        }
        else{
            a=parent[head[a]];
        }
    }
    return ((lvl[a]<lvl[b])? a:b );
}

// u =lca node
ii query(int u,int v){
    int chid,chpos;
    Chain *ch; ii ret=0;
    while(lvl[u]<lvl[v]){
        chid=chainid[v];chpos=chainpos[v]; ch=chains[chid];
        if(lvl[head[v]]>lvl[u]){
            ret+=ch->query(1,0,(ch->n)-1,chainpos[head[v]],chainpos[v]);
        }
        else{
            ret+=ch->query(1,0,(ch->n)-1,chainpos[u]+1,chainpos[v]);
        }
        v=parent[head[v]];
    }
    return ret;
}
// u =node....
void update(int u,ii val){
    int chid,chpos;
    Chain *ch; ii ret=0;
    chid=chainid[u];chpos=chainpos[u]; ch=chains[chid];
    ch->update(1,0,(ch->n)-1,chainpos[u],val);
}
//  Finish..................................




int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(i=0;i<=n;i++){ G[i].clear(); }


        for(i=0;i<n;i++){
            scanf("%d",&cost[i]);
        }

        int u,v;
        for(i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        // heavy - light Decompose......
        hld(0);

        scanf("%d",&q);
        printf("Case %d:\n",t++);

        int type,lc_node;
        for(i=1;i<=q;i++){
            scanf("%d %d %d",&type,&u,&v);
            if(!type){
                lc_node=lca(u,v);
                ii res=query(lc_node,u)+query(lc_node,v)+cost[lc_node];
                printf("%d\n",res);
            }
            else{
                cost[u]=v;
                update(u,v);
            }
        }

    }

    return 0;
}
