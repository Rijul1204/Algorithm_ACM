#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define inf (1<<26)
#define pi acos(-1.0)
#define eps (1e-9)
#define iseq(a,b) (fabs(a-b)<eps)
#define maxm 110

double mini(double a,double b){
	if(a<b) return a; return b;
}
double maxi(double a,double b){
	if(a>b) return a; return b;
}
// Creates Point 2D
struct point{
    double x,y;
    point(){}
    point(double a,double b){ x=a; y=b; }
};

// Creates a line with equation ax + by + c = 0
struct line {
    double a, b, c;
    line() {}
    line( point p1,point p2 ) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
};

// Creates Segment.....
struct segment{
    point p1,p2;
    segment(){}
    segment(point a,point b){ p1=a; p2=b;}
};
segment segs[maxm];

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
bool seg_linear(segment s1,segment s2){
    if(!iseq(cross(s1.p1,s1.p2,s2.p1),0.0)) return 0;
    if(!iseq(cross(s1.p1,s1.p2,s2.p2),0.0)) return 0;
    if(!iseq(cross(s2.p1,s2.p2,s1.p1),0.0)) return 0;
    if(!iseq(cross(s2.p1,s2.p2,s1.p2),0.0)) return 0;
    return 1;
}

bool satisfy_line(line l,point p1,point p2){

    double ret=l.a*p1.x+l.b*p1.y+l.c;
    if(!iseq(ret,0.0)) return 0;

    ret=l.a*p2.x+l.b*p2.y+l.c;
    if(!iseq(ret,0.0)) return 0;

    return 1;
}

bool point_in_segment(segment s1,point p){

    double dist1=distancepp(s1.p1,s1.p2);
    double dist2=distancepp(s1.p1,p)+distancepp(s1.p2,p);
    if(iseq(dist1,dist2)) return true;


    return false;
}

int n;
bool fl[maxm];
point p[maxm];
line line1,line2;


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);
        int ans=0,ans1=n,val;
        for(i=0;i<n;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        memset(fl,0,sizeof(fl));

        for(i=0;i<n;i++){
            if(fl[i]) continue;
            for(j=i+1;j<n;j++){
                if(iseq(p[i].x,p[j].x)&&iseq(p[i].y,p[j].y)){
                  fl[j]=1; ans1--;
                }
            }
        }

        if(ans1==1){
            printf("Data set #%d contains a single gnu.\n",t++);
            continue;
        }

        for(i=0;i<n;i++){
            if(fl[i]) continue;
            for(j=i+1;j<n;j++){
                if(fl[j]) continue;
                val=2; line1=line(p[i],p[j]);
                for(k=j+1;k<n;k++){
                    if(fl[k]) continue;
                    if(satisfy_line(line1,p[i],p[k])) val++;

                }
                if(ans<val) ans=val;
            }
        }

        printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n",t++,ans1,ans);

    }

    return 0;
}
