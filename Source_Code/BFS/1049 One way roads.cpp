#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

#define maxm 160
#define inf 1<<28

struct node{
	int no;
	int cost;
	int pre;
};

queue<node>q;
vector<int>v[maxm];
int mat[maxm][maxm],n;

int bfs(int s);
int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=0;i<=n+10;i++) v[i].clear();

		for(i=1;i<=n;i++){
			scanf("%d %d %d",&k,&l,&j);
			v[k].push_back(l);
			v[l].push_back(k);
			mat[k][l]=0; mat[l][k]=j;
		}

		printf("Case %d: %d\n",t++,bfs(1));

	}


	return 0;
}


int bfs(int s){

	int i,j,k,l,ret;

	ret=inf;
	node temp,temp1;

	j=v[s][0];
	temp.cost=mat[s][j];
	temp.no=j;
	temp.pre=1;
	q.push(temp);

	while(!q.empty()){
		
		temp=q.front(); q.pop();

		if(temp.no==s){
			ret=mini(ret,temp.cost);
			break;
		}

		i=temp.no;
		
		j=v[i][0];

		if(j!=temp.pre){
			temp1.no=j; temp1.pre=i; temp1.cost=temp.cost+mat[i][j];
			q.push(temp1);
			continue;
		}

		j=v[i][1];

		
		if(j!=temp.pre){
			temp1.no=j; temp1.pre=i; temp1.cost=temp.cost+mat[i][j];
			q.push(temp1);
			continue;
		}	

	}

	while(!q.empty()) q.pop();

	j=v[s][1];
	temp.cost=mat[s][j];
	temp.no=j;
	temp.pre=1;
	q.push(temp);

	while(!q.empty()){
		
		temp=q.front(); q.pop();

		if(temp.no==s){
			ret=mini(ret,temp.cost);
			break;
		}

		i=temp.no;
		
		j=v[i][0];

		if(j!=temp.pre){
			temp1.no=j; temp1.pre=i; temp1.cost=temp.cost+mat[i][j];
			q.push(temp1);
			continue;
		}

		j=v[i][1];

		
		if(j!=temp.pre){
			temp1.no=j; temp1.pre=i; temp1.cost=temp.cost+mat[i][j];
			q.push(temp1);
			continue;
		}	

	}

	return ret;

}