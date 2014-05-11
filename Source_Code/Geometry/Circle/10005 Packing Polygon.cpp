// Geometry Templates>>>>>>>>>>>>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

//Macro........
#define maxm 100100
#define pi acos(-1.0)
#define eps 1e-9
#define sq(a) ((a)*(a))
#define dist(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) iseq(a,b)
#define mini(a,b) a<b ? a:b
#define maxi(a,b) a>b ? a:b
#define area_t(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define spDist(lat1,long1,lat2,long2,r) ( r * acos( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1-long2) ) )

// Template........
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

// Structure....
struct point { // Creates normal 2D point
    double x, y;
    point() {}
    point( double xx, double yy ) { x = xx, y = yy; }
    bool operator <(point b)const{
		if(!eq(x,b.x) )	return x < b.x;
		return y < b.y;
	}
	bool operator == (point b) const{
		if(eq(x,b.x) && eq(y,b.y))	return true;
		return false;
	}

};
struct point3D { // Creates normal 3D point
    double x, y, z;
};
struct line { // Creates a line with equation ax + by + c = 0
    double a, b, c;
    line() {}
    line( point p1,point p2 ) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
};
struct circle { // Creates a circle with point 'center' as center and r as radius
    point center;
    double r;
    circle() {}
    circle( point P, double rr ) { center = P; r = rr; }
};
struct segment { // Creates a segment with two end points -> A, B
    point A, B;
    segment() {}
    segment( point P1, point P2 ) { A = P1, B = P2; }
    bool operator < (const segment &a)const{
        return A<a.A;
    }
};
inline double distancepp( point a, point b ) {
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
inline double sq_distance( point a, point b ) {
    return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}
inline double distancepl( point P, line L ) {
    return fabs( L.a * P.x + L.b * P.y + L.c ) / sqrt( L.a * L.a + L.b * L.b );
}
inline double cross( point p0, point p1, point p2 ) {
    return( ( p1.x - p0.x ) * ( p2.y - p0.y ) - ( p2.x - p0.x ) * ( p1.y - p0.y ) );
}
double areaPoly(point P[],int n){
    double area=0;
    for( int i = 0, j = n - 1; i < n; j = i++ ) area += P[j].x * P[i].y - P[j].y * P[i].x;
    return fabs(area)*.5;

}
bool sort_x(point a,point b){
    if(iseq(a.x,b.x)) return a.y<b.y;
    return a.x<b.x;
}
bool sort_y(point a,point b){
    if(iseq(a.y,b.y)) return a.x<b.x;
    return a.y<b.y;
}
//end>>>>>

int n,nc;
point p[maxm]; // p=all points
double r;

double ang(point a,point b,point c){    //returns angle <bac
    double absq = sq_distance(a , b);
    double bcsq = sq_distance(c , b), acsq = sq_distance(a , c);
    double cosp = (absq+acsq - bcsq)/(2.0*sqrt(absq * acsq) );
    return acos(cosp);
}
//  radian  to  degree.
double conv(double theta){

    double ret=180; ret/=pi; return ret*theta;
}

bool normal(const point &a, const point &b) {   return (iseq(a.x,b.x) ? a.y < b.y : a.x < b.x);}
bool issame(const point &a, const point &b) {   return (iseq(a.x,b.x) && iseq(a.y,b.y));}
void makeUnique(int &np) {  sort(&p[0], &p[np], normal);    np = unique(&p[0], &p[np], issame) - p;}

int cal();
int chck(point p1,point p2);
int chck1(circle c);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    while(scanf("%d",&n)==1){

        if(!n) break;

        for(i=0;i<n;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        scanf("%lf",&r);


        if(cal()){
            printf("The polygon can be packed in the circle.\n");
        }
        else printf("There is no way of packing that polygon.\n");


    }


    return 0;
}

int chck1(circle c){

    int i;

    for(i=0;i<n;i++){
        if(distancepp(c.center,p[i])>c.r) return 0;
    }

    return 1;

}

int chck(point p1,point p2){

    circle c1=circle(p1,r),c2=circle(p2,r);
    circle c;

    double x1 = p1.x, x2 = p2.x, y1 = p1.y, y2 = p2.y;
    double q = distancepp(p1,p2);


    double x_part = sqrt(r * r - 0.25 * q * q) * (y1 - y2) / q;
    double y_part = sqrt(r * r - 0.25 * q * q) * (x2 - x1) / q;
    double x3 = 0.5 * (x1 + x2), y3 = 0.5 * (y1 + y2);
    point p = point(x3 + x_part, y3 + y_part);

    c=circle(p,r);
    if(chck1(c)) return 1;
    p = point(x3 - x_part, y3 - y_part);

    c=circle(p,r);
    if(chck1(c)) return 1;



    return 0;

}


int cal(){

    int i,j,k,l;

	if(n==1) return 1;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(sq_distance(p[i],p[j])>4*r*r) return 0;
            if(chck(p[i],p[j])) return 1;
        }
    }

    return 0;
}
