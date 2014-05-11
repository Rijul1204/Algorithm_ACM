#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 1000

double x,y,h,rh,hin;

int f(double mid);
double bs();
double cal(double rat);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%lf %lf %lf",&x,&y,&h);
		hin=1; hin/=h;
		rh=(y*y)-(x*x);
		double rat=bs();
		double ans=cal(rat);
		printf("Case %d: %lf\n",t++,ans);
	}

	return 0;
}

double bs(){

	int i,j,k,c=100;
	double lo,hi,mid,d=2.0;
	lo=0; hi=y;
	while(c--){
		mid=lo+hi; mid/=d;
		k=f(mid);
		if(k==0) return mid;
		if(k==1){
			hi=mid;
		}
		else if(k==-1) lo=mid;
	}
	return mid;
}
int f(double mid){
	
	double b=mid;
	double bin=1; bin/=mid;
	double cin=hin-bin;
	double c=1.0; c/=cin;
	double lh=(b*b)-(c*c);
	double com=rh-lh;
	if(com<0) com*=-1;
	if(com<1e-11) return 0;
	com=rh-lh;
	if(com<0) return 1;
	return -1;
}
double cal(double rat){

	double b=rat;
	double lh=(y*y)-(b*b);
	double ret=sqrt(lh);
	return ret;

}