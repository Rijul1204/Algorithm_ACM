#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 400100
#define pi acos(-1.0)
#define eps 1e-11
#define sq(a) ((a)*(a))
#define dist(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
#define mini(a,b) a<b ? a:b
#define maxi(a,b) a>b ? a:b

struct point{
    double x,y;
    point(){}
    point(double _x,double _y){
        x=_x; y=_y;
    }
};

struct rect{
    point p1,p2;
    rect(){}
    rect(point _p1,point _p2){
        p1=_p1; p2=_p2;
    }
};
struct circle{
    point cen;
    double r;
    circle(){}
    circle(point p,double _r){
        cen=p; r=_r;
    }
};
struct tri{
    point p1,p2,p3;
    tri(){}
    tri(point _p1,point _p2,point _p3){
        p1=_p1; p2=_p2; p3=_p3;
    }
};

inline double cross( point p0, point p1, point p2 ) {
    return( ( p1.x - p0.x ) * ( p2.y - p0.y ) - ( p2.x - p0.x ) * ( p1.y - p0.y ) );
}

rect rr[maxm];
circle cc[maxm];
tri  tt[maxm];

int fl[maxm];
char s[10];

int chck1(rect r,point p);
int chck2(circle c,point p);
int chck3(tri t,point p);

int main(){

    int i,j,k,l,test,t=1,c=0,c1=0,c2=0,c3=0;
    double x1,y1,x2,y2,x3,y3;

    //freopen("in.txt","r",stdin);

    while(scanf("%s",s)==1){

        if(s[0]=='r'){
            fl[c++]=0;
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            rr[c1++]=rect(point(x1,y1),point(x2,y2));
        }
        else if(s[0]=='c'){
            fl[c++]=1;
            scanf("%lf %lf %lf",&x1,&y1,&x2);
            cc[c2++]=circle(point(x1,y1),x2);
        }
        else if(s[0]=='t'){
            fl[c++]=2;
            scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
            tt[c3++]=tri(point(x1,y1),point(x2,y2),point(x3,y3));
        }
        else break;
    }

    int now=1;

    while(1){

        scanf("%lf %lf",&x1,&y1);
        if(iseq(x1,9999.9) && iseq(y1,9999.9)) break;

        point p=point(x1,y1);

        c1=0; c2=0; c3=0; int flag=0;
        for(i=0;i<c;i++){
            if(fl[i]==0){
                if(chck1(rr[c1++],p)){ flag=1; printf("Point %d is contained in figure %d\n",now,i+1); }
            }
            else if(fl[i]==1){
                if(chck2(cc[c2++],p)){flag=1; printf("Point %d is contained in figure %d\n",now,i+1); }
            }
            else if(fl[i]==2){
                if(chck3(tt[c3++],p)){flag=1; printf("Point %d is contained in figure %d\n",now,i+1); }
            }
        }
		if(!flag){
			printf("Point %d is not contained in any figure\n",now);
		}
		now++;

    }

    return 0;
}

int chck3(tri t,point p){

    point p1=t.p1,p2=t.p2,p3=t.p3;

    //  check  for boundary........
    if(iseq(cross(p,p1,p2),0)) return 0;
    if(iseq(cross(p,p2,p3),0)) return 0;
    if(iseq(cross(p,p1,p3),0)) return 0;
    // .........

    if(cross(p,p1,p2)*cross(p3,p1,p2)<0) return 0;
    if(cross(p,p2,p3)*cross(p1,p2,p3)<0) return 0;
    if(cross(p,p1,p3)*cross(p2,p1,p3)<0) return 0;

    return 1;

}


int chck2(circle c,point p){

    double d=dist(c.cen,p);

    if(d>sq(c.r)) return 0;
    if(iseq(d,sq(c.r))) return 0;

    return 1;
}


int chck1(rect r,point p){

    if(r.p1.x>r.p2.x) swap(r.p1,r.p2);



    point p1=r.p1,p2=r.p2;

	//if(p.x>p1.x && p.x<p2.x && p.y<p1.y && p.y>p2.y ) return 1;
	//return 0;


    if(iseq(cross(p,p1,point(p1.x,p2.y)),0)) return 0;

    //puts("sadsad");

    if(iseq(cross(p,p1,point(p2.x,p1.y)),0)) return 0;

    //puts("sadsad");

    if(iseq(cross(p,p2,point(p1.x,p2.y)),0)) return 0;

    //puts("sadsad");
    if(iseq(cross(p,p2,point(p2.x,p1.y)),0)) return 0;

    //puts("sadsad");


    if(p.x<p1.x) return 0;
    if(p.y>p1.y) return 0;
    if(p.x>p2.x) return 0;
    if(p.y<p2.y) return 0;

    return 1;
}
