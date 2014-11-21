#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxn 1000100
#define ii long long int

bool p[maxn];
int prime[(maxn/3)],tot,v1[(maxn/3)];
ii a,b,c,d,l;

ii gcd(ii a,ii b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
ii cal(ii l,ii d);
void gen(int n);
void take(int n);

int main(){

    int i,j,k,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    gen(maxn-10);
    take(maxn-10);
   // printf("%d\n",tot);

    while(test--){

        scanf("%lld %lld %lld",&a,&b,&l);
        d=(a*b); d/=(gcd(a,b));
        if(l%d){ printf("Case %d: impossible\n",t++); continue;}

        l/=d;

        printf("Case %d: %lld\n",t++,cal(l,d));

    }

    return 0;
}

ii cal(ii l,ii d){

    int i,j,k,sq;
    double nd=l,sqd;
    sqd=sqrt(nd); sq=sqd;

    ii ret=1;
    for(i=0;prime[i]<=sq;i++){
        if(l%prime[i]==0){
            j=0;
            while(l%prime[i]==0){
                l/=prime[i]; j++;
            }
            while(d%prime[i]==0){
                d/=prime[i]; j++;
            }
            for(k=1;k<=j;k++){
				ret*=(prime[i]);
			}
            nd=l; sqd=sqrt(nd); sq=sqd;
        }
        while(d%prime[i]==0){
            d/=prime[i];
        }
    }

    if(l>1){
		j=1;
		while(d%l==0){
           d/=l; j++;
        }
		for(k=1;k<=j;k++){
			ret*=l;
		}
	}
    return ret;
}

void take(int n){

    int i,j,k,l;
    prime[tot++]=2;
    for(i=3;i<=n;i+=2){
        if(!p[i]) prime[tot++]=i;
    }
}

void gen(int n){

    int i,j,k,l,sq;

    sq=sqrt(n);

    p[0]=p[1]=1;

    for(i=4;i<=n;i+=2) p[i]=1;

    for(i=3;i<=sq;i+=2){
        if(p[i]) continue;
        for(j=i*i;j<=n;j+=(2*i)){
            p[j]=1;
        }
    }
}
