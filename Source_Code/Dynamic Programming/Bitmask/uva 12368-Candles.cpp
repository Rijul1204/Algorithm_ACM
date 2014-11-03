/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-10-14
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

#define maxm 2010
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

struct node{
    ii val;
    int mask;
};
node nodes[maxm];

bool comp(node a,node b){
    return a.val<b.val;
}

int age[maxm],age_mask[maxm];
int n,m;

int dp[maxm][maxm];
bool vis[maxm][maxm];

ii gen_val(int mask){

    ii ret=0;

    for(int i=9;i>=0;i--){
        if(!chck(mask,i)) continue;
        ret*=(ii)10;
        ret+=(ii)i;
    }

    return ret;
}

int find_mask(int age){

    int ret=0;

    while(age){
        if(chck(ret,age%10)) return -1;
        ret=on(ret,age%10);
        age/=10;
    }
    return ret;
}

int can(int mask,int req){

    if(!req) return 1;
    if(req<0) return 0;

    if(vis[mask][req]) return dp[mask][req];
    vis[mask][req]=1;

    int req1=req,mask1=mask;

    while(req1){
        int now=req1%10;
        if(!chck(mask1,now)) break;
        mask1=off(mask1,now);
        req1/=10;
    }

    if(!req1){
        return dp[mask][req]=1;
    }

    int i,j;

    for(i=1;i<req;i++){
        j=req-i;
        if(j<=i) break;
        if(age_mask[i]==-1 || age_mask[j]==-1) continue;
        if(age_mask[i]&age_mask[j]) continue;
        if( (age_mask[i]&mask) !=age_mask[i]) continue;
        if( (age_mask[j]&mask) !=age_mask[j]) continue;
        return dp[mask][req]=1;
    }

    return dp[mask][req]=0;
}


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    for(i=1;i<=100;i++){
        age_mask[i]=find_mask(i);
    }

    for(i=0;i<1024;i++){
        nodes[i].val=gen_val(i);
        nodes[i].mask=i;
    }
    sort(nodes,nodes+1024,comp);
    //printf("%lld\n",nodes[1023].val);

    while(scanf("%d",&n)==1){

        if(!n) break;

        for(i=1;i<=n;i++){
            scanf("%d",&age[i]);
        }

        printf("Case %d: ",t++);
        for(i=0;i<1024;i++){
            for(j=1;j<=n;j++){
                if(!can(nodes[i].mask,age[j])) break;
            }
            if(j>n){
                printf("%lld\n",nodes[i].val);
                break;
            }
        }
    }

    return 0;
}

