#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define maxm 18
#define inf (1<<29)
#define maxn (1<<17)
#define ii long long int

int on(int n,int k){
    return (n|(1<<k));
}
int off(int n,int k){
    return (n-(n&(1<<k)));
}
bool chck(int n,int k){
    return (n&(1<<k));
}

vector<int>v[maxm];
ii dp[maxn],dp1[maxm][maxn];
int n,m;
ii cost[maxm][maxm];
bool fl[maxn],fl1[maxm][maxn];


ii mini(ii a,ii b){
    if(a<b) return a; return b;
}
ii cal(int mask,int pos);
ii f_cost(int ind,int mask);
ii cal_cost(int ind1,int ind2);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&m);

        for(i=0;i<=m;i++){
            v[i].clear();
        }

        for(i=0;i<n;i++){
            scanf("%d",&k);
            k--;
            v[k].push_back(i);
        }

        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                if(i==j) continue;
                cost[i][j]=cal_cost(i,j);
            }
        }

        memset(fl,0,sizeof(fl));
        memset(fl1,0,sizeof(fl1));

        printf("Case %d: %lld\n",t++,cal(0,0));

    }

    return 0;
}


ii cal(int mask,int pos){

    if(mask==(1<<m)-1) return 0;

    if(fl[mask]) return dp[mask];
    fl[mask]=1;

    int i,enter=0;
    ii ret=inf;
    int mask1=(1<<m)-1;

    for(i=0;i<m;i++){
        if(chck(mask,i)) continue;
        if(!enter) ret=cal(on(mask,i),pos+v[i].size()-1)+f_cost(i,mask1^mask);
        else ret=mini(ret,cal(on(mask,i),pos+v[i].size()-1)+f_cost(i,mask1^mask));
        enter=1;
    }

    return dp[mask]=ret;
}


ii f_cost(int ind,int mask){

    if(mask==0) return 0;

    if(fl1[ind][mask]) return dp1[ind][mask];
    fl1[ind][mask]=1;

    int i,j,k;
    mask=off(mask,ind);

    for(i=0;i<m;i++){
        if(chck(mask,i)){
            return dp1[ind][mask]=f_cost(ind,off(mask,i))+cost[ind][i];
        }
    }


    return dp1[ind][mask]=0;
}

ii cal_cost(int ind1,int ind2){

    int i,j=0;
    ii ret=0,ret1=0;

    for(i=0;i<v[ind1].size();i++){
        while(j<v[ind2].size()){
            if(v[ind2][j]>v[ind1][i]) break;
			j++;
            ret1++;
        }
        ret+=ret1;
    }

    return ret;
}
