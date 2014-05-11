#include<stdio.h>
#define inf 15000

typedef struct{
	int mark;
	char name[50];
}player;
player players[50];

int a[50][50];

void set(int n);

int main(){

	int i,j,k,w,n,m,min,sum,node,test=1;
	char nam[30],help[5];

	while(1){
		scanf("%d %d",&n,&m);
		if(n==0) break;

		set(n);

		for(i=1;i<=n;i++){
		   players[i].mark=i;
		   scanf("%s",players[i].name);
		   gets(help);
		}
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&j,&k,&w);
			a[j][k]=a[k][j]=w;
		}

		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(a[i][j]>a[i][k]+a[k][j]){
						a[i][j]=a[i][k]+a[k][j];
					}
				}
			}
		}

		for(i=1;i<=n;i++){
			sum=0;
			for(j=1;j<=n;j++){
				sum+=a[i][j];
			}
			if(i==1) {
				min=sum;
				node=1;
			}
			else {
				if(sum<min){
					min=sum;
					node=i;
				}
			}
		}
		printf("Case #%d : %s\n",test++,players[node].name);

	}

	return 0;
}

void set(int n){

	int i,j;

	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			a[i][j]=inf;
			if(i==j) a[i][j]=0;
		}
	}

}






