#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 1010

struct node{
	int no,road;
};

vector<int>v[maxm];
node dp[maxm][5];
bool vis[maxm][5],col[maxm];
int n,m;

node mini(node a,node b){
	if(a.no==b.no){
		if(a.road>b.road) return a;
		return b;
	}
	if(a.no<b.no) return a;
	return b;
}

node cal(int no,int fl,int pre);

int main(){
	
	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d %d",&n,&m);
		
		for(i=0;i<=n;i++){
			v[i].clear();
		}
		
		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
			v[l].push_back(k);
		}
		memset(vis,0,sizeof(vis));
		memset(col,0,sizeof(col));
		
		node ans,ans1,ans2;
		ans.no=0; ans.road=0;
		for(i=0;i<n;i++){
			if(col[i]) continue;
			//ans1=cal(i,0,-1);
			ans2=cal(i,2,-1);
			ans.no+=ans2.no; ans.road+=ans2.road;			
		}

		printf("Case %d: %d %d %d\n",t++,ans.no,ans.road,m-ans.road);
		
		
	}
	
	return 0;
}

node cal(int no,int fl,int pre){


	if(vis[no][fl]) return dp[no][fl];
	col[no]=1;


	int i,j,k,l;

	node ret,temp,temp1;
	ret.no=0; ret.road=0;
	

	temp.no=1;	temp.road=0;
	if(fl==1) temp.road=1;
	for(i=0;i<v[no].size();i++){
		k=v[no][i];
		if(k==pre) continue;
		temp1=cal(k,1,no);
		temp.no+=temp1.no; temp.road+=temp1.road;
	}
	if(fl==0) return dp[no][fl]=temp;

	ret=temp;
	temp.no=0; temp.road=0;
	
	for(i=0;i<v[no].size();i++){
		k=v[no][i];
		if(k==pre) continue;
		temp1=cal(k,0,no);		
		temp.no+=temp1.no; temp.road+=temp1.road;
	}

	ret=mini(ret,temp);
	return dp[no][fl]=ret;
	
}
