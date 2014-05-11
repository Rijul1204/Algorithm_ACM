#include<stdio.h>
#include<string.h>
#include<math.h>

//#define pi 3.14159265358979323846264338327950288419716939937510
#define pi acos(-1.0)
double R,r,n;

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%lf %lf",&R,&n);
		double angle;
		angle=pi; angle/=n;
		R*=(sin(angle));
		double rh=(1+sin(angle));
		double ans=R/rh;
		printf("Case %d: %lf\n",t++,ans);


	}

	return 0;
}