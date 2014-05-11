#include<stdio.h>
#include<string.h>

#define maxn 35
#define maxm 260
#define inf 1<<27

int dp[maxn][maxm][maxm];
int sum[maxn],a1[maxn],n1,lim;

int cal(int n,int a,int b);
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){
	
	int i,j,k,l,test,t=1;
	
   // freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d",&n1);
		
		
		for(i=1;i<=n1;i++){
			scanf("%d",&a1[i]);
			
		}
	//	memset(sum,0,sizeof(sum));
		memset(dp,-1,sizeof(dp));
		
		sum[n1+1]=0;
		for(i=n1;i>=1;i--){
			sum[i]=sum[i+1]+a1[i];
		}
		
		lim=sum[1];
		lim/=3;
		lim+=50;
		
		printf("Case %d: %d\n",t++,cal(n1,0,0));
		
		
		
	}
	
	return 0;
}

int cal(int n,int a,int b){
	
	int k,l;
	if(a>lim||b>lim||sum[n]-(a+b)>lim) return inf;
	if(n==0){
		k=maxi(maxi(a,b),sum[1]-(a+b));
		l=mini(mini(a,b),sum[1]-(a+b));
		return k-l;
	}
	
	if(dp[n][a][b]!=-1||dp[n][b][a]!=-1) return mini(dp[n][a][b],dp[n][b][a]);
	
	int ret=0;

	if(a+b>sum[n]-(a+b)+lim-30){
		k=cal(n-1,a,b);
	}

	else if(sum[n]-b>b+lim-30){
		k=cal(n-1,a,b+a1[n]);
	}
	else if(sum[n]-a>a+lim-30){
		k=cal(n-1,a+a1[n],b);
	}

	else if(a>(b+sum[n]-(a+b)+lim-30)){
		k=mini(cal(n-1,a,b+a1[n]),cal(n-1,a,b));
	}
	else if(b>(a+sum[n]-(a+b)+lim-30)){
		k=mini(cal(n-1,a+a1[n],b),cal(n-1,a,b));
	}
	else if(sum[n]-(a+b)>(a+b+lim-30)){
		k=mini(cal(n-1,a+a1[n],b),cal(n-1,a,b+a1[n]));
	}
	else {		
		k=mini(cal(n-1,a+a1[n],b),cal(n-1,a,b+a1[n]));
		k=mini(k,cal(n-1,a,b));
	}
	
	return dp[n][a][b]=dp[n][b][a]=k;
	
}