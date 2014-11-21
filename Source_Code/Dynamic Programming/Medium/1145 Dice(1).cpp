#pragma warning (disable: 4786)
#pragma comment (linker, "/STACK:0x800000")


#include<stdio.h>
#include<string.h>

#define maxm 1011
#define maxe 15100
#define ii __int64
#define mod 100000007

ii dp[100][100];
ii row1[maxe],col1[maxe],row2[maxe],col2[maxe];
int n,s,kk;
ii cal(int n,int s);

int main(){
	
	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d %d %d",&n,&kk,&s);
		
		for(i=0;i<=n;i++){
			//dp[i][0]=0; 
			col1[i]=0;
		}
		for(j=0;j<=s;j++){
			row1[j]=0;
		//	dp[0][j]=0;
		}
		
		//dp[0][0]=1;
		row1[0]=1; col1[0]=1; col1[1]=0;
		ii ret,ret1;
		for(i=1;i<=n;i++){
			if(i>1){
				row1[0]=row2[0]=0;
			}
			for(j=1;j<=s;j++){
				if(j<i){
					col1[i]=0;
				//	dp[i][j]=0;
					if(i%2) row2[j]=0;
			    	else row1[j]=0;
					continue;
				}
			//	ret=dp[i-1][j-1]; 
				if(i%2) ret1=row1[j-1];
				else ret1=row2[j-1];
			//	ret+=dp[i][j-1]; ret%=mod;
				ret1+=col1[i]; ret1%=mod;
				if(j-(kk+1)>=0){
				//	ret-=dp[i-1][j-(kk+1)];  ret+=mod;	ret%=mod;
					if(i%2) ret1-=row1[j-(kk+1)];
					else ret1-=row2[j-(kk+1)];
					ret1+=mod; ret1%=mod;
					
				}
			//	if(ret!=ret1) printf("%d %d\n",i,j);
			//	dp[i][j]=ret;
				col1[i]=ret1;
				if(i%2) row2[j]=ret1;
				else row1[j]=ret1;
			}			
		}
		
		printf("Case %d: %I64d\n",t++,col1[n]);
		//		memset(dp,-1,sizeof(dp));
		//		printf("%I64d\n",cal(n,s));
		
	}
	
	return 0;
}

ii cal(int n,int s){
	
	if(n==0&&s==0) return 1;
	if(n==0||s==0) return 0;
	if(s<0||s<n) return 0;	
	
	if(dp[n][s]!=-1) return dp[n][s];
	ii ret=0; int i;
	
	ret=cal(n-1,s-1);
	ret+=cal(n,s-1);
	ret%=mod;
	ret-=cal(n-1,s-(kk+1)); ret+=mod;
	ret%=mod;
	
	/*
	for(i=1;i<=kk;i++){
	ret+=cal(n-1,s-i);
	ret%=mod;
	}
	*/
	
	return dp[n][s]=ret;
}
