#include<stdio.h>
#include<string.h>

#define maxm 500

int mat[maxm][maxm],ans,vis[maxm][maxm];

int main(){

	int i,j,k,l,t=1,test,n;
	
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&mat[i][j]);
			}
		}

		memset(vis,0,sizeof(vis));
		
		int flag=1;
		ans=n*n;
		ans-=n;

		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++){
				if(i==k) continue;
				for(j=1;j<=n;j++){
					if(i==j||j==k) continue;
					if(mat[i][j]==(mat[i][k]+mat[k][j])&&!vis[i][j]){
						ans--; 
						vis[i][j]=1;
					}
					if(mat[i][j]>(mat[i][k]+mat[k][j])){
						flag=0;
					}
					if(!flag) break;
				}
				if(!flag) break;
			}
			if(!flag) break;
		}

		if(!flag) printf("Case %d: impossible\n",t++);
		else printf("Case %d: %d\n",t++,ans);


	}

	return 0;
}