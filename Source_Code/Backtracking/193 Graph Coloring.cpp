#include<stdio.h>

int mat[200][200],col[200],res[200],ans,max,n;

void set(int n);
void back(int s,int cnt);

int main(){

	int i,j,k,l,m,test;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		set(n);

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			mat[k][l]=mat[l][k]=1;
		}

		back(1,0);

		printf("%d\n",ans);

		bool space=0;

		for(i=1;i<=n;i++){
			if(res[i]){
				if(space) printf(" ");
				space=1;
				printf("%d",i);
			}
		}

		printf("\n");

	}




	return 0;
}

void back(int s,int cnt){

	if(s>n){
		if(cnt>ans){
			ans=cnt;
			for(int i=1;i<=n;i++) res[i]=col[i];
		}
		return ;
	}

	if(cnt+n-s+1<=ans) return;

	int flag=1;
	for(int i=1;i<=n;i++){
		if(mat[s][i]&&col[i]){
			flag=0;
			break;
		}
	}

	if(flag){
		col[s]=1;
		back(s+1,cnt+1);
		col[s]=0;
	}
	back(s+1,cnt);


}

void set(int n){

	int i,j;

	for(i=0;i<=n;i++){
		col[i]=0;
		for(j=0;j<=n;j++){
			mat[i][j]=0;
		}
	}
	ans=0;

}
