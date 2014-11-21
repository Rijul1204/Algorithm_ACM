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

map<string,int>city;
map<int,string>city1;
vector<int>v[10100];
queue<int>q;

int col[11100],dist[11100],pre[11100],count1;

void bfs(int s);
void set(int n);
void print(int n,int end);

int main(){

	int i,j,k,l,ret,ans,flag,e,n;
	bool blank=0;
	char s1[10000],s2[10000];

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		
		set(10100);

		city.clear(); city1.clear();
		for(i=0;i<=10000;i++) v[i].clear();

		count1=1;
		for(i=1;i<=n;i++){
			scanf("%s %s",s1,s2);
			
			if(!city[s1]){
				city[s1]=count1++;
				city1[count1-1]=s1;
			}
			if(!city[s2]){
				city[s2]=count1++;
				city1[count1-1]=s2;
			}
			
			v[city[s1]].push_back(city[s2]);
			v[city[s2]].push_back(city[s1]);

		}

		scanf("%s %s",s1,s2);
		//printf("%s %d %s %d\n",s1,city[s1],s2,city[s2]);
		bfs(city[s1]);
		
		if(blank) printf("\n");
		blank=1;
		
		if(city[s2]==0) printf("No route\n");
		else if(dist[city[s2]]==inf) printf("No route\n");
		else print(city[s2],city[s2]);
		//printf("\n");
		

	}


	return 0;

}

void print(int n,int end){

	if(pre[n]==n){
		cout<<city1[n];
		return;
	}
	print(pre[n],end);
	cout<<" "<<city1[n]<<endl;
	if(n!=end) cout<< city1[n];


}

void set(int n){

	for(int i=0;i<=n;i++){
		col[i]=0;
		dist[i]=inf;
		pre[i]=i;
	}
}

void bfs(int s){

	dist[s]=0;
	col[s]=1;
	q.push(s);

	while(!q.empty()){
		int temp=q.front();
		q.pop();
		
		for(int i=0;i<v[temp].size();i++){
			int t1=v[temp][i];
			if(!col[t1]){
				dist[t1]=dist[temp]+1;
				col[t1]=1;
				pre[t1]=temp;
				q.push(t1);
			}
		}

		col[temp]=2;
	}	


}