#include<stdio.h>


int main(){

	int i,j,n,test,max,temp,lis[3000],array[3000],lds[3000];

	
//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		if(n==0){
			printf("0\n");
			continue;
		}
        lis[0]=0;
		lds[0]=0;
		for(i=0;i<n;i++){
			lis[i]=1;
			lds[i]=1;
			scanf("%d",&array[i]);
		}

		for(i=n-1;i>=0;i--){
			for(j=i-1;j>=0;j--){
				if(array[j]<array[i]){
					if(lis[i]+1>lis[j]){
						lis[j]=lis[i]+1;
						
					}
				}
				if(array[j]>array[i]){
					if(lds[i]+1>lds[j]){
						lds[j]=lds[i]+1;
					}
				}

			}
		}

		max=lis[0]+lds[0]-1;
		              
		for(i=1;i<n;i++){
			temp=lis[i]+lds[i]-1;
			if(temp>max){
				max=lis[i]+lds[i]-1;
			}	
		}

		printf("%d\n",max);

	}

	return 0;

	
}


					




