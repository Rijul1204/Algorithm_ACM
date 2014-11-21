#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

#define maxm 20
vector<int>v[maxm];
int mat[maxm][maxm],pre[maxm];
int flag,col[maxm],n,m;
void dfs(int s,int par,int lev);
void print(int s);

int main(){
	
	int i,j,k,l;
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(scanf("%d %d",&n,&m)==2){
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&mat[i][j]);
			}
		}
		
		memset(col,0,sizeof(col));		
		
		flag=0;
		
		dfs(1,1,0);
		
		if(!flag) printf("no walk of length %d\n",m);
		if(scanf("%d",&n)==1){
			printf("\n");
		}
		else break;
		
	}

return 0;

}

void print(int s){
	
	if(pre[s]==s){
		printf("%d",s);
		return ;
	}	
	print(pre[s]);
	printf(",%d",s);
}

void dfs(int s,int par,int lev){
	
	if(col[s]) return ;
	
	col[s]=1;
	pre[s]=par;
		
	if(lev==m){
	//	printf("%d %d\n",s,lev);
		flag=1;
		printf("(");
		print(s);
		printf(")\n");
		return ;
	}
	
	int i,j;
	
	for(i=1;i<=n;i++){
		if(mat[s][i]==1&&col[i]==0){
			dfs(i,s,lev+1);
			col[i]=0;			
		}
		
	}
	
}
