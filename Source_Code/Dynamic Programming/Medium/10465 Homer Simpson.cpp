#include<stdio.h>
#include<string.h>

#define maxm 11000

int dp[maxm],n,m,t;

void cal(int t,int i,int j);
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l;


	while(scanf("%d %d %d",&m,&n,&t)==3){
		
		memset(dp,0,sizeof(dp));
		cal(t,m,n);

		if(dp[t]!=0){
			printf("%d\n",dp[t]);
			continue;
		}

		for(i=t;i>=0;i--){
			if(dp[i]!=0){
				printf("%d %d\n",dp[i],t-i);
		    	break;
			}
		}
		if(i<0) printf("0 %d\n",t);

	}


	return 0;
}

void cal(int t,int i,int j){

	if(t==0) return ;

	if(t==i){
		dp[t]=maxi(dp[t],1);
	}

	if(t==j){
		dp[t]=maxi(dp[t],1);
	}

	cal(t-1,i,j);
	
	if(t>=i) if(dp[t-i]!=0){
		dp[t]=maxi(dp[t],dp[t-i]+1);
	}

	if(t>=j) if(dp[t-j]!=0){
		dp[t]=maxi(dp[t],dp[t-j]+1);
	}


}