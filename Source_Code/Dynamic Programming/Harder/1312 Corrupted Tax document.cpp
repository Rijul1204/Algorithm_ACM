#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 10100
#define mod 10007
#define ii long long int

struct node{
	int max1;
	ii num;
	node(){}
	node(int a,ii b){max1=a; num=b;}
};

vector<int>v[maxm];
node dp[maxm][4];
int n,vis[maxm][4];

node cal(int ind,int fl);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=0;i<=n;i++){
			v[i].clear();
		}

		int i1,j1;
		for(i=1;i<=n;i++){
			scanf("%d %d",&j,&k);
			for(i1=1;i1<=k;i1++){
				scanf("%d",&l);
				v[j].push_back(l);
			}
		}
		memset(vis,0,sizeof(vis));
		node ans=cal(1,1);

		printf("Case %d: %d %lld\n",t++,ans.max1,ans.num);


	}

	return 0;
}

node cal(int ind,int fl){

	if(v[ind].size()==0) return node(0,1);

	if(vis[ind][fl]) return dp[ind][fl];
	vis[ind][fl]=1;

	ii i,j,k;
	ii l;
	node ret=node(0,1),ret1,ret2,ret3;

	for(i=0;i<v[ind].size();i++){
		k=v[ind][i];
		ret1=cal(k,1);
		ret.max1+=ret1.max1;
		ret.num*=ret1.num;
		ret.num%=mod;
	}

	if(fl==0) return dp[ind][fl]=ret;


	node temp=ret;

	for(i=0;i<v[ind].size();i++){
		k=v[ind][i];
		ret1=cal(k,0); ret1.max1+=1;
		ret2=node(0,1); l=1;
		for(j=0;j<v[ind].size();j++){
			k=v[ind][j];
			if(j==i) continue;
			ret3=cal(k,1);
			ret1.max1+=ret3.max1; ret1.num*=ret3.num; ret1.num%=mod;
			ret2.max1+=ret3.max1;
			ret2.num*=ret3.num; ret2.num%=mod;
			if(j>i){
				l*=ret3.num; l%=mod;
			}
		}
		if(ret1.max1==ret.max1){
			//j=cal(k,0).num; j*=l; j%=mod;
			ret.num+=ret1.num; ret.num%=mod;
		}
		else if(ret1.max1>ret.max1){
			ret=ret1;
		}

	}
	ret.num%=mod;

	return dp[ind][fl]=ret;

}
