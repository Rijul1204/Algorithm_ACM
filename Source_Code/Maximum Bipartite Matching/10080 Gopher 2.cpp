#include<stdio.h>
#include<vector>
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

struct node{
	int x1;
	int y1;
};

vector<int>vec[1000];
double x[1000],y[1000],x2[1000],y2[1000];
int n,count1;
int flag[1000],mark[1000],col[1000],left[1000],right[1000];
int bipartite(int n);
bool dfs(int s);

int main(){

	int i,j,k,l,ret,ans,e,m,s,v;
	double dis;
	
	//freopen("in.txt","r",stdin);

	while(scanf("%d %d %d %d",&n,&m,&s,&v)==4){
		
		for(i=0;i<=n+m;i++) flag[i]=0;
		for(i=0;i<=n+m;i++) col[i]=0;
		for(i=0;i<=n+m;i++) mark[i]=0;
		
		for(i=1;i<=n+m;i++){
			scanf("%lf %lf",&x[i],&y[i]);
		}
		for(i=1;i<=n;i++) vec[i].clear();


		for(i=1;i<=n;i++){
			for(j=n+1;j<=n+m;j++){
				dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				//printf("dis->%lf\n",dis);
				if(dis/(v*v)<(s*s)){
					vec[i].push_back(j);
				}
				double temp=dis/(double)(v*v);
				temp=(temp-s*s);
				if(temp<0) temp*=-1;
				if(temp<.00000001){
					vec[i].push_back(j);
				}
			
			}
		}
		
		printf("%d\n",n-bipartite(n));
		
	}


	return 0;

}

void set(int n){

	for(int i=0;i<=n;i++) col[i]=0;
}

int bipartite(int n){

	int i,j,k,l;
	count1=0;
	memset(left,-1,sizeof(left));
	memset(right,-1,sizeof(right));

	bool done=false;

	do{
		done=true;
		set(n);
		for(i=1;i<=n;i++){
			if(left[i]==-1&&dfs(i)){
				done=0;
			}						
		}
	}while(!done);

	for(i=1;i<=n;i++){
		if(left[i]!=-1) count1++;
	}

	return count1;

}

bool dfs(int s){

	if(col[s]==1) return false;
	col[s]=1;
	int i;

	for(i=0;i<vec[s].size();i++){
		int t=vec[s][i];
		if(right[t]==-1){
			right[t]=s;
			left[s]=t;
			return true;
		}
	}
	for(i=0;i<vec[s].size();i++){
		int t=vec[s][i];
		if(dfs(right[t])){
			right[t]=s;
			left[s]=t;
			return true;
		}
	}

	return false;

}