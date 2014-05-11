#include<stdio.h>
#include<math.h>
#include<string.h>

#define maxm 10111100
#define ii long long int

bool p[1000000+100],segment[maxm];

void gen(int n){

    int i,j,k,l,sq;
    sq=sqrt(n);
    p[0]=1; p[1]=1;
    for(i=4;i<=n;i+=2) p[i]=1;

    for(i=3;i<=sq;i+=2){
        if(p[i]) continue;
        for(j=i*i;j<=n;j+=(2*i)){
            p[j]=1;
        }
    }
}
int maxi(int a,int b){
    if(a>b) return a;
    return b;
}
int f(int l,int i){
    if(l%i==0) return maxi(l,i*i);
    return maxi(l+(i-(l%i)),i*i);
}

int main(){

    int i,j,k,l,test,t=1,h;

    freopen("in.txt","r",stdin);
    gen(1000000);
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&l,&h);
        memset(segment,0,sizeof(segment));
        if(l==1) segment[0]=1;
        int sq=sqrt(h);
        for(i=2;i<=sq;i++){
            if(p[i]) continue;
            for(j=f(l,i);j>=l&&j<=h;j+=i){
                segment[j-l]=1;
            }
        }

        int ans=0;
        ii i1;
        for(i1=l;i1<=h;i1++){
            if(!segment[i1-l]) ans++;
        }
        printf("Case %d: %d\n",t++,ans);


    }



}
