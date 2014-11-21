#include<stdio.h>
#include<math.h>

#define inf 1<<28

int mat[110][110],x[110],y[110];
double matd[110][110];

int dist(int x,int y,int x1,int y1){
	int i,j,k,l;
	i=x-x1;
	i*=i;
	j=y-y1;
	j*=j;
	k=i+j;
	return k;
}

int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}


int main(){

	int i,j,k,l,test,n,t=1;

	freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=1;i<=n;i++){
			scanf("%d %d",&x[i],&y[i]);
		}

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				mat[i][j]=dist(x[i],y[i],x[j],y[j]);
				//mat[i][j]=sqrt(mat[i][j]);
				matd[i][j]=mat[i][j];
				matd[i][j]=sqrt(matd[i][j]);
				if(mat[i][j]>100) matd[i][j]=inf;
				
			}
		}


	
		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					//mat[i][j]=mini(mat[i][j],mat[i][k]+mat[k][j]);
					if(matd[i][j]>matd[i][k]+matd[k][j]){
						matd[i][j]=matd[i][k]+matd[k][j];
					}
				}
			}
		}
		double ret=0;

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
				//if(mat[i][j]==inf) printf("%3d ",-1);
			//	else printf("%.2lf ",matd[i][j]);
				//ret=maxi(ret,mat[i][j]);
				if(matd[i][j]>ret) ret=matd[i][j];
			}
			//9printf("\n");
		}
		
		printf("Case #%d:\n",t++);
		
		if(ret<inf){
			printf("%.4lf\n",ret);
			
		}

		else{
			printf("Send Kurdy\n");	 
		}
		printf("\n");



	}


	return 0;
}