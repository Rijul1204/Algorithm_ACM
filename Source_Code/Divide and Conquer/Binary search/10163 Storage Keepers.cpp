#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxn 110
#define maxm 1010
#define ii int
#define inf 1<<28

struct node{
	ii res,sum;
	node(){}
	node(ii a,ii b){ res=a; sum=b;}
};

node dp[maxn][35][maxm];
bool v[maxn][35][maxm];
int p[35],n,m;
ii bs();
bool f(int val);
node cal(int n,int m,int now);
node mini(node a,node b){
	if(a.res==b.res){
		if(a.sum<b.sum) return a;
		return b;
	}
	if(a.res>b.res) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(1){

		scanf("%d %d",&n,&m);
		if(!n&&!m) break;

		for(i=0;i<m;i++){
			scanf("%d",&p[i]);
		}
		sort(p,p+m);
		node ans;
		ans.res=bs();
		if(ans.res==0){
			ans.sum=0;
			printf("%d %d\n",ans.res,ans.sum);
			continue;
		}
		
		memset(v,0,sizeof(v));
		node ans1=cal(n,m-1,ans.res);
		ans.sum=ans1.sum;
		ans1=node(0,0);
		ans=mini(ans,ans1);
		
		printf("%d %d\n",ans.res,ans.sum);
	}

	return 0;
}

ii bs(){

	int lo=1,hi=p[m-1],mid;

	if(!f(1)) return 0;

	while(lo<=hi){

		mid=lo+hi; mid/=2;

		if(!f(mid)){
			hi=mid-1;
		}
		else{
			if(mid==lo){
				if(f(mid+1)) return mid+1;
				return mid;
			}
			lo=mid;
		}
	}
	return lo;

}

bool f(int val){

	int i,j,k,l;
	j=n; 
	for(i=m-1;i>=0;i--){
		k=p[i]/val;
		j-=k; if(j<=0) return 1;
	}
	return 0;

}

node cal(int n,int m,int now){

	if(n<=0) return node(now,0);
	if(m<0) return node(-inf,inf);

	if(v[n][m][now]) return dp[n][m][now];
	v[n][m][now]=1;

	int i,j,k,l;
	node ret,ret1;
	
	ret=cal(n,m-1,now);

	for(i=now;i>=now;i--){
		k=p[m]/i;
		ret1=cal(n-k,m-1,i);
		ret1.sum+=p[m];
		ret=mini(ret,ret1);		
		if(n-k<0) break;		
		if(ret.res>=i) break;
	}
	
	return dp[n][m][now]=ret;
}