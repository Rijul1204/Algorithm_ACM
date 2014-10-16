/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-09-21
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
#define maxc 100
#define inf (1<<29)
#define ii long long int

#define mod 1000000007

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

int n,m;
ii dp1[maxc];

void fix(ii &ret){
    if(ret>=mod) ret%=mod;
}

ii base[maxc][maxc],unit[maxc][maxc],res[maxc][maxc];
void build_matrix(int k);

void cal(ii a[maxc][maxc],ii b[maxc][maxc],ii n){

    ii ret[maxc][maxc];
    int i,j,k;
	memset(ret,0,sizeof(ret));

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				ret[i][j]+=(a[i][k]*b[k][j]);
				fix(ret[i][j]);
			}
		}
	}
	memcpy(a,ret,sizeof(ret));
}

void exp(ii r[maxc][maxc],ii n,int n1){

	ii b[maxc][maxc];
	memcpy(r,unit,sizeof(unit));
	memcpy(b,base,sizeof(base));

	while(n>0){
		if(n%2==1) cal(r,b,n1);
		n/=2;
		cal(b,b,n1);
	}
}


ii cal1(int r,int c){

    if(c<1 || c>m) return 0;
    if(r==n) return 1;


    if(r%2) return cal1(r+1,c-1)+cal1(r+1,c+1);
    else    return cal1(r+1,c-1)+cal1(r+1,c+1)+cal1(r+1,c);

}


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out1.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&m);

        ii ans=0,ans1=0;

        if(n<=2){
            for(i=1;i<=m;i++){
                ans+=cal1(1,i);
                fix(ans);
            }
            printf("%lld\n",ans);
            continue;
        }



        int n1=n/2+n%2;

        build_matrix(m);

        exp(res,n1-1,m);

        memset(dp1,0,sizeof(dp1));

        /*puts("");
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                printf("%2d ",res[i][j]);
            }
            puts("");
        }
        */

        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                dp1[i]+=res[i][j];
                ans1+=res[i][j];
                fix(ans1);
                fix(dp1[i]);
            }
        }

        if(n%2==0){
            ans1=0;
            for(i=1;i<=m;i++){
                if(i>1) ans1+=dp1[i-1];
                if(i<m) ans1+=dp1[i+1];
                fix(ans1);
            }
        }

        printf("%lld\n",ans1);

    }

    return 0;
}


void build_matrix(int K){

    int i,j;

    for(i=0;i<=K+1;i++){
        for(j=0;j<=K+1;j++){
            if(i==j) unit[i][j]=1;
            else     unit[i][j]=0;
            base[i][j]=0;
        }
    }

    memset(base,0,sizeof(base));

    for(i=0;i<=K;i++){
        for(j=i-2;j<=i+2;j++){
			if(j<1 || j>m) continue;
            if(j==i) continue;
            base[i][j]=1;
        }
        if(i>1){
            base[i][i]++;
        }
        if(i<m){
            base[i][i]++;
        }

    }

    /*
    for(i=1;i<=K;i++){
        for(j=1;j<=K;j++){
            printf("%2d ",base[i][j]);
        }
        puts("");
    }*/

}
