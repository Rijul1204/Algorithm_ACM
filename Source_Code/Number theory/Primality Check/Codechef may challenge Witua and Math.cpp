#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define maxm 1000110
#define ii unsigned long long int
#define inf (1<<29)


int fermat_prime(ii p,int itt);
bool Miller(long long p,int iteration);

/* this function calculates (a*b)%c taking into account that a*b might overflow */
ii mulmod(ii a,ii b,ii c){
    ii x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}


ii big_mod(ii a,ii b,ii c){

    ii x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=mulmod(x,y,c);
            //x=x*y;
            if(x>=c) x%=c;
        }
        y = mulmod(y,y,c);
        //y=y*y; if(y>=c) y%=c;
        b /= (ii)2;
    }
    return x%c;

}


int main(){

	int j,k,l,test,t=1;
	ii i,n;

	//freopen("in.txt","r",stdin);
	//freopen("out1.txt","w",stdout);

	scanf("%d",&test);

	while(test--){

	    scanf("%llu",&n);
	    //printf("%lld\n",n);

	    if((n%(ii)2)==0 && n!=2) n--;
	    for(i=n;i>=0;i-=2){
	        if(Miller(i,4)){
	            printf("%llu\n",i);
	            //printf("gap: %lld\n",n-i);
	            break;
	        }
	        //printf("%lld\n",i);
	    }
	    //if(i==1){
	    //}

	}

	return 0;
}

int fermat_prime(ii p,int itt){

    if(p==1) return 0;

    int i;

    for(i=0;i<=itt;i++){
        ii a = rand()%(p-1)+1;
        if(big_mod(a,p-1,p) != 1){
            return 0;
        }
    }
    return 1;
}

/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=big_mod(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}
