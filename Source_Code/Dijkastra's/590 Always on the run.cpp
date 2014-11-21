#include<stdio.h>
#include<queue>
using namespace std;

#define inf 1<<28

struct node{
	int dist;
	int no;
	int day;
};

bool operator <(const node& a,const node &b){
	return a.dist>b.dist;
}

priority_queue<node>q;
void dij(int s);
node city[100];
int mat[20][20][1010];
int d[20][1010];

int n,da;

int main(){

	int i,j,k,l,t,cas=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&da)==2){
		if(!n&&!da) break;

		for(i=1;i<=n;i++){
	
			for(j=1;j<=n;j++){
				if(i==j) continue;
				scanf("%d",&k);
				for(l=1;l<=k;l++){
					scanf("%d",&mat[i][j][l]);
				}
				for(;l<=da;l++){
					t=l%k;
					if(t==0) t=k;
					mat[i][j][l]=mat[i][j][t];
				}
			}
		}
		for(i=1;i<=n+2;i++){
			for(j=1;j<=da+2;j++){
				d[i][j]=inf;
			}
		}
		
		dij(1);
		printf("Scenario #%d\n",cas++);
        if(d[n][da]!=inf) printf("The best flight costs %d.\n",d[n][da]);
		else printf("No flight possible.\n");
		printf("\n");

	}


	return 0;
}
void dij(int s){

	int i,j,k,l,day;
	node temp,temp1;
	
	temp.day=0;
	temp.dist=0;
	temp.no=1;
	d[1][1]=0;
	q.push(temp);
	while(!q.empty()){
		temp=q.top(); q.pop();
		day=temp.day+1;
		i=temp.no;
		if(day>da) continue;

		for(j=1;j<=n;j++){
			if(mat[i][j][day]==0) continue;
			if(d[j][day]>mat[i][j][day]+d[i][day-1]){
				d[j][day]=mat[i][j][day]+d[i][day-1];
				temp1.dist=d[j][day];
				temp1.no=j;
				temp1.day=day;
				q.push(temp1);
			}
			
		}


	}

}