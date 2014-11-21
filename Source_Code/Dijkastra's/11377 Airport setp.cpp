#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define maxm 2100
#define inf 1<<25

struct node{
	int no;
	int dis;
	
};

int n,m,k;
vector<int>v[maxm+10];
int flag[maxm+10],pre[maxm+10],dis[maxm+10];
bool operator<(const node &a,const node &b){
	return a.dis>b.dis;
}
priority_queue<node>q;

int dij(int s,int d);

int main(){

	int i,j,l,test,t=1;

//	freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d %d %d",&n,&m,&k);
		for(i=0;i<=n;i++){
			v[i].clear();
			flag[i]=0;
			pre[i]=i;
		}

		for(i=1;i<=k;i++){
			scanf("%d",&j);
			flag[j]=1;
		}

		for(l=1;l<=m;l++){
			scanf("%d %d",&i,&j);
			v[i].push_back(j);
			v[j].push_back(i);
		}
		int qu;
		scanf("%d",&qu);
		printf("Case %d:\n",t++);
		for(l=1;l<=qu;l++){
			scanf("%d %d",&i,&j);
			printf("%d\n",dij(i,j));
		}
		printf("\n");


	}

	return 0;
}

int dij(int s,int d){
	
	if(s==d) return 0;
	int i,j,k,l,c;
	node temp,temp1;
	temp.dis=0;
	temp.no=s;
	for(i=0;i<=n;i++) dis[i]=inf;
	if(flag[s]!=1) dis[s]=1;
	else dis[s]=0;
	

	while(!q.empty()) q.pop();

	q.push(temp);

	while(!q.empty()){
		temp=q.top();q.pop();
		i=temp.no;

		for(j=0;j<v[i].size();j++){
			l=v[i][j];
			if(flag[l]==1) c=0;
			else c=1;
			if(dis[l]>dis[i]+c){
				dis[l]=dis[i]+c;
				temp1.dis=dis[l];
				temp1.no=l;
				q.push(temp1);
			}
		}
	}
	if(dis[d]==inf) return -1;
	return dis[d];

}