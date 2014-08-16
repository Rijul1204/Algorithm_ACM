/*
Author : Rashedul Hasan Rijul ( Silent_coder ).
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

#define maxm 1000
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

int n;
char s[maxm],out[maxm];
bool fl[maxm];

char to_lower(char ch){
    if(ch<'a') return ch-'A'+'a';
    return ch;
}

bool comp(char ch1,char ch2){
    char ch3=to_lower(ch1);
    char ch4=to_lower(ch2);
    if(ch3==ch4){
        return ch1<ch2;
    }
    return ch3<ch4;
}

void back(int ind){

    if(ind==n){
        puts(out);
        return ;
    }

    for(int i=0;s[i];i++){
        if(fl[i]) continue;
        fl[i]=1;
        out[ind]=s[i];
        back(ind+1);
        fl[i]=0;
        while(s[i+1]==s[i]){
            i++;
        }
    }
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%s",s);
        n=strlen(s);
        sort(s,s+n,comp);

        memset(fl,0,sizeof(fl));
        out[n]=0;
        back(0);
    }


    return 0;
}

