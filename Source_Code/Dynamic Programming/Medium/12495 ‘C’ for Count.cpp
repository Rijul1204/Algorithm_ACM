#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define ii  long long int
#define mod 1000000007
#define maxm 1010

int n,k,d;
int dp1[maxm][maxm][15],dp[maxm][maxm][15];

void init();
ii cal(int n,int k,int d);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    init();

    scanf("%d",&test);

    while(test--){

        scanf("%d %d %d",&n,&k,&d);

        printf("Case %d: %d\n",t++,dp[n][k][d]);
    }


    return 0;
}


void init(){

    int i,j,k,l;

    memset(dp1,-1,sizeof(dp1));
    for(d=1;d<=10;d++){
        for(n=1;n<=1000;n++){
            for(k=1;k<=n;k++){
                ii ret=0;
                for(i=1,j=n-d+1;i<d;i++,j++){
					l=(j-(i+d-1));
					if(l<=0) break;
					ret+=cal(l,k-1,d);
                    if(ret>mod) ret%=mod;
                }
				l=n-d+1;
				if(l>0){
                    ret+=cal(l,k,d);
                    if(ret>mod) ret%=mod;
				}
				if(k==1) ret=n;
                dp[n][k][d]=ret;
            }
        }
    }

}

ii cal(int n,int k,int d){

	if(k<0) return 0;
	if(k==0) return 1;

    if(n<1&&k==0) return 1;
    if(n<1) return 0;

    if(dp1[n][k][d]!=-1) return dp1[n][k][d];

    ii ret=0;

    ret=cal(n-1,k,d);
    if(ret>mod) ret%=mod;
    ret+=cal(n-d,k-1,d);
    if(ret>mod) ret%=mod;

    return dp1[n][k][d]=ret;

}
