#include<stdio.h>
#include<string.h>

#define maxm 110

int a[maxm],b[maxm];

int main(){

	int i,j,k,l,test,t=1,n;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		
		for(i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}

		int ans=0;

		for(i=1;i<=n;i++){
			k=(b[i]-a[i]-1);
			ans^=k;
		}

		if(ans){
			printf("Case %d: white wins\n",t++);
		}
		else{
			printf("Case %d: black wins\n",t++);
		}

	}

	return 0;
}