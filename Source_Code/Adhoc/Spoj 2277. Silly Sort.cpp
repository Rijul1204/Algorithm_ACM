/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-08-08
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

#define maxm 2010
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

int n,M,m,c,sum;
int a[maxm],b[maxm],pos[maxm];
int edge[maxm];
bool vis[maxm];

void dfs(int s){

    if(vis[s]) return ;
    vis[s]=1;
    c++;
    sum+=b[s];
    m=mini(m,b[s]);
    dfs(edge[s]);
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(scanf("%d",&n)==1){

        if(!n) break;

        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
            pos[a[i]]=i;
        }
        sort(a+1,a+n+1);

        for(i=1;i<=n;i++){
            edge[i]=pos[a[i]];
        }

        memset(vis,0,sizeof(vis));
        M=a[1];

        int ans=0,ans1=0;
        for(i=1;i<=n;i++){
            if(vis[i]) continue;
            m=inf,c=0,sum=0;
            dfs(i);
            if(c<=1) continue;
            int ans1=mini((c-2)*m,m+M+(c*M));
            ans+=(ans1+sum);
        }

        printf("Case %d: %d\n\n",t++,ans);
    }

    return 0;
}

