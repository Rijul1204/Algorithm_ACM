/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-11-12
Algo        : Tortoise-Hare
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


ii n;
ii a,b;

ii f(ii x){
    ii ret=x*x;
    ret%=n;
    ret*=a;
    ret%=n;
    ret+=b; ret%=n;
    return ret;
}


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(scanf("%lld",&n)==1){

        if(!n) break;

        scanf("%lld %lld",&a,&b);

        ii tortoise=0,hare=0;

        // finding k*cyclelenght
        while(1){
            tortoise=f(tortoise);

            hare=f(f(hare));

            if(tortoise==hare) break;
        }

        // finding starting point of cycle .. . .
        int ind=0; // starting ind ..

        hare=0;

        while(1){

            tortoise=f(tortoise);
            hare=f(hare);
            ind++;
            if(tortoise==hare) break;
        }

        // curr hare is starting value of cycle .. .

        // finding cycle length . . . .

        ii cycle_len=0;
        while(1){
            hare=f(hare);
            cycle_len++;
            if(tortoise==hare) break;
        }

        // remaining soldier (n-cycle_len)
        printf("%lld\n",n-cycle_len);
    }

    return 0;
}

