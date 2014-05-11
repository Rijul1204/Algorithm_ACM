#include<stdio.h>
#include<string.h>

int mini(int a,int b){
    if(a<b) return a;
    return b;
}
int maxi(int a,int b){
    if(a>b) return a;
    return b;
}

int n;

int main(){

    int i,j,k,l,test,t=1;

   // freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        int x1,y1,z1,x2,y2,z2,a,b,c,d,e,f;

        for(i=1;i<=n;i++){
            scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
            if(i==1){
                a=x1; b=y1; c=z1; d=x2; e=y2; f=z2;
            }
            a=maxi(a,x1); b=maxi(b,y1); c=maxi(c,z1);
            d=mini(d,x2); e=mini(e,y2); f=mini(f,z2);
        }
        d-=a; e-=b; f-=c;
        int ans=d*e*f;
        if(ans<0) ans=0;
        printf("Case %d: %d\n",t++,ans);

    }

    return 0;
}
