#include<stdio.h>

#define ii long long int

int w[5000][5000];
int end[5000],c,s,e,t;
ii dp[5000][5500];
int flag[5000][5500];

ii travel(int n,int d);

ii max(ii a,ii b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d %d %d",&c,&s,&e,&t)==4){

		if(!c&&!s&&!e&&!t) break;

		for(i=1;i<=c;i++){
			for(j=1;j<=c;j++){
				scanf("%d",&w[i][j]);
			}
		}
		for(i=1;i<=e;i++){
			scanf("%d",&end[i]);

		}

		for(i=0;i<=c;i++){
			for(j=0;j<=t;j++){
		//		dp[i][j]=-1;
				flag[i][j]=0;
			}
		}

		printf("%lld\n",travel(s,t));


	}


	return 0;
}

ii travel(int n,int d){

	int i,j,k,l;

	if(d==0) return 0;
	if(flag[n][d]==1) return dp[n][d];
	
	flag[n][d]=1;
    ii mx=-123456789;
	dp[n][d]=mx;
	if(d==1){		
		for(i=1;i<=e;i++){
			dp[n][d]=max(dp[n][d],w[n][end[i]]+travel(end[i],d-1));			
		}
		return dp[n][d];
	}	
	for(i=1;i<=c;i++){

		dp[n][d]=max(dp[n][d],w[n][i]+travel(i,d-1));
	}

	return dp[n][d];

}