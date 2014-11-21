#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

#define maxm 200
#define maxe 20000

struct node{
	int x;
	int y;
	int dist;
};
node nodes[maxm];

struct edge{
	int u,v,cost;
};

edge edges[maxe];
int pre[maxm],col[200][200],mark[100][100],d[200][200];
int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}
bool comp(edge a,edge b){
	return a.cost<b.cost;
}
queue<node>q;
char grid[100][100],tmp[10];
int r,c,c1;
void bfs(node s);

int main(){

	int i,j,k,l,test;

//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--){
		
		memset(mark,-1,sizeof(mark));

		scanf("%d %d",&c,&r);
		gets(tmp);
		
		for(i=0;i<r;i++){
			gets(grid[i]);
		}
		c1=0;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(grid[i][j]=='A'||grid[i][j]=='S'){
					nodes[c1].x=i; nodes[c1].y=j;
					mark[i][j]=c1;
					c1++;
				}
			}
		}
		
		int tot=0;

		for(i=0;i<c1;i++){
			memset(col,0,sizeof(col));
			node temp;
			temp=nodes[i];
			bfs(temp);
			for(j=i+1;j<c1;j++){
				edges[tot].u=i;
				edges[tot].v=j;
				edges[tot++].cost=d[nodes[j].x][nodes[j].y];				
			}
		}

		sort(edges,edges+tot,comp);

		for(i=0;i<=150;i++) pre[i]=i;

		int sum=0;

		for(i=0;i<tot;i++){
			k=find(edges[i].u);
			l=find(edges[i].v);
			if(k!=l){
				pre[k]=l;
				sum+=edges[i].cost;
			}
		}

		printf("%d\n",sum);


	}

	return 0;
}

void bfs(node s){

	int i,j,k,l;
	node temp,temp1;

	s.dist=0;
	col[s.x][s.y]=1;
	d[s.x][s.y]=0;
	s.dist=0;
	q.push(s);

	while(!q.empty()){
		
		temp=q.front(); q.pop();

		j=temp.y; i=temp.x;

		//up>>>>>>>
		k=i-1; l=j;
		if(k>=0){
			if(col[k][l]==0&&grid[k][l]!='#'){
				col[k][l]=1;
				d[k][l]=temp.dist+1;
				temp1.dist=d[k][l];
				temp1.x=k; temp1.y=l;
				q.push(temp1);
			}
		}		

		//down>>>>>>>>>>

		k=i+1; l=j;
		if(k<r){
			if(col[k][l]==0&&grid[k][l]!='#'){
				col[k][l]=1;
				d[k][l]=temp.dist+1;
				temp1.dist=d[k][l];
				temp1.x=k; temp1.y=l;
				q.push(temp1);
			}
		}

		//right>>>>>>>>>>>
		k=i; l=j+1;
		if(l<c){
			if(col[k][l]==0&&grid[k][l]!='#'){
				col[k][l]=1;
				d[k][l]=temp.dist+1;
				temp1.dist=d[k][l];
				temp1.x=k; temp1.y=l;
				q.push(temp1);
			}
		}

		//left>>>>>>>>>>>>>>>

		k=i; l=j-1;
		if(l>=0){
			if(col[k][l]==0&&grid[k][l]!='#'){
				col[k][l]=1;
				d[k][l]=temp.dist+1;
				temp1.dist=d[k][l];
				temp1.x=k; temp1.y=l;
				q.push(temp1);
			}
		}


	}
	


}