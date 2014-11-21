#include<stdio.h>


int main(){

	int i,j,t,test,n,a[100],high,low;

	scanf("%d",&test);

	for(t=1;t<=test;t++){
		high=0;
		low=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(i==0) continue;
			if(a[i-1]<a[i]) high++;
			else if(a[i-1]>a[i]) low++;
		}

		printf("Case %d: %d %d\n",t,high,low);
	}

	return 0;
}




