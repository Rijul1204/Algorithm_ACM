#include<stdio.h>
#include<queue>
using namespace std;

#define inf  494967296
#define ii  int
//1073741823

queue<int>q;

ii mat[1000][1000],d[10000];
int pre[1000][1000],par[1000];

void set(int n);
void print(int i,int j);
void floyd(int n);
void bfs(int s,int n);
void print1(int i);



int main(){
	
	int i,j,k,l,test,n,m,t=1;
	
	//freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)&&n){
		
		set(n);
		
		for(i=1;i<=n;i++){
			scanf("%d",&m);
			for(j=1;j<=m;j++){
				scanf("%d %d",&k,&l);
				mat[i][k]=l;
			}
		}
		
		//floyd(n);

	    			
		
		scanf("%d %d",&i,&j);
		bfs(i,n);
		
		printf("Case %d: Path = ",t++);
		print1(j);
		//if(i!=j) print(i,j);
		//else printf("%d",i);
		printf("; %lld second delay\n",d[j]);
		
		
	}
	
	return 0;
	
}

void set(int n){
	
	for(int i=1;i<=n;i++){
         par[i]=i;
		for(int j=1;j<=n;j++){
			mat[i][j]=inf;
			//if(i==j) mat[i][j]=0;
			d[i]=inf;
			pre[i][j]=i;
		}
	}
	
}

void bfs(int s,int n){

	d[s]=0;
	q.push(s);

	while(!q.empty()){
		int temp=q.front(); q.pop();
		for(int i=1;i<=n;i++){
			if(mat[temp][i]!=inf){
				if(d[i]>d[temp]+mat[temp][i]){
					d[i]=d[temp]+mat[temp][i];
					par[i]=temp;
					q.push(i);
				}
			}
		}
	}

}

void print1(int n){
	if(par[n]==n){
		printf("%d",n);
		return ;
	}
	else print1(par[n]);
	printf(" %d",n);
}

	

void floyd(int n){
	
	int i,j,k,l;
	
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(mat[i][j]>mat[i][k]+mat[k][j]){
					mat[i][j]=mat[i][k]+mat[k][j];
					pre[i][j]=k;
				}
			}
		}
	}
}



void print(int i,int j){

	if(pre[i][j]==i){
		printf("%d %d",i,j);
		return;
	}
	print(i,pre[i][j]);
	printf(" %d",j);

}
