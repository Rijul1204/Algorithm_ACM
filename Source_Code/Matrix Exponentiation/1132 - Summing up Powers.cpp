#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
#include<stack>
using namespace std;

#define maxn 1001000
#define maxm 100000
#define maxc 60
#define inf (1<<29)
#define ii unsigned int
#define iid long long int

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second


ii mini(ii a,ii b){
    if(a<b) return a;
    return b;
}
ii maxi(ii a,ii b){
    if(a>b) return a;
    return b;
}

iid n;
int K;

ii dp[maxc][maxc];
bool vis[maxc][maxc];
ii ncr(int n,int r){
    if(n<0 || r<0 || n<r) return 0;
    if(r==0) return 1;
    if(n==1 || n==0 || n==r) return 1;
    if(vis[n][r]) return dp[n][r];
    vis[n][r]=1;

    dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
    return dp[n][r];
}

ii base[maxc][maxc],unit[maxc][maxc],res[maxc][maxc];
void build_matrix(int k);
ii cal(ii a[maxc][maxc],ii b[maxc][maxc],ii n){

    ii ret[maxc][maxc];
    int i,j,k;
	memset(ret,0,sizeof(ret));

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				ret[i][j]+=(a[i][k]*b[k][j]);
				//ret[i][j]%=mod;
			}
		}
	}
	memcpy(a,ret,sizeof(ret));
}
void exp(ii r[maxc][maxc],iid n,int n1){

	ii b[maxc][maxc];
	memcpy(r,unit,sizeof(unit));
	memcpy(b,base,sizeof(base));

	while(n>0){
		if(n%2==1) cal(r,b,n1);
		n/=2;
		cal(b,b,n1);
	}
}

ii cal_p(iid n,int k); // calculate 1^k+2^k+ .... + n^k

void print(ii mat[maxc][maxc],ii n,ii m){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%2d ",mat[i][j]);
        }
        puts("");
    }
    puts("");
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%lld %d",&n,&K);

        printf("Case %d: %u\n",t++,cal_p(n,K));

    }

    return 0;
}

ii cal_p(iid n,int K){

    if(n==1) return 1;

    int i,j;
    ii ret=0;

    build_matrix(K);

    //print(base,K+2,K+2);

    exp(res,n,K+2);

    return res[K+1][0];

}

void build_matrix(int K){

    int i,j;

    for(i=0;i<=K+1;i++){
        for(j=0;j<=K+1;j++){
            if(i==j) unit[i][j]=1;
            else     unit[i][j]=0;
            base[i][j]=0;
        }
    }
    for(i=0;i<=K;i++){
        for(j=0;j<=i;j++){
            base[i][j]=ncr(i,j);
        }
    }
    for(j=0;j<=K;j++) base[K+1][j]=base[K][j];
    base[K+1][K+1]=1;
}
