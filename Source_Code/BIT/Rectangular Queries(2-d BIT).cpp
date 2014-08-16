#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
#include<stack>
using namespace std;

#define maxm 350
#define maxn 15
#define inf (1<<29)
#define ii int

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

// 2-D BIT.......................

#define mod 5000000
#define max_v 500

struct BIT_2{

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
BIT_2 bit[maxn];


ii mini(ii a,ii b){
    if(a<b) return a;
    return b;
}
ii maxi(ii a,ii b){
    if(a>b) return a;
    return b;
}

int n,q,mat[maxm][maxm];


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&n);

    for(i=1;i<=10;i++) bit[i].init(n);

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&k);
            bit[k].update(i,j,1);
        }
    }

    scanf("%d",&q);

    int x1,y1,x2,y2;
    for(i=1;i<=q;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int ans=0;
        for(j=1;j<=10;j++){
            if(bit[j].read(x1,y1,x2,y2)) ans++;
        }
        printf("%d\n",ans);
    }

    return 0;
}

