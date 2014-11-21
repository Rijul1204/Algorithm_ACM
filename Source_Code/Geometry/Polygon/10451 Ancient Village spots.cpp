#include<stdio.h>
#include<string.h>
#include<math.h>

#define pi 2*acos(0)

int n;
double area,r,apothem,areaout,areain,nd;

void findap();
void findr();

int main(){
	
	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1){
		
		if(n<3) break;
		nd=n;
		scanf("%lf",&area);
		findap();
		findr();
		areain=apothem*pi;
		double ans1=area-areain;
		areaout=r*pi;
		double ans2=areaout-area;
		printf("Case %d: %.5lf %.5lf\n",t++,ans2,ans1);

	}

	return 0;
}

void findap(){
	
	double angle,right;
	//angle=(double)180/nd;
	angle=pi/nd;
	angle=tan(angle);
	right=nd*angle;
	apothem=area/right;

}

void findr(){
	
	double angle,right;
	angle=pi/nd;
	right=sin(angle);
	right*=cos(angle);
	right*=nd;
	r=area/right;

}
