#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

#define maxm 9
#define maxn (1<<9)
#define inf (1<<28)

int on(int n,int k){
    return (n|(1<<k));
}
int off(int n,int k){
    return (n-(n&(1<<k)));
}
bool chck(int n,int k){
    return (1<<k)==(n&(1<<k));
}

struct node{
    int mask1,mask2,mask3,cost;
};

int a[]={1,2,2,1,2,2,1,2,2};
int dp[maxm][maxn],req,r,c;
bool vis[maxm][maxn];
char s[maxm][maxm];
int masks[maxm];

int mini(int a,int b){ if(a<b) return a; return b; }
int cal(int ind,int mask1,int mask2,int val);
node update(int mask1,int mask2,int mask3,int val);
void upd(int *mask,int ind);
void init();

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%d %d",&r,&c);

        memset(masks,0,sizeof(masks));
        memset(vis,0,sizeof(vis));

        req=(1<<c)-1;

        for(i=0;i<r;i++){
            scanf("%s",s[i]);
            for(j=c-1,k=0;j>=0;j--,k++){
                if(s[i][j]=='*') masks[i]=on(masks[i],k);
            }
        }

        node temp;
        int ans=inf;
        for(i=0;i<=req;i++){
            temp=update(0,masks[0],masks[1],i);
            ans=mini(ans,cal(1,temp.mask2,temp.mask3,i)+temp.cost);
        }

        if(ans==inf)    printf("Case %d: impossible\n",t++);
        else            printf("Case %d: %d\n",t++,ans);

    }

    return 0;
}

int cal(int ind,int mask1,int mask2,int val){


    if(ind>=r&&mask1==req) return 0;
    if(ind>=r) return inf;

    int piv;
    if(a[ind]==1) piv=mask1; else piv=val;

    if(vis[ind][piv]) return dp[ind][piv];
    vis[ind][piv]=1;




    int i,j,k,l;
    int ret=inf,ret1;
    node temp;

    for(i=0;i<(1<<c);i++){
        temp=update(mask1,mask2,masks[ind+1],i);
        if(temp.mask1==req){
            //if(ind==2) printf(" Inside  %d => %d %d %d %d\n",ind,mask1,mask2,temp.mask3,i);
            ret1=cal(ind+1,temp.mask2,temp.mask3,i)+temp.cost;
        }
        else continue;
        if(ret1<ret) ret=ret1;
    }

    return dp[ind][piv]=ret;

}

node update(int mask1,int mask2,int mask3,int val){

    int i,j,k,l;
    node ret;

    ret.cost=0;
    for(i=0;i<c;i++){
        if(chck(val,i)){
            ret.cost++;
            upd(&mask1,i-1);
            upd(&mask1,i);
            upd(&mask1,i+1);

            upd(&mask2,i-1);
            upd(&mask2,i);
            upd(&mask2,i+1);

            upd(&mask3,i-1);
            upd(&mask3,i);
            upd(&mask3,i+1);
        }
    }

    ret.mask1=mask1; ret.mask2=mask2; ret.mask3=mask3;

	return ret;

}

void upd(int *mask,int ind){

	if(ind<0||ind>=c) return ;

    if(chck((*mask),ind)) (*mask)=off((*mask),ind);
    else (*mask)=on((*mask),ind);

}
