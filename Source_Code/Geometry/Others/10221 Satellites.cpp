#include<stdio.h>
#include<string.h>
#include<math.h>

#define pi 2*acos(0.0)

#define c_r 6440

double d,a;
char s[10];

double conv(double deg){

    double rad= pi;
    rad*=deg;
    rad/=(double)180.0;
    return rad;
}

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    double rad,ang;

    while(scanf("%lf %lf %s",&d,&ang,s)==3){

        while(ang>360) ang-=360;
        if(ang>180) ang=360-ang;

        if(s[0]=='m') ang/=(double)60.0;

        rad=conv(ang);

        double tot=d+c_r;

        double ans1=tot*rad;

        printf("%.6lf ",ans1);

        double sina,sinc;
        sinc=rad;
        sina=pi-rad;
        sina/=(double)2.0;

        tot=2.0*(tot*tot) *(1.0-cos(rad))  ;
        tot=sqrt(tot);

        printf("%.6lf\n",tot);

    }

    return 0;
}
