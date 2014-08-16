#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 100
#define ii long long int
#define inf (1LL<<40LL)

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

ii mini(ii a,ii b){ if(a<b) return a; return b; }
ii maxi(ii a,ii b){ if(a>b) return a; return b; }

ii n,c1,c2,n1,n2;

ii find_lo(ii x0,ii y0,ii ag,ii bg);
int valid_lo(ii x0,ii t,ii bg,ii lo,ii hi);
ii find_hi(ii x0,ii y0,ii ag,ii bg);
int valid_hi(ii x0,ii t,ii bg,ii lo,ii hi);

void find_ans(){

    node piv=euclid(n1,n2);
    if(n%piv.g){
        puts("failed");
        return ;
    }

    ii x0=piv.x,y0=piv.y;
    x0*=(n/piv.g); y0*=(n/piv.g);
    //printf("%d %d\n",x0,y0);


    // x= x0 - t*bg , y= y0 + t*ag;
    ii ag=n1/piv.g,bg=n2/piv.g;

    ii lo1=find_lo(x0,bg,0,n);
    ii lo2=find_lo(y0,-ag,0,n);

    ii hi1=find_hi(x0,bg,0,n);
    ii hi2=find_hi(y0,-ag,0,n);

    lo1=maxi(lo1,lo2);
    hi1=mini(hi1,hi2);

    if(lo1>hi1){
        puts("failed");
        return ;
    }

    ii x1,y1,x2,y2,cc1,cc2;
    x1=x0-lo1*bg; y1=y0 + lo1*ag;
    cc1=x1*c1+y1*c2;

    x2=x0-hi1*bg; y2=y0 + hi1*ag;
    cc2=x2*c1+y2*c2;

    if(cc1<cc2){
        printf("%lld %lld\n",x1,y1);
    }
    else{
        printf("%lld %lld\n",x2,y2);
    }
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    while(scanf("%lld",&n)==1){

        if(!n) break;

        scanf("%lld %lld %lld %lld",&c1,&n1,&c2,&n2);

        find_ans();
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
