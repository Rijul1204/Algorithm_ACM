#include<stdio.h>
#include<math.h>

int main(){

	int i,j,test;
	double n,k,p,res,l;
	
	scanf("%d",&test);

	while(test--){

		scanf("%lf %lf %lf",&n,&p,&k);

		res=0;
		l=k;

		while(1){

			res+=(p*pow((1-p),l-1));
			l+=n;
			if(p*pow((1-p),l)<.000000001) break;

		}

		printf("%.4lf\n",res);



	}



	return 0;
}


