#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

#define maxm 60

struct node{
	int x,y,cost;
};

int col[maxm][maxm],d[maxm][maxm],r,c,ans;
queue<node>q;
char grid[maxm][maxm];

void bfs(node s);

int main(){

	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&r,&c);

		for(i=1;i<=r;i++) scanf("%s",grid[i]+1);
		node temp;
		
		ans=-1;
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				if(grid[i][j]=='a'||grid[i][j]=='b'||grid[i][j]=='c'){
					temp.x=i; temp.y=j; temp.cost=0; 
					bfs(temp);
				}
			}
		}

		printf("Case %d: %d\n",t++,ans);


	}

	return 0;
}

void bfs(node s){

	int i,j,k,l;
	node temp,temp1;

	while(!q.empty()) q.pop();

	memset(col,0,sizeof(col));
	col[s.x][s.y]=1;

	q.push(s);

	while(!q.empty()){

		temp=q.front(); q.pop();

		i=temp.x; j=temp.y;

		if(grid[i][j]=='h'){
			if(temp.cost>ans) ans=temp.cost;
			return ;
		}

		//left>?>>

		k=i; l=j-1;

		if(l>0){
			if(grid[k][l]!='#'&&grid[k][l]!='m'&&col[k][l]==0){
				temp1.cost=temp.cost+1; temp1.x=k; temp1.y=l;
				col[k][l]=1;
				q.push(temp1);
			}
		}

		//right

		
		k=i; l=j+1;

		if(l<=c){
			if(grid[k][l]!='#'&&grid[k][l]!='m'&&col[k][l]==0){
				temp1.cost=temp.cost+1; temp1.x=k; temp1.y=l;
				col[k][l]=1;
				q.push(temp1);
			}
		}

		//up

		
		k=i-1; l=j;

		if(k>0){
			if(grid[k][l]!='#'&&grid[k][l]!='m'&&col[k][l]==0){
				temp1.cost=temp.cost+1; temp1.x=k; temp1.y=l;
				col[k][l]=1;
				q.push(temp1);
			}
		}
		
		//down

		
		k=i+1; l=j;

		if(k<=r){
			if(grid[k][l]!='#'&&grid[k][l]!='m'&&col[k][l]==0){
				temp1.cost=temp.cost+1; temp1.x=k; temp1.y=l;
				col[k][l]=1;
				q.push(temp1);
			}
		}


	}

}