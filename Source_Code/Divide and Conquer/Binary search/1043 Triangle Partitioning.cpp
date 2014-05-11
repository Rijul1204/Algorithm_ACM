#include<stdio.h>
#include<string.h>
#include<math.h>

double a,b,c,d,e,f,ar1,ar2,ar3,ra;
int t=1;
void bs();
int cal(double ratio);
double area(double a,double b,double c);

int main(){

	int i,j,k,l,test;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%lf %lf %lf %lf",&a,&b,&c,&ra);
		ar1=1; 
		ra=ar1/ra;		
		ar3=area(a,b,c);

		bs();
	}

	return 0;
}

void bs(){

	int i,j,k,l,c=50;
	double lo=0,hi=1.0,mid;
	
	while(c--){

		mid=hi+lo; mid/=2;
		k=cal(mid);
		if(k==1){
			printf("Case %d: %lf\n",t++,mid*a);
			return ;			
		}
		else if(k==-1){
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	printf("Case %d: %d\n",t++,mid*a);
}

double area(double a,double b,double c){

	double s=a+b+c;
	s=s/(double)2.0;
	double ret=s;
	ret=ret*(s-a)*(s-b)*(s-c);
	ret=sqrt(ret);
	return ret;
}

int cal(double ratio){

	d=a*ratio; e=b*ratio; f=c*ratio;

	ar2=area(d,e,f);
	ar1=ar2+ra*ar2;
	double ans=ar1-ar3;
	if(ans<0) ans*=-1;
	if(ans<1e-9) return 1;
	
	if(ar1>ar3) return -1;
	else return 0;

}