#include<stdio.h>
#include<string.h>
#include<math.h>

#define ii long long int

int n,r,p,q,a[4];
int cal(int n,int val);
void cal1(int n);
ii mini(ii a,ii b){if(a<b) return a; return b;}

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d %d %d",&n,&r,&p,&q);

        ii two,five;
        two=cal(n,2); two-=cal(r,2); two-=cal(n-r,2);
        five=cal(n,5); five-=cal(r,5); five-=cal(n-r,5);
        cal1(p);
        two+=(a[0]*q); five+=(a[1]*q);
        printf("Case %d: %lld\n",t++,mini(two,five));


    }

    return 0;
}

void cal1(int n){

    int i;
    a[0]=a[1]=0;
    if(n%2==0){
        while(n%2==0){
            n/=2; a[0]++;
        }
    }
    if(n%3==0){
        while(n%3==0){
            n/=3;
        }
    }
    if(n%5==0){
        while(n%5==0){
            n/=5; a[1]++;
        }
    }

}

int cal(int n,int val){

    int ret=0;

    while(n){
        ret+=(n/val);
        n/=val;
    }
    return ret;

}
