#include<stdio.h>
#include<string.h>

#define maxm 200

int mat[maxm][maxm],n,m;
int a[maxm],b[maxm],a1,b1,part[maxm];

int main(){
	
	int i,j,k,l,test,t=1;
	
	//freopen("in.txt","r",stdin);
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d %d",&n,&m);
		memset(mat,0,sizeof(mat));
		memset(part,0,sizeof(part));
		
		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			mat[k][l]=mat[l][k]=1;					
		}
		
		k=0; l=0;
		a[k++]=1;
		
		for(i=2;i<=n;i++){
			a1=0; b1=0;
			for(j=0;j<k;j++){
				if(mat[i][a[j]]){
					a1++;				
				}
			}
			for(j=0;j<l;j++){
				if(mat[i][b[j]]){
					b1++;				
				}
			}
			if(a1<b1){
				a[k++]=i;				
			}
			else b[l++]=i;
		}
		
		if(n<=1){
			printf("Case #%d: %d\n",t++,0);
			continue;
		}
		
		printf("Case #%d: %d\n",t++,k);
		for(i=0;i<k;i++){
			if(i) printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");

				
		
	}	
	
	return 0;
}
