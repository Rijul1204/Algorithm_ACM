#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 1010
#define maxe (1<<11)

int on(int n,int k){
	return n|(1<<k);
}
int off(int n,int k){
	return n-(n&(1<<k));
}
bool chck(int n,int k){
	return (1<<k)==(n&(1<<k));
}

int dp[maxe+10][maxm+10],mod,len;
char s[maxm];
int cal(int ind,int mask,int d); 

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);
	
	while(test--){
		
		scanf("%s",s); scanf("%d",&mod);
		len=strlen(s);
		sort(s,s+len);
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",t++,cal(0,0,0));


	}
	
	return 0;
}

int cal(int ind,int mask,int d){

	if(mask==((1<<len)-1)&&!d) return 1;
	if(mask==((1<<len)-1)&&d) return 0;

	if(dp[mask][d]!=-1) return dp[mask][d];

	int ret=0;
	int i,k,l;
	
	for(i=0;i<len;i++){
		if(chck(mask,i)) continue;
		if(i!=0&&s[i-1]==s[i]&&!chck(mask,i-1)) continue;
		k=on(mask,i);
		l=d*10+s[i]-'0';
		l%=mod;
		ret+=cal(ind+1,k,l);
	}

	return dp[mask][d]=ret;
	
}