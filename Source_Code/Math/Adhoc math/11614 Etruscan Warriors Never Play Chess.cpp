#include<stdio.h>
#include<math.h>


int main(){

	int i,j,k,l,n,test;

	double temp;

    scanf("%d",&test);

	while(test--){

		double c;

		scanf("%lf",&c);
		c++;

		k=8*c;
		temp=k;

		temp=sqrt(temp);
		temp-=1.0;
		temp/=2.0;
		
		n=floor(temp);

		printf("%d\n",n);

	}

	return 0;


}