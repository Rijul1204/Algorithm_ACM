#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;


#define pi acos(-1.0)
#define inf (1<<28)
#define eps 1e-9
#define area(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define sqr(x) ((x)*(x))
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define spDist(lat1,long1,lat2,long2,r) ( r * acos( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1-long2) ) )
#define isEq(a,b) (fabs(a-b)<eps)

vector<int>e[1200];
int dp[1220][5];
int back[1220];

int F(int u,int state);
int min(int a,int b){ if(a<b) return a; return b; }

int main(){

	int i,j,k,l,n,m,ans;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		if(!n) break;

		memset(dp,-1,sizeof(dp));
		memset(back,0,sizeof(back));
		for(i=0;i<=n;i++)e[i].clear();

		for(i=1;i<=n;i++){
			scanf("%d",&m);
			for(j=1;j<=m;j++){
				scanf("%d",&l);
				e[i].push_back(l);
				//e[l].push_back(i);
			}

		}
		back[1]=1;
		ans=min(F(1,1),F(1,-1));
	//	printf("%d\n",F(1,-1));
		printf("%d\n",ans);
	}

	return 0;

}

int F(int u,int state){

	if(e[u].size()==0) return 1;
	
	if(dp[u][state]!=-1) return dp[u][state];

	int sum;
	if(state==-1) sum=0;
	else sum=1;

	for(int i=0;i<e[u].size();i++){

		int curr=e[u][i];
		if(!back[curr]){
			back[curr]=1;
			if(state==-1) sum+=F(curr,1);
			else sum+=min(F(curr,-1),F(curr,1));
			back[curr]=0;
		}
	}

	return dp[u][state]=sum;

}