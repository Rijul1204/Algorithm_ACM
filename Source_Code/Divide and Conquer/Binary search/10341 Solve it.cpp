#include<stdio.h>
#include<math.h>

#define eps 1e-9

int p,q,r,s,t,u;

double f(double x){
	return (p*(exp(-x))+q*(sin(x))+r*(cos(x))+s*(tan(x))+t*x*x+u);
}
double root(int beg,int end);

int main(){

	int i,j,k,l;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6){

		if(f(0)*f(1)>0) printf("No solution\n");
		else printf("%.4lf\n",root(0,1));
	}

	return 0;
}

double root(int beg,int end){

	int i,j;

	double hi=end;
	double lo=beg;
	double mid;

	while(lo+eps<hi){
		mid=lo+hi;
		mid/=2.0;
		if(f(mid)*f(lo)<=0){
			hi=mid;			
		}
		else lo=mid;		
	}
	
	mid=lo+hi;
	mid/=2.0;
	return mid+eps;
}
