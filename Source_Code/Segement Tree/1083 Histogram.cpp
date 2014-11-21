#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define ii long long int
#define maxm 500000
#define maxn 30010

struct point{
	int x,y;
};

struct tree{
	ii sum,pre,suff,res;
};

ii maxi(ii a,ii b){
	if(a>b) return a;
	return b;
}

vector<int>v[maxn];
tree m[maxm];
point p[maxm];
int n;

void update(int node,int b,int e,int k);
void init(int node,int b,int e);

int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d",&n);
		for(i=0;i<=30010;i++){
			v[i].clear();
		}

		for(i=1;i<=n;i++){
			scanf("%d",&k);
			v[k].push_back(i);
		}
		ii ans,ans1;
		ans=0;
		init(1,1,n);
		for(i=30000;i>=0;i--){
			if(v[i].size()==0) continue;
			for(j=0;j<v[i].size();j++){
				k=v[i][j];
				update(1,1,n,k);
			}
			ans1=i*m[1].res;
			if(ans1>ans) ans=ans1;
		}
		printf("Case %d: %d\n",t++,ans);

	}

	return 0;
}

void update(int node,int b,int e,int k){

	if(b==e){
		m[node].pre=m[node].suff=m[node].sum=m[node].res=1;
		return ;
	}
	
	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	if(k<=mid) update(left,b,mid,k);
	else update(right,mid+1,e,k);

	m[node].pre=maxi(m[left].pre,m[left].sum+m[right].pre);
	m[node].suff=maxi(m[right].suff,m[right].sum+m[left].suff);
	m[node].sum=m[left].sum+m[right].sum;

	m[node].res=maxi(m[left].res,m[right].res);
	m[node].res=maxi(m[node].res,m[left].suff+m[right].pre);
	m[node].res=maxi(m[node].res,maxi(m[node].sum,maxi(m[node].pre,m[node].suff)));

}

void init(int node,int b,int e){

	if(b==e){
		m[node].pre=m[node].suff=m[node].sum=m[node].res=-55553000;
		return ;
	}
	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	init(left,b,mid);
	init(right,mid+1,e);

	m[node].pre=m[node].suff=m[node].sum=m[node].res=-55553000;

}