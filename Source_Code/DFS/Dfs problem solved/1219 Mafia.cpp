#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 10100

struct node{
	int cost,no;
};

vector<int>v[maxm];
int a[maxm],col[maxm],n;

node dfs(int s,int pre);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		for(i=0;i<=n;i++){
			v[i].clear();
		}
		int i1,k1,l1;
		for(i=1;i<=n;i++){
			scanf("%d %d %d",&j,&k,&l);
			a[j]=k;
			for(i1=1;i1<=l;i1++){
				scanf("%d",&k1);
				v[j].push_back(k1);
				v[k1].push_back(j);
			}
		}
		
		
		node ans=dfs(1,0);
		printf("Case %d: %d\n",t++,ans.cost);


	}

	return 0;
}

node dfs(int s,int pre){
	
	int i,j,k,l;
	node ret,temp;
	ret.cost=0; ret.no=0;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		if(k==pre) continue;
		temp=dfs(k,s);
		ret.cost+=temp.cost;
		l=temp.no; if(l<0) l*=-1;
		ret.cost+=l;
		ret.no+=temp.no;
	}
	ret.no+=(a[s]-1);
	return ret;
}