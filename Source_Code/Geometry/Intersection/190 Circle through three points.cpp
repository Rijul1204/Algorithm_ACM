#include<stdio.h>
#include<math.h>

struct point{
	double x,y;
};
struct eq{
	double a,b,c;
};

eq gen(point a,point b);
point find(point a,point b,point c);
eq genp(eq a);
point findintersect(eq a,eq b);
double dist(point a,point b);

int main(){

	int i,j,l,test;

//	freopen("in.txt","r",stdin);

	point a,b,c;

	while(scanf("%lf %lf",&a.x,&a.y)==2){

		scanf("%lf %lf %lf %lf",&b.x,&b.y,&c.x,&c.y);

		point cen=find(a,b,c);
		double d=dist(a,cen);
		double h,k,c1,h1,k1;
		h=-((double)2.0*cen.x);
		k=-((double)2.0*cen.y);
		h1=h/(double)2.0; k1=k/(double)2.0;
		c1=h1*h1+k1*k1-d*d;
		printf("(x ");
		if(cen.x<0) printf("+"); else printf("-");
		if(cen.x<0) cen.x*=-1;
		printf(" %.3lf)^2 + (y ",cen.x);
		if(cen.y<0) printf("+"); else printf("-");
		if(cen.y<0) cen.y*=-1;
		printf(" %.3lf)^2 = %.3lf^2\n",cen.y,d);
		printf("x^2 + y^2 ");
		if(h<0) printf("-"); else printf("+");
		if(h<0) h*=-1;
		printf(" %.3lfx ",h);
		if(k<0) printf("-"); else printf("+");
		if(k<0) k*=-1;
		printf(" %.3lfy ",k);
		if(c1<0) printf("-"); else printf("+");
		if(c1<0) c1*=-1;
		printf(" %.3lf = 0\n\n",c1);

		//printf("%.3lf %.3lf %.3lf\n",cen.x,cen.y,d);


	}

	return 0;
}
double dist(point a,point b){

	double ret,k,l;
	k=a.x-b.x; l=a.y-b.y;
	k*=k; l*=l;
	ret=k+l;
	return sqrt(ret);
}
point findintersect(eq a,eq b){

	point ret;
	double det=a.a*b.b-b.a*a.b;
	if(det==0){
		ret.x=ret.y=0; return ret;
	}
	ret.x=(a.c*b.b-b.c*a.b)/det;
	ret.y=(a.a*b.c-b.a*a.c)/det;
	return ret;

}

eq genp(point a,point b){

	eq n1,pn1;
	point mid;
	mid.x=(a.x+b.x)/(double) 2.0;
	mid.y=(a.y+b.y)/(double) 2.0;
	n1=gen(a,b);
	pn1.a=-n1.b; pn1.b=n1.a;
	pn1.c=mid.x*pn1.a+mid.y*pn1.b;
	return pn1;
}
eq gen(point a,point b){

	eq ret;
	ret.a=b.y-a.y; ret.b=a.x-b.x;
	ret.c=ret.a*a.x+ret.b*a.y;
	return ret;
}

point find(point a,point b,point c){

	eq pn1,pn2;
	pn1=genp(a,b); pn2=genp(b,c);
	point ret=findintersect(pn1,pn2);

	return ret;
}

