#include<stdio.h>
#include<string.h>

#define inf 1<<26
#define maxm 30010
#define EPSILON 1e-10


int dp[maxm],dp1[maxm];

int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l;
	int coin[]={5,10,20,50,100,200};
	int c[10],tot;
	double totd;

//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	
	for(i=0;i<=maxm;i++) dp[i]=inf;
	
	for(i=0;i<6;i++){
		k=coin[i];
		dp[k]=mini(dp[k],1);
		for(j=0;j<=20010;j++){
			if(dp[j]!=0) dp[j+k]=mini(dp[j+k],dp[j]+1); 
		}
	}


	while(1){

		k=0;
	
		for(i=0;i<6;i++){
			scanf("%d",&c[i]);
			if(c[i]!=0) k=1;
		}
		
		if(!k) break;

		for(i=0;i<=maxm;i++) dp1[i]=inf;

		scanf("%lf",&totd);
	//	totd*=100;
	//	tot*=100;
	//	tot+=k;
		tot = int(totd * 100 + EPSILON);
		//tot=totd;

		//dp1[0]=1;
		for(i=0;i<6;i++){
			for(j=1;j<=c[i];j++){
												
				for(k=20010;k>coin[i];k--){
					if(dp1[k-coin[i]]>0) dp1[k]=mini(dp1[k-coin[i]]+1,dp1[k]);
				}

				dp1[coin[i]]=mini(dp1[coin[i]],1);
			}						
		}

		

		int ans=dp1[tot];

		for(i=tot+1;i<=20010;i++){
			if(dp1[i]+dp[i-tot]<ans){
				ans=dp1[i]+dp[i-tot];
			}
		}

		//j=ans;
		printf("%3d\n",ans);

		

		



	}

	return 0;
}