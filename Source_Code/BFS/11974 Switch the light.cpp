#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int on(int n,int k){
	return (n|(1<<k));
}
int off(int n,int k){
	return (n-(1<<k));
}
bool chck(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}

queue<int>q;

int m[200][20];
int d[131072],n,m1,col[131072];

void bfs(int s);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&n,&m1);
		memset(m,0,sizeof(m));

		for(i=1;i<=m1;i++){
			for(j=0;j<n;j++) scanf("%d",&m[i][j]);
		}

		int k=(1<<n)-1;
		
		memset(col,0,sizeof(col));
		bfs(k);

		if(col[0]==0) printf("Case %d: IMPOSSIBLE\n",t++);
		else printf("Case %d: %d\n",t++,d[0]);
	}
	
	return 0;
}

void bfs(int s){

	col[s]=1;

	d[s]=0;
	
	q.push(s);

	int i,j,k,l,num;


	while(!q.empty()){

		num=q.front(); q.pop();
		
		for(i=1;i<=m1;i++){
			k=num;
			for(j=0;j<n;j++){
				if(m[i][j]==1){
					if(chck(k,j)){
						k=off(k,j);											
					}
					else {
						k=on(k,j);		
					}
				}
			}
			if(!col[k]){
				col[k]=1;
				d[k]=d[num]+1;
				q.push(k);
			}
		}
	}

}