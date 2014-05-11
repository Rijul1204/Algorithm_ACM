#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define inf (1<<26)
#define pi acos(-1.0)
#define eps (1e-9)
#define iseq(a,b) (fabs(a-b)<eps)
#define maxm 1010

double mini(double a,double b){
	if(a<b) return a; return b;
}
double maxi(double a,double b){
	if(a>b) return a; return b;
}

struct point{
    double x,y;
    point(){}
    point(double a,double b){ x=a; y=b; }
};
point p[maxm];

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

bool point_in_segment(segment s1,point p){

    double dist1=distancepp(s1.p1,s1.p2);
    double dist2=distancepp(s1.p1,p)+distancepp(s1.p2,p);
    if(iseq(dist1,dist2)) return true;


    return false;
}



int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        int n,q;

        scanf("%d",&n);

        for(i=1;i<=n;i++){
            scanf("%d %d",&k,&l);
            p[i]=point(k,l);
        }
        segs[0]=segment(p[n],p[1]);
        for(i=1;i<n;i++){
            segs[i]=segment(p[i],p[i+1]);
        }
        scanf("%d",&q);

        // qp= query point...
        point qp,tempp;
        segment tempseg;
        double x2 = rand()*10000+100007;
        double y2 = rand()*10000+100007;
        tempp=point(x2,y2);
        int flag;

        printf("Case %d:\n",t++);
        for(i=1;i<=q;i++){
            scanf("%d %d",&k,&l);
            qp=point(k,l);
            tempseg=segment(qp,tempp);

            flag=0;
            for(j=0;j<n;j++){
				if(point_in_segment(segs[j],qp)) flag=1;
                if(flag) break;
            }
            if(flag){
                printf("Yes\n"); continue;
            }

            flag=0;
            for(j=0;j<n;j++){
                if(seg_linear(segs[j],tempseg)) continue;
                if(seg_intersect(segs[j],tempseg)){
                    flag=!flag;
                }
            }
            if(flag) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}
