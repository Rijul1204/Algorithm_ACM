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

#define maxm 32
#define maxn 6002
#define cn   3000

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

char s[155];
int n,num[maxm],op[maxm],ans;

int vis[maxm][maxm][maxn];
int vis_num[maxn],kas=1;

void dfs(int ind,int brac,int res){

    if(vis[ind][brac][res+cn]==kas) return ;
    vis[ind][brac][res+cn]=kas;

    if(ind>n){
        if(vis_num[res+cn]==kas) return;
        ans++;
		vis_num[res+cn]=kas;
        return ;
    }

    if(brac) dfs(ind,brac-1,res);

    int sgn=brac%2;
    if(sgn) sgn=-1;
    else    sgn=1;

    int prev_sgn=op[ind-1];
    if(prev_sgn) prev_sgn=-1;
    else         prev_sgn=1;

    int curr_num=sgn*prev_sgn*num[ind];

    // not adding any bracket . . .
    dfs(ind+1,brac,res+curr_num);

    // adding bracket . . .
    if(prev_sgn==-1){
        dfs(ind+1,brac+1,res+curr_num);
    }

}


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(gets(s)){

        char *tmp=strtok(s," ");

        int tot=1;

        num[tot]=atoi(tmp);

        while(1){

            tmp=strtok(NULL," ");
            if(tmp==NULL) break;

            if(tmp[0]=='+') op[tot++]=0;
            else            op[tot++]=1;

            tmp=strtok(NULL," ");
            num[tot]=atoi(tmp);
        }
        n=tot;

        ans=0;

        kas++;
        dfs(2,0,num[1]);

        printf("%d\n",ans);

    }


    return 0;
}

