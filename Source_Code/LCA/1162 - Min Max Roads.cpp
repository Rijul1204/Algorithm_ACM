/*
Author : Rashedul Hasan Rijul.
Algo   : LCA O(sqrt) per query..
Problem: Min-Max Roads (light oj )
*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;

#define maxm 100010
#define inf (1<<28)

struct node{
    int min1,max1;
    node(){}
    node(int a,int b){ min1=a; max1=b;}
};

// n=no of node, nr = sqrt of max heigt.....
int n,nr,T[maxm],L[maxm],costT[maxm],P[maxm],costP1[maxm],costP2[maxm];
// v for storing graph , w =weight of the edge ......
vector<int>v[maxm],w[maxm];

int mini(int a,int b){
    if(a<b) return a; return b;
}
int maxi(int a,int b){
    if(a>b) return a; return b;
}
// for calculate P .........
void dfs(int node,int val1,int val2);
// for calculate L and T.
void dfs1(int s,int lev,int pre);
// finding LCA .....
node lca(int x,int y);

int main(){

    int i,j,k,l,test,t=1;

   //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(i=0;i<=n;i++){
            v[i].clear();w[i].clear();
        }

        for(i=1;i<n;i++){
            scanf("%d %d %d",&k,&l,&j);
            v[k].push_back(l); w[k].push_back(j);
            v[l].push_back(k); w[l].push_back(j);
        }

        nr=0;
        dfs1(1,0,1);
        // fix height sqrt
        k=sqrt(nr); if(k*k!=nr) k++; nr=k;

        dfs(1,0,0);

        int q;
        scanf("%d",&q);
        printf("Case %d:\n",t++);
        for(i=1;i<=q;i++){
            scanf("%d %d",&k,&l);
            node ans=lca(k,l);
            printf("%d %d\n",ans.min1,ans.max1);
        }


    }

    return 0;
}
node lca(int x,int y){

    node ret=node(inf,-inf);

    while(P[x]!=P[y]){
        if(L[x]>L[y]){
            ret.min1=mini(ret.min1,costP1[x]);
            ret.max1=maxi(ret.max1,costP2[x]);
            x=P[x];
        }
        else{
            ret.min1=mini(ret.min1,costP1[y]);
            ret.max1=maxi(ret.max1,costP2[y]);
            y=P[y];
        }
    }
    while(x!=y){
        if(L[x]>L[y]){
            ret.min1=mini(ret.min1,costT[x]);
            ret.max1=maxi(ret.max1,costT[x]);
            x=T[x];
        }
        else{
            ret.min1=mini(ret.min1,costT[y]);
            ret.max1=maxi(ret.max1,costT[y]);
            y=T[y];
        }
    }

    // Lca node = x
	return ret;

}

//val1= min cost of edge;
//val2= max cost of edge;
void dfs(int node,int val1,int val2){

    int i,j,k,l;

    if(L[node]<nr) P[node]=1;
    else{
        if(!(L[node]%nr)){
			val1=val2=costT[node];
            P[node]=T[node];
        }
        else{
            P[node]=P[T[node]];
        }
    }
    costP1[node]=val1;
    costP2[node]=val2;

    for(i=0;i<v[node].size();i++){
        k=v[node][i];
        if(L[k]<=L[node]) continue;
        dfs(k,mini(val1,w[node][i]),maxi(val2,w[node][i]));
    }
}

void dfs1(int s,int lev,int pre){

    int i,j,k,l;
    T[s]=pre;
    L[s]=lev;
    nr=maxi(nr,lev);

    for(i=0;i<v[s].size();i++){
        k=v[s][i]; if(k==pre) continue;
        costT[k]=w[s][i];
        dfs1(k,lev+1,s);
    }

}
