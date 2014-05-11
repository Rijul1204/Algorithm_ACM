#include<stdio.h>

#define inf 715827882;

int mat[500][500];

void set(int n);
void minimax(int n);
int min(int a,int b);
int max(int a,int b);

int main(){

	int i,c,s,q,c1,c2,w,t=1,blank=0;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d %d",&c,&s,&q)==3&&c&&s&&q){

		set(c);
		
		for(i=1;i<=s;i++){
			scanf("%d %d %d",&c1,&c2,&w);
			mat[c1][c2]=mat[c2][c1]=w;
			if(w>715827882){
				while(1){
					printf("%d",w);
				}
			}
		}
		minimax(c);

		if(blank) printf("\n");
		blank=1;

		printf("Case #%d\n",t++);

		for(i=1;i<=q;i++){
			scanf("%d %d",&c1,&c2);
			if(mat[c1][c2]==715827882){
				printf("no path\n");
			}
			else printf("%d\n",mat[c1][c2]);
		}

	}

	return 0;
}

void set(int n){

	int i,j;

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			mat[i][j]=inf;
		}
	}

}

void minimax(int n){

	int i,j,k;

	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				mat[i][j]=min(mat[i][j],max(mat[i][k],mat[k][j]));
			}
		}
	}

}

int min(int a,int b){
	if(a<b) return a;
	else return b;
}

int max(int a,int b){
	if(a>b) return a;
	else return b;
}




