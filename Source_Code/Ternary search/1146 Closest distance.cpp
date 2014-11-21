#include<stdio.h>
#include<string.h>
#include<math.h>

struct point{
	double a,b;
};

double dist(double a,double b,double c,double d){

	double k=a-c;
	double l=b-d;
	double ret=k*k+l*l;
	return ret;
}
double ax,ay,bx,by,cx,cy,dx,dy,ratio,len1,len2,a1,b1,a2,b2,ans;
void ts();
double fun(double a);

int main(){
	
	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
		a1=bx-ax; a2=dx-cx;
		b1=by-ay; b2=dy-cy;
		
		ts();

		printf("Case %d: %lf\n",t++,ans);
		

	}

	return 0;
}

void ts(){

	double min=0;
	double max=1;
	int c=100;
	double k,l,f,g;
	while(c--){
		
		f=min+(max-min)/(double)3.0;
		g=min+(double)2.0*((max-min)/(double)3.0);
		k=fun(f); l=fun(g);
		if(k<l){
			max=g;
		}
		else{
			min=f;
		}
	}
	
	k=(max+min)/2;
	ans=fun(k);
	ans=sqrt(ans);
}

double fun(double t){
	
	point a,b;

	a.a=ax+a1*t; a.b=ay+b1*t;
	b.a=cx+a2*t; b.b=cy+b2*t;
	
	return dist(a.a,a.b,b.a,b.b);
}
