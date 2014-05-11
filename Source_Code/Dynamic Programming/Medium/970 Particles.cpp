#include<stdio.h>
#include<string.h>

#define maxm 105

int dp[maxm][maxm][5];
char s[maxm];

int cal(int b,int e,int req);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--){

		scanf("%s",s); memset(dp,-1,sizeof(dp));
		l=strlen(s);
		
		if(cal(0,l-1,3)==1){
			printf("Z\n"); continue;
		}
		if(cal(0,l-1,2)==1){
			printf("Y\n"); continue;
		}
		else printf("X\n");
		

	}

	return 0;
}

int cal(int b,int e,int req){

	if(b>e) return 1;
	if(b==e){
		if(req==(s[b]-'X'+1)) return 1;
		return 0;
	}

	if(dp[b][e][req]!=-1) return dp[b][e][req];

	int i;

	for(i=b+1;i<=e;i++){
		if(req==3){
			if(cal(b,i-1,1)&&cal(i,e,3)) return dp[b][e][req]=1;
			if(cal(b,i-1,3)&&cal(i,e,1)) return dp[b][e][req]=1;
		}
		if(req==2){
			if(cal(b,i-1,1)&&cal(i,e,1)) return dp[b][e][req]=1;
			if(cal(b,i-1,2)&&cal(i,e,2)) return dp[b][e][req]=1;
			if(cal(b,i-1,2)&&cal(i,e,3)) return dp[b][e][req]=1;
			if(cal(b,i-1,3)&&cal(i,e,2)) return dp[b][e][req]=1;
		}
		if(req==1){
			if(cal(b,i-1,1)&&cal(i,e,2)) return dp[b][e][req]=1;
			if(cal(b,i-1,2)&&cal(i,e,1)) return dp[b][e][req]=1;
			if(cal(b,i-1,3)&&cal(i,e,3)) return dp[b][e][req]=1;
		}
	}

	return dp[b][e][req]=0;
}