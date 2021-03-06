/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-11-19
Algo        : Counting number of distinct lcs.
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

#define maxm 1550
#define maxc 30
#define inf (1<<29)
#define ii long long int

#define mod 23102009

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,ii>
#define mp  make_pair
#define uu first
#define vv second

ii on(ii n,ii k){ return (n|(1<<k)); }
ii off(ii n,ii k){ return (n-(n&(1<<k))); }
bool chck(ii n,ii k){ return (n&(1<<k)); }

ii mini(ii a,ii b){ if(a<b) return a;  return b;  }
ii maxi(ii a,ii b){ if(a>b) return a;  return b;  }

int n,m;

char s1[maxm],s2[maxm];
int pre1[maxm][maxc],pre2[maxm][maxc];

pii dp[maxm][maxm];
int vis[maxm][maxm],kas=1;

void init(char *s,int pre[maxm][maxc]){

    int i,j;

	for(j=0;j<26;j++){
		pre[0][j]=-1;
	}

    for(i=0;s[i];i++){
        for(j=0;j<26;j++){
            //printf("%d %d %c %d\n",i,j,s[i],pre[i][j]);
            if(s[i]-'a'==j){
                pre[i][j]=i;
            }
            else{
                if(i) pre[i][j]=pre[i-1][j];
            }
            //printf("%d %d %c %d\n",i,j,s[i],pre[i][j]);
        }
    }
}

pii cal(int ind1,int ind2){

    if(ind1<0 || ind2<0) return pii(0,1);

    if(vis[ind1][ind2]==kas) return dp[ind1][ind2];
    vis[ind1][ind2]=kas;

    int i;
    ii ret_way=1,ret_len=0;
    pii now;

    if(s1[ind1]==s2[ind2]){
        now=cal(ind1-1,ind2-1);
        now.uu++;
        return dp[ind1][ind2]=now;
    }

    for(i=0;i<26;i++){
        now=cal(pre1[ind1][i],pre2[ind2][i]);
        if(now.uu==0) continue;
        if(now.uu>ret_len){
            ret_len=now.uu;
            ret_way=now.vv;
        }
        else if(now.uu==ret_len){
            ret_way+=now.vv;
            if(ret_way>=mod){
                ret_way%=mod;
            }
        }
    }
    now=mp(ret_len,ret_way);

    return dp[ind1][ind2]=now;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%s %s",s1,s2);

        init(s1,pre1);
        init(s2,pre2);

//        for(i=0;s1[i];i++){
//            printf("i= %d : ",i);
//            for(j=0;j<4;j++){
//                printf("%d ",pre1[i][j]);
//            }
//            puts("");
//        }

        kas++;
        pii ans=cal(strlen(s1)-1,strlen(s2)-1);

        printf("%d %lld\n",ans.uu,ans.vv);
    }

    return 0;
}

