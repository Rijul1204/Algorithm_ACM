#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define inf 1<<28

struct node{
    int c,ind; double v;
};
node nodes[60];
int d,m,n,pre[25][55][105][2];
double dp[25][55][105][2];
bool v[25][55][105][2];

bool comp(node a,node b){
    if(a.c==b.c) return a.v>b.v;
    return a.c<b.c;
}
double cal(int day,int last,int cost,int tt);
void print(int day,int last,int cost,int tt);

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);

    while(scanf("%d %d %d",&d,&n,&m)==3){

		if(!n&&!m&&!d) break;

        for(i=1;i<=n;i++){
            scanf("%d %lf",&nodes[i].c,&nodes[i].v);
            nodes[i].ind=i;
        }
        sort(nodes+1,nodes+1+n,comp);

        memset(v,0,sizeof(v));
        double ans=cal(d,0,0,0);
        if(ans<0){
           ans=0;
           printf("%.1lf\n",ans);
           continue;
        }
        printf("%.1lf\n",ans);
        print(d,0,0,0);
    }

    return 0;
}
void print(int day,int last,int cost,int tt){

   if(day==0) return ;
   int i=pre[day][last][cost][tt];
   printf("%d ",nodes[i].ind);
   if(i==last){
      if(tt==0) print(day-1,i,cost+nodes[i].c,1);
      else print(day-1,i,cost+nodes[i].c,1);
   }
   else{
      print(day-1,i,cost+nodes[i].c,0);
   }

}

double cal(int day,int last,int cost,int tt){

	if(cost>m) return -inf;
    if(day==0) return 0;

    if(v[day][last][cost][tt]) return dp[day][last][cost][tt];
    v[day][last][cost][tt]=1;
    double ret=-inf,ret1; int i;

    for(i=1;i<=n;i++){
        if(i==last){
            if(tt==0) ret1=cal(day-1,i,cost+nodes[i].c,1)+(.5*nodes[i].v);
            else ret1=cal(day-1,i,cost+nodes[i].c,1);
        }
        else{
            ret1=cal(day-1,i,cost+nodes[i].c,0)+nodes[i].v;
        }
        if(ret1>ret){
            ret=ret1;
            pre[day][last][cost][tt]=i;
        }
    }
    return dp[day][last][cost][tt]=ret;
}
