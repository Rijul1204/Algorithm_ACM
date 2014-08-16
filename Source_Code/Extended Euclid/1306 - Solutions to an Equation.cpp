#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define ii long long int
#define inf (1<<30)

// Extended Euclid .....
struct node{
	ii x,y,g;
	node(){};
	node(ii xx,ii yy,ii gg){ x=xx; y=yy; g=gg;};
};
//  ax+by=g where g=gcd(a,b)....
node euclid(ii a,ii b){
	if(!b) return node(1,0,a);
	node r=euclid(b,a%b);
	return node(r.y,r.x-(a/b)*r.y,r.g);
}
//............//

ii A,B,C,xl,xh,yl,yh;

ii find_lo(ii x0,ii y0,ii ag,ii bg);
int valid_lo(ii x0,ii t,ii bg,ii lo,ii hi);
ii find_hi(ii x0,ii y0,ii ag,ii bg);
int valid_hi(ii x0,ii t,ii bg,ii lo,ii hi);

ii common(ii a,ii b,ii c,ii d){

    if(b<c || d<a) return 0;

    if(a>=c && b<=d) return (b-a+1);
    if(c>=a && d<=b) return (d-c+1);

    if(b>=c && a<=c) return (b-c+1);
    if(a<=d && b>d)  return (d-a+1);

    return 0;
}

ii find_ans(){

    node piv=euclid(A,B);
    if(!piv.g){
        if(C) return 0;
        return (xh-xl+1)*(yh-yl+1);
    }
    if(C%piv.g) return 0;

    ii x0=piv.x,y0=piv.y;
    x0*=(C/piv.g); y0*=(C/piv.g);

    ii ag=A/piv.g,bg=B/piv.g;

    //printf("%d %d\n",x0,y0);

    // x= x0 - t*bg , y= y0 + t*ag;

    ii lo1=find_lo(x0,bg,xl,xh);
    ii lo2=find_lo(y0,-ag,yl,yh);

    ii hi1=find_hi(x0,bg,xl,xh);
    ii hi2=find_hi(y0,-ag,yl,yh);

    return common(lo1,hi1,lo2,hi2);
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%lld %lld %lld %lld %lld %lld %lld",&A,&B,&C,&xl,&xh,&yl,&yh);
        C=-C;
        printf("Case %d: %lld\n",t++,find_ans());

    }

    return 0;
}

ii find_lo(ii x0,ii bg,ii lox,ii hix){

   // x= x0 - t*bg , y= y0 + t*ag;

   ii lo=-inf,hi=inf;
   ii mid;

   while(lo<hi){

       mid=lo+hi; mid/=2;

       if(valid_lo(x0,mid,bg,lox,hix)){
           if(hi==mid){
               if(valid_lo(x0,mid-1,bg,lox,hix)) return mid-1;
               return mid;
           }
           hi=mid;
       }
       else{
           lo=mid+1;
       }

   }
   return hi;
}
ii find_hi(ii x0,ii bg,ii lox,ii hix){

   // x= x0 - t*bg , y= y0 + t*ag;

   ii lo=-inf,hi=inf;
   ii mid;

   while(lo<hi){

       mid=lo+hi; mid/=2;

       if(valid_hi(x0,mid,bg,lox,hix)){
           if(lo==mid){
               if(valid_hi(x0,mid+1,bg,lox,hix)) return mid+1;
               return mid;
           }
           lo=mid;
       }
       else{
           hi=mid-1;
       }

   }
   return lo;
}

int valid_lo(ii x0,ii t,ii bg,ii lo,ii hi){

    // check increasing .....
    if(bg<0){
        if(x0-(t*bg)<lo) return 0;
        return 1;
    }
    else{
        if(x0-(t*bg)>hi) return 0;
        return 1;
    }
}

int valid_hi(ii x0,ii t,ii bg,ii lo,ii hi){

    // check increasing .....
    if(bg<0){
        if(x0-(t*bg)>hi) return 0;
        return 1;
    }
    else{
        if(x0-(t*bg)<lo) return 0;
        return 1;
    }
}
