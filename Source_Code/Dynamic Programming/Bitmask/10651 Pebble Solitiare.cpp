#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int on(int n,int k)
{
	return n | (1 << k);
}

int off(int n,int k)
{
	return n - (1<<k);
}

bool check(int n,int k)
{
	if ((n & (1<<k)) == (1<<k)) return 1;
	return 0;
}

int dp[5000];

int call(int mask);
int min(int a,int b){
	if(a<b) return a;
	return b;

}

int main()
{
	int i,j,k,l,n,test;
	char s[1000];

	scanf("%d",&test);

	while(test--){
		memset(dp,-1,sizeof(dp));
		scanf("%s",s);
		n=0;
		for(i=0;s[i];i++){
			if(s[i]=='o') n=on(n,i);
		}
		printf("%d\n",call(n));			


	}

	return 0;

}

int call(int mask){

	if(dp[mask]!=-1) return dp[mask];

	int i,j,k,l,mask2,mini=0;
	bool found=0;

	for(i=1;i<11;i++){
		if(!check(mask,i)) continue;

		if(check(mask,i+1)&&!check(mask,i-1)){
			
			mask2=off(mask,i+1);
			mask2=on(mask2,i-1);
			mask2=off(mask2,i);
			if(!found) mini=call(mask2);
			else mini=min(mini,call(mask2));
			found=1;
		}
		
		if(!check(mask,i+1)&&check(mask,i-1)){
			mask2=off(mask,i-1);
			mask2=on(mask2,i+1);
			mask2=off(mask2,i);
			if(!found) mini=call(mask2);
			else mini=min(mini,call(mask2));
			found=1;
		}

	}
	if(!found){
		for(i=0;i<12;i++){
			if(check(mask,i)) mini++;
		}
	}

	return dp[mask]=mini;

}