// Geometry Templates>>>>>>>>>>>>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

//Macro........
#define inf 1<<30
#define maxm 10100
#define pi acos(-1.0)
#define eps 1e-9
#define sq(a) ((a)*(a))
#define dist(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
//#define mini(a,b) a<b ? a:b
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



double ang(point a,point b,point c){    //returns angle <bac
    double absq = sq_distance(a , b);
    double bcsq = sq_distance(c , b), acsq = sq_distance(a , c);
    double cosp = (absq+acsq - bcsq)/(2.0*sqrt(absq * acsq) );
    return acos(cosp);
}
double conv(double theta){

    double ret=180; ret/=pi; return ret*theta;
}

#define lim 10000*10000
double mini(double a,double b){
	if(a<b) return a;
	return b;
}
int n,nc;
point p[maxm],temp1[maxm],temp2[maxm];
double cal(int beg,int end);

int main(){

    int i,j,k,l,test,t=1;

  // freopen("in.txt","r",stdin);

    while(scanf("%d",&n)&&n){

		double kd,ld;
		for(i=0;i<n;i++){
			scanf("%lf %lf",&p[i].x,&p[i].y);
		}
		if(n==1){
			printf("INFINITY\n");
			continue;
		}
		sort(p,p+n,sort_x);
		double ans=cal(0,n-1);
		if(ans>lim) printf("INFINITY\n");
		else printf("%.4lf\n",sqrt(ans));

    }


    return 0;
}

double cal(int beg,int end){

	double d,d1,d2;
	if(beg>end) return inf;
	if(beg==end) return 0;
	if(beg+1==end) return dist(p[beg],p[end]);
	if(beg+2==end){
		d=dist(p[beg],p[beg+1]);
		d1=dist(p[beg+2],p[beg+1]);
		d2=dist(p[beg],p[beg+2]);
		d=mini(d,d1); d=mini(d,d2);
		return d;
	}
	int i,j,ns1,ns2,mid;
	mid=beg+end; mid/=2;
	d=cal(beg,mid);
	d1=cal(mid+1,end);

	d=mini(d,d1);
	d2=sqrt(d);
	ns1=ns2=0;
	for(i=mid;i>=beg;i--){
		if(sq(p[mid].x-p[i].x)>d) break;
		temp1[ns1++]=p[i];
	}
	for(i=mid+1;i<=end;i++){
		if(sq(p[i].x-p[mid+1].x)>d) break;
		temp2[ns2++]=p[i];
	}
	sort(temp1,temp1+ns1,sort_y);
	sort(temp2,temp2+ns2,sort_y);

	for(i=0;i<ns1;i++){
		for(j=0;j<ns2;j++){
			if(temp2[j].y-temp1[i].y>d2) break;
			if(dist(temp2[j],temp1[i])<d) d=dist(temp2[j],temp1[i]);
		}
	}
	return d;

}


