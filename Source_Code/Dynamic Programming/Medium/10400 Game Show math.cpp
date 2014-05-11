#include<stdio.h>
#include<string.h>

#define maxm 110
#define maxn 32000

int dp[maxm][2*maxn+100],n1,pre[maxm];
int a[maxm],target;
char op[]="+-*/";

int cal(int n,int res);

int main(){
	
	int i,j,k,l,test;
	
//	freopen("in.txt","r",stdin);
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d",&n1);
		for(i=1;i<=n1;i++){
			scanf("%d",&a[i]);
			//	a[i]+=maxn;
		}
		scanf("%d",&target);
		//target+=maxn;
		memset(dp,-1,sizeof(dp));
	//	printf("%d\n",cal(2,maxn+a[1]));
		if(cal(1,maxn)){
			printf("%d",a[1]);
			for(i=2;i<=n1;i++){
				//printf("%d ",pre[i]);
				printf("%c%d",op[pre[i]-1],a[i]);
			}
			printf("=%d\n",target);		}

		else printf("NO EXPRESSION\n");
		
	}
	
	
	return 0;
}

int cal(int n,int res){
	
	if(n>n1&&res-maxn==target){
		return 1;
	}

	if(n>n1) return 0;
	
	int i,j,k,l;
	if(dp[n][res]!=-1) return dp[n][res];
	
	k=res-maxn;
	k+=a[n];	
	if(k>=-maxn&&k<=maxn){
		if(cal(n+1,k+maxn)){
			pre[n]=1;
			return dp[n][res]=1;
		}
	}
	
	k=res-maxn;
	k-=a[n];	
	if(k>=-maxn&&k<=maxn){
		if(cal(n+1,k+maxn)){
			pre[n]=2;
			return dp[n][res]=1;
		}
	}
	
	
	k=res-maxn;
	k*=a[n];	
	
	if(k>=-maxn&&k<=maxn){
		if(cal(n+1,k+maxn)){
			pre[n]=3;
			return dp[n][res]=1;
		}
	}
	
	
	k=res-maxn;
	if(k%a[n]==0){
		k/=a[n];	
		if(k>=-maxn&&k<=maxn){
			if(cal(n+1,k+maxn)){
			pre[n]=4;
			return dp[n][res]=1;
			}
		}
		
		
	}
	
	return dp[n][res]=0;
	
	
}