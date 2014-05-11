#pragma warning (disable: 4786)
#pragma comment (linker, "/STACK:0x800000")


#include<stdio.h>
#include<string.h>

#define maxm 1000
#define ii long long int
#define mod 100000007

ii dp1[2][15010];

int n,s,K;


//ii cal(int n,int s);
ii cal1(int ind,int s);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d %d",&n,&K,&s);

		ii ans=0;

		memset(dp1,0,sizeof(dp1));
		dp1[0][0]=1;

		for(i=1;i<=n;i++){
		    if(i%2){
		        k=1; l=0;
		    }
		    else{
		        l=1; k=0;
		    }
		    for(j=0;j<=s;j++){
		        ii ret=cal1(l,j-1); //ret%=mod;
                ret+=((ii)2*cal1(k,j-1)); //ret%=mod;
                ret-=(cal1(k,j-2)); //ret%=mod; if(ret<0) ret+=mod;
                ret-=((K+1)*cal1(l,j-(K+1))); //ret%=mod;
                ret+=(K*(cal1(l,j-(K+2)))); ret%=mod; if(ret<0) ret+=mod;
                dp1[k][j]=ret;
		    }
		}

		printf("Case %d: %lld\n",t++,dp1[k][s]);
	}
	return 0;
}

ii cal1(int ind,int s){
    if(s<0) return 0;
    return dp1[ind][s];
}

/*
ii cal(int n,int s){

	if(n==0&&s==0) return 1;
	if(s<=0||n<=0) return 0;

	if(dp[n][s]!=-1) return dp[n][s];

	ii ret=cal(n-1,s-1); ret%=mod;
	ret+=((ii)2*cal(n,s-1)); ret%=mod;
	ret-=(cal(n,s-2)); ret%=mod; if(ret<0) ret+=mod;
	ret-=((K+1)*cal(n-1,s-(K+1))); ret%=mod; if(ret<0) ret+=mod;
	ret+=(K*(cal(n-1,s-(K+2)))); ret%=mod;

	return dp[n][s]=ret;

}
*/
