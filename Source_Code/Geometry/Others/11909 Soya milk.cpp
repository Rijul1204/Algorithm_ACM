#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 100
#define pi 3.141592654

double l,w,h,theta,v1,v2,ans,rad,angle;


int main(){

	int i,j,k,test,t=1;

//	freopen("in.txt","r",stdin);
	rad=180;

	while(scanf("%lf %lf %lf %lf",&l,&w,&h,&theta)==4){

		angle=theta;
		theta=theta*pi/rad;
		if(l*tan(theta)>h){
			angle=90-angle;
			theta=angle*pi/rad;
			v2=h*h*tan(theta);
			v2=(double) (v2/(double)2.0);
			v2*=w;
			printf("%.3lf mL\n",v2+.000000001);
			continue;
		}
		v1=l*w*h; v2=l*l*tan(theta);
		v2=(double) (v2/(double)2.0);
		v2*=w;
		ans=v1-v2;
		printf("%.3lf mL\n",ans+.000000001);

	}


	return 0;
}