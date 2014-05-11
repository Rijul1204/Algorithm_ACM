#include<stdio.h>
#include<math.h>

#define eps 1e-7
const double pi=2*acos(0.0);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--){
		
		int n,d;
		double a,b,f;
		scanf("%d %d",&n,&d);
	
		f=n; a=d; a=a/(double) 2.0; f=f/(double)2.0;
		b=a*a-f*f; b=sqrt(b);
		double ans=pi*a*b;
		ans+=eps;
		printf("%.3lf\n",ans);
	}

	return 0;
}