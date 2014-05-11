#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define pi acos(-1.0)
#define sq(a) ((a)*(a))
#define eps 1e-10
#define iseq(a,b) (fabs(a-b)<eps)

struct point{
    double x,y;
    point(){}
    point(double _x,double _y){
        x=_x; y=_y;
    }
};

struct line{  //  ax + by + c = 0;
    double a,b,c;
    line(){}
    line(double _a,double _b,double _c){
        a=_a; b=_b; c=_c;
    }
    line(point p1,point p2){
        a=p1.y-p2.y;
        b=p2.x-p1.x;
        c=p1.x*p2.y -p2.x*p1.y;
    }
};

inline bool intersect(line l1,line l2,point &p){

    double det=l1.a*l2.b - l1.b*l2.a;
    if(iseq(det,0.0)) return false;
    p.x = ( l1.b * l2.c - l2.b * l1.c ) / det;
	p.y = ( l1.c * l2.a - l2.c * l1.a ) / det;

	return true;

}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    double a1,b1,c1,a2,b2,c2;

    while(scanf("%lf %lf %lf %lf %lf %lf",&a1,&b1,&c1,&a2,&b2,&c2)==6){

        if(iseq(a1,0.0) && iseq(b1,0.0) &&  iseq(c1,0.0) &&  iseq(a2,0.0) &&  iseq(b2,0.0) && iseq(c2,0.0)) break;

        line l1=line(a1,b1,-c1);
        line l2=line(a2,b2,-c2);
        point p;

        if(intersect(l1,l2,p)){
            if(iseq(p.x,0.0)) p.x=fabs(p.x);
            if(iseq(p.y,0.0)) p.y=fabs(p.y);
            printf("The fixed point is at %.2lf %.2lf.\n",p.x,p.y);
        }
        else printf("No fixed point exists.\n");

    }

    return 0;
}

