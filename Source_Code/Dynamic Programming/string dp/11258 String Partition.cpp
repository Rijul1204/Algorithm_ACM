#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define maxm 250
//#define ii __int64
#define ii long long int

ii dp[maxm][20];
char s[maxm];
int len;

ii cal(int i,int l);
ii maxi(ii a,ii b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test;

//	freopen("in.txt","r",stdin);
	scanf("%d",&test);
	
	while(test--){

		scanf("%s",s);
		len=strlen(s);
		
		memset(dp,-1,sizeof(dp));

		printf("%lld\n",cal(0,0));


	}


	return 0;
}

ii cal(int i,int l){

	if(i==len) return 0;

	if(dp[i][l]!=-1) return dp[i][l];

	
	ii ret=0;

	if(s[i]=='0'&&l==0){
		ret=cal(i+1,0)+0;
		return dp[i][l]=ret;
	}

	int j,k;
	ii num=0;

	for(j=0;j<=10;j++){
		if(i+j>=len) break;
		num*=10;
		num+=(s[i+j]-'0');
		if(num>=(2147483648)) break;
		ret=maxi(ret,cal(i+j+1,j)+num);
	}

	return dp[i][l]=ret;

}