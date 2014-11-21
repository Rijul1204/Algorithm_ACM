#include<stdio.h>
#include<string.h>
#include<math.h>

#define pi acos(-1.0)
#define eps (1e-9)

// Convert Radian to Degree..
double conv(double ang){
    return (ang*180.0)/(double) pi;
}

int main(){

    int n,r,R;
    double nd,rd,Rd,num,den,ang;

    scanf("%d %d %d",&n,&R,&r);

    if(R<r){
        printf("NO\n"); return 0;
    }
    if(R==r||n==1){
        if(n>1) printf("NO\n");
        else printf("YES\n");
        return 0;
    }

    num=2*r*r; den=(R-r)*(R-r);

    //printf("%.3lf\n",num);
    //printf("%.3lf\n",den);

    num/=den; num=1.0-num;

    //printf("%.3lf\n",num);

    ang=acos(num);
    ang=conv(ang);

    //printf("%.3lf\n",ang);

    ang=360.0/ang;

    //printf("%lf\n",ang);

    int max1=ang+eps;

    //printf("%d\n",max1);

    if(max1>=n) printf("YES\n");
    else printf("NO\n");

    return 0;
}
