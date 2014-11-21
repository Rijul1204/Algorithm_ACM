#include<stdio.h>
#include<string.h>
#include<math.h>

double a,b,c,d,h,s,ans,two=2.0;

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        if(c>a){
            double temp=c; c=a; a=temp;
        }


        s=(a-c)+b+d; s/=two;
        h=s*(s-(a-c))*(s-b)*(s-d);
        h=sqrt(h); h*=two; h/=(a-c);
        ans=h*(a+c); ans/=two;

        printf("Case %d: %.10lf\n",t++,ans);

    }

    return 0;
}
