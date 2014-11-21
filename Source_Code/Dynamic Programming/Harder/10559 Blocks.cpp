#include<stdio.h>
#include<string.h>

#define ii int
#define maxm 250



int dp[maxm][maxm][maxm];
bool v[maxm][maxm][maxm];
int a[maxm],n;

int cal(int b,int e,int left);

int main(){

    int i,j,k,l,test,t=1;

// freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(v,0,sizeof(v));
        int ans=cal(1,n,0);
        printf("Case %d: %d\n",t++,ans);
    }

    return 0;
}

int cal(int b,int e,int l){

    if(b>e) return (l*l);
    if(b==e) return ((l+1)*(l+1));

    if(v[b][e][l]) return dp[b][e][l];
    v[b][e][l]=1;

    int ret,ret1,ret2;
    int i;

    ret=cal(b+1,e,0);
    ret+=((l+1)*(l+1));
    for(i=b+1;i<=e;i++){
        if(a[i]==a[b]){
            ret2=cal(b+1,i-1,0);
            ret1=cal(i,e,l+1);
            ret1+=ret2;
            if(ret<ret1){
                ret=ret1;
            }
        }
    }

    return dp[b][e][l]=ret;
}
