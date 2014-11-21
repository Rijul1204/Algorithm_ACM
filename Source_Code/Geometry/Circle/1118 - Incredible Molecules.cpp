#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define pi acos(-1.0)
#define eps 1e-11
#define iseq(a,b) (fabs(a-b)<eps)

struct point{
    double x,y;
    point(){}
    point(double _x,double _y){
        x=_x; y=_y;
    }
};
struct circle{
    point cen;
    double r;
    circle(){}
    circle(point _c,double _r){
        cen=_c; r=_r;
    }
};

inline double distancepp( point a, point b ) {
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
inline double sq_distance( point a, point b ) {
    return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}

double ang(point a,point b,point c){    //returns angle <bac
    double absq = sq_distance(a , b);
    double bcsq = sq_distance(c , b), acsq = sq_distance(a , c);
    double cosp = (absq+acsq - bcsq)/(2.0*sqrt(absq * acsq) );
    return acos(cosp);
}


double areatri(double a,double b,double c);
double cal_area(circle c1,circle c2);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        circle  c1,c2;
        double x,y,r;

        scanf("%lf %lf %lf",&x,&y,&r);
        c1=circle(point(x,y),r);

        scanf("%lf %lf %lf",&x,&y,&r);
        c2=circle(point(x,y),r);

        printf("Case %d: %lf\n",t++,cal_area(c1,c2)+eps);

    }

    return 0;
}

double areatri(double a,double b,double c){

    double s=a+b+c; s/=2.0;

    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double cal_area(circle c1,circle c2){

    point p1,p2;
    double ret,r1,r2,theta1,theta2;

    p1=c1.cen; p2=c2.cen;
    r1=c1.r;   r2=c2.r;

    double d=distancepp(p1,p2);

    c2.cen.x = distancepp( c1.cen, c2.cen );
	c1.cen.x = c1.cen.y = c2.cen.y = 0;

	if(d+eps>r1+r2) return 0;
    if(d<fabs(r1-r2)+eps){
        if(r1<r2) return  pi*r1*r1;
        else return pi*r2*r2;
    }

   // if( c1.r < c2.cen.x - c2.r + eps ) return 0;
//	if( -c1.r + eps > c2.cen.x - c2.r ) return pi * c1.r * c1.r;
//	if( c1.r + eps > c2.cen.x + c2.r ) return pi * c2.r * c2.r;


    // c*c=a*a+b*b-2abcos(x)..
    theta1=acos(((r1*r1+d*d-r2*r2)/(2.0*r1*d)));
    theta2=acos(((r2*r2+d*d-r1*r1)/(2.0*r2*d)));

    //theta1*=2.0; theta2*=2.0;

    double area1=theta1*r1*r1;
    double area2=theta2*r2*r2;

    theta1*=2.0;
	double cc1=r1*sin(theta1)/sin((pi-theta1)/2.0);
    if(theta1<pi){
		area1-=areatri(r1,r1,cc1);
	}
	else if(iseq(theta1,pi)){}
	else area1+=areatri(r1,r1,cc1);

    theta2*=2.0;
	double cc2=r2*sin(theta2)/sin((pi-theta2)/2.0);
    if(theta2<pi){
		area2-=areatri(r2,r2,cc2);
	}
	else if(iseq(theta2,pi)){}
	else area2+=areatri(r2,r2,cc2);

    return area1+area2;
}
