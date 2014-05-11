#include<stdio.h>
#include<queue>
using namespace std;

struct node{
	int x;
	int y;
	int cost;
};

node nodes[1000];
int dis[200][200],mat[200][200];

bool operator <(const node &a,const node &b){
	return a.cost<b.cost;
}

priority_queue<node>q;

int maxi,n,c;

void bfs(node s);


int main(){

	int i,j,k,l,test,bl=0;
	
	//freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&c);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dis[i][j]=-1;
                 scanf("%d",&mat[i][j]);   		
			}
		}
		maxi=-1;
		node s;
		s.cost=mat[1][1];
		s.x=1;
		s.y=1;
		bfs(s);
        
		if(bl) printf("\n");
		bl=1;
		printf("%d\n",maxi);


	}


	return 0;
}

void bfs(node s){

	int i,j,k,l,flag;
	node temp,temp1;

	dis[s.x][s.y]=s.cost;
	q.push(s);

	while(!q.empty()){
		
		temp=q.top(); q.pop();
		i=temp.x;
		j=temp.y;
		flag=0;
		
		for(l=1;l<=c;l++){
			if(l+i>n) break;
			k=l+i;
			if(mat[k][j]>mat[i][j]){
				if(dis[k][j]<dis[i][j]+mat[k][j]){
					flag=1;
                    dis[k][j]=dis[i][j]+mat[k][j];
					temp1.x=k; temp1.y=j; temp1.cost=dis[k][j];
					q.push(temp1);
				}
			}
		}
		for(l=1;l<=c;l++){
			k=i-l;
			if(k<1) break;
			if(mat[k][j]>mat[i][j]){
				if(dis[k][j]<dis[i][j]+mat[k][j]){
					flag=1;
                    dis[k][j]=dis[i][j]+mat[k][j];
					temp1.x=k; temp1.y=j; temp1.cost=dis[k][j];
					q.push(temp1);
				}
			}
		}
		for(l=1;l<=c;l++){
			k=j+l;
			if(k>n) break;
			if(mat[i][k]>mat[i][j]){
				if(dis[i][k]<dis[i][j]+mat[i][k]){
					flag=1;
                    dis[i][k]=dis[i][j]+mat[i][k];
					temp1.x=i; temp1.y=k; temp1.cost=dis[i][k];
					q.push(temp1);
				}
			}
		}
		for(l=1;l<=c;l++){
			k=j-l;
			if(k<1) break;
			if(mat[i][k]>mat[i][j]){
				if(dis[i][k]<dis[i][j]+mat[i][k]){
					flag=1;
                    dis[i][k]=dis[i][j]+mat[i][k];
					temp1.x=i; temp1.y=k; temp1.cost=dis[i][k];
					q.push(temp1);
				}
			}
		}
		
		if(flag==0){
			if(temp.cost>maxi) maxi=temp.cost;
		}

	}
}
