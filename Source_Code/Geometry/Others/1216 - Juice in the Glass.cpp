#include<stdio.h>
#include<string.h>
#include<math.h>

#define pi acos(-1.0)

double r1,r2,r3,h,p,h1,h2;

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    //printf("%lf\n",pi);

    scanf("%d",&test);

    while(test--){

        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);

        h1=(h*r2)/(r1-r2); h2=p+h1;
        r3=(h2*r2)/h1;
        double ans=(r3*r3*h2)-(r2*r2*h1);
        ans*=pi; ans/=(double)3.0;
        printf("Case %d: %.10lf\n",t++,ans);

    }

    return 0;
}
