#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define maxn 101005
//#define inf 1<<29
//#define ii long long int
#define ii __int64

struct node{
	int no;
	ii cost;
};

bool operator <( const node &a,const node &b){
	return a.cost>b.cost;
}

int on(int n,int k){

	return (n|1<<k);

}

int off(int n,int k){

	return (n- (1<<k));

}

int check(int n,int k){

	return ((n&1<<k)==(1<<k));

}

vector<node>v[maxn];
ii d[15][maxn];
int store[15],n,m,ns;
priority_queue<node>q;
ii dp[15][7000];
ii inf;

void dijkstra(int st,int ind);
ii run(int n,int curr); 
ii min(ii a,ii b){ if(a<b) return a;  return b; }

int main(){

	int i,j,k,l,test;
	node temp;
	inf=1<<30; inf*=inf;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		for(i=0;i<=n;i++){
			v[i].clear();

		}

		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			temp.no=l ;temp.cost=j;
			v[k].push_back(temp);
			temp.no=k;
			v[l].push_back(temp);
		}

		scanf("%d",&ns);

		for(i=1;i<=ns;i++){
			scanf("%d",&store[i]);
		}
		
		dijkstra(0,0);
		for(i=1;i<=ns;i++){
			dijkstra(store[i],i);
		}

	//	for(i=1;i<=ns;i++){
	//		for(j=0;j<n;j++){
	//			printf("%2d ",d[i][j]);
	//		}
	//		printf("\n");
	//	}

		for(j=0;j<=ns+2;j++){
			for(i=0;i<=7000;i++){
				
				dp[j][i]=-1;
			}
		}
		store[0]=0;
		ii ans=run(0,0);
		

		printf("%lld\n",ans);


	}
	


	return 0;
}

ii run(int n,int curr){


	if(dp[curr][n]!=-1) return dp[curr][n];
	
	ii ret=inf;
	
	int temp;

	for(int i=1;i<=ns;i++){
		if(!check(n,i)){
			temp=on(n,i);
			ret=min(ret,run(temp,i)+d[curr][store[i]]);
		}
//		else {
//		     temp=off(n,i);
//		     ret=min(ret,run(temp,curr));
//		}
	}
	if(ret==inf) ret=d[0][store[curr]];

	return dp[curr][n]=ret;

}

void dijkstra(int st,int ind){

	ii i,j,k,l;
	node temp,temp1;

	for(i=0;i<=n;i++) d[ind][i]=inf;
	
	d[ind][st]=0;
	temp.no=st;
	temp.cost=0;
	q.push(temp);

	while(!q.empty()){

		temp=q.top(); q.pop();
		i=temp.no; k=temp.cost;

		for(j=0;j<v[i].size();j++){
			temp1=v[i][j];
			l=temp1.no; k=temp1.cost;
			if(d[ind][l]>d[ind][i]+k){
				d[ind][l]=d[ind][i]+k;
				temp1.no=l; temp1.cost=d[ind][l];
				q.push(temp1);
			}
		}

	}

}