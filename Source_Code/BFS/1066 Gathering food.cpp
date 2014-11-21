#include<stdio.h>
#include<string.h>
#include<queue>
#include<ctype.h>
using namespace std;

#define inf 1<<28
#define maxm 30

struct node{
	int x,y,cost,no;
};

int col[maxm][maxm][maxm],n,ans,tot;
char grid[maxm][maxm];
void bfs(node s);

queue<node>q;

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;
	
	freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=1;i<=n;i++) scanf("%s",grid[i]+1);
		
		k=0;
		ans=inf;
		node temp;
				
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(grid[i][j]=='A'){
					temp.cost=0; temp.no=1; temp.x=i; temp.y=j;
					//bfs(temp);					
				}
				if(isalpha(grid[i][j])){
					k=maxi(k,grid[i][j]-'A'+1);
				}
			}
		}
		tot=k;
		bfs(temp);
		
		if(ans==inf) printf("Case %d: Impossible\n",t++);
		else printf("Case %d: %d\n",t++,ans);


	}

	return 0;
}


void bfs(node s){

	int i,j,k,l,no;
	node temp,temp1; 

	memset(col,0,sizeof(col));

	col[s.no][s.x][s.y]=1;

	q.push(s);

	while(!q.empty()){

		temp=q.front(); q.pop();

		if(temp.no==tot){
			if(ans>temp.cost) ans=temp.cost;
			continue;
		}

		i=temp.x; j=temp.y;		

		//left>>>>>>>>>

		k=i; l=j-1;

		if(l>0){
			
			if(grid[k][l]!='#'&&col[temp.no][k][l]==0){
				col[temp.no][k][l]=1;
				if(isalpha(grid[k][l])){
					if(grid[k][l]-'A'+1==temp.no+1){
						temp1.no=temp.no+1;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
					else if(grid[k][l]-'A'+1<temp.no+1){
						temp1.no=temp.no;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}				
				}
				else{
					temp1.no=temp.no;
					col[temp1.no][k][l]=1;
					temp1.cost=temp.cost+1;
					temp1.x=k; temp1.y=l;
					q.push(temp1);
					
				}
				
			}
		}

		//right>>>>>>>>>

		k=i; l=j+1;

		if(l<=n){
			
			if(grid[k][l]!='#'&&col[temp.no][k][l]==0){
				col[temp.no][k][l]=1;
				if(isalpha(grid[k][l])){
					if(grid[k][l]-'A'+1==temp.no+1){
						temp1.no=temp.no+1;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
					else if(grid[k][l]-'A'+1<temp.no+1){
						temp1.no=temp.no;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}				
				}
				else{
					temp1.no=temp.no;
					col[temp1.no][k][l]=1;
					temp1.cost=temp.cost+1;
					temp1.x=k; temp1.y=l;
					q.push(temp1);
					
				}
				
			}
		}



		//up>>>>>>>>>>>>

		
		k=i-1; l=j;

		if(k>0){
			
			if(grid[k][l]!='#'&&col[temp.no][k][l]==0){
				col[temp.no][k][l]=1;
				if(isalpha(grid[k][l])){
					if(grid[k][l]-'A'+1==temp.no+1){
						temp1.no=temp.no+1;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
					else if(grid[k][l]-'A'+1<temp.no+1){
						temp1.no=temp.no;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}				
				}
				else{
					temp1.no=temp.no;
					col[temp1.no][k][l]=1;
					temp1.cost=temp.cost+1;
					temp1.x=k; temp1.y=l;
					q.push(temp1);
					
				}
				
			}
		}


		//down>>>>>>>>>>>

		
		k=i+1; l=j;

		if(k<=n){
			
			if(grid[k][l]!='#'&&col[temp.no][k][l]==0){
				col[temp.no][k][l]=1;
				if(isalpha(grid[k][l])){
					if(grid[k][l]-'A'+1==temp.no+1){
						temp1.no=temp.no+1;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
					else if(grid[k][l]-'A'+1<temp.no+1){
						temp1.no=temp.no;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}				
				}
				else{
					temp1.no=temp.no;
					col[temp1.no][k][l]=1;
					temp1.cost=temp.cost+1;
					temp1.x=k; temp1.y=l;
					q.push(temp1);
					
				}
				
			}
		}



	}

	



}