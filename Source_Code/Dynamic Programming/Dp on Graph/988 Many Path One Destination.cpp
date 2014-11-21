#include<stdio.h>
#include<vector>
using namespace std;

vector<int>v[11000];
int dp[11000];
int col[11000];

int dfs(int s);

int main(){

	int i,j,k,l,n,bl=0;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){

		for(i=0;i<=n;i++){
			v[i].clear();
			dp[i]=0; col[i]=0;			
		}
		
		for(i=0;i<n;i++){
			scanf("%d",&k);
			for(j=1;j<=k;j++){
				scanf("%d",&l);
				v[i].push_back(l);
			}
		}

		int ans=dfs(0);
		
		if(bl) printf("\n");
		bl=1;
		printf("%d\n",ans);


	}


	return 0;
}

int dfs(int s){

	if(v[s].size()==0) return 1;
	if(col[s]==2) return dp[s];
	col[s]=1;
	int i,j,k;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		if(col[k]==1) continue;		
		dp[s]+=dfs(k);	
	}
	col[s]=2;
	return dp[s];
}