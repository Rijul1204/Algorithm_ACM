#include<stdio.h>
#include<string.h>

#define ii long long int


int n,r,c;
int sx,sy,dx,dy,vis[100][100],dir[100][100][10];

ii dp[100][100];
ii run(int x,int y);

int main(){

	int i,j,k,l,test;
	char ch[10];
	
//	freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dp[i][j]=vis[i][j]=0;
				dir[i][j][1]=dir[i][j][2]=0;
			}
		}
	

		scanf("%d %d",&sx,&sy);
		scanf("%d %d",&dx,&dy);
		scanf("%d",&k);
		for(l=1;l<=k;l++){
			scanf("%d %d %s",&i,&j,ch);
			if(ch[0]=='S') dir[i][j-1][1]=1;
			else if(ch[0]=='W') dir[i-1][j][2]=1;
			else if(ch[0]=='N') dir[i][j][1]=1;
			else if(ch[0]=='E') dir[i][j][2]=1;

		}
		printf("%lld\n",run(sx,sy));


	}



	return 0;
}

ii run(int x,int y){
	
	if(x>dx||y>dy) return 0;
	if(x==dx&&y==dy) return 1;
	if(vis[x][y]==1) return dp[x][y];
	vis[x][y]=1;
	ii i,j,k,l;

	if(dir[x][y][2]==0) j=run(x+1,y);
	else j=0;
	if(dir[x][y][1]==0) k=run(x,y+1);
	else k=0;

	return dp[x][y]=j+k;

}