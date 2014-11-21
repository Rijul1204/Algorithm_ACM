#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

#define ii long long int
#define maxm 510
#define inf 1<<28
#define maxl (1<<17)


struct node{
	int no;
	int cost;
};


bool operator<(const node &a,const node &b){
	return a.cost>b.cost;
}

vector<int>v[maxm];
priority_queue<node>pq;


int on(int n,int k){
	return (n|(1<<k));
}
int off(int n,int k){
	return n-(n&(1<<k));
}
bool check(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}

node dp[17][maxl+10];
bool vis[17][maxl+10];
int mat[maxm][maxm],n,m,s,shop[18],ansn,ansd,d[maxm];

node cal(int ind,int state);
void dij(int s);

int main(){

	int i,j,k,l,test,t=1;

    //printf("hi\n");

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d %d\n",&n,&m,&s);

		for(i=0;i<=n;i++){
			for(j=0;j<=n;j++){
				mat[i][j]=inf;				
			}
			v[i].clear();
			mat[i][i]=0;
		}

		for(i=1;i<=s;i++){
			scanf("%d",&shop[i]);
		}
		
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			v[k].push_back(l);
			mat[k][l]=min(mat[k][l],j);
		}
		
		dij(0);
		for(i=1;i<=s;i++){
			dij(shop[i]);
		}

		memset(vis,0,sizeof(vis));
		node ans=cal(0,0);
		
		if(ans.cost>=inf) printf("Case %d: Impossible\n",t++);
		else printf("Case %d: %d %d\n",t++,ans.no,ans.cost);
		

	}


	return 0;
}

void dij(int s){
	
	int i,j,k,l;
	
	node temp,temp1;
	
	for(i=0;i<=n;i++) d[i]=inf;
	d[s]=0;
	temp.no=s; temp.cost=0;
	pq.push(temp);

	while(!pq.empty()){
		
		temp=pq.top(); pq.pop();
		i=temp.no;
		
		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(d[k]>temp.cost+mat[i][k]){
				d[k]=temp.cost+mat[i][k];
				temp1.no=k; temp1.cost=d[k];
				pq.push(temp1);
			}			
		}			
	}
	
	for(i=0;i<=n;i++){
		mat[s][i]=d[i];
	}
	
}


node cal(int ind,int state){

	if(state==(1<<s)-1){
		node temp;
		temp.cost=mat[shop[ind]][n-1];
		temp.no=s;
		//printf("%d\n",temp.no);
		return temp;
	}

	if(vis[ind][state]) return dp[ind][state];
	vis[ind][state]=1;

	int i,j,k,l;
	node ret,temp;
	
	ret.no=-1; ret.cost=inf;
	l=0;

	for(i=1;i<=s;i++){
		k=state;
		if(!check(state,i-1)){
			k=on(k,i-1);
			temp=cal(i,k);
			if(temp.cost==inf) continue;
			temp.cost+=mat[shop[ind]][shop[i]];
			if(temp.cost<inf){
				if(ret.no<temp.no){
					ret.no=temp.no; ret.cost=temp.cost;
				}
				else if(ret.no==temp.no){
					if(ret.cost>temp.cost) ret.cost=temp.cost;
				}
			}
		}		
		else l++;
	}
	
	//if(!check(state,ind)) l++;

	if(ret.no<l){
		ret.no=l; ret.cost=mat[shop[ind]][n-1];
	}
	else if(ret.no==l){
		if(mat[shop[ind]][n-1]<ret.cost){
			ret.no=l; ret.cost=mat[shop[ind]][n-1];
		}
	}

	return dp[ind][state]=ret;

}
