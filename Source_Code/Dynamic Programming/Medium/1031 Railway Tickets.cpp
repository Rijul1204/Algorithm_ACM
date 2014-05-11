#include<stdio.h>
#include<string.h>

#define maxm 10100
#define inf 1<<30

int dp[maxm],l1,l2,l3,c1,c2,c3,s,d,a[maxm],n;

int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int cal(int ind);

int main(){
	
	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d %d %d %d %d",&l1,&l2,&l3,&c1,&c2,&c3)==6){

		scanf("%d %d %d",&n,&s,&d);
		if(s>d){
			k=s; s=d; d=k;
		}
		a[1]=0;
		for(i=2;i<=n;i++){
			scanf("%d",&a[i]);
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",cal(s));

	}


	return 0;
}

int cal(int ind){
	
	if(ind==d) return 0;

	if(dp[ind]!=-1) return dp[ind];

	int i,j,k,l;
	dp[ind]=inf;
	i=ind+1;
	for(i=ind+1;i<=d;i++){
		if(a[i]-a[ind]<=l1){
			while(a[i]-a[ind]<=l1&&i<=d) i++;
			i--;
			dp[ind]=mini(dp[ind],cal(i)+c1);
		}
		else break;
	}
	
	for(;i<=d;i++){
		if(a[i]-a[ind]<=l2){	
			while(a[i]-a[ind]<=l2&&i<=d) i++;
			i--;
			dp[ind]=mini(dp[ind],cal(i)+c2);
		}
		else break;
	}

	
	for(;i<=d;i++){
		if(a[i]-a[ind]<=l3){	
			while(a[i]-a[ind]<=l3&&i<=d) i++;
			i--;
			dp[ind]=mini(dp[ind],cal(i)+c3);
		}
		else break;
	}

	return dp[ind];

}