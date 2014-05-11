#include<stdio.h>
#include<algorithm>
using namespace std;

#define maxm 21000

int loo[maxm],knight[maxm];

int main(){

	int i,j,n,m,sum;

//	freopen("in.txt","r",stdin);

	while(1){

		scanf("%d %d",&n,&m);

		if(!m&&!n)break;

		for(i=0;i<n;i++){
			scanf("%d",&loo[i]);
		}
		sort(loo,loo+n);

		for(i=0;i<m;i++){
			scanf("%d",&knight[i]);
		}
		sort(knight,knight+m);

		if(m<n){
			printf("Loowater is doomed!\n");
			continue;
		}

		sum=0;
		for(i=0,j=0;i<m&&j<n;i++){
			if(loo[j]<=knight[i]){
				j++;
				sum+=knight[i];
			}
		}
		if(j==n) printf("%d\n",sum);
		else printf("Loowater is doomed!\n");

	}


	return 0;
}






