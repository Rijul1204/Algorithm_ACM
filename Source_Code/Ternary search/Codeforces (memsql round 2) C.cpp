/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-08-12
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

#define maxm 200010
#define inf (1<<30)
#define ii __int64

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

#define lim 100000

struct node{
    int val,ind;
    node(){}
    node(int _ind,int _val){
        ind=_ind;
        val=_val;
    }
};

bool operator <(const node &a,const node &b){
    return a.val>b.val;
}

bool cmp_cand(node a,node b){
    return a.val>b.val;
}

int n,m;
int a[maxm],b[maxm],pn[maxm];
vector<int>vote[maxm];
vector<node>cand;

ii func(int x){

    memset(pn,0,sizeof(pn));
    priority_queue<node>pq;

    //printf("HERE %d:\n",x);

    ii ret=0;
    int i,my_vote=vote[0].size()+x;

    for(i=0;i<cand.size();i++){
        int curr_vote=cand[i].val;
        int ind=cand[i].ind;
        //printf("%d %d\n",ind,curr_vote);
        while(curr_vote>=my_vote){
            curr_vote--;
            x--;
            if(x<0) return inf;
            ret+=vote[ind][pn[ind]];
            pn[ind]++;
        }
        if(curr_vote){
            pq.push(node(ind,vote[ind][pn[ind]]));
            pn[ind]++;
        }
    }

    while(x--){
        node now=pq.top(); pq.pop();
        ret+=now.val;
        int ind=now.ind;
        if(pn[ind]>=vote[ind].size()) continue;

        pq.push(node(ind,vote[ind][pn[ind]]));
        pn[ind]++;
    }

    return ret;
}

ii ts(){

    ii lo=0,hi=n-vote[0].size();

    while(lo<hi){

        ii f=lo+(hi-lo)/3;
        ii g=lo+((hi-lo)*2)/3;

        if(lo>=hi-3){
            ii ret=inf;
            for(int i=lo;i<=hi;i++){
                ret=mini(ret,func(i));
            }
            return ret;
        }

        ii f_val=func(f);
        ii g_val=func(g);

        if(f_val<g_val){
            hi=g;
        }
        else{
            lo=f;
        }
    }

    lo=lo+hi; lo/=2;

    return func(lo);
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&n);

    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i],&b[i]);
        vote[a[i]].push_back(b[i]);
    }

    for(i=1;i<=lim;i++){
        sort(vote[i].begin(),vote[i].end());
        if(vote[i].size()){
            cand.push_back(node(i,vote[i].size()));
        }
    }
    sort(cand.begin(),cand.end(),cmp_cand);

    int ans=ts();

    printf("%d\n",ans);

    return 0;
}

