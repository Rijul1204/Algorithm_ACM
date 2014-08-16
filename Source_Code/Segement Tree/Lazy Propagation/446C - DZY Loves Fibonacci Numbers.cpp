/*
Author : Rashedul Hasan Rijul ( Silent_coder ).
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define maxm 300100
#define inf (1<<29)
#define ii __int64
#define mod 1000000009

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,ii>
#define mp  make_pair
#define uu first
#define vv second


ii on(ii n,ii k){ return (n|(1<<k)); }
ii off(ii n,ii k){ return (n-(n&(1<<k))); }
bool chck(ii n,ii k){ return (n&(1<<k)); }

ii mini(ii a,ii b){ if(a<b) return a;  return b;  }
ii maxi(ii a,ii b){ if(a>b) return a;  return b;  }

void fix(int &n){
    if(n>=mod) n%=mod;
}
void fixii(ii &n){
    if(n>=mod) n%=mod;
}

struct seg_tree{
    int a,b,sum; // a,b= first two number of fib series
    bool flag; // lazy prop
};
seg_tree T[4*maxm];

void init(int node,int beg,int end);
void update(int node,int beg,int end,int k,int l,int a,int b);
int query(int node,int beg,int end,int k,int l);

int n,m;
int a[maxm],c1[maxm],c2[maxm],sum_c1[maxm],sum_c2[maxm];

void init_coef(int n);

int find_sum(int a,int b,int upto){
    ii ret=0;

    ret=(ii)((ii)a*(ii)sum_c1[upto]);
    fixii(ret);

    ret+=(ii)((ii)b*(ii)sum_c2[upto]);
    fixii(ret);

    return ret;
}

int find_num(int a,int b,int kth){

    ii ret=0;

    ret=(ii)((ii)a*(ii)c1[kth]);
    fixii(ret);

    ret+=(ii)((ii)b*(ii)c2[kth]);
    fixii(ret);

    return ret;
}


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    init_coef(maxm-10);

    while(scanf("%d %d",&n,&m)==2){

        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }

        init(1,1,n);

        int type,L,R;
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&type,&L,&R);
            if(type==1){
                update(1,1,n,L,R,1,1);
            }
            else{
                printf("%d\n",query(1,1,n,L,R));
            }
        }

    }

    return 0;
}

int query(int node,int beg,int end,int k,int l){

    if(beg==k && end==l){
        return T[node].sum;
    }

    int left,right,mid;

    left=node<<1,right=left+1; mid=beg+end; mid/=2;

    if(T[node].flag){
        int a=T[node].a,b=T[node].b;
        int new_a=find_num(a,b,mid-beg+2);
        int new_b=find_num(a,b,mid-beg+3);

        update(left,beg,mid,beg,mid,a,b);
        update(right,mid+1,end,mid+1,end,new_a,new_b);

        T[node].flag=T[node].a=T[node].b=0;
    }

    if(l<=mid) return query(left,beg,mid,k,l);
    else if(k>mid) return query(right,mid+1,end,k,l);
    else{
        int ret=query(left,beg,mid,k,mid);
        ret+=query(right,mid+1,end,mid+1,l);
        fix(ret);
        return ret;
    }

    return 0;
}

void update(int node,int beg,int end,int k,int l,int a,int b){

    if(beg==end){
        T[node].sum+=a;
        fix(T[node].sum);
        return ;
    }

    if(beg==k && end==l){
        T[node].a+=a;
        T[node].b+=b;
        T[node].sum+=(find_sum(a,b,l-k+1));

        fix(T[node].a); fix(T[node].b);
        fix(T[node].sum);
        T[node].flag=1;
        return ;
    }

    int left,right,mid;

    left=node<<1,right=left+1; mid=beg+end; mid/=2;

    if(T[node].flag){

        int a=T[node].a;
        int b=T[node].b;

        int new_a=find_num(a,b,mid-beg+2);
        int new_b=find_num(a,b,mid-beg+3);

        update(left,beg,mid,beg,mid,a,b);
        update(right,mid+1,end,mid+1,end,new_a,new_b);

        T[node].flag=T[node].a=T[node].b=0;
    }

    if(l<=mid) update(left,beg,mid,k,l,a,b);
    else if(k>mid) update(right,mid+1,end,k,l,a,b);
    else{
        int new_a=find_num(a,b,mid-k+2);
        int new_b=find_num(a,b,mid-k+3);

        update(left,beg,mid,k,mid,a,b);
        update(right,mid+1,end,mid+1,l,new_a,new_b);
    }

    T[node].sum=T[left].sum+T[right].sum;
    fix(T[node].sum);
    T[node].flag=0;
}

void init(int node,int beg,int end){

    if(beg==end){
        T[node].sum=a[beg];
        return ;
    }

    int left,right,mid;

    left=node<<1,right=left+1; mid=beg+end; mid/=2;

    init(left,beg,mid);
    init(right,mid+1,end);

    T[node].sum=T[left].sum+T[right].sum;
    fix(T[node].sum);
    T[node].flag=0;
}

void init_coef(int n){

    c1[1]=c2[2]=1;
    c1[2]=c2[1]=0;

	sum_c1[1]=sum_c1[2]=1;
	sum_c2[1]=0;
	sum_c2[2]=1;

    for(int i=3;i<=n;i++){
        c1[i]=c1[i-1]+c1[i-2];
        c2[i]=c2[i-1]+c2[i-2];

        fix(c1[i]);
        fix(c2[i]);

        sum_c1[i]=sum_c1[i-1]+c1[i];
        sum_c2[i]=sum_c2[i-1]+c2[i];

        fix(sum_c1[i]);
        fix(sum_c2[i]);

     }
}
