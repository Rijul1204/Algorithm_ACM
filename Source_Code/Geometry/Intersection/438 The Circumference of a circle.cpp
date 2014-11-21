#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 1000
#define eps 1e-7
#define pi 3.141592653589793

struct point{
	double x,y;
};
struct eq{
	double a,b,c;
};

point getcenter(point a,point b,point c);
point intersect(eq a,eq b);
eq geteqp(eq a,point n);
eq geneq(point a,point b);
double dist(point a,point b);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	point a,b,c;

	while(scanf("%lf %lf",&a.x,&a.y)==2){

		scanf("%lf %lf %lf %lf",&b.x,&b.y,&c.x,&c.y);

		point cen=getcenter(a,b,c);
		double r=dist(a,cen);
		double ans=(double)2.0*r*pi;
		
		printf("%.2lf\n",ans);

	}

	return 0;
}

double dist(point a,point b){

	double k,l,ret;

	k=a.x-b.x; l=a.y-b.y;
	k*=k; l*=l;
	ret=k+l;
	ret=sqrt(ret);
	return ret;
}

point intersect(eq a,eq b){

	double A1,A2,B1,B2,C1,C2,det;
	point ret;

	A1=a.a; A2=b.a; B1=a.b; B2=b.b; C1=a.c; C2=b.c;
	
	det=A1*B2-A2*B1;
	ret.x=(C1*B2-C2*B1)/det;
	ret.y=(C2*A1-C1*A2)/det;
	return ret;
}

eq geteqp(eq a,point n){
	
	eq ret;
	ret.a=-a.b; ret.b=a.a;
	ret.c=n.x*ret.a+n.y*ret.b;
	return ret;
}

eq geneq(point a,point b){

	eq ret; point mid;	
	mid.x=(a.x+b.x)/(double)2.0; mid.y=(a.y+b.y)/(double)2.0;
	ret.a=b.y-a.y; ret.b=a.x-b.x; ret.c=a.x*ret.a+a.y*ret.b;
	ret=geteqp(ret,mid);
	return ret;
}

point getcenter(point a,point b,point c){

	eq n1,n2;
	point ret;

	n1=geneq(a,b);
	n2=geneq(b,c);
	ret=intersect(n1,n2);
	
	return ret;
}