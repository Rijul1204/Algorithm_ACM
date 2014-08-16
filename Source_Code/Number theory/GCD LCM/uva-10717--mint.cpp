/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-07-25
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

int n,t;

ii gcd(ii a,ii b){
    if(!a) return b;
    if(!b) return a;
    return gcd(b%a,a);
}

ii lcm(ii a,ii b){
    return (a/gcd(a,b))*b;
}

int coin[maxm],table[maxm];
int l_ans[maxm],h_ans[maxm];

int main(){

    int i,j,k,l;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(scanf("%d %d",&n,&t)==2){

        if(!n && !t) break;

        for(i=1;i<=n;i++){
            scanf("%d",&coin[i]);
        }

        for(i=1;i<=t;i++){
            scanf("%d",&table[i]);
            l_ans[i]=h_ans[i]=-1;
        }

        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                for(k=j+1;k<=n;k++){
                    for(l=k+1;l<=n;l++){
                        ii now=lcm(lcm(coin[i],coin[j]),lcm(coin[k],coin[l]));

                        for(ii tt=1;tt<=t;tt++){

                            ii lo=(table[tt]/now)*now;
                            ii hi;
                            if(table[tt]%now==0) hi=lo;
                            else                hi=lo+now;

                            if(l_ans[tt]==-1 || l_ans[tt]<lo) l_ans[tt]=lo;
                            if(h_ans[tt]==-1 || h_ans[tt]>hi) h_ans[tt]=hi;

                        }
                    }
                }
            }
        }

        for(i=1;i<=t;i++){
            printf("%d %d\n",l_ans[i],h_ans[i]);
        }
    }


    return 0;
}

