#include<stdio.h>
#include<string.h>

#define maxm 1000
#define ii  int

ii dp[maxm];

ii cal(int n);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	memset(dp,-1,sizeof(dp));

	scanf("%d",&test);

	while(test--){

		scanf("%d",&j);
		
		printf("%d %d\n",t++,cal(j));

	}

	return 0;
}

ii cal(int n){

	if(n<0) return 0;
	if(n==0||n==1) return 1;
	
	if(dp[n]!=-1) return dp[n];

	ii i,k;
	ii ret=cal(n-1)+4*cal(n-2);

	for(i=3;i<=n;i++){
		if(i%2) k=2;
		else k=3;
		ret+=(k*cal(n-i));		
	}

	return dp[n]=ret;

}