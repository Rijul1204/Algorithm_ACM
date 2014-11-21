#include<stdio.h>
#include<string.h>
#include<math.h>

#define sq(a) ((a)*(a))

struct point{
    double x,y,z;
    point(){}
    point(double a,double b,double c){ x=a; y=b; z=c; }
};
point p[5];


double dist(point p1,point p2){
    return (sq(p1.x-p2.x)+sq(p1.y-p2.y)+sq(p1.z-p2.z));
}
double ts();
// func =  x= xo + t(x1-xo);
double func(double t);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        double a,b,c;
        for(i=1;i<=3;i++){
            scanf("%lf %lf %lf",&a,&b,&c);
            p[i]=point(a,b,c);
        }
        printf("Case %d: %lf\n",t++,sqrt(ts()));

    }

    return 0;
}

double ts(){

    double min1=0,max1=1,f,g,val1,val2;
    int c=100;

    while(c--){

        f=min1+(max1-min1)/(double) 3.0;
        g=min1+(double) 2.0 * ((max1-min1)/(double)3.0);
        val1=func(f); val2=func(g);
        if(val1<val2){
            max1=g;
        }
        else{
            min1=f;
        }

    }

    f=(min1+max1)/(double) 2.0;
    return func(f);
}

double func(double t){

    point pp;

    pp.x=p[1].x+(p[2].x-p[1].x)*t;
    pp.y=p[1].y+(p[2].y-p[1].y)*t;
    pp.z=p[1].z+(p[2].z-p[1].z)*t;

    return dist(pp,p[3]);
}
