#include<stdio.h>
#include<string.h>

#define maxm 40
//#define ii long long int
#define ii int


ii mat[maxm][maxm];
int n,tot;
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){
	
	int i,j,k,l,test,t=0;
	
//	freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1){
		
		memset(mat,0,sizeof(mat));
		tot=0;
		
		for(i=1;i<=n;i++){
			scanf("%d %d",&j,&k);
			mat[j][k]=1;
			tot=maxi(tot,maxi(j,k));	
		}
		
		for(k=0;k<=tot;k++){
			for(i=0;i<=tot;i++){
				for(j=0;j<=tot;j++){
					mat[i][j]+=(mat[i][k]*mat[k][j]);
				}
			}
		}

		for(k=0;k<=tot;k++){
			for(i=0;i<=tot;i++){
				if(mat[i][k]==0) continue;
				for(j=0;j<=tot;j++){
					if(mat[i][j]==0||mat[k][j]==0) continue;
					if(mat[k][k]>0||mat[i][i]>0||mat[j][j]>0){
						mat[i][j]=-1;
					}
					else if(mat[i][k]==-1||mat[k][j]==-1){
						mat[i][j]=-1;
					}
				}
			}
		}
		
	
		printf("matrix for city %d\n",t++);
	
		for(i=0;i<=tot;i++){
			for(j=0;j<=tot;j++){
				if(j) printf(" ");
				printf("%d",mat[i][j]);
			}
			printf("\n");
		}		
		
		
	}
	
	return 0;
}