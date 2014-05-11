#include<stdio.h>
#include<string.h>

#define ii long long int
#define maxm 400

ii dp[50][50][maxm];
ii cal(int ind,int l,int s);

int main(){
	
	int i,j,k,l,t=1,s;
	//freopen("in.txt","r",stdin);
	
	memset(dp,-1,sizeof(dp));
	
	while(scanf("%d %d",&l,&s)==2){
		
		if(!l&&!s) break;
		
		if(l>26||s>360) printf("Case %d: 0\n",t++);		
		else printf("Case %d: %lld\n",t++,cal(0,l,s));		
		
	}	
	
	return 0;
}

ii cal(int ind,int l,int s){
	
	//printf("%d %d %d\n",ind,l,s);
	
	if(ind>26) return 0;
	if(l<0||s<0) return 0;
	if(l==0&&s==0) return 1;
	
	if(dp[ind][l][s]!=-1) return dp[ind][l][s];
	
	int i;
	ii ret=0;
	
	for(i=ind+1;i<=26;i++){
		ret+=cal(i,l-1,s-i);		
	}
	
	return dp[ind][l][s]=ret;	
}
