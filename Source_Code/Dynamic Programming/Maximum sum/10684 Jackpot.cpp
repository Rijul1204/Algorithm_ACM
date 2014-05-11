#include<stdio.h>

int a[20000];

int main(){

	int i,j,k,l,n,sum,max;
	
	

	while(scanf("%d",&n)==1){
		if(!n) break;

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		sum=a[0];
		
		max=0;
		
		if(sum<0) sum=0;

		for(i=1;i<n;i++){
			sum+=a[i];
			//if(sum<a[i]) sum=a[i];
			if(sum<0) sum=0;
			if(sum>max) max=sum;
		}

		if(max!=0) printf("The maximum winning streak is %d.\n",max);
		else printf("Losing streak.\n");

	}

	return 0;

}



