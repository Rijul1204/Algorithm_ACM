#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

#define maxm 160

struct node{
	int no;
	int state;
	int pre;
};

vector<int>v[maxm];
int col[maxm][10],n,m,state[maxm],one,two;

queue<node>q;

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
void bfs(int s,int st);

int main(){

	int i,j,k,l,test,t=1;
	
	//freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		for(i=0;i<=n+2;i++){
			v[i].clear();
		}

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
			v[l].push_back(k);
		}

		bfs(1,1);

		k=0;
		for(i=1;i<=n;i++){
			if(col[i][1]==1) k++;
		}

		int maxi=k;		

		
		printf("Case %d: %d\n",t++,k);

	}
	
	return 0;

}

void bfs(int s,int st){

	int i,j,k,l;
	node temp,temp1;
	
	memset(col,0,sizeof(col));
	memset(state,0,sizeof(state));

	temp.no=s; temp.state=st; temp.pre=-1;
	q.push(temp);


	while(!q.empty()){

		temp=q.front(); q.pop();

		i=temp.no; k=temp.state;
		k=!k;

		for(j=0;j<v[i].size();j++){
			l=v[i][j];
			if(l==temp.pre) continue;
			if(col[l][k]==0){
				col[l][k]=1;
				temp1.no=l; temp1.state=k;
				q.push(temp1);
			}
		}

	}



}