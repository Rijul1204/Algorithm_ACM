/*
Author : Rashedul Hasan Rijul ( Silent_coder ).
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define maxm 1050
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

struct city{
    char os[15];
    int t_value;
};
city city_south[maxm],city_north[maxm];

int n,m;

pii dp[maxm][maxm];
int vis[maxm][maxm],kas=1;

pii maxi(pii a,pii b){
    if(a.uu==b.uu){
        if(a.vv<b.vv) return a;
        return b;
    }
    if(a.uu>b.uu) return a;
    return b;
}
pii cal(int ind_s,int ind_n);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        char tmp[20];

        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%s %s %d",tmp,city_south[i].os,&city_south[i].t_value);
        }

        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%s %s %d",tmp,city_north[i].os,&city_north[i].t_value);
        }

        printf("%d %d\n",cal(1,1).uu,cal(1,1).vv);

        kas++;

    }

    return 0;
}

pii cal(int ind_s,int ind_n){

    if(ind_s>n || ind_n>m) return mp(0,0);

    if(vis[ind_s][ind_n]==kas) return dp[ind_s][ind_n];
    vis[ind_s][ind_n]=kas;

    pii ret=mp(0,0);
    pii ret1=mp(0,0);

    if(strcmp(city_south[ind_s].os,city_north[ind_n].os)==0){
        ret1=cal(ind_s+1,ind_n+1);
        ret1.uu+=(city_south[ind_s].t_value+city_north[ind_n].t_value);
        ret1.vv++;
    }

    ret=maxi(cal(ind_s+1,ind_n),cal(ind_s,ind_n+1));
    ret=maxi(ret,ret1);

    return dp[ind_s][ind_n]=ret;
}

