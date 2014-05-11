#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

#define maxm 3000

vector<int>v[maxm],vt[maxm],topo;
vector<int>super[maxm],supert[maxm];
int ws[maxm],d[maxm],count1;
int col[maxm],n,m,pre[maxm];

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

void set(int n){

	for(int i=0;i<=n;i++){
		super[i].clear(); supert[i].clear();
		v[i].clear(); vt[i].clear();
		d[i]=0; pre[i]=i;	ws[i]=0;	
	}
	topo.clear();


}
void dfs(int s);
void dfst(int s,int par);

int main(){

	int i,j,k,l,test;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);
		set(maxm-100);

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
			vt[l].push_back(k);
		}
		
		memset(col,0,sizeof(col));

		for(i=1;i<=n;i++){			
			if(!col[i]) dfs(i);
		}

		memset(col,0,sizeof(col));

		int c=n+1;

		for(j=topo.size()-1;j>=0;j--){
			i=topo[j];
			if(!col[i]){
				count1=0;
				dfst(i,++c);
				ws[c]=count1;
			}
		}

	//	printf("%d\n",c-n);

		

		for(i=1;i<=n;i++){
			for(j=0;j<v[i].size();j++){
				l=v[i][j];
				k=find(i);
				l=find(l);
				if(k!=l){
					super[k].push_back(l);
					supert[l].push_back(k);
				}
			}
		}

		for(i=n+2;i<=c;i++){
			if(supert[i].size()==0){
				super[n+1].push_back(i);
			}
			if(super[i].size()==0){
				super[i].push_back(c+1);
			}
		}
		
		d[n+1]=0;
		for(i=n+1;i<=c+1;i++){
			for(j=0;j<super[i].size();j++){
				k=super[i][j];
				if(d[k]<d[i]+ws[k]){
					d[k]=d[i]+ws[k];
				}
			}
		}

		printf("%d\n",d[c+1]);

	}

	return 0;
}

void dfst(int s,int par){

	col[s]=1;
	pre[s]=par;
	count1++;

	int i,j,k;

	for(j=0;j<vt[s].size();j++){
		i=vt[s][j];
		if(col[i]==0){
			dfst(i,par);
		}
	}

	col[s]=2;	

}

void dfs(int s){

	col[s]=1;

	int i,j,k;

	for(j=0;j<v[s].size();j++){
		i=v[s][j];
		if(col[i]==0){
			dfs(i);
		}
	}

	col[s]=2;
	topo.push_back(s);

}