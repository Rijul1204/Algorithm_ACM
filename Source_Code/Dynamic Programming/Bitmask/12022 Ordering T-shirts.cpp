#include<stdio.h>
#include<string.h>

#define ii long long int
#define maxm 15
#define maxn (1<<13)

int on(int n,int k){
	return n|(1<<k);
}
int off(int n,int k){
	return n-(n&(1<<k));
}
bool chck(int n,int k){
	return (n&(1<<k));
}

ii dp[maxn][4][maxm];
int n;
ii cal(int mask,int last,int ind);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		printf("%lld\n",cal(0,0,0));

	}

	return 0;
}

ii cal(int mask,int last,int ind){

	if(mask==(1<<n)-1 && !last) return 1;
	if(mask==(1<<n)-1) return 0;

	if(dp[mask][last][ind]!=-1) return dp[mask][last][ind];

	ii ret=0;

	for(int i=0;i<n;i++){
		if(chck(mask,i)) continue;
		if(last && i<ind) continue;
		ret+=cal(on(mask,i),0,i);
		ret+=cal(on(mask,i),1,i);
	}

	return dp[mask][last][ind]=ret;
}
