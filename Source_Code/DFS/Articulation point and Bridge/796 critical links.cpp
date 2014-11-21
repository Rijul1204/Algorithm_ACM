#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;

#define pi acos(-1.0)
#define inf (1<<28)
#define eps 1e-9
#define area(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define sqr(x) ((x)*(x))
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define spDist(lat1,long1,lat2,long2,r) ( r * acos( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1-long2) ) )
#define isEq(a,b) (fabs(a-b)<eps)
#define  ii __int64

int diru[] = {-1,-1,-1,0,0,1,1,1};
int dirv[] = {-1,0,1,-1,1,-1,0,1};


int node,edge;
vector<int>v[1100];
int low[1100],col[1100],time1,dis[1100],count1,flag[1100];
bool bridge[1100][1100];

void set(int n);
void dfs(int s,int pre,int deep);


int main(){

	int i,j,k,l,ret,ans,e,n;

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&node)==1){

		
		for(i=0;i<=node;i++) v[i].clear();
		
		for(i=0;i<node;i++){
			scanf("%d (%d)",&n,&e);
			for(j=1;j<=e;j++){
				scanf("%d",&l);
				v[n].push_back(l);
				v[l].push_back(n);
			}
		}

		set(node);
		
		for(i=0;i<node;i++){
			if(!col[i]) dfs(i,0,0);
		}
		
			
		printf("%d critical links\n",count1);

		for(i=0;i<node;i++){
			for(j=i+1;j<node;j++){
				if(bridge[i][j]) printf("%d - %d\n",i,j);
			}	
		}
		printf("\n");
	
	
	}


	return 0;

}

void set(int n){

	int i,j;

	for(i=0;i<=n;i++){
		low[i]=col[i]=dis[i]=0;
	}
	time1=1;

	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			bridge[i][j]=0;
		}
	}
	
	count1=0;

}

void dfs(int s,int pre,int deep){

	col[s]=1;
	dis[s]=deep;
	low[s]=deep;

	for(int i=0;i<v[s].size();i++){
		int temp=v[s][i];
		if(col[temp]==1&&temp!=pre){
			if(dis[temp]<low[s]) low[s]=dis[temp];
		}
		else if(col[temp]==0){
			dfs(temp,s,deep+1);
			if(low[temp]<low[s]) low[s]=low[temp];
			if(low[temp]>dis[s]){
				count1++;
				bridge[temp][s]=bridge[s][temp]=1;
			}
		}

	}
	
	col[s]=2;


}