#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define pi acos(-1.0)
#define eps (1e-9)
#define iseq(a,b) (fabs(a-b)<eps)

struct point{
    double x,y;
    point(){}
    point(double a,double b){ x=a; y=b; }
};
point p[10];

struct segment{
    point p1,p2;
    segment(){}
    segment(point a,point b){ p1=a; p2=b;}
};
segment segs[10];

// cross product ..
inline double cross( point p0, point p1, point p2 ) {
    return( ( p1.x - p0.x ) * ( p2.y - p0.y ) - ( p2.x - p0.x ) * ( p1.y - p0.y ) );
}
// Distance between point a and b..
inline double distancepp( point a, point b ) {
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
// Square of  Distance between point a and b..
inline double sq_distance( point a, point b ) {
    return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}
// segment segment Intersection.........
bool seg_intersect(segment s1,segment s2){

    if((cross(s1.p1,s1.p2,s2.p1)*cross(s1.p1,s1.p2,s2.p2)<0)&&(cross(s2.p1,s2.p2,s1.p1)*cross(s2.p1,s2.p2,s1.p2)<0)) return true;
    return false;
}
bool seg_touch(segment s1,segment s2){

    double dist1=distancepp(s1.p1,s1.p2);
    double dist2=distancepp(s1.p1,s2.p1)+distancepp(s1.p2,s2.p1);
    if(iseq(dist1,dist2)) return true;

    dist2=distancepp(s1.p1,s2.p2)+distancepp(s1.p2,s2.p2);
    if(iseq(dist1,dist2)) return true;

    return false;
}
bool chck(segment s,point p1,point p2){

    point p=s.p1;

    if((p.x>p1.x&&p.x<p2.x)&&(p.y<p1.y&&p.y>p2.y)) return 1;

    p=s.p2;
    if((p.x>p1.x&&p.x<p2.x)&&(p.y<p1.y&&p.y>p2.y)) return 1;

    return 0;
}

bool comp(point a,point b){
    if(iseq(a.y,b.y)) return a.x<b.x;
    return a.y<b.y;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        // Line segment
        for(i=0;i<2;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        segs[0]=segment(p[0],p[1]);

        for(i=0;i<2;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        if(p[0].x>p[1].x) swap(p[0].x,p[1].x);
        if(p[0].y<p[1].y) swap(p[0].y,p[1].y);

        // building rectangle  segments..........
        segs[1]=segment(p[0],point(p[1].x,p[0].y));
        segs[2]=segment(point(p[1].x,p[0].y),p[1]);
        segs[3]=segment(p[1],point(p[0].x,p[1].y));
        segs[4]=segment(point(p[0].x,p[1].y),p[0]);

        int flag=0;
        for(i=1;i<=4;i++){
            if(seg_intersect(segs[0],segs[i])||seg_touch(segs[0],segs[i])||seg_touch(segs[i],segs[0])){
                flag=1; break;
            }
        }
        if(chck(segs[0],p[0],p[1])) flag=1;

        if(flag){
            printf("T\n");
        }
        else{
            printf("F\n");
        }

    }

    return 0;
}
