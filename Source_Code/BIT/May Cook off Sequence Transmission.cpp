/*
Author : Rashedul Hasan Rijul
Algo   : BIT
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

#define maxm 200010

// BIT.......................

#define ii long long int
#define mod 1000000009
#define maxval 262150

struct BIT{

    ii tree[maxval+100];
    ii n;

    void init(int n1){
        n=n1;
        memset(tree,0,sizeof(tree));
    }
    void clear(){
        memset(tree,0,sizeof(tree));
    }

    ii read(int idx){
        ii sum=0;
        while(idx>0){
            sum+=tree[idx];
            idx-=(idx& -idx);
            sum%=mod;
        }
        return sum;
    }
    void update(int idx ,int val){

        while (idx <= n){
            tree[idx] += val;
            tree[idx]%=mod;
            idx += (idx & -idx);
        }
    }
    ii read(int beg,int end){
        ii ret=read(end)-read(beg-1);
        if(ret<0) ret+=mod;
        return ret;
    }
};


// BIT  finish ......

ii poww(int b,int p){
    if(!p) return 1; return b*poww(b,p-1);
}

int n,m,a[maxm],pre_sum[maxm];
ii mod1;
BIT bit;


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&m);
        mod1=poww(2,m);

        ii sum=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i]; sum%=mod1;
            pre_sum[i]=sum;
          //printf("%d ",sum);
        }
        //puts("");

        int valid_low=0,valid_right=poww(2,m-1)-1;
        int vl,vr;

        //printf("%d\n",n);

        bit.init(mod1+2);
        bit.clear();
        bit.update(1,1);

        ii res;

        for(i=1;i<=n;i++){
            vl=pre_sum[i]-valid_right;
            vr=pre_sum[i]; vr%=mod1;
            //printf("%d %d\n",vl,vr);
            if(vl<0){
                res=bit.read(vl+mod1+1,mod1)+bit.read(1,vr+1);
            }
            else{
                res=bit.read(vl+1,vr+1);
            }
            res%=mod;
            bit.update(pre_sum[i]+1,res);
        }

        printf("%lld\n",res);

    }

    return 0;
}
