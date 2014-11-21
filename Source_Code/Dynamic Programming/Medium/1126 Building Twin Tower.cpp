#include<stdio.h>
#include<string.h>

#define maxm 53
#define maxh 2*500010
#define inf 1<<29

int n,h[maxm],dp1[maxh],dp2[maxh],sum1[maxm];
int dp[3][maxh];
int cal(int ind,int diff);
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){
	
	int i,j,k,l,test,t=1,mark;
	
	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d",&n);
		int sum=0;
		for(i=1;i<=n;i++){
			scanf("%d",&h[i]);
			sum+=h[i];
			sum1[i]=sum1[i-1]+h[i];
		}
		
	//	memset(dp,-1,sizeof(dp));
		
		
		int ret=0;
	//	for(i=0;i<=n;i++){
			for(j=0;j<=sum*2;j++){
			//	dp[i][j]=-inf; 
				dp1[j]=dp2[j]=-inf;
				dp[0][j]=dp[1][j]=-inf;
			}
	//	}
		
		
	
		
		mark=sum;
		int kk=sum/2;
		kk+=mark;
		int kk1=sum/2;
		kk1=mark-kk1;
	
		dp[0][mark]=0;
		dp1[mark]=0;
	//	dp[0][mark]=0;

		int i1,i2,j1;
		
	
		for(i=1;i<=n;i++){
			if(i%2) i1=1; else i1=0;
			i2=!i1;
		//	j=maxi(mark-sum1[i],mark-sum/2); j1=mini(mark+sum1[i],sum/2);
			for(j=mark-sum1[i];j<=mark+sum1[i];j++){
				if(j>kk) break; if(j<kk1) continue;
				if(j-h[i]>=0){
					dp[i1][j]=dp[i2][j-h[i]];
				//	dp2[j]=dp1[j-h[i]];					
				}
				
				if(j+h[i]<=kk){
					//if(j+h[i]>mark) printf("%d %d\n",i,j+h[i]);
					dp[i1][j]=maxi(dp[i1][j],dp[i2][j+h[i]]+h[i]);
					
					//dp2[j]=maxi(dp2[j],dp1[j+h[i]]+h[i]);
				}
				dp[i1][j]=maxi(dp[i1][j],dp[i2][j]);
			//	dp2[j]=maxi(dp2[j],dp1[j]);
				//	if(dp[i][j]!=dp2[j]){
				//		printf("%d %d\n",i,j);
				//	}
			}
			/*
			for(j=mark-sum1[i];j<=mark+sum1[i];j++){
				dp1[j]=dp2[j];
				dp2[j]=-inf;				
			}
			*/
		}
		
		int ans=dp[i1][mark]; 
		if(ans==0){
			printf("Case %d: impossible\n",t++);
			continue;
		}
		
		printf("Case %d: %d\n",t++,ans);
		
		
	}
	
	return 0;
}

int cal(int ind,int diff){
	
	if(ind==0&&diff==0) return 0;
	if(ind<=0) return -inf;
	
	if(dp[ind][diff]!=-1) return dp[ind][diff];
	
	int ret;
	
	ret=maxi(cal(ind-1,diff-h[ind]),cal(ind-1,diff+h[ind])+h[ind]);
	ret=maxi(ret,cal(ind-1,diff));
	
	return dp[ind][diff]=ret;
}
