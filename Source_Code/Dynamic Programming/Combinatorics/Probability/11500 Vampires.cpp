#include<stdio.h>
#include<math.h>

int main(){

	int i,j,k,l,n;
	double ev1,ev2,at,d,p,q,n1,res,n2;

	while(scanf("%d %d %d %d",&i,&j,&k,&l)==4){

		if(!i&&!j&&!k&&!l) break;

		ev1=i;ev2=j;at=k;d=l;

		
		if(at==3){
				
			n1=ceil(ev1/d);
			n2=ceil(ev2/d);

			res=n1/(n1+n2);
			
			printf("%.1lf\n",res*100.0);


		}
		else{
			
			p=at;
			q=6-at;

			n1=ceil(ev1/d);
			n2=ceil(ev2/d);

			res=(1-pow((q/p),n1))/(1-pow((q/p),n1+n2));

			res*=100.0;

			printf("%.1lf\n",res);


		}

	
	}


	
	return 0;

}