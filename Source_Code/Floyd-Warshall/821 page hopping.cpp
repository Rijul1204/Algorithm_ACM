#include<stdio.h>

#define inf 1<<22

int mat[200][200],flag[200],count1;

void set(int n);
void floyd(int n);

int main(){

	int i,j,k,l,a,b,t=1;

	while(1){
		scanf("%d %d",&a,&b);
		if(!a&&!b) break;
		set(110);
		flag[a]=flag[b]=1;
		mat[a][b]=1;
		while(1){
			scanf("%d %d",&a,&b);
			if(!a&&!b) break;
			mat[a][b]=1;
			flag[a]=flag[b]=1;
		}
		floyd(110);
		for(i=0;i<=110;i++){
			if(flag[i]) count1++;
		}
		int dis=0;
		for(i=1;i<=105;i++){
			if(!flag[i]) continue;
			for(j=1;j<=105;j++){
				if(!flag[j]) continue;
				if(i==j) continue;
				dis+=mat[i][j];
			}
		}
		count1*=(count1-1);
		double res;
		res=(double)((double) dis/(double) count1);
		res+=.000000001;
		printf("Case %d: average length between pages = %.3lf clicks\n",t++,res);

	}


	return 0;
}

void set(int n){

	count1=0;
	for(int i=0;i<=n;i++){
		flag[i]=0;
		for(int j=0;j<=n;j++){
			mat[i][j]=inf;
		}
	}
}

void floyd(int n){

	int i,j,k;

	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(mat[i][j]>mat[i][k]+mat[k][j]){
					mat[i][j]=mat[i][k]+mat[k][j];
				}
			}
		}
	}
}


