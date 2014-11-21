#include<stdio.h>


int p[50]={0,1,5,8,2,2,4,5,6,7,8,9,6,65,5,3,3,3,5,6,2,3,4,5,6,7,8,9,0,1,8,7,6,5,5,6,7,8,9,0,2,34,4,5};
int dp[50];
int len;

int sum(int n);
int max(int a,int b);

int main(){
	
	int i,j,k,n;
		
	while(scanf("%d",&n)==1){
	len=n;

	printf("%d\n",sum(n));

	}
	
	return 0;
	
}

int sum(int n){

	if(n==0){
		dp[0]=p[0];
		return p[0];
	}
	if(n==1){
		dp[1]=p[1];		
		return p[1];
	}
	
	int q=-10;	
	for(int i=1;i<=n;i++){

		q=max(q,p[i]+sum(n-i));		
	}
		
	return q;
}

int max(int a,int b){

	if(a>b) return a;

	return b;
}
