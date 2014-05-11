#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<string.h>
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

map<string,int>word;
vector<int>v[1000];

string str[]={"XXL","XL","L","M","S","XS"};
int n,m,lefts[100],rights[100],col[100];

int bipartite(int n);
bool dfs(int u);

int main(){

	int i,j,k,l,ret,ans,flag,e,test;
	char s1[100],s2[100];

	//freopen("in.txt","r",stdin);

	for(i=0;i<6;i++){
		word[str[i]]=i+1;
	}
//	printf("%d %d",word["XL"],word["S"]);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&n,&m);

		for(i=1;i<=m;i++) v[i].clear();

		for(i=1;i<=m;i++){
			scanf("%s %s",s1,s2);
			for(j=0;j<n/6;j++){
				v[i].push_back(word[s1]+(6*j));
				v[i].push_back(word[s2]+(6*j));
			}
		}

		for(i=1;i<=m;i++){
			for(j=0;j<v[i].size();j++){
		//		printf("%d ",v[i][j]);
			}
		//	printf("\n");
		}
		if(bipartite(m)==0) printf("YES\n");
		else printf("NO\n");

	}


	return 0;

}


int bipartite(int n){

	memset(lefts,-1,sizeof(lefts));
	memset(rights,-1,sizeof(rights));

	int i,j,k,l;
	bool done=false;

	do{
		done=true;
		memset(col,0,sizeof(col));
		for(i=1;i<=n;i++){
			if(rights[i]==-1&&dfs(i)){
				done=false;
			}
		}
	}while(!done);

	for(i=1,k=0;i<=n;i++){
		if(rights[i]==-1) k++;
	}


	return k;
}

bool dfs(int u){

	if(col[u]) return false;
	col[u]=1;

	int i=0,t;

	for(i=0;i<v[u].size();i++){
		t=v[u][i];
		if(lefts[t]==-1){
			lefts[t]=u;
			rights[u]=t;
			return true;
		}
	}

	for(i=0;i<v[u].size();i++){
		
		t=v[u][i];

		if(dfs(lefts[t])){
			lefts[t]=u;
			rights[u]=t;
			return true;
		}
	}


	return false;

}