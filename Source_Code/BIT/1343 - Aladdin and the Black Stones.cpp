/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-08-09
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

#define maxm 501
#define inf (1<<29)
#define ii unsigned int

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

// 2-D BIT.......................

#define max_v maxm+2

struct bit_2{

    ii BIT[max_v+10][max_v+10];
    ii n;

    void init(int n1){
        n=n1;
        memset(BIT,0,sizeof(BIT));
    }
    void init(){
        n=max_v;
        memset(BIT,0,sizeof(BIT));
    }
    void update( ii x,ii y ,ii v)
    {
        while( x<=n ){
            ii ty = y;
            while( ty<=n ){
                BIT[x][ty] += v;
                ty += ty & -ty;
            }
            x += x & -x;
        }
    }
    ii read( ii x,ii y ){
        ii s = 0;
        while( x ){
            ii ty = y;
            while( ty ){
                s += BIT[x][ty];
                ty -= ty & -ty;
            }
            x -= x & -x;
        }
        return s;
    }
    ii read(int x1,int y1,int x2,int y2){
        if(x1>x2 || y1>y2) return 0;
        return read( x2,y2 ) - read( x1-1,y2 ) - read( x2,y1-1 ) + read( x1-1,y1-1 );
    }
};

// BIT  finish ......
bit_2 bit;

struct node{
    int i,j,sum;
    node(){}
    node(int _i,int _j,int _sum){
        i=_i,j=_j,sum=_sum;
    }
};

node nodes[maxm*maxm];

bool comp(node a,node b){
    if(a.sum==b.sum){
        if(a.i==b.i) return a.j>b.j;
        return              a.i>b.i;
    }
    return a.sum>b.sum;
}

int n,m;
int a[maxm];

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }

        int tot=0;
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                nodes[tot++]=node(i,j,a[i]+a[j]);
            }
        }

        sort(nodes,nodes+tot,comp);

        ii ans=0;

        bit.init();
        bit.update(1,1,1);

        for(i=0;i<tot;i++){
			int x=nodes[i].i,y=nodes[i].j;
            ii ans1=bit.read(x,y);
            ans+=ans1;
            //printf("%d %d %d %d\n",nodes[i].i,nodes[i].j,nodes[i].sum,ans1);
            bit.update(x+1,x+1,ans1);
			bit.update(x+1,y,-ans1);
        }

        printf("Case %d: %u\n",t++,ans);

    }

    return 0;
}

