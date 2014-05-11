// Geometry Templates>>>>>>>>>>>>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

//Macro........
#define ii long long int
#define maxm 100100
#define pi acos(-1.0)
#define eps 1e-9
#define sq(a) ((a)*(a))
#define dist(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) iseq(a,b)
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

inline bool intersectioncl(circle C,line L,point &p1,point &p2) {
	if( distancepl( C.center, L ) > C.r + eps ) return false;
	double a, b, c, d, x = C.center.x, y = C.center.y;
	d = C.r*C.r - x*x - y*y;
	if( eq( L.a, 0) ) {
		p1.y = p2.y = -L.c / L.b;
		a = 1;
		b = 2 * x;
		c = p1.y * p1.y - 2 * p1.y * y - d;
		d = b * b - 4 * a * c;
		d = sqrt( fabs (d) );
		p1.x = ( b + d ) / ( 2 * a );
		p2.x = ( b - d ) / ( 2 * a );
	}
	else {
		a = L.a *L.a + L.b * L.b;
		b = 2 * ( L.a * L.a * y - L.b * L.c - L.a * L.b * x);
		c = L.c * L.c + 2 * L.a * L.c * x - L.a * L.a * d;
		d = b * b - 4 * a * c;
		d = sqrt( fabs(d) );
		p1.y = ( b + d ) / ( 2 * a );
		p2.y = ( b - d ) / ( 2 * a );
		p1.x = ( -L.b * p1.y -L.c ) / L.a;
		p2.x = ( -L.b * p2.y -L.c ) / L.a;
	}
	return true;
}



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

int K,s,d;

ii mini(ii a,ii b){
	if(a<b) return a; return b;
}
ii maxi(ii a,ii b){
	if(a>b) return a; return b;
}
ii bs();
int f(ii val);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&K);
        scanf("%d %d %d",&n,&s,&d);

        for(i=0;i<n;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        sort(p,p+n,sort_x);

        ii ans=bs();
        printf("Case %d: ",t++);
        if(ans==-1) printf("impossible\n");
        else printf("%lld\n",ans);


    }


    return 0;
}

ii bs(){

    ii lo,hi,mid;

    lo=1,hi=1000001000;

    if(!f(lo)) return -1;

    while(lo<hi){

        mid=lo+hi; mid/=2;

        if(!f(mid)){
            hi=mid-1;
        }
        else{
            if(lo==mid){
                if(f(mid+1)) return mid+1;
                return lo;
            }
            lo=mid;
        }

    }

    return lo;

}

int f(ii val){

    int rem=s;

    line ll;
    point p1,p2;
    ll.a=0; ll.b=1; ll.c=-(K-val);

    ii leftx,rightx;
    int i;
    circle c=circle(p[0],d);

    if(!intersectioncl(c,ll,p1,p2)) return 0;
    leftx=mini(p1.x,p2.x); rightx=maxi(p1.x,p2.x);

    for(i=1;i<n;i++){
        c=circle(p[i],d);
        if(!intersectioncl(c,ll,p1,p2)) return 0;
        leftx=maxi(leftx,mini(p1.x,p2.x)); rightx=mini(rightx,maxi(p1.x,p2.x));
        if(leftx>rightx){
            rem--; if(!rem) return 0;
            leftx=mini(p1.x,p2.x); rightx=maxi(p1.x,p2.x);
        }
    }

    return 1;
}
