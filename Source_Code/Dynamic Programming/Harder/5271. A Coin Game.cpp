#include<stdio.h>
#include<string.h>

#define maxm 2100
#define ii long long int
#define inf (1<<28)

ii sum[maxm],n,a[maxm];
ii dp[maxm][maxm];

ii maxi(ii a,ii b){
	if(a>b) return a; return b;
}
ii mini(ii a,ii b){
	if(a<b) return a; return b;
}
ii cal(int ind,int can);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%lld",&n)==1){

		memset(sum,0,sizeof(sum));
		memset(dp,-1,sizeof(dp));

		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		ii ans=cal(1,1);
		ii ans1=sum[n]-ans;
		ans1/=2;
		printf("%lld\n",ans+ans1);

	}

	return 0;
}

ii cal(int ind,int can){

	if(can==0) return -inf;
	if(ind>n) return 0;

	if(dp[ind][can]!=-1) return dp[ind][can];

	ii ret; int k=2*can,l=2*can-1; 
	k=ind+k-1; k=mini(k,n); 
	l=ind+l-1; l=mini(l,n);
	ii val=sum[k]-sum[ind-1];
	ii val1=sum[l]-sum[ind-1]; 
	ret=maxi(val-cal(k+1,2*can),val1-cal(l+1,2*can-1));

	ret=maxi(ret,cal(ind,can-1));

	return dp[ind][can]=ret;

}