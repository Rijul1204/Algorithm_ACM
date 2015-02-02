/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2015-01-30
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
#include<unordered_map>
#include<set>
using namespace std;

#define maxm 10100
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

struct c_set{
    int a[6];
    string s;
};
c_set c_sets[maxm];

int n;
unordered_map<string,int>map_str;

void convert(c_set &curr){

    sort(curr.a,curr.a+5);

    curr.s="";

    char nums[10];

    for(int i=0;i<5;i++){
        sprintf(nums,"%d",curr.a[i]);
        curr.s+=nums;
    }
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(scanf("%d",&n)==1){

        if(!n) break;

        map_str.clear();

        int mx_cnt=0;
        for(i=0;i<n;i++){
            for(j=0;j<5;j++){
                scanf("%d",&c_sets[i].a[j]);
            }
            convert(c_sets[i]);

            map_str[c_sets[i].s]++;

            mx_cnt=maxi(mx_cnt,map_str[c_sets[i].s]);
        }

        int ans=0;

        for(i=0;i<n;i++){
            //cout << c_sets[i].s << " "  << map_str[c_sets[i].s] << endl;
            if(map_str[c_sets[i].s]==mx_cnt) ans++;
        }

        printf("%d\n",ans);
    }

    return 0;
}

