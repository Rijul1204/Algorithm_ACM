// Geometry Templates>>>>>>>>>>>>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
 
//Macro........
#define pi acos(-1.0)
#define eps 1e-9
#define sq(a) ((a)*(a))
#define dist(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
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


#define maxm 1000
 
int n,nc;
 


double ang(point a,point b,point c){    //returns angle <bac
    double absq = sq_distance(a , b);
    double bcsq = sq_distance(c , b), acsq = sq_distance(a , c);
    double cosp = (absq+acsq - bcsq)/(2.0*sqrt(absq * acsq) );
    return acos(cosp);
}
double conv(double theta){
 
    double ret=180; ret/=pi; return ret*theta;
}
point p,points[maxm]; 
point bs(point a,point b,point c);

int main(){
 
    int i,j,k,l,test,t=1;
 
   // freopen("in.txt","r",stdin);
	double kd,ld; 
    
    while(scanf("%lf",&kd)==1){
		
		scanf("%lf",&ld);
		p=point(kd,ld);
		
		double ans,ansd;
		point ret,ret1;
		scanf("%d",&n);
		
		scanf("%lf %lf",&kd,&ld);
		points[0]=point(kd,ld);
		
		for(i=1;i<=n;i++){
			scanf("%lf %lf",&kd,&ld);
			points[i%2]=point(kd,ld);
			ret1=bs(points[0],points[1],p);
			if(i==1){
				ans=dist(ret1,p);
				ret=ret1;
			}
			else if(dist(ret1,p)<ans){
				ans=dist(ret1,p);
				ret=ret1;
			}
		}
		printf("%.4lf\n%.4lf\n",ret.x,ret.y);	
       
    }
 
   
    return 0;
}
 

point bs(point lo,point hi,point p){

	if(dist(lo,p)>dist(hi,p)){
		swap(lo,hi);
	}
	int i,j,k,l,c=200;
	point mid;
	double kd,ld,t=2;

	while(c--){
		
		kd=lo.x+hi.x; kd/=t;
		ld=lo.y+hi.y; ld/=t;
		mid=point(kd,ld);
	
		if(dist(mid,p)<dist(lo,p)&&dist(lo,p)>dist(hi,p)){
			swap(lo,mid);
		}
		else{
			swap(hi,mid);
		}


	}
	
	return mid;

}