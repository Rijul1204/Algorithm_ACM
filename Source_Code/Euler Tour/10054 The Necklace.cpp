#include<stdio.h>
#include<vector>
#include<map>
#include<string.h>
using namespace std;

#define maxm 1100

struct edge{
	int u;
	int v;
};

edge edges[maxm];

int deg[maxm],n,tot,ans[maxm],mark[maxm];

void back(int x);

int main(){

	int i,j,k,l,test,t=1,bl=0;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		memset(mark,0,sizeof(mark));
		memset(deg,0,sizeof(deg));
		
		scanf("%d",&n);
		
		for(i=1;i<=n;i++){
			scanf("%d %d",&k,&l);
			deg[k]++; deg[l]++;
			edges[i].u=k; edges[i].v=l;
		}

		int flag=1;

		for(i=1;i<=60;i++){
			if(deg[i]%2){
				flag=0;
				break;
			}			
		}

		if(bl) printf("\n");
		bl=1;

		printf("Case #%d\n",t++);

		if(!flag){
			printf("some beads may be lost\n");
			continue;
		}
		
		tot=0;

		for(i=1;i<=60;i++) if(deg[i]) break;

		back(i);
		
		printf("%d %d\n",ans[1],ans[2]);
		for(i=2;i<tot;i++){
			printf("%d %d\n",ans[i],ans[i+1]);
		}
		
		


	}


	return 0;
}

void back(int x){
     
	int i,y;

	for(i=1;i<=n;i++){
		if(mark[i]) continue;

		if(edges[i].u==x){
		//	ret[++tot]=edges[i];
			mark[i]=1;
			y=edges[i].v;
			back(y);
		}
		else if(edges[i].v==x){
		//	ret[++tot]=edges[i];
			mark[i]=1;
			y=edges[i].u;
			back(y);
		}

	}

	ans[++tot]=x;


}

