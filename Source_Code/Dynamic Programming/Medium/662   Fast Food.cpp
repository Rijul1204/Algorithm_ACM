#include<stdio.h>
#include<string.h>

#define maxm 250
#define inf 1<<28

int a[maxm],dp[maxm][50],pre[maxm][50],n,dp1[maxm][maxm];

int cal(int ind,int k);
int compute(int beg,int end);
int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&k)==2){

		if(!n&&!k) break;
		
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		memset(dp1,-1,sizeof(dp1));
		memset(dp,-1,sizeof(dp));
		int ans=cal(1,k);
		l=1;
		printf("Chain %d\n",t++);
		for(i=1;i<=k;i++){
			j=l+pre[l][k-i+1]; j/=2;
			if(pre[l][k-i+1]==l) printf("Depot %d at restaurant %d serves restaurant %d\n",i,j,l);
			else printf("Depot %d at restaurant %d serves restaurants %d to %d\n",i,j,l,pre[l][k-i+1]);
			l=pre[l][k-i+1]+1;
		}

		printf("Total distance sum = %d\n\n",ans);

	}

	return 0;
}

int cal(int ind,int k){

	if(ind>n) return 0;
	if(k<=0) return inf;
	
	if(dp[ind][k]!=-1) return dp[ind][k];

	int ret=inf,ret1,cost,i;

	for(i=ind;i<=n;i++){
		cost=compute(ind,i);
		ret1=cal(i+1,k-1)+cost;
		if(ret>ret1){
			ret=ret1; pre[ind][k]=i;
		}
	}
	
	return dp[ind][k]=ret;
}

int compute(int beg,int end){

	
	int ret=0; 
	int k=beg+end; k/=2;
	int i,l;

	if(dp1[beg][end]!=-1) return dp1[beg][end];

	for(i=beg;i<=end;i++){
		l=a[i]-a[k];
		if(l<0) l*=-1;
		ret+=l;
	}	
	return dp1[beg][end]=ret;
	
}