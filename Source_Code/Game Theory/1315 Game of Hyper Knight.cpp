#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;

#define maxm 1050

int dp[maxm][maxm];
int dx[]={-1,-1,1,-2,-2,-3};
int dy[]={-2,-3,-2,-1,1,-1};

int cal(int i,int j);

int main(){
	
	int i,j,k,l,test,t=1,n;

//	freopen("in.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		int ans=0;
		for(i=1;i<=n;i++){
			scanf("%d %d",&k,&l);
			ans^=cal(k,l);
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

int cal(int i,int j){

	if(dp[i][j]!=-1) return dp[i][j];

	set<int>s;

	int ret=0,i1,k,l,j1,val;

	for(i1=0;i1<6;i1++){
		k=i+dx[i1]; l=j+dy[i1];
		if(k>=0&&l>=0){
			s.insert(cal(k,l));
		}
	}

	while(s.find(ret)!=s.end()){
		ret++;
	}
	
	return dp[i][j]=ret;
}