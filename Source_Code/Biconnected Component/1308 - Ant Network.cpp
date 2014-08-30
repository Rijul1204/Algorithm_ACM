/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-08-29.
Algo        : Biconnected-Component.
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

#define maxm 100100
#define inf (1<<29)
#define ii unsigned long long int

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
stack<pii>st_pii;
set<int>sets[maxm];
int n,m,tot,root;
int low[maxm],dep[maxm],tim;
bool vis[maxm],is_cut[maxm];

void dfs(int s,int pre,int root);
void bi_comp(int u,int v){

    while(!st_pii.empty()){

        pii now=st_pii.top(); st_pii.pop();
        sets[tot].insert(now.uu);
        sets[tot].insert(now.vv);

        if(now.uu==u && now.vv==v) break;
        if(now.uu==v && now.vv==u) break;
    }

    tot++;
}

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        ii min_num=0,no_way=1;

        scanf("%d %d",&n,&m);

        // Initialization..
        for(i=0;i<=n;i++){
            G[i].clear();
            sets[i].clear();
        }
        memset(vis,0,sizeof(vis));
        memset(is_cut,0,sizeof(is_cut));
        while(!st_pii.empty()) st_pii.pop();
        tot=0,tim=1;

        for(i=1;i<=m;i++){
            scanf("%d %d",&k,&l);
            G[k].push_back(l);
            G[l].push_back(k);
        }

        for(i=0;i<n;i++){
            if(vis[i]) continue;
            root=i;
            dfs(i,i,root);
        }

        for(i=0;i<n;i++){
            if(is_cut[i]) break;
        }
        if(i>=n){
            no_way=n*(n-1); no_way/=2;
            min_num=2;
            printf("Case %d: %llu %llu\n",t++,min_num,no_way);
            continue;
        }

        for(i=0;i<tot;i++){
            //printf("set : ");
            ii val=0,sum=0;
            int cut_count=0;
            for(set<int>::iterator it=sets[i].begin();it!=sets[i].end();it++){
                //printf("%d ",*it);
                if(is_cut[*it]){
                    cut_count++;
                    continue;
                }

                sum++;
                val=1;
            }
            if(!cut_count && sets[i].size()==2){
                min_num+=2;
                continue;
            }
            if(cut_count>1){
                continue;
            }

            if(val){
                min_num+=val;
                no_way*=sum;
            }
            //puts("");
        }

        printf("Case %d: %llu %llu\n",t++,min_num,no_way);

    }

    return 0;
}


void dfs(int s,int pre,int root){

    if(vis[s]) return;

    vis[s]=1;
    low[s]=dep[s]=tim++;

    // bi-connected with a single vertex
    if(G[s].size()==0){
        sets[tot++].insert(s);
        return ;
    }

    int i,j,k,c=0;

    for(i=0;i<G[s].size();i++){
        int d=G[s][i];

        if(d==pre) continue;

        if(vis[d] && dep[d]<dep[s]){
            st_pii.push(mp(s,d));
            low[s]=mini(low[s],dep[d]);
        }
        else if(!vis[d]){
            st_pii.push(mp(s,d));

            dfs(d,s,root); c++;

            if(low[d]>=dep[s]){
                bi_comp(s,d);
                if(s!=root){
                    is_cut[s]=1;
                }
            }
            low[s]=mini(low[s],low[d]);
        }
    }

    if(s==root && c>1){
        is_cut[s]=1;
    }
}
