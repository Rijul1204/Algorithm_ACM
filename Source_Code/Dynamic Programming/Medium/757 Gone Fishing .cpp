#include<stdio.h>
#include<string.h>

#define maxm 30
#define inf 1<<28

int n,h,ff[maxm],dd[maxm],tt[maxm],ans[maxm];

int dp[maxm][200][200],pre[maxm][200][200];

int cal(int ind,int rem,int now);
void print(int ind,int rem,int now);

int main(){
	
	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);
	
	bool blank=false;

	while(scanf("%d",&n)==1){

		if(!n) break; 
		
		scanf("%d",&h); h*=12;
		
		for(i=1;i<=n;i++){
			scanf("%d",&ff[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&dd[i]);
		}
		for(i=1;i<n;i++){
			scanf("%d",&tt[i]);
		}
		
		memset(dp,-1,sizeof(dp));
		memset(ans,0,sizeof(ans));

		int ret=cal(1,h,0);
		print(1,h,0);
		if(blank) printf("\n");
		blank=true;
		for(i=1;i<=n;i++){
			if(i==1) printf("%d",ans[i]*5);
			else printf(", %d",ans[i]*5);
		}
		printf("\n");
		printf("Number of fish expected: %d\n",ret);


	}

	return 0;
}

void print(int ind,int rem,int now){

	if(ind>n) return ;
	if(rem<=0) return ;

	if(pre[ind][rem][now]==1){
		print(ind+1,rem-tt[ind],0);
	}
	else{
		ans[ind]++;
		print(ind,rem-1,now+1);
	}
}

int cal(int ind,int rem,int now){

	if(ind>n) return -inf;
	if(rem<0) return -inf;
	if(rem==0) return 0;

	if(dp[ind][rem][now]!=-1) return dp[ind][rem][now];

	int i,j,k,l,ret,ret1;
	
	k=(ff[ind]-(dd[ind]*now)); if(k<0) k=0;
	ret=cal(ind,rem-1,now+1)+k;

	ret1=cal(ind+1,rem-tt[ind],0);

	if(ret1>ret){
		pre[ind][rem][now]=1;
		ret=ret1; 
	}
	else pre[ind][rem][now]=2;
	return dp[ind][rem][now]=ret;
}