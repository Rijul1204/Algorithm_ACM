#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 10010
//#define ii __int64
#define ii long long int
#define lim 10000

ii val[maxm],a[maxm],val1[maxm];
int n;

ii ncr(ii n,ii r);
void assign();
ii cal();

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out1.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        memset(val,0,sizeof(val));

        scanf("%d",&n);

        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        assign();

        for(i=1;i<=lim;i++){
            val1[i]=ncr(val[i],4);
        }

        printf("Case %d: %lld\n",t++,cal());

    }

    return 0;
}

ii cal(){

    int i,j,k,sq;
    ii curr;

    for(i=lim;i>1;i--){
        sq=sqrt(i);
        curr=val1[i];
        for(j=1;j<=sq;j++){
            if(i%j==0){
                k=i/j;
                val1[j]-=curr;
                if(k!=j) val1[k]-=curr;
            }
        }
    }

    return val1[1];

}

void assign(){

    int i,j,k,l,sq;

    for(i=1;i<=n;i++){
        sq=sqrt(a[i]);
        for(j=1;j<=sq;j++){
            if((a[i]%j)==0){
                k=a[i]/j;
                val[j]++;
                if(j!=k) val[k]++;
            }
        }
    }

}

ii ncr(ii n,ii r){

    if(n<r) return 0;

    ii ans=1; ii i;

    for(i=0;i<(r);i++){
        ans*=(ii)(n-i);
    }
    for(i=2;i<=r;i++){
        ans/=(ii)i;
    }

    return ans;


}
