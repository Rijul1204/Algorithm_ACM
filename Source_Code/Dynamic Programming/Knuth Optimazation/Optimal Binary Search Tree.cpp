#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 270
#define ii int
#define inf (1<<30)

struct node{
    ii root,cost,sum;
    node(){}
    node(ii _root,ii _cost,ii _sum){
        root=_root,cost=_cost,sum=_sum;
    }
};

int n;
ii f[maxm];
node dp[maxm][maxm];
bool fl[maxm][maxm];

node cal(ii b,ii e);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out1.txt","w",stdout);

    while(scanf("%d",&n)==1){

        for(i=1;i<=n;i++){
            scanf("%d",&f[i]);
        }

        memset(fl,0,sizeof(fl));
        node ans=cal(1,n);
        printf("%d\n",ans.cost);
    }

    return 0;
}

node cal(ii b,ii e){

    if(b>e) return node(b,0,0);
    if(b==e) return node(b,0,f[b]);

    if(fl[b][e]) return dp[b][e];
    fl[b][e]=1;

    node ret=node(0,inf,inf);
    node ret1,retl,retr;

	retl=cal(b,e-1); retr=cal(b+1,e);
	int lr=retl.root,rr=retr.root;

	for(int i=lr;i<=rr;i++){
        retl=cal(b,i-1); retr=cal(i+1,e);
        ret1.cost=retl.cost+retr.cost+retl.sum+retr.sum;
        ret1.sum=retl.sum+retr.sum+f[i];
        ret1.root=i;
        if(ret.cost>ret1.cost) ret=ret1;
    }

    return dp[b][e]=ret;
}
