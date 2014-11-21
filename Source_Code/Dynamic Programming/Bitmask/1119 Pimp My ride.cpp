#include<stdio.h>
#include<string.h>

#define inf 1<<29
#define maxm 20
#define maxn (1<<16)

int on(int n,int k){
	return n|(1<<k);
}
int off(int n,int k){
	return n-(n&(1<<k));
}
bool chck(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}
int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int dp[maxn+15],mat[maxm][maxm],n;
int cal(int bit);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d",&n);
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&mat[i][j]);
			}
		}
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",t++,cal(0));


	}

	return 0;
}

int cal(int bit){

	if(bit==(1<<n)-1) return 0;

	if(dp[bit]!=-1) return dp[bit];

	int i,j,k,ret=inf,cost=0;
	for(i=0;i<n;i++){
		if(!chck(bit,i)){
			cost=0;
			for(j=0;j<n;j++){
				if(chck(bit,j)) cost+=mat[i][j];
			}
			k=on(bit,i);
			ret=mini(ret,cal(k)+mat[i][i]+cost);
		}
	}

	return dp[bit]=ret;

}