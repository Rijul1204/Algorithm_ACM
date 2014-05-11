#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>	
using namespace std;

#define maxm 1330
#define inf 1<<30

struct node{
	int no;
	int cost;
	int rem;
};

bool operator<(const node &a,const node &b){
	return a.cost>b.cost;
}

struct edge{
	int u,v,next,cost;
};

vector<int>v[maxm];
priority_queue<node>pq;
int d[maxm][maxm],mat[maxm][maxm],p[maxm],ans,cap,dest,n,col[maxm][maxm],prev[maxm];

int dij(int s);

int main(){

	int i,j,k,l,test,t=1,c,m,q;
	node temp,temp1;

	//freopen("in.txt","r",stdin);
	//scanf("%d",&test);


	while(scanf("%d %d",&n,&m)==2){

		memset(mat,0,sizeof(mat));

		for(i=0;i<=n+2;i++){
			v[i].clear();
		}

		for(i=0;i<n;i++){
			scanf("%d",&p[i]);
		}

		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&c);
			mat[l][k]=mat[k][l]=c;
			v[l].push_back(k);
			v[k].push_back(l);			
		}

		scanf("%d",&q);
		
		//printf("Case %d:\n",t++);
		
		for(i=1;i<=q;i++){
			scanf("%d %d %d",&cap,&j,&dest);
			ans=inf;
			ans=dij(j);
			if(ans==inf)printf("impossible\n");
			else printf("%d\n",ans);
		}

	}

	return 0;
}

int dij(int s){

	int i,j,k,l;
	node temp,temp1;
	memset(col,0,sizeof(col));

	for(i=0;i<=n+1;i++){
		for(j=0;j<=cap;j++){
			d[i][j]=inf;
		}
	}
	while(!pq.empty()) pq.pop();

	temp.cost=0; temp.rem=0; temp.no=s;
	d[s][0]=0;
	pq.push(temp);

	while(!pq.empty()){

		temp=pq.top(); pq.pop();
		col[temp.no][temp.rem]=1;

		if(temp.no==dest){
			if(temp.cost<ans) ans=temp.cost;
			return temp.cost;
		}

		i=temp.no;
		l=temp.rem;

		if(temp.rem+1<=cap){
			if(d[i][temp.rem+1]>temp.cost+p[i]&&col[i][temp.rem+1]==0){
				d[i][temp.rem+1]=temp.cost+p[i];
				temp1.cost=temp.cost+p[i];
				temp1.no=i; temp1.rem=temp.rem+1;
				pq.push(temp1);
			}
		}

		/*for(l=1;l<=cap-temp.rem;l++){
			if(d[i][temp.rem+l]>temp.cost+p[i]*l){
				d[i][temp.rem+l]=temp.cost+p[i]*l;
				temp1.cost=temp.cost+p[i]*l;
				temp1.no=i;
				temp1.rem=temp.rem+l;
				pq.push(temp1);
			}
		}*/

		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(temp.rem>=mat[i][k]){
				temp1.cost=temp.cost;
				temp1.no=k; temp1.rem=temp.rem-mat[i][k];
				if(d[temp1.no][temp1.rem]>temp.cost&&col[k][temp1.rem]==0){
					d[temp1.no][temp1.rem]=temp.cost;
					pq.push(temp1);
				}
			}
			
			
		}

	}

	return ans;

}