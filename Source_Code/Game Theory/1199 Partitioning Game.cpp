#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;

#define maxm 10010

int dp[maxm],n;

int cal(int n);

int main(){

	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		int ans=0;

		for(i=1;i<=n;i++){
			scanf("%d",&k);
			ans^=cal(k);
		}

		if(ans){
			printf("Case %d: Alice\n",t++);
		}
		else{
			printf("Case %d: Bob\n",t++);
		}


	}


	return 0;
}

int cal(int n){

	if(dp[n]!=-1) return dp[n];
	
	set<int>s;
	
	int ret=0,i,k,l;
	for(i=1;i<=(n/2);i++){
		if(i==n-i) break;
		k=cal(i);
		l=cal(n-i);
		s.insert(k^l);
	}

	while(s.find(ret)!=s.end()) {
		ret++;
	}
	
	return dp[n]=ret;
}