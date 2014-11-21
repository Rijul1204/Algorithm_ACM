#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct point{
    double x,y;
    point(){}
    point(double a,double b){x=a;b=y;}
};

struct line{
    double a,b,c;
    line(){}
    line(point p1,point p2){
        a=p1.y-p2.y;
        b=p2.x-p1.x;
        c=p1.x*p2.y-p2.x*p1.y;
    }
};

#define pi acos(-1.0)
#define eps 1e-7
#define sq(a) ((a)*(a))
#define dist(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
#define maxm 120

double area_poly(point p[],int n){
    double area=0;
    int i,j;
    for(i=0,j=n-1;i<n;j=i++){
        area+=((p[j].x*p[i].y)-(p[i].x*p[j].y));
    }
    return (fabs(area)*.5);
}

point p[maxm],c[maxm];
int n,nc;
double cross(point p0,point p1,point p2){
    return ((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}
bool comp(point a,point b){
    double d=cross(p[0],a,b);
    if(d<0) return false;
    if(iseq(d,0)&&dist(p[0],b)<dist(p[0],a)) return false;
    return true;
}

bool normal(const point &a, const point &b) {   return (iseq(a.x,b.x) ? a.y < b.y : a.x < b.x);}
bool issame(const point &a, const point &b) {   return (iseq(a.x,b.x) && iseq(a.y,b.y));}
void makeUnique(int &np) {  sort(&p[0], &p[np], normal);    np = unique(&p[0], &p[np], issame) - p;}
void convex_hull(point c[],int &n,int &nc);


int main(){

    int i,j,k,l,t=1;

   // freopen("in.txt","r",stdin);

    while(scanf("%d",&n)&&n){

        for(i=0;i<n;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        double area1=area_poly(p,n);
        convex_hull(c,n,nc);
        double area2=area_poly(c,nc);
        double ans=((area2-area1)/area2);
        ans*=100.0;
        printf("Tile #%d\nWasted Space = %.2lf %%\n\n",t++,ans);
    }

    return 0;
}

void convex_hull(point c[],int &n,int &nc){

    int i,pos=0;
    makeUnique(n);
    for(i=0;i<n;i++){
        if((p[i].y<p[pos].y)||(p[i].y==p[pos].y)&&p[i].x<p[pos].x){
            pos=i;
        }
    }
    swap(p[pos],p[0]);
    sort(p+1,p+n,comp);

    c[0]=p[0];
    if(n>=2) c[1]=p[1];
    for(i=nc=2;i<n;i++){
        while(nc>=2&&(cross(c[nc-2],c[nc-1],p[i])<0||iseq(cross(c[nc-2],c[nc-1],p[i]),0))){
            nc--;
        }
        c[nc++]=p[i];
    }
    if(n==1)        nc=1;
    else if(nc==2)
    {
        if(p[0].x == p[1].x && p[0].y == p[1].y)   nc=1;
    }

}
