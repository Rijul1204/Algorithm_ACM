#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

#define ii int
#define maxm 101010

struct tree{
    int val;
};
tree m[4*maxm];
ii a[maxm],b[maxm],n,d;
int tot,next[maxm],prev[maxm];
map<int,int>num;
ii maxi(ii a,ii b){ if(a>b) return a; return b;}
int cal1(int lo,ii val);
int cal2(int hi,ii val);
void init(int node,int b,int e);
void update(int node,int b,int e,int x,int val);
int query(int node,int b,int e,int x,int y);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    while(scanf("%d %d",&n,&d)==2){

		num.clear();

        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b,b+n);
        num[b[0]]=1; tot=1;
        for(i=1;i<n;i++){
            if(b[i]==b[i-1]) continue;
            num[b[i]]=++tot;
        }
        
        next[1]=cal1(0,b[0]);
        next[1]=num[b[next[1]]];
        prev[1]=1;
        for(i=1;i<n;i++){
            if(b[i]==b[i-1]) continue;
            k=num[b[i]];
            next[k]=cal1(i,b[i]);
            prev[k]=cal2(i,b[i]);
            next[k]=num[b[next[k]]];
            prev[k]=num[b[prev[k]]];
        }
        init(1,1,tot);
        int ans=0;
        for(i=0;i<n;i++){
            k=num[a[i]];
            j=query(1,1,tot,prev[k],k);
			l=query(1,1,tot,k,next[k]);
			l=maxi(j,l);
            update(1,1,tot,k,l+1);
            if(l+1>ans) ans=l+1;
        }
        printf("%d\n",ans);
    }

    return 0;
}
int query(int node,int b,int e,int x,int y){

    if(b==x&&e==y) return m[node].val;

    int left,right,mid,ret;
    left=node<<1; right=left+1; mid=b+e; mid/=2;

    if(y<=mid) return query(left,b,mid,x,y);
    else if(x>mid)return query(right,mid+1,e,x,y);
    return maxi(query(left,b,mid,x,mid),query(right,mid+1,e,mid+1,y));
}
void update(int node,int b,int e,int x,int val){

    if(b==e){
        m[node].val=val; return ;
    }
    int left,right,mid;
    left=node<<1; right=left+1; mid=b+e; mid/=2;

    if(x<=mid) update(left,b,mid,x,val);
    else update(right,mid+1,e,x,val);

    m[node].val=maxi(m[left].val,m[right].val);

}
void init(int node,int b,int e){

    if(b==e){
        m[node].val=0; return ;
    }
    int left,right,mid;
    left=node<<1; right=left+1; mid=b+e; mid/=2;
    init(left,b,mid); init(right,mid+1,e);
    m[node].val=maxi(m[left].val,m[right].val);
}

//cal= prev  number in range
int cal2(int hi,ii val){

    int lo,mid;
    val-=d;
    lo=0;
    if(b[lo]>=val) return lo;

    while(lo<hi){

        mid=lo+hi; mid/=2;

        if(b[mid]<val){
            lo=mid+1;
        }
        else{
            if(hi==mid){
                if(mid>0) if(b[mid-1]>=val) return mid-1;
                return mid;
            }
            hi=mid;
        }

    }
    return hi;
}
//cal= next  number in range
int cal1(int lo,ii val){

    int hi,mid;
    val+=d;
    hi=n-1;
    if(b[hi]<=val) return hi;

    while(lo<hi){

        mid=lo+hi; mid/=2;

        if(b[mid]>val){
            hi=mid-1;
        }
        else{
            if(lo==mid){
                if(mid+1<n) if(b[mid+1]<=val) return mid+1;
                return mid;
            }
            lo=mid;
        }

    }
    return lo;
}
