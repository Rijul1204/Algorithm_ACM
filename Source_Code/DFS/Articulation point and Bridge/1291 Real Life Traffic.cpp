#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 11000

vector<int>v[maxm];
int n,m,col[maxm],low[maxm],d[maxm],ans,time,pre[maxm],deg[maxm];

void dfs(int s,int pre);

int main(){
	
	int i,j,k,l,test,t=1;

   //freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		for(i=0;i<=n+2;i++){
			v[i].clear();		
		}
	
		memset(col,0,sizeof(col));
		memset(low,0,sizeof(low));
		memset(d,0,sizeof(d));

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
			v[l].push_back(k);
		}	
		
		ans=0;
		time=0;
		dfs(0,0);
		
		for(i=0;i<n;i++){
			pre[i]=low[i];
		}

		int fl=0;
		memset(deg,0,sizeof(deg));


		for(i=0;i<n;i++){
			k=pre[i];
			for(j=0;j<v[i].size();j++){
				l=pre[v[i][j]];
				if(k==l) continue;
				fl=1;
				deg[k]++; deg[l]++;
			}
		}

		if(!fl){
			printf("Case %d: %d\n",t++,0);
			continue;
		}
		memset(col,0,sizeof(col));
		
		ans=0;
		for(i=0;i<n;i++){
			j=pre[i];
			if(!col[j]){
			//	printf("%d %d\n",j,deg[j]);
				if(deg[j]==2) ans++;
				col[j]=1;
			}
		}
		
		if(ans%2) ans++;
		ans/=2;		

		printf("Case %d: %d\n",t++,ans);


	}	

	return 0;
}

void dfs(int s,int pre){

	col[s]=1;

	d[s]=time++;
	low[s]=d[s];

	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];

		if(col[k]==1&&k!=pre){
			if(d[k]<low[s]) low[s]=d[k];
			continue;
		}

	    if(!col[k]){
			dfs(k,s);		

			if(low[k]<low[s]){
				low[s]=low[k];
			}
		
		}

	}

}