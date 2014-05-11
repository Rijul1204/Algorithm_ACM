#include<stdio.h>

#define inf 1<<25

int mat[500][500];
int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){
	
	int i,j,k,l,c,t=1,n,m,test;	
	
///	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	
	while(test--){
		
		scanf("%d %d",&n,&m);
		
		for(i=0;i<=n;i++){
			for(j=0;j<=n;j++){
				mat[i][j]=inf;
			}
			mat[i][i]=0;
		}
		
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&c);
			mat[k][l]=mini(mat[k][l],c);
			mat[l][k]=mat[k][l];
		}
		
		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					mat[i][j]=mini(mat[i][j],mat[i][k]+mat[k][j]);
				}
			}
		}		
/*		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(mat[i][j]==inf) printf("%2d ",-1);
				else printf("%2d ",mat[i][j]);
			}
			printf("\n");
		}
*/		
		int flag=0,ans=0;
		//max=0;
		int maxi=inf;
		
		for(i=1;i<=n;i++){
			l=0;
			flag=1;
			for(j=2;j<=n;j++){
				if(j<=5){
					if(mat[i][j]!=mat[i][j-1]||mat[i][j]==inf){
						flag=0;
						break;
					}
				}
				else if(mat[i][j]==inf){
					flag=0;
					break;
				}
				
			}

			if(flag==1){
				ans=1;
				l=mat[i][1];
				for(j=2;j<=n;j++){
					if(mat[i][j]>l) l=mat[i][j];
				}
				maxi=mini(maxi,l);
			}
			
		}
		
		printf("Map %d: ",t++);
		if(ans) printf("%d\n",maxi);
		else printf("-1\n");
		
	}
	
	return 0;
}