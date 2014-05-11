#include<stdio.h>
#include<string.h>

#define ii long long int

int n;

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		if(!n) break;

		ii ans;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(i==1){
				ans=k;
			}
			else ans=ans^k;
		}
		if(ans){
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}

	}

	return 0;
}