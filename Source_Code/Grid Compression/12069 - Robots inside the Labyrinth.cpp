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

#define maxm 350
#define ii int

struct point{
    int x,y;
    point(){}
    point(int _x,int _y){
        x=_x; y=_y;
    }
};
point s[maxm],d[maxm];

struct rect{
    point pl,pu;
    rect(){}
    rect(point _pl,point _pu){
        pl=_pl; pu=_pu;
    }
};
rect rects[maxm];

set<int>::iterator it;
int totx,toty;

int tot;
int  dist[maxm][maxm][5];
int  fl[maxm][maxm][5],kas=1;
bool grid[maxm][maxm];

void fill(point p1,point p2);

int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};
struct node{
    int x,y,dir;
    ii cost;
};
bool operator<(const node &a,const node &b){
    return a.cost>b.cost;
}

ii dij(point s,point d);

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);
    while(test--){


        set<int>setx,sety;
        map<int,int>mapx,mapy;
        tot=totx=toty=1;
        memset(grid,0,sizeof(grid));

        int q,qr,x,y;
        point p1,p2;
        scanf("%d",&qr);

        for(i=1;i<=qr;i++){
            scanf("%d %d",&p1.x,&p1.y);
            setx.insert(p1.x); sety.insert(p1.y);
            //setx.insert(p1.x-1); sety.insert(p1.y-1);
            //setx.insert(p1.x+1); sety.insert(p1.y+1);

            scanf("%d %d",&p2.x,&p2.y);
            setx.insert(p2.x); sety.insert(p2.y);
            //setx.insert(p2.x-1); sety.insert(p2.y-1);
            //setx.insert(p2.x+1); sety.insert(p2.y+1);

            if(p1.x>p2.x) swap(p1,p2);
            if(p1.y>p2.y) swap(p1,p2);

            rects[tot++]=rect(p1,p2);
        }

		scanf("%d",&q);

        for(i=1;i<=q;i++){
            scanf("%d %d",&x,&y);
            setx.insert(x); sety.insert(y);
            //setx.insert(x-1); sety.insert(y-1);
            //setx.insert(x+1); sety.insert(y+1);
            s[i]=point(x,y);

            scanf("%d %d",&x,&y);
            setx.insert(x); sety.insert(y);
            //setx.insert(x-1); sety.insert(y-1);
            //setx.insert(x+1); sety.insert(y+1);
            d[i]=point(x,y);
        }

        totx=0,toty=0;
        for(it=setx.begin();it!=setx.end();it++){
            totx+=2;
            mapx[*it]=totx;
            //map1x[totx]=*it;
        }
        for(it=sety.begin();it!=sety.end();it++){
            toty+=2;
            mapy[*it]=toty;
            //map1y[toty]=*it;
        }
        totx++,toty++;

        for(i=1;i<tot;i++){
            p1=point(mapx[rects[i].pl.x],mapy[rects[i].pl.y]);
            p2=point(mapx[rects[i].pu.x],mapy[rects[i].pu.y]);
            fill(p1,p2);
        }


        printf("Labyrinth #%d\n",t++);
        for(i=1;i<=q;i++){
            p1=point(mapx[s[i].x],mapy[s[i].y]);
            p2=point(mapx[d[i].x],mapy[d[i].y]);
            ii ans=dij(p1,p2);
            if(ans==-1) printf("Impossible.\n");
            else printf("%d\n",ans);
            kas++;
        }

    }

    return 0;
}

ii dij(point s,point d){

    int i,j,k,l,reqx,reqy;
    node temp,temp1;

    reqx=d.x; reqy=d.y;

	queue<node>pq;

    for(i=0;i<4;i++){
        temp.x=s.x,temp.y=s.y; temp.dir=i; temp.cost=0;
        dist[temp.x][temp.y][temp.dir]=0;
		fl[temp.x][temp.y][temp.dir]=kas;
		pq.push(temp);
    }
    ii ret=-1;

    while(!pq.empty()){

        temp=pq.front(); pq.pop();

        if(temp.x==reqx && temp.y==reqy){
            if(ret==-1 || temp.cost<ret){
				ret=temp.cost;
			}
            continue;
        }

        for(int i1=0;i1<4;i1++){
            i=temp.x+dirx[i1]; j=temp.y+diry[i1];
            if(i<=0 || j<=0 || i>totx || j>toty) continue;
            if(grid[i][j]) continue;
            int cost=0;
            if(i1!=temp.dir) cost=1;
            if(fl[i][j][i1]!=kas || dist[i][j][i1]>cost+dist[temp.x][temp.y][temp.dir]){
                fl[i][j][i1]=kas;
                dist[i][j][i1]=cost+dist[temp.x][temp.y][temp.dir];
                temp1.x=i,temp1.y=j,temp1.cost=dist[i][j][i1]; temp1.dir=i1;
                pq.push(temp1);
            }
        }

    }

    return ret;

}


void fill(point p1,point p2){

    int i,j;

    int x1=p1.x,y1=p1.y;
    int x2=p2.x,y2=p2.y;

    for(i=x1;i<=x2;i++){
        for(j=y1;j<=y2;j++){
            grid[i][j]=1;
        }
    }

}
