#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

#define maxm 105
#define inf (1<<29)
#define ii int

vector<int>v[maxm],w[maxm];
int n,lim;

int dp[maxm][maxm][maxm];
int fl[maxm][maxm][maxm],kas=1;

ii mini(ii a,ii b){
    if(a<b) return a; return b;
}
int cal(int s,int pre,int child,int rem);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&lim);

        for(i=0;i<=n;i++){
            v[i].clear(); w[i].clear();
        }

        for(i=1;i<n;i++){
            scanf("%d %d %d",&k,&l,&j);
            v[k].push_back(l);
            v[l].push_back(k);
            w[k].push_back(j);
            w[l].push_back(j);
        }

        printf("Case %d: %d\n",t++,cal(1,1,v[1].size(),lim));
        kas++;

    }

    return 0;
}

int cal(int s,int pre,int child,int rem){

    if(rem<0) return inf;

    if(fl[s][child][rem]==kas) return dp[s][child][rem];
    fl[s][child][rem]=kas;

    int i,j,k,l;
    int ret=0,ret1;

    for(i=0;i<child;i++){
        k=v[s][i];
        if(k==pre) continue;
        ret+=cal(k,s,v[k].size(),lim);
        for(j=0;j<rem;j++){
            ret=mini(ret,cal(s,pre,i,j)+cal(k,s,v[k].size(),rem-j-w[s][i]));
        }
        ret1=ret;

    }
    if(rem==lim) ret++;
    return dp[s][child][rem]=ret;
}

int dfs(int s){

}
