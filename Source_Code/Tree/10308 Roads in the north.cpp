#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>
#include<stdio.h>
using namespace std;

#define maxm 10100
#define inf 1<<28

struct node{
	int no;
	int cost;
};

node ret;

bool operator<(const node &a,const node &b){
	return a.cost>b.cost;
}

vector<node>v[maxm+20];
priority_queue<node>q;
int n,flag[maxm+20];
int dist[maxm+20];
char s[maxm];

node dij(node s);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	//scanf("%d",&test);
	
	while(gets(s)){
		
		for(i=0;i<=maxm-5;i++){v[i].clear();}
		
		memset(flag,0,sizeof(flag));
		node temp;

		if(!s[0]){
			printf("0\n");
			gets(s);
			continue;
		}
		sscanf(s,"%d %d %d",&k,&l,&j);
		flag[k]=flag[l]=1;
		temp.cost=j; temp.no=k;
		v[l].push_back(temp);
		temp.no=l;
		v[k].push_back(temp);	
		
		while(gets(s)){
			if(!s[0]) break;
			sscanf(s,"%d %d %d",&k,&l,&j);
			flag[k]=flag[l]=1;
			temp.cost=j; temp.no=k;
			v[l].push_back(temp);
			temp.no=l;
			v[k].push_back(temp);
		}
		
		for(i=0;i<=maxm-2;i++) if(flag[i]) break;
	
		temp.no=i;
		temp.cost=0; 
		temp=dij(temp);
		temp.cost=0;
		temp=dij(temp);

		printf("%d\n",temp.cost);

	}


	return 0;
}

node dij(node s){

	int i,j,k,l;
	node temp,temp1,t1;

	for(i=0;i<=maxm;i++) dist[i]=inf;
	dist[s.no]=0;
	
	q.push(s);

	while(!q.empty()){

		temp=q.top(); q.pop();
		i=temp.no;

		for(j=0;j<v[i].size();j++){
			t1=v[i][j];
			k=t1.no;
			if(dist[k]>temp.cost+t1.cost){
				dist[k]=temp.cost+t1.cost;
				temp1.cost=temp.cost+t1.cost;
				temp1.no=t1.no;
				q.push(temp1);
			}
		}
	}

	ret.cost=0;
	ret.no=s.no;

	for(i=0;i<maxm+2;i++){
		if(dist[i]>ret.cost&&dist[i]!=inf){
			ret.cost=dist[i]; ret.no=i;
		}
	}

	return ret;
	
	
}


