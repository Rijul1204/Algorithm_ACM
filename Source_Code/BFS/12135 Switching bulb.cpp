#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

#define maxm 45
#define maxl 1<<17

int on(int n,int k){
	return n|(1<<k);
}
int off(int n,int k){
	return n-(n&1<<k);
}

bool check(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}

vector<int>v[maxm];
int n,m;
int state[maxl];

void bfs(int s);
queue<int>q;

int main(){

    int i,j,k,l,test,t=1,q,j1;
    
  //  freopen("in.txt","r",stdin);
    scanf("%d",&test);
    
    while(test--){
		
		scanf("%d %d",&n,&m);
		for(i=0;i<=m;i++) v[i].clear();
		
		
		for(i=1;i<=m;i++){
			scanf("%d",&k);
			for(j=1;j<=k;j++){
				scanf("%d",&l);
				v[i].push_back(l);
			}
		}
		
		
		memset(state,-1,sizeof(state));
				
		char s[100];
		bfs(0);
		
		scanf("%d",&q);
		printf("Case %d:\n",t++);		
		for(i=1;i<=q;i++){
			l=0;
			scanf("%s",s);
			j1=strlen(s);
			j1--;		
			for(j=0;s[j];j++){
				if(s[j]=='1') l=on(l,j1);
				j1--;
			}
		//	printf("%d\n",l);
			printf("%d\n",state[l]);
		}
		printf("\n");		
				
	}    
	 
   return 0;
}

void bfs(int s){
	
	int i,j,k,l,i1;
	
	q.push(s);
	
	state[s]=0;
	
	while(!q.empty()){
		
		k=q.front(); q.pop();
		
		//printf("%d %d\n",k,state[k]);
		
		for(i=1;i<=m;i++){
			l=k;
			for(j=0;j<v[i].size();j++){
				i1=v[i][j];
				if(check(l,i1)) l=off(l,i1);
				else l=on(l,i1);
			}
			if(state[l]==-1){
				state[l]=state[k]+1;
				q.push(l);
			}		
		}
		
	}	

}
