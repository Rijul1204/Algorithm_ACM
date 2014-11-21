#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

#define eps (1e-9)
#define iseq(a,b) (fabs(a-b)<eps)
#define inf (1<<28)
#define maxm 60
#define maxn 14
#define maxmm (1<<14)

int on(int n,int k){
    return (n|(1<<k));
}
int off(int n,int k){
    return (n-(n&(1<<k)));
}
bool chck(int n,int k){
    return ((1<<k)==(n&(1<<k)));
}
int n,m,flag[maxm],shop[maxn],p;
double val[maxm],dp[maxn][maxmm],mat[maxm][maxm];
bool vis[maxn][maxmm];
double mini(double a,double b){
    if(a<b) return a; return b;
}
double maxi(double a,double b){
    if(a>b) return a; return b;
}
void floyd(double mat[maxm][maxm]);
double cal(int ind,int mask);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&n,&m);

        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                mat[i][j]=inf;
            }
            mat[i][i]=0;
        }

        double vd;
        for(i=1;i<=m;i++){
            scanf("%d %d %lf",&k,&l,&vd);
            mat[l][k]=mat[k][l]=mini(mat[k][l],vd);
        }
        floyd(mat);

        scanf("%d",&p);
        memset(flag,0,sizeof(flag));

        j=1;
        shop[0]=0;
        for(i=1;i<=p;i++){
            scanf("%d %lf",&k,&vd);
            if(flag[k]==0){
                flag[k]=j; val[j]=vd; shop[j]=k;
                j++;
            }
            else{
                val[flag[k]]+=vd;
            }
        }
        p=j;
        memset(vis,0,sizeof(vis));
        double ans=cal(0,1);
        if(iseq(ans,0.0)){
            printf("Don't leave the house\n");
        }
        else{
            printf("Daniel can save $%.2lf\n",ans+eps);
        }


    }

    return 0;
}

double cal(int ind,int mask){

    if(mask==(1<<p)-1) return (-mat[shop[ind]][0]);

    if(vis[ind][mask]) return dp[ind][mask];
    vis[ind][mask]=1;

    int i,j,k,l;
    double ret,ret1;
    ret=-mat[shop[ind]][0];

    for(i=1;i<p;i++){
        if(chck(mask,i)) continue;
        k=on(mask,i);
        ret1=cal(i,k)+val[i]-mat[shop[ind]][shop[i]];
        ret=maxi(ret,ret1);
    }

    return dp[ind][mask]=ret;
}

void floyd(double mat[maxm][maxm]){

    int i,j,k;

    for(k=0;k<=n;k++){
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                mat[i][j]=mini(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
}
