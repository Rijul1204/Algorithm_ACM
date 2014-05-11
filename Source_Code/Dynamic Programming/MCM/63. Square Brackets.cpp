#include<stdio.h>
#include<string.h>

#define maxm 50
#define ii int

int a[maxm],n;
ii dp[maxm][maxm];
bool v[maxm][maxm];

ii cal(int b,int e);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));

		scanf("%d %d",&n,&k);

		for(i=1;i<=k;i++){
			scanf("%d",&j);
			a[j]=1;
		}

		printf("%d\n",cal(1,2*n));

	}

	return 0;
}

ii cal(int b,int e){

	if(b>e) return 1;
	if(b==e) return 0;

	if(v[b][e]) return dp[b][e];
	v[b][e]=1;

	int i,j,k,l;
	ii ret=0,ret1;

	for(i=b+1;i<=e;i+=2){
		if(a[i]==1) continue;
		ret1=cal(b+1,i-1)*cal(i+1,e);
		ret+=ret1;
	}
	
	return dp[b][e]=ret;
}