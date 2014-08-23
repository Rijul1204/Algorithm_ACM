/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-08-23
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

#define maxm 210
#define maxn ((1<<8)+2)
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

int s,n,m;
ii curr_mask1,curr_mask2,req;
int cost[maxm],masks[maxm];

char str[maxm];

int dp[maxm][maxn][maxn];
int vis[maxm][maxn][maxn],kas=1;

int cal(int ind,int mask1,int mask2){

    if(mask1==req && mask2==req) return 0;
    if(ind<=0) return inf;

    if(vis[ind][mask1][mask2]==kas) return dp[ind][mask1][mask2];
    vis[ind][mask1][mask2]=kas;

    int ret=inf,ret1;

    ii tmp_mask=(mask1&masks[ind]);

    ret=mini(ret,cal(ind-1,mask1|masks[ind],mask2|tmp_mask)+cost[ind]);
    ret=mini(ret,cal(ind-1,mask1,mask2));

    return dp[ind][mask1][mask2]=ret;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(scanf("%d %d %d",&s,&m,&n)==3){
        if(!s) break;

        gets(str);

        curr_mask1=curr_mask2=0;
        req=((1<<s)-1);
        int ans=0;
        for(i=1;i<=m;i++){
            gets(str);

            char *pch=strtok(str," ");
            ans+=(atoi(pch));

            pch=strtok(NULL," ");
            int mask=0;
            while(pch!=NULL){
                mask=on(mask,atoi(pch)-1);
                pch=strtok(NULL," ");
            }

            ii tmp_mask=( (curr_mask1) & mask);

            curr_mask1|=(mask);
            curr_mask2|=(tmp_mask);

        }

        for(i=1;i<=n;i++){
            gets(str);

            char *pch=strtok(str," ");
            cost[i]=atoi(pch);

            pch=strtok(NULL," ");
            masks[i]=0;
            while(pch!=NULL){
                masks[i]=on(masks[i],atoi(pch)-1);
                pch=strtok(NULL," ");
            }
        }

        ans+=cal(n,curr_mask1,curr_mask2);

        printf("%d\n",ans);
        kas++;
    }

    return 0;
}

