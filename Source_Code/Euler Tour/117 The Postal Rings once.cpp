#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;

#define inf 12345678

int mat[100][100],deg[100];

void floyd(int n);

int main(){

	int i,j,k,l,sum,flag;
	char s[1000];
	//freopen("in.txt","r",stdin);

	while(gets(s)){
		flag=0;
		if(strcmp(s,"deadend")==0) break;
		for(i=0;i<=30;i++){
			deg[i]=0;
			for(j=0;j<=30;j++){
				mat[i][j]=inf;
			}
		}
		sum=0;

		l=strlen(s);
		i=s[0]-'a';
		j=s[l-1]-'a';
		mat[i][j]=mat[j][i]=l;
		sum+=l;
		deg[i]++;
		deg[j]++;

		while(gets(s)){
			flag=1;
			if(strcmp(s,"deadend")==0) break;
			l=strlen(s);
			i=s[0]-'a';
			j=s[l-1]-'a';
			mat[i][j]=mat[j][i]=l;
			sum+=l;
			deg[i]++;
			deg[j]++;
		}
		k=0; int a[100];
		for(i=0;i<=30;i++){
			if(deg[i]>0&&deg[i]%2==1){
				a[k++]=i;
			}
		}
		floyd(28);
		if(k==0) printf("%d\n",sum);
		else printf("%d\n",sum+mat[a[0]][a[1]]);

	}

	if(!flag) printf("0\n");


	return 0;
}

void floyd(int n){

	for(int k=0;k<=n;k++){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				if(mat[i][j]>mat[i][k]+mat[k][j]){
					mat[i][j]=mat[i][k]+mat[k][j];
				}
			}
		}
	}
}



