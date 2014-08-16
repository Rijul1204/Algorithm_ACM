/*
Author : Rashedul Hasan Rijul.
Algo   : LCA O(sqrt) per query..
Problem: Codeforces div-1 round 121( problem c)
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

#define maxm 100100
#define ii int

// G for storing graph......
vector<int>G[maxm],E[maxm];
// n=no of node, nr = sqrt of max heigt.....
int n,nr,root;
// T = for storing immediate parent, L = for storing leve;
// P = for storing parent of current block....
int T[maxm],L[maxm],P[maxm];

// problem  dependent.....
// fin[i] = number of path finish in i.
// st[i]  = number of path start from i.
int fin[maxm],st[maxm],P_E[maxm],ans[maxm];

void init(int n){
    for(int i=0;i<=n;i++){
        G[i].clear(); E[i].clear();
        fin[i]=st[i]=0; ans[i]=0; P_E[i]=0;
    }
    nr=0; root=1;
}
// for calculate L and T.
void dfs(int s,int pre,int lev);
// for calculate P .........
void dfs1(int s);
int find_lca(int u,int v);
ii mini(ii a,ii b){ if(a<b) return a; return b; }
ii maxi(ii a,ii b){ if(a>b) return a; return b; }

int cal(int s,int pre);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    while(scanf("%d",&n)==1){

        init(n);

        for(i=1;i<n;i++){
            scanf("%d %d",&k,&l);
            G[k].push_back(l); E[k].push_back(i);
            G[l].push_back(k); E[l].push_back(i);
        }

        dfs(root,root,1);
        double tmpd=sqrt((double)nr);
        int tmp=tmpd;
        if((tmp*tmp)!=nr) tmp++; nr=tmp;

        dfs1(root);

        int q,u,v;

		scanf("%d",&q);
        for(i=1;i<=q;i++){
            scanf("%d %d",&u,&v);
            int lca=find_lca(u,v);
            fin[lca]+=2;
            st[u]++; st[v]++;
        }
        cal(root,root);

        for(i=1;i<n;i++){
            if(i>1) printf(" ");
            printf("%d",ans[i]);
        }
        puts("");

    }

    return 0;
}

int cal(int s,int pre){

    int i,j,k,ret=st[s]-fin[s];

    for(i=0;i<G[s].size();i++){
        k=G[s][i];
        if(k==pre) continue;
        ret+=cal(k,s);
    }
    ans[P_E[s]]+=ret;
    return ret;
}

int find_lca(int x,int y){

    while(P[x]!=P[y]){
        if(L[x]>L[y]){
            x=P[x];
        }
        else y=P[y];
    }
    while(x!=y){
        if(L[x]>L[y]){
            x=T[x];
        }
        else y=T[y];
    }

    return x;
}

void dfs1(int s){

    if(L[s]<nr) P[s]=root;
    else{
        if(!(L[s]%nr)){
            P[s]=T[s];
        }
        else{
            P[s]=P[T[s]];
        }
    }

    for(int i=0;i<G[s].size();i++){
        int k=G[s][i];
        if(L[k]<=L[s]) continue;
        dfs1(k);
    }

}

void dfs(int s,int pre,int lev){

    int i,k;

    T[s]=pre;
    L[s]=lev;
    nr=maxi(nr,lev);

    for(i=0;i<G[s].size();i++){
        k=G[s][i];
        if(k==pre){ P_E[s]=E[s][i]; continue; }
        dfs(k,s,lev+1);
    }
}
