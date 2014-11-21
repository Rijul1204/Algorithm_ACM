#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 100010
#define inf 1<<28

int dp[maxm],a[maxm],k,n;
bool vis[maxm];

int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int cal(int ind);

int main(){

	int i,j,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&k);

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		a[n+1]=101110010;
		sort(a+1,a+n+1);	
		memset(dp,-1,sizeof(dp));
		memset(vis,0,sizeof(vis));
		int ans=cal(1);
		if(ans>=inf) ans=-1;
		printf("Case %d: %d\n",t++,ans);
	}

	return 0;
}

int cal(int ind){

	if(ind>n) return 0;
	if(ind==n-1||ind==n) return inf;

	if(vis[ind]) return dp[ind];
	vis[ind]=1;
	
	int ret=inf,i,j=0;
	
	if(a[ind]<a[ind+2]-(2*k)) return dp[ind]=inf;	
//	if(cal(ind+3)>=inf) ret=inf;
//	else  ret=1+cal(ind+3);
	
	for(i=3;ind+i<=n;i++,j++){
		if(a[ind]<a[ind+i]-(2*k)) break;
	}
	
	ret=mini(ret,1+cal(ind+i));
	if(j==1){
		ret=mini(ret,1+cal(ind+i-1));
	}	
	else if(j>1){
		ret=mini(ret,mini(1+cal(ind+i-2),1+cal(ind+i-1)));
	}


	return dp[ind]=ret;
}