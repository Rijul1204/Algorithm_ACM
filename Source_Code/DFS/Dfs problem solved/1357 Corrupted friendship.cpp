#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

#define maxm 100100
//#define ii __int64
#define ii long long int

ii ans;
vector<int>v[maxm];
int col[maxm],n;

int dfs(int s);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=0;i<=n+5;i++){
			v[i].clear();
		}
		memset(col,0,sizeof(col));

		for(i=1;i<n;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
		}
		
		ans=0;
		dfs(1);

		printf("Case %d: %d %lld\n",t++,n-1,ans);
	}


	return 0;
}

int dfs(int s){

	col[s]=1;

	int i,j,k,l,c=1,sum=0;
	vector<int>vt;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		if(!col[k]){
			col[k]=1;
			l=dfs(k);
			c+=l;
			vt.push_back(l);
			sum+=l;
		}
	}
	
	ii n1,n2;
	n1=sum;
	for(i=0;i<vt.size();i++){
		ans+=((n1-vt[i])*vt[i]);
		n1-=vt[i];
	}

	return c;
}