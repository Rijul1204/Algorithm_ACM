#include<stdio.h>
#include<math.h>

int main(){

	int i,j,t,test,a[10],start,count,num;

	scanf("%d",&test);

	for(t=1;t<=test;t++){
		scanf("%d",&num);
        a[0]=a[1]=a[2]=a[3]=0; 
		start=sqrt(num);
        count=0;
		for(i=start;i>=1;i--){
			if(num%i==0){
				a[count++]=i;
				a[count++]=num/i;
				if(a[count-1]==a[count-2]) count-=2;
			}
			if(count==4) break;

		}

		printf("Case #%d: %d = %d * %d = %d * %d\n",t,num,a[0],a[1],a[2],a[3]);

	}

	return 0;

}

			
				




