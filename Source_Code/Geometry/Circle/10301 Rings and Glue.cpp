// Geometry Templates>>>>>>>>>>>>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

//Macro........
#define maxm 1010
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

inline double intersectionArea2C( circle C1, circle C2 ) {
	C2.center.x = distancepp( C1.center, C2.center );
	C1.center.x = C1.center.y = C2.center.y = 0;
	if( C1.r < C2.center.x - C2.r + eps ) return 0;
	if( -C1.r + eps > C2.center.x - C2.r ) return pi * C1.r * C1.r;
	if( C1.r + eps > C2.center.x + C2.r ) return pi * C2.r * C2.r;
	double c, CAD, CBD, res;
	c = C2.center.x;
	CAD = 2 * acos( (C1.r * C1.r + c * c - C2.r * C2.r) / (2 * C1.r * c) );
	CBD = 2 * acos( (C2.r * C2.r + c * c - C1.r * C1.r) / (2 * C2.r * c) );
	res=C1.r * C1.r * ( CAD - sin( CAD ) ) + C2.r * C2.r * ( CBD - sin ( CBD ) );
	return .5 * res;
}

//end>>>>>

circle cs[maxm];
int pre[maxm],count1[maxm];
int find(int x){
    if(pre[x]==x) return x;
    return pre[x]=find(pre[x]);
}
bool chck(circle c1,circle c2){

    double d=distancepp(c1.center,c2.center);
    if(d>c1.r+c2.r) return 0;
    if(fabs(c1.r-c2.r)>d) return 0;
    return 1;
}

int main(){

    int i,j,k,l,test,t=1,n;

    //freopen("in.txt","r",stdin);

    while(scanf("%d",&n)==1){

        if(n==-1) break;

        double xd,yd,rd;
        for(i=1;i<=n;i++){
            scanf("%lf %lf %lf",&xd,&yd,&rd);
            cs[i]=circle(point(xd,yd),rd);
            pre[i]=i; count1[i]=1;
        }

        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(i==j) continue;
                k=find(i); l=find(j);
                if(k==l) continue;
                if(chck(cs[i],cs[j])){
                    pre[k]=l;
                    count1[k]=count1[l]+=count1[k];
                }
            }
        }

        int ans=0;
        for(i=1;i<=n;i++){
            if(count1[i]>ans) ans=count1[i];
        }
		if(ans==1) printf("The largest component contains %d ring.\n",ans);
        else printf("The largest component contains %d rings.\n",ans);

    }

    return 0;
}

