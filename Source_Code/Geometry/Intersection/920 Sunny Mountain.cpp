#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define inf (1<<28)
#define maxm 110
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
struct line { // Creates a line with equation ax + by + c = 0
    double a, b, c;
    line() {}
    line( point p1,point p2 ) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
};

struct segment { // Creates a segment with two end points -> A, B
	point A, B;
	segment() {}
	segment( point P1, point P2 ) { A = P1, B = P2; }
};


inline bool intersect(line l1,line l2,point &p){

    double det=l1.a*l2.b - l1.b*l2.a;
    if(iseq(det,0.0)) return false;
    p.x = ( l1.b * l2.c - l2.b * l1.c ) / det;
	p.y = ( l1.c * l2.a - l2.c * l1.a ) / det;

	return true;

}
inline double Distance( point a, point b ) {
	return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}

inline double sq_distance( point a, point b ) {
    return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}

bool sort_x(point a,point b){
    if(iseq(a.x,b.x)) return a.y<b.y;
    return a.x<b.x;
}

int n;
point p[maxm];

inline bool intersection_seg( segment L1, segment L2, point &p ) {
	if( !intersect( line( L1.A, L1.B ), line( L2.A, L2.B ), p) ) {
		return false; // can lie on another, just check their equations, and check overlap
	}
	return(iseq(Distance(L1.A,p)+Distance(L1.B,p),Distance(L1.A,L1.B)) &&
		iseq(Distance(L2.A,p)+Distance(L2.B,p),Distance(L2.A,L2.B)));
}
double cal();

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(i=0;i<n;i++){
            scanf("%d %d",&k,&l);
            p[i]=point(k,l);
        }
        sort(p,p+n,sort_x);
        printf("%.2lf\n",cal());

    }

    return 0;
}


double cal(){

    double ret=0;
    if(n==1) return ret;
    int i,j,k;
    point pn[maxm];
    pn[0]=p[n-1];
    bool flag=1;


    for(i=n-2,k=n-3,j=1;k>=0;i--,k--){
       // if(flag){
        //    if(p[k].y>p[i].y)continue;
            pn[j++]=p[i];
       /*     flag=0;
        }
        else{
            if(p[k].y<p[i].y)continue;
            pn[j++]=p[i];
            flag=1;
        }
        */
    }
    pn[j++]=p[0];
    sort(pn,pn+j,sort_x);
    n=j;
    memcpy(p,pn,sizeof(pn));

    point curr=point(p[n-1].x+1,0);
    point curr1=point(-inf,curr.y);
    point p1;

    for(i=n-1,j=n-2;j>=0;i--,j--){
		curr1=point(-inf,curr.y);
        segment seg=segment(p[i],p[j]);
        segment seg1=segment(curr,curr1);
        if(!intersection_seg(seg,seg1,p1)) continue;
        if(p[i].y>p[j].y){ ret+=Distance(p1,p[i]); curr=p[i]; }
        else { ret+=Distance(p1,p[j]); curr=p[j]; }
    }


    return ret;

}
