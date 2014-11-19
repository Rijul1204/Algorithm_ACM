/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-11-19
Algo		: Ternary mask,Meet in the middle.
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

#define maxm 20
#define maxn ((1<<18)+1)
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

struct ternary{
    ii pow3[maxm];

    void init(){
        init(maxm-1);
    }
    void init(int n){
        pow3[0]=1;
        for(int i=1;i<=n;i++){
            pow3[i]=pow3[i-1]*3;
        }
    }
    int get_bit(int mask,int k){
        ii tmp=mask; tmp/=pow3[k];
        return (tmp%3);
    }
    int set_bit(int mask,int k,int v){
        ii tmp=mask;
        tmp/=pow3[k];
        tmp%=3;
        mask-=(tmp*pow3[k]);
        mask+=(v*pow3[k]);
        return mask;
    }
};
ternary t_mask;

int n,req;
int a[maxm],b[maxm];

set<int>can_set;

int build(int mask,int a[],int n,int flag){

    int ret=0;

    for(int i=0;i<n;i++){
		int bit_val=t_mask.get_bit(mask,i);

		for(int j=1;j<=bit_val;j++){
			ret+=a[i];
			if(ret>req) return -1;
		}
    }

	if(flag) can_set.insert(ret);
    return ret;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    t_mask.init();

    scanf("%d",&test);

    while(test--){

		can_set.clear();

        scanf("%d %d",&n,&req);

        int n1=n/2,n2=n-n1;

        for(i=0;i<n1;i++){
            scanf("%d",&a[i]);
        }
		for(i=n1,j=0;i<n;i++,j++){
			scanf("%d",&b[j]);
		}


        int tot=0;
        for(i=0;i<t_mask.pow3[n1];i++){
            build(i,a,n1,1);
        }

		bool soln_found=false;
        for(i=0;i<t_mask.pow3[n2];i++){
            int now=build(i,b,n2,0);
			if(now==-1) continue;
			now=req-now;
			if(can_set.find(now)!=can_set.end()){
				soln_found=true;
				break;
			}
        }

        printf("Case %d: ",t++);

		if(soln_found==true){
            printf("Yes\n");
        }
        else{
            puts("No");
        }

    }

    return 0;
}

