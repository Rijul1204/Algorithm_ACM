#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

#define maxm 110
#define ii long long int
#define inf 1<<29
#define mod 1000000009

struct node{
	int x,y,x1,y1,cost;
	ii tot;
};

bool operator<(const node &a,const node &b){
	return a.cost>b.cost;
}

int d[maxm][maxm],a[maxm][maxm],n,d1[maxm][maxm];
int dirx[]={1,0,-1,0};
int diry[]={0,1,0,-1};

int dirx1[]={0,-1,0,1};
int diry1[]={-1,0,1,0};

priority_queue<node>pq;
ii ans=-1;
ii dij();

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)&&n){
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		printf("%lld\n",dij());

	}

	return 0;
}

ii dij(){
	
	int i,j,k,l,i1,j1,k1,l1;
	ii ret=0; ii ans=-1;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			d[i][j]=inf;
		}
	}
	memset(d1,0,sizeof(d1));

	node temp,temp1;
	temp.cost=a[1][1]+a[n][n]; temp.tot=1; temp.x=1; temp.y=1; temp.x1=n; temp.y1=n;
	d[1][1]=temp.cost; d1[1][1]=1;
	
	while(!pq.empty()) pq.pop();
	pq.push(temp);
	
	while(!pq.empty()){

		temp=pq.top(); pq.pop();
		if(temp.x+temp.y==n+1&&temp.x==temp.x1&&temp.y==temp.y1){
			if(ans==-1) ans=temp.cost;
			else if(ans!=temp.cost) break;
			ret+=d1[temp.x][temp.y]; ret%=mod;
			continue;
		}

		i=temp.x; j=temp.y;
		int val;
		for(i1=0;i1<4;i1++){
			k=i+dirx[i1]; l=j+diry[i1];
			k1=temp.x1+dirx1[i1]; l1=temp.y1+diry1[i1];
			if(k<1||l<1||k>n||l>n||k1<1||l1<1||k1>n||l1>n) continue;
			if(k==k1&&l==l1) val=a[k][l];
			else val=a[k][l]+a[k1][l1];
			if(d[k][l]>temp.cost+val){
				d[k][l]=temp.cost+val;
				temp1.cost=d[k][l];
				temp1.x=k; temp1.y=l; temp1.x1=k1; temp1.y1=l1;
				d1[k][l]=d1[i][j];
				temp1.tot=d1[k][l]; 
				pq.push(temp1);
			}
			else if(d[k][l]==temp.cost+val){
				d1[k][l]+=d1[i][j];
				d1[k][l]%=mod;
			}
		}

	}

	return ret;
}