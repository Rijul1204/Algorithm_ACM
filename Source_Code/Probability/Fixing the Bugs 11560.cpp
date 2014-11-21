/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-11-20
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

#define maxm 102
#define maxc 12
#define maxn ((1<<11)+1)
#define inf (1<<29)
#define ii double 

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

int on(int n,int k){ return (n|(1<<k)); }
int off(int n,int k){ return (n-(n&(1<<k))); }
bool chck(int n,int k){ return (n&(1<<k)); }


ii mini(ii a,ii b){ if(a<b) return a;  return b;  }
ii maxi(ii a,ii b){ if(a>b) return a;  return b;  }

int B,T;
int s[maxc],failed[maxc];
double F;
double prob[maxm];

double dp[maxn][maxm][maxm];
int vis[maxn][maxm][maxm],kas=1;

// f= number of failed attempt uncheked
double cal(int mask,int t,int f){

    if(t<=0 || mask==(1<<B)-1) return 0;

    if(vis[mask][t][f]==kas) return dp[mask][t][f];
	vis[mask][t][f]=kas;
	
	int i;
	double ret=0;

	// finding maximum expected value of ind
	int ind=0;
	double res=-1.0;
	for(i=0;i<B;i++){
		if(chck(mask,i)) continue;
		if((double)s[i]*prob[i]>res){
			res=s[i]*prob[i];
			ind=i;
		}
	}
	
	// successfull move 
	ret=(cal(on(mask,ind),t-1,f-failed[ind])+(double)s[ind])*prob[ind];

	// unsuccessful
	double tmp=prob[ind];
	prob[ind]*=F;
	failed[ind]++;
	ret+=(cal(mask,t-1,f+1)*(1.0-tmp));
	failed[ind]--;
	prob[ind]=tmp;

    return dp[mask][t][f]=ret;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(scanf("%d %d %lf",&B,&T,&F)==3){	

        for(i=0;i<B;i++){
            scanf("%lf %d",&prob[i],&s[i]);
        }

		memset(failed,0,sizeof(failed));
		
		kas++;
        printf("%.7lf\n",cal(0,T,0));
    }

    return 0;
}

