#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 40
#define maxl 5
#define ii long long int

vector<int>v[maxm];
char s1[5],s2[5],s3[5],s4[5];
int flag[maxm],move,n;
ii dp[maxm][maxm];
ii cal(int n,int m);

int main(){
	
	int i,j,k,l,test;
	
	//freopen("in.txt","r",stdin);
			
	while(scanf("%d",&n)==1){
		
		//printf("%d\n",n);		
		
		for(i=0;i<=30;i++){
			 v[i].clear();
		}
		
		memset(flag,0,sizeof(flag));
						
		for(i=1;i<=n;i++){
			scanf("%s %s %s %s",s1,s2,s3,s4);
			v[s1[0]-'A'].push_back(s2[0]-'A');
			v[s1[0]-'A'].push_back(s3[0]-'A');
			if(s4[0]=='x') flag[s1[0]-'A']=1;			
		}
		
		scanf("%d",&move);
		memset(dp,-1,sizeof(dp));		
		printf("%lld\n",cal(0,0));				
		
	}	
	
	return 0;
}

ii cal(int n,int m){
	
	if(m==move&&flag[n]==1) return 1;
	if(m>=move) return 0;
	
	
	if(dp[n][m]!=-1) return dp[n][m];
	
	ii ret;
	
	int n1,n2;
	
	n1=v[n][0]; n2=v[n][1];
	//printf("%d %d\n",n1,n2);
	
	ret=cal(n1,m+1);
	ret+=cal(n2,m+1);
	
	return dp[n][m]=ret;	
	
}
