#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 1000
#define pi 3.14159265358979323846264338327950288419716939937510

int a,b;
double h,w,ratio;

double findtheta(double h,double w,double theta);
double finds(double h,double w);
double di(double h,double w);
double bs();
int f(double val);

int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d : %d",&a,&b);
		
		double ans1=bs();
		double ans2=ratio*ans1;
		printf("Case %d: %lf %lf\n",t++,ans1,ans2);

	}


	return 0;
}

double bs(){

	int i,j,k,l,c=50;
	double lo,hi,mid;
	ratio=b;
	ratio/=(double)a;
	lo=0; hi=400;
	while(c--){

		mid=lo+hi;
		mid/=(double)2.0;
		k=f(mid);
		if(k==1){
			return mid;
		}
		else if(k==-1){
			lo=mid;
		}
		else {
			hi=mid;
		}		

	}

	return mid;

}

double findtheta(double h,double w,double di){
	
	double rh=h/w;
	double theta=atan(rh);
	theta*=(double) 180.0;
	theta/=pi;
	theta*=(double)2.0;
	theta=(double)180-theta;
	theta/=(double)180.0;
	theta=theta*pi;
	return theta;
}

int f(double val){
	
	h=val; w=ratio*h;
	double s=finds(h,w);
	double ret=s+s;
	ret=ret+h+h;
	double ret1=400.0;
	double com=ret-ret1;
	if(com<0) com*=-1;
	if(com<1e-9) return 1;
	if(ret-ret1<0) return -1;
	return 0;

}

double di(double h,double w){
	double ret=h*h+w*w;
	return sqrt(ret);
}
double finds(double h,double w){

	double d=di(h,w);
	double v=2.0;
	double r=d/v;
	double theta=findtheta(h,w,d);
	return r*theta;
}