/*
Author : Rashedul Hasan Rijul
Algo   : Grid Compression
*/
#pragma warning (disable:4786)
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std;

#define maxm 1000
#define ii long long int

struct point{
    int x,y;
    point(){}
    point(int _x,int _y){
        x=_x; y=_y;
    }
};
point s,d;

struct rect{
    point pl,pu;
    rect(){}
    rect(point _pl,point _pu){
        pl=_pl; pu=_pu;
    }
};
rect rects[maxm];

set<int>setx,sety;
set<int>::iterator it;
map<int,int>mapx,mapy;
int totx,toty,map1x[maxm],map1y[maxm];

int tot;
ii   dist[maxm][maxm];
bool grid[maxm][maxm];

void fill(point p1,point p2);

int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};
struct node{
    int x,y;
    ii cost;
};
bool operator<(const node &a,const node &b){
    return a.cost>b.cost;
}

ii dij();
ii cal_cost(int x1,int y1,int x2,int y2){

    int ret=0,ret1;

    ret1=map1x[x1]-map1x[x2];
    if(ret1<0) ret1=-ret1;
    ret+=ret1;

    ret1=map1y[y1]-map1y[y2];
    if(ret1<0) ret1=-ret1;
    ret+=ret1;

    return ret;
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        setx.clear();  sety.clear();
        mapx.clear();  mapy.clear();
        tot=totx=toty=1;

        memset(grid,0,sizeof(grid));
        memset(dist,-1,sizeof(dist));

        point p1,p2;
        int x,y;
        scanf("%d %d",&x,&y);
        setx.insert(x); sety.insert(y);
        setx.insert(x-1); sety.insert(y-1);
        setx.insert(x+1); sety.insert(y+1);
        s=point(x,y);

        scanf("%d %d",&x,&y);
        setx.insert(x); sety.insert(y);
        setx.insert(x-1); sety.insert(y-1);
        setx.insert(x+1); sety.insert(y+1);
        d=point(x,y);

        int qp,ql,qr;
        scanf("%d %d %d",&qp,&ql,&qr);

        for(i=1;i<=qp;i++){
            scanf("%d %d",&p1.x,&p1.y);
            setx.insert(p1.x); sety.insert(p1.y);
            setx.insert(p1.x-1); sety.insert(p1.y-1);
            setx.insert(p1.x+1); sety.insert(p1.y+1);

            rects[tot++]=rect(p1,p1);
        }
        for(i=1;i<=ql;i++){
            scanf("%d %d",&p1.x,&p1.y);
            setx.insert(p1.x); sety.insert(p1.y);
            setx.insert(p1.x-1); sety.insert(p1.y-1);
            setx.insert(p1.x+1); sety.insert(p1.y+1);

            scanf("%d %d",&p2.x,&p2.y);
            setx.insert(p2.x); sety.insert(p2.y);
            setx.insert(p2.x-1); sety.insert(p2.y-1);
            setx.insert(p2.x+1); sety.insert(p2.y+1);

            if(p1.x>p2.x) swap(p1,p2);
            if(p1.y>p2.y) swap(p1,p2);

            rects[tot++]=rect(p1,p2);
        }
        for(i=1;i<=qr;i++){
            scanf("%d %d",&p1.x,&p1.y);
            setx.insert(p1.x); sety.insert(p1.y);
            setx.insert(p1.x-1); sety.insert(p1.y-1);
            setx.insert(p1.x+1); sety.insert(p1.y+1);

            scanf("%d %d",&p2.x,&p2.y);
            setx.insert(p2.x); sety.insert(p2.y);
            setx.insert(p2.x-1); sety.insert(p2.y-1);
            setx.insert(p2.x+1); sety.insert(p2.y+1);

            if(p1.x>p2.x) swap(p1,p2);
            if(p1.y>p2.y) swap(p1,p2);

            rects[tot++]=rect(p1,p2);
        }

        for(it=setx.begin();it!=setx.end();it++){
            if((*it)<-1000000000) continue;
            if((*it)> 1000000000) continue;
            mapx[*it]=totx;
            map1x[totx++]=*it;
        }
        for(it=sety.begin();it!=sety.end();it++){
            if((*it)<-1000000000) continue;
            if((*it)> 1000000000) continue;
            mapy[*it]=toty;
            map1y[toty++]=*it;
        }

        for(i=1;i<tot;i++){
            fill(rects[i].pl,rects[i].pu);
        }

        ii ans=dij();

        printf("Case %d: ",t++);
        if(ans==-1) printf("Impossible\n");
		else printf("%lld\n",ans);

    }

    return 0;
}

ii dij(){

    int i,j,k,l,reqx,reqy;
    reqx=mapx[d.x]; reqy=mapy[d.y];

    node temp,temp1;
    temp.x=mapx[s.x],temp.y=mapy[s.y]; temp.cost=0;
    dist[temp.x][temp.y]=0;

    priority_queue<node>pq;
    pq.push(temp);

    while(!pq.empty()){

        temp=pq.top(); pq.pop();

        if(temp.x==reqx && temp.y==reqy){
            return temp.cost;
        }

        for(int i1=0;i1<4;i1++){
            i=temp.x+dirx[i1]; j=temp.y+diry[i1];
            if(i<1 || j<1 || i>=totx || j>=toty) continue;
            if(grid[i][j]) continue;
            int cost=cal_cost(temp.x,temp.y,i,j);
            if(dist[i][j]==-1 || dist[i][j]>cost+temp.cost){
                dist[i][j]=cost+temp.cost;
                temp1.x=i,temp1.y=j,temp1.cost=dist[i][j];
                pq.push(temp1);
            }
        }

    }

    return -1;

}


void fill(point p1,point p2){

    int i,j;

    int x1=mapx[p1.x],y1=mapy[p1.y];
    int x2=mapx[p2.x],y2=mapy[p2.y];

    for(i=x1;i<=x2;i++){
        for(j=y1;j<=y2;j++){
            grid[i][j]=1;
        }
    }

}
