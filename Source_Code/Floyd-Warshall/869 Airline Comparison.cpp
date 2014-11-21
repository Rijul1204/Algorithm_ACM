#include<stdio.h>
#include<map>
using namespace std;

map<char,int>my;
int mat[2000][2000],mat1[2000][2000];

void floyd(int n);

int main(){

	int i,j,k,l,n,m,flag,test;
	bool blank=0;
	char s[1000],s1[100];

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);;

	while(test--){

		for(i=1;i<=200;i++){
			for(j=1;j<=200;j++){
				mat[i][j]=0;
			}
		}

		my.clear();

		scanf("%d",&m);
		n=1;
		for(i=1;i<=m;i++){
			scanf("%s %s",s,s1);
			if(!my[s[0]]){
				my[s[0]]=n++;
			}
			if(!my[s1[0]]){
				my[s1[0]]=n++;
			}
			mat[my[s[0]]][my[s1[0]]]=1;
		
		}
		flag=0;
		scanf("%d",&m);
		for(i=1;i<=m;i++){
			scanf("%s %s",s,s1);
			if(!my[s[0]]){
				my[s[0]]=n++;
				flag=1;
			}
			if(!my[s1[0]]){
				my[s1[0]]=n++;
				flag=1;
			}
			mat1[my[s[0]]][my[s1[0]]]=1;
		
		}

		if(blank) printf("\n");
		blank=true;

		if(flag){
			printf("NO\n");
			continue;
		}
		floyd(n-1);

		flag=0;
		for(i=1;i<n;i++){
			for(j=1;j<n;j++){
				if(mat[i][j]&&!mat1[i][j]||mat1[i][j]&&!mat[i][j]){
					flag=1;
					break;
				}
			}
			if(flag) break;
		}

		if(flag) printf("NO\n");
		else printf("YES\n");

	}



	return 0;

}


void floyd(int n){

	int i,j,k,l;

	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(mat[i][k]&&mat[k][j]){
					mat[i][j]=1;
				}
				if(mat1[i][k]&&mat1[k][j]){
					mat1[i][j]=1;
				}
			}
		}
	}

}
