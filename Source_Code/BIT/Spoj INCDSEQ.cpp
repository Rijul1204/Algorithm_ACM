#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

#define maxm 10010
#define maxn 100010

// BIT.......................

#define ii long long int
#define mod 5000000
#define maxval 10005

struct BIT{

    ii tree[maxval+100];
    ii n;

    void init(int n1){
        n=n1;
        memset(tree,0,sizeof(tree));
    }
    void init(){
        n=maxval;
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
        if(!idx){
        //    tree[idx]+=val; idx++;
        }
        while (idx <= n){
            tree[idx] += val;
            tree[idx] += mod;
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

int n,m,a[maxm],b[maxm];
bool fl[maxm];
map<int,int>map1;
BIT bit[54];


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    while(scanf("%d %d",&n,&m)==2){

        for(i=0;i<=m;i++){
            bit[i].init();
        }
        map1.clear();
        memset(fl,0,sizeof(fl));

        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        int now=2;

        map1[b[1]]=now++;
        for(i=2;i<=n;i++){
            if(b[i]==b[i-1]) continue;
            map1[b[i]]=now++;
        }

        int num;
        ii res,res1;
        bit[0].update(1,1);
        for(i=1;i<=n;i++){
            num=map1[a[i]];

            for(j=m;j>=1;j--){
                res=bit[j-1].read(num-1);

                if(fl[num]){
                    res1=bit[j].read(num,num);
                    bit[j].update(num,-res1);
                }

                bit[j].update(num,res);
            }
            fl[num]=1;
        }

        res=bit[m].read(maxval);
        printf("%lld\n",res);

    }

    return 0;
}
