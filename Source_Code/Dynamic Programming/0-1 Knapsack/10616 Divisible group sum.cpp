#include<stdio.h>
#include<string.h>

#define maxm 250
#define maxim 50
#define inf 1<<27
//#define ii __int64
#define ii long long int

ii dp[maxm][maxim][maxim];
int n1,d1,m1,a[maxm],q;

ii cal(int n,int m,ii d);

int main(){

	int i,j,k,l,t=1;

//	k=-20%7;
//	printf("%d\n",k);
	
//	freopen("in.txt","r",stdin);
	while(scanf("%d %d",&n1,&q)==2){

		if(!n1&&!q) break;

		for(i=1;i<=n1;i++){
			scanf("%d",&a[i]);
		}
		
		printf("SET %d:\n",t++);
		for(i=1;i<=q;i++){
			scanf("%d %d",&d1,&m1);
			memset(dp,-1,sizeof(dp));
			printf("QUERY %d: %lld\n",i,cal(n1,0,d1));
		}

	}

	return 0;
}

ii cal(int n,int m,ii d){

	if(m>m1) return 0;
	if(m==m1&&d==0) return 1;
	if(m==m1&&d!=0) return 0;
	if(n==0&&m==m1&&d==0) return 1;
	else if(n==0) return 0;
	
	if(dp[n][m][d]!=-1) return dp[n][m][d];

	ii ret=0;

	ret+=cal(n-1,m+1,(d+a[n])%d1);
	ret+=cal(n-1,m,d);

	return dp[n][m][d]=ret;

}