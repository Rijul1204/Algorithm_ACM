#include<stdio.h>
#include<string.h>

#define maxm 110

int a[maxm],map[maxm];

int main(){

	int i,j,k,l,test,t=1,n;
	
//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d",&n);
		int temp;

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			map[a[i]]=i;
		}

		int ans=0;
		for(i=1;i<=n;i++){
			k=map[i];
			if(k==i) continue;
			a[k]=a[i];
			map[a[i]]=map[i];		
			a[i]=i;
			ans++;
		}

		printf("Case %d: %d\n",t++,ans);


	}

	return 0;
}