/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-08-14
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

#define maxm 155
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

int n,m;
int mat[maxm][maxm],sum[maxm][maxm];

int get_sum(int i,int j,int k,int l){
	return sum[k][l]-sum[i-1][l]-sum[k][j-1]+sum[i-1][j-1];
}

int cal(){

    int ret,i,j,k,l,t;

	ret=mat[1][1];
	int i1,j1,ret1;

	for(k=1;k<=n;k++){
		for(l=1;l<=n;l++){
			for(i=1;i<=m;i++){
				if(i+k>m) break;
				for(j=1;j<=m;j++){
					if(j+l>m) break;
					i1=i+k-1,j1=j+l-1;
					ret1=sum[i1][j1]-sum[i-1][j1]-sum[i1][j-1]+sum[i-1][j-1];
					if(ret1>ret) ret=ret1;
				}
			}
		}
	}

	return ret;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);
        m=n+n;

        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&mat[i][j]);
                mat[i+n][j]=mat[i][j+n]=mat[i+n][j+n]=mat[i][j];
            }
        }

        for(i=1;i<=m;i++){
			int curr_sum=0;
            for(j=1;j<=m;j++){
				curr_sum+=mat[i][j];
                sum[i][j]=sum[i-1][j]+curr_sum;
            }
        }

        printf("%d\n",cal());

    }

    return 0;
}

