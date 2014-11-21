#include<stdio.h>
#include<string.h>

#define maxm 510

int mat1[maxm][maxm],mat2[maxm][maxm],cmat1[maxm][maxm],cmat2[maxm][maxm];
int dp[maxm][maxm],r,c;

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
int cal(int i,int j);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&r,&c);

		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				scanf("%d",&mat1[i][j]);
			}
		}		
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				scanf("%d",&mat2[i][j]);
			}
		}

		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				cmat1[i][j]=cmat1[i][j-1]+mat1[i][j];
				cmat2[i][j]=cmat2[i-1][j]+mat2[i][j];
			}
		}

		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",t++,cal(r,c));


	}

	return 0;
}

int cal(int i,int j){
	
	if(i==0||j==0) return 0;

	if(dp[i][j]!=-1) return dp[i][j];

	int ret;

	ret=maxi(cal(i-1,j)+cmat1[i][j],cal(i,j-1)+cmat2[i][j]);
	
	return dp[i][j]=ret;
}