#include<stdio.h>
#include<string.h>

#define maxm 350
#define inf 1<<29

int dp[40][maxm],pre[40][maxm],t1,t2,n;
int a[40][maxm],b[40][maxm],m[maxm],ans[maxm];

int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int cal(int ind,int i,int j);
void print(int ind,int i,int j);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&t1,&t2)==2){
		
		if(!t1&&!t2) break;

		scanf("%d",&n);
		l=0; int l1=0;
		
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			m[i]=k;
			for(j=1;j<=k;j++){
				scanf("%d",&a[i][j]);
			}
			for(j=1;j<=k;j++){
				scanf("%d",&b[i][j]);
			}
		}
	
		memset(dp,-1,sizeof(dp));
	
		printf("%d\n",cal(1,0,0));
		print(1,0,0);
		for(i=1;i<=n;i++){
			if(i!=1) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n\n");
		
	}	

	return 0;
}

void print(int ind,int i,int j){
	
	if(i==t1&&j==t2||ind>n) return ;
	ans[ind]=pre[ind][j];
	print(ind+1,pre[ind][j]+i,j+m[ind]-pre[ind][j]);

}

int cal(int ind,int i,int j){

	if(i==t1&&j==t2) return 0;
	if(i>t1||j>t2) return inf;

	if(dp[ind][j]!=-1) return dp[ind][j];

	int ret=inf,ret1,k,i1,j1;
	k=i+j;
	
	for(i1=0;i1<=m[ind];i1++){
		j1=m[ind]-i1;
		ret1=cal(ind+1,i+i1,j+j1)+a[ind][i1]+b[ind][j1];
		if(ret1<ret){
			ret=ret1;
			pre[ind][j]=i1;
		}
	}
	

	return dp[ind][j]=ret;

}