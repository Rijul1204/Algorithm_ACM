#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

#define maxm 150
#define inf 1<<28

struct node{
	int floor;
	int hole;
	int cost;
};

bool operator<(const node &a,const node &b){
	if(a.cost==b.cost) return a.floor<b.floor;
	return a.cost>b.cost;
}
priority_queue<node>pq;


int d[maxm][20][20],mat[maxm][20][20],n,m,ans;
char s[maxm];

void dij();

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%s",s)==1){

		scanf("%d %d",&n,&m);

		for(k=1;k<n;k++){
			for(i=1;i<=m;i++){
				for(j=1;j<=m;j++){
					scanf("%d",&l);
					mat[k][i][j]=l;
				}
			}
		}

		dij();

		printf("%s\n%d\n",s,ans);

	}

	return 0;
}

void dij(){

	int i,j,k,l;
	node temp,temp1;

	while(!pq.empty()) pq.pop();

	for(k=1;k<=n;k++){
		for(i=1;i<=m;i++){
			for(j=1;j<=m;j++){
				d[k][i][j]=inf;
			}
		}
	}

	temp.cost=0; temp.floor=0;
	
	for(i=1;i<=m;i++){
		temp.hole=i;
		pq.push(temp);
	}

	while(!pq.empty()){

		temp=pq.top(); pq.pop();

		if(temp.floor==n-1){
			ans=temp.cost;
			return;
		}

		l=temp.floor;
		i=temp.hole;

		for(j=1;j<=m;j++){
			if(d[l+1][i][j]>temp.cost+mat[l+1][i][j]+2){
				d[l+1][i][j]=temp.cost+mat[l+1][i][j]+2;
				temp1.cost=d[l+1][i][j];
				temp1.floor=l+1;
				temp1.hole=j;
				pq.push(temp1);
			}
		}

	}




}