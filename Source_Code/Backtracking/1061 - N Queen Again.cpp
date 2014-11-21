#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 10
#define inf 1<<28
#define maxn (1<<10)

int on(int n,int k){
    return (n|(1<<k));
}
int off(int n,int k){
    return (n-(n&(1<<k)));
}
bool chck(int n,int k){
    return ((1<<k)==(n&(1<<k)));
}

struct pos{
    int x,y;
    pos(){}
    pos(int a,int b){x=a; y=b;}
};
pos soln[100][maxm],out[maxm],curr[maxm];

int dp[maxn],grid[maxm][maxm],tot;
bool v[maxn];
char s[maxm][maxm];

void back(int col);
void mark(int row,int col,int v);
int cal(int no,int ind,int mask);
int f_cost(pos a,pos b);
int mini(int a,int b){ if(a<b) return a; return b; }

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    // Generate all solution.........
    back(0);

    scanf("%d",&test);

    while(test--){

        for(i=0;i<8;i++) scanf("%s",s[i]);

        int tot=0;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(s[i][j]=='q') curr[tot++]=pos(i,j);
            }
        }

        int ans=inf;
        for(i=0;i<92;i++){
            memset(v,0,sizeof(v));
            ans=mini(ans,cal(i,0,0));
        }
        printf("Case %d: %d\n",t++,ans);
    }


    return 0;

}

int cal(int no,int ind,int mask){

    if(ind==8) return 0;
    if(v[mask]) return dp[mask];
    v[mask]=1;

    int i,j,k,l,ret=inf,ret1;

    for(i=0;i<8;i++){
        if(chck(mask,i)) continue;
        k=on(mask,i);
		j=f_cost(soln[no][ind],curr[i]);
        ret1=cal(no,ind+1,k)+j;
        ret=mini(ret,ret1);
    }
    return dp[mask]=ret;
}

int f_cost(pos a,pos b){

    if(a.x==b.x&&a.y==b.y) return 0;
    if(a.x==b.x||a.y==b.y) return 1;
    if(a.x-a.y==b.x-b.y||a.x+a.y==b.x+b.y) return 1;
    return 2;

}

void back(int col){

    int i;

    if(col==8){
        for(i=0;i<8;i++){
            soln[tot][i]=out[i];
        }
        tot++; return ;
    }

    for(i=0;i<8;i++){
        if(grid[i][col]) continue;
        mark(i,col,1);
        out[col]=pos(i,col);
        back(col+1);
        mark(i,col,-1);
    }

}

void mark(int x,int y,int v){

    int i,j,k,l;

    //  row .>>>
    for(i=0;i<8;i++){
        if(i==x) continue;
        grid[i][y]+=v;
    }
    //  col .>>>
    for(i=0;i<8;i++){
        if(i==y) continue;
        grid[x][i]+=v;
    }
    //diag>>>>>>>
    for(i=0;i<8;i++){
        if(i==x) continue;
        for(j=0;j<8;j++){
            if(j==y) continue;
            if((x-y)==(i-j)) grid[i][j]+=v;
            if((x+y)==(i+j)) grid[i][j]+=v;
        }
    }
    // curr pos
    grid[x][y]+=v;

}
