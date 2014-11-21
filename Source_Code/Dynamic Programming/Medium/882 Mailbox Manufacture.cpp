#include<stdio.h>
#include<string.h>

#define maxm 105
#define inf 1<<27

int dp[maxm][maxm][maxm],m;
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int cal(int n,int lo,int hi);


int main(){
	
	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	scanf("%d",&test);
	
	while(test--){

		scanf("%d %d",&k,&m);
		
		printf("%d\n",cal(k,1,m));

	}

	return 0;
}

int cal(int n,int lo,int hi){
	
	if(lo>hi) return 0;
	if(lo==hi) return lo;
	if(n==1){
		int m=hi; m*=m+1; m/=2;
		int m1=lo-1; m1*=m1+1; m1/=2;
		return m-m1;
	}
	if(dp[n][lo][hi]!=-1) return dp[n][lo][hi];

	int i,ret=inf,k,l;

	for(i=lo;i<=hi;i++){
		k=cal(n-1,lo,i-1)+i;
		l=cal(n,i+1,hi)+i;
		ret=mini(ret,maxi(k,l));
	}	

	return dp[n][lo][hi]=ret;
	
}

