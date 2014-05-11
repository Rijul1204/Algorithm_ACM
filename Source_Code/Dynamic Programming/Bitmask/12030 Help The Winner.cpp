#include<stdio.h>
#include<string.h>

#define maxm 17
#define maxn 1<<17
//#define ii __int64
#define ii long long int

int on(int n,int k){
	return (n|(1<<k));
}
int off(int n,int k){
	return (n-(n&(1<<k)));
}
bool check(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}
int n,mat[maxm][maxm];
ii dp[maxn][3][3];
ii cal(int i,int num,int fl,int fl1);

int main(){
	
	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d",&n);
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&mat[i][j]);
			}
		}
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %lld\n",t++,cal(1,0,1,0));
		
	}
	
	return 0;
}

ii cal(int i,int num,int fl,int fl1){

	if(num==((1<<n)-1)&&(fl||fl1)) return 1;
	else if(num==((1<<n)-1)) return 0;

	if(dp[num][fl][fl1]!=-1) return dp[num][fl][fl1];
	int j,k,l,l1;
	ii ret=0;

	for(j=1;j<=n;j++){
		if(check(num,j-1)) continue;
		k=num;
		k=on(k,j-1);
		l=(mat[i][j]==1&&fl);
		l1=(mat[i][j]==2||fl1);
		ret+=cal(i+1,k,l,l1);
	}
	return dp[num][fl][fl1]=ret;
	
}
/*
ii cal1(int i,int num,int fl){
	
	if(num==((1<<n)-1)) return 1;
	if(i>n) return 0;
	
	if(dp[i][num][fl]!=-1) return dp[i][num][fl];
	int j,k;
	ii ret=0;
	
	for(j=1;j<=n;j++){
		if(check(num,j-1)) continue;
		if(fl==0){			
			if(mat[i][j]==1){
				k=num;
				k=on(k,j-1);
				ret+=cal(i+1,k,0);
			}
			if(mat[i][j]==2){
				k=num;
				k=on(k,j-1);
				ret+=cal(i+1,k,1);
			}
		}
		if(fl){
			k=num;
			k=on(k,j-1);
			ret+=cal(i+1,k,1);
		}
	}
	return dp[i][num][fl]=ret;
}
*/