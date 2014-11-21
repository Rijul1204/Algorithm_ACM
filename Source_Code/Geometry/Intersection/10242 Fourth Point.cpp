#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 10
#define eps 1e-7
#define iseq(a,b) (fabs(a-b)<eps)

struct point {
	double x,y;
    point() {}
    point( double xx, double yy ) { x = xx, y = yy; }
};

struct line{
	double a,b,c;
	line(){}
	line(point p1,point p2){
		a=p1.y-p2.y;
		b=p2.x-p1.x;
		c=p1.x*p2.y-p2.x*p1.y;
	}
};

double cross(point p0,point p1,point p2){
	return ((p1.x-p0.x)*(p1.x-p0.x));
}
point p[maxm];
line genp(line l,point p);
point intersect(line ret1,line ret2);

int main(){

	int i,j,k,l;

//	freopen("in.txt","r",stdin);

	while(scanf("%lf %lf",&p[0].x,&p[0].y)==2){

		for(i=1;i<=3;i++){
			scanf("%lf %lf",&p[i].x,&p[i].y);
		}
		if(iseq(p[0].x,p[2].x)&&iseq(p[0].y,p[2].y)) swap(p[0],p[1]);
		else if(iseq(p[0].x,p[3].x)&&iseq(p[0].y,p[3].y)){
			swap(p[0],p[1]); swap(p[2],p[3]);
		}
		else if(iseq(p[1].x,p[3].x)&&iseq(p[1].y,p[3].y)){
			swap(p[2],p[3]);
		}


		line l1=line(p[0],p[1]); 
		line l2=line(p[2],p[3]);
		line l3,l4;
		
		l3=genp(l1,p[3]); l4=genp(l2,p[0]);
		point ans=intersect(l3,l4);
		printf("%.3lf %.3lf\n",ans.x+eps,ans.y+eps);
	}

	return 0;
}

point intersect(line ret1,line ret2){

	double A1,B1,A2,B2,C1,C2;
	A1=ret1.a; A2=ret2.a; B1=ret1.b; B2=ret2.b;
	C1=-ret1.c; C2=-ret2.c;
	point ret;

	double det=A1*B2-A2*B1;
	double com=det-0; 
	if(com<0) com*=-1;
	if(com<eps){
		ret.x=0; ret.y=0;
		return ret;
	}
	ret.x=C1*B2-C2*B1; ret.x/=det;
	ret.y=A1*C2-A2*C1; ret.y/=det;
	return ret;	
}

//genp= Parallel>>>>>
line genp(line l,point p){

	line ret;
	ret.a=l.a; ret.b=l.b;
	ret.c=ret.a*p.x+ret.b*p.y;
	ret.c*=-1;
	return ret;

}