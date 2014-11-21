#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define maxm 60
#define maxn (1<<16)
#define ii long long int

ii val[3][maxn],w,c[maxm];
int n,tot[3],n1,n2;

void gen(int ind,int i,ii v);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %lld",&n,&w);
        for(i=1;i<=n;i++){
            scanf("%lld",&c[i]);
        }

        n1=n/2; tot[0]=tot[1]=0;

        gen(0,1,0);     gen(1,n1+1,0);

        sort(val[1],val[1]+tot[1]);

        ii req,ans=0,pos;
        for(i=0;i<tot[0];i++){
            req=w-val[0][i]; if(req<0) break;
            pos=upper_bound(val[1],val[1]+tot[1],req)-val[1];
            ans+=(pos);
        }
        printf("Case %d: %lld\n",t++,ans);

    }

    return 0;
}

void gen(int ind,int i,ii v){

    if(v>w) return;
    if(ind==0&&i>n1){
        val[ind][tot[ind]++]=v;
        return;
    }
    if(ind==1&&i>n){
        val[ind][tot[ind]++]=v;
        return;
    }

    gen(ind,i+1,v);
    gen(ind,i+1,v+c[i]);

}
