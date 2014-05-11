#include<stdio.h>
#include<string.h>
#include<math.h>

#define pi (2 * acos (0.0))

double r,area1,area2;

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%lf",&r);
        area1=pi*r*r;
        area2=2.0; area2*=r; area2*=area2;
        double ans=area2-area1;
        printf("Case %d: %.2lf\n",t++,ans);
    }

    return 0;
}
