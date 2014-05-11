#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

#define maxm 50100
#define maxe 100100

struct edge{
    int u,v,cost;
};
edge edges[maxe];

int pre[maxm],n,m,L[maxm],T[maxm],P[maxm],nr,cost[maxm],q,x,y,ct[maxm];
vector<int>v[maxm],w[maxm];
int find(int x){
    if(pre[x]==x) return x;
    return pre[x]=find(pre[x]);
}
bool comp(edge a,edge b){
    return a.cost<b.cost;
}
int maxi(int a,int b){
    if(a>b) return a;
    return b;
}
void dfs(int node,int co);
void dfs1(int s,int lev,int pre);
int lca(int x,int y);

int main(){

    int i,j,k,l,test,t=1;

//  freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&m);

        for(i=0;i<=n;i++){
            v[i].clear();
            w[i].clear();
            pre[i]=i;
        }
        for(i=0;i<m;i++){
            scanf("%d %d %d",&k,&l,&j);
            edges[i].u=k; edges[i].v=l; edges[i].cost=j;
        }
        sort(edges,edges+m,comp);

        for(i=0;i<m;i++){
            k=find(edges[i].u); l=find(edges[i].v);
            if(k==l) continue;
            pre[k]=l;
            v[edges[i].u].push_back(edges[i].v);
            v[edges[i].v].push_back(edges[i].u);

            w[edges[i].u].push_back(edges[i].cost);
            w[edges[i].v].push_back(edges[i].cost);
        }
        nr=0;
        ct[1]=0;
        dfs1(1,0,1);
        k=sqrt(nr);
        if(k*k!=nr) k++;
        nr=k;
        dfs(1,0);
        scanf("%d",&q);
        printf("Case %d:\n",t++);
        for(i=1;i<=q;i++){
            scanf("%d %d",&x,&y);
            printf("%d\n",lca(x,y));
        }



    }

    return 0;
}

int lca(int x,int y){

    int ret=0;

    while(P[x]!=P[y]){
        if(L[x]>L[y]){
            ret=maxi(ret,cost[x]);
            x=P[x];
        }
        else{
            ret=maxi(ret,cost[y]);
            y=P[y];

        }
    }

    while(x!=y){
        if(L[x]>L[y]){

            ret=maxi(ret,ct[x]);
            x=T[x];
        }
        else{
            ret=maxi(ret,ct[y]);
            y=T[y];

        }
    }

    return ret;

}

void dfs(int node,int co){

    int i,j,k,l;

    if(L[node]<nr){
        P[node]=1;
    }
    else{
        if(!(L[node]%nr)){
            P[node]=T[node];
        }
        else{
            P[node]=P[T[node]];
        }
    }
    cost[node]=co;

    if((L[node]+1)%nr==0) co=0;
    for(i=0;i<v[node].size();i++){
        k=v[node][i];
        if(L[k]<=L[node]) continue;
        dfs(k,maxi(co,w[node][i]));
    }

}

void dfs1(int s,int lev,int pre){

    int i,j,k,l;
    nr=maxi(nr,lev);
    T[s]=pre;
    L[s]=lev;
    for(i=0;i<v[s].size();i++){
        k=v[s][i];
        if(k==pre) continue;
        ct[k]=w[s][i];
        dfs1(k,lev+1,s);
    }

}
