#include<stdio.h>
#include<algorithm>
using namespace std;

#define maxm 10100

int b[maxm],s[maxm];

int main(){

	int i,j,k,l,t=1,n,m;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){

		if(!n&&!m) break;

		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
		}

		for(i=0;i<m;i++){
			scanf("%d",&s[i]);
		}

		if(n<=m){
			printf("Case %d: 0\n",t++);
			continue;
		}

		sort(b,b+n);

		printf("Case %d: %d %d\n",t++,n-m,b[0]);

	}

	return 0;
}