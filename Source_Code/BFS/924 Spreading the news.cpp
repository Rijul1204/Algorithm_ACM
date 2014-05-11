#include<stdio.h>
#include<queue>
using namespace std;

#define inf 999999

queue<int>q;

int mat[3000][3000],e;
int dis[3000],col[3000],boom,day;


void bfs(int s);
void set();


int main(){
	
	int i,j,k,l,t,n,x,test;

	//freopen("in.txt","r",stdin);
	
	scanf("%d",&e);
	
	for(i=0;i<e;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&x);
			mat[i][x]=1;
		}
	}
	
	scanf("%d",&test);
	
	while(test--){
		set();
		scanf("%d",&n);
		bfs(n);
		if(boom==0)	printf("0\n");
		else printf("%d %d\n",boom,day);
	}

	
	
	return 0;
	
}

void set(){
	
	int i;
	
	for(i=0;i<=e;i++){
		dis[i]=inf;
		col[i]=0;
	}
}


void bfs(int s){
	
	q.push(s);
	col[s]=1;
	dis[s]=0;
    int max=0;
	int i,j,count,temp;
	
	while(!q.empty()){
		
		temp=q.front();
		q.pop();
		
		for(i=0;i<e;i++){
			if(mat[temp][i]==1&&col[i]==0){
				col[i]=1;
				dis[i]=dis[temp]+1;
				if(dis[i]>max) max=dis[i];
				q.push(i);
			}
		}
		
	}
	
	
	boom=0,day=0;
	for(i=1;i<=max;i++){
		count=0;
		for(j=0;j<e;j++){
			if(dis[j]==i){
				count++;
			}
		}
		if(count>boom){
			boom=count;
			day=i;
		}
	}
	
}













