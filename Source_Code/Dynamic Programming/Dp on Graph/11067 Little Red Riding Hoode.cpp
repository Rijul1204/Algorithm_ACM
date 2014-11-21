#include<stdio.h>

#define ii long long int

int mat[1000][1000];
ii dp[1000][1000];
int vis[1000][1000];
int w,h;

ii run(int i,int j);

int main(){

	int i,j,k,l,n;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&w,&h)==2){

		if(!w&&!h)  break;
		
		for(i=0;i<=w;i++){
			for(j=0;j<=h;j++){
				mat[i][j]=0;
				dp[i][j]=0;
				vis[i][j]=0;
			}
		}

		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d %d",&k,&l);
			mat[k][l]=1;
		}
		
		ii ans;

		ans=run(0,0);
		
		if(ans==0) printf("There is no path.\n");
		else if(ans==1) printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
		else printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n",ans);


	}

	return 0;
}

ii run(int i,int j){

	if(i>w||j>h) return 0;
	if(i==w&&j==h) return 1;
	if(mat[i][j]==1) return 0;
	if(vis[i][j]==1) return dp[i][j];

	vis[i][j]=1;

	dp[i][j]=run(i+1,j)+run(i,j+1);

	return dp[i][j];

}