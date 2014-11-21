#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

#define maxm 705

struct point{
    int x,y;
    point(){}
    point(int a,int b){ x=a; y=b; }
};

struct node{
    int dx,dy;
};

int gcd(int a,int b){
    if(!a||!b) return 1;
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int n;
int p1[41000],p2[41000];
node P[maxm*maxm];
point ps[maxm*maxm];
int maxi(int a,int b){
	if(a>b) return a; return b;
}
bool comp(node a,node b){
    if(a.dx==b.dx) return a.dy<b.dy;
    return a.dx<b.dx;
}

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        // p1 and p2 for  number of points  which share  Same X or Y co-ordinate
        memset(p1,0,sizeof(p1)); memset(p2,0,sizeof(p2));
        int ans=1;

		for(i=0;i<n;i++){
            scanf("%d %d",&k,&l);
            ps[i]=point(k,l);
            k+=10000; l+=10000;
			p1[k]++; p2[l]++;
			ans=maxi(ans,p1[k]-1);
			ans=maxi(ans,p2[l]-1);
        }

        if(n==1){
            printf("Case %d: %d\n",t++,1); continue;
        }

        int dx,dy;
        for(i=0;i<n;i++){
            for(j=0,k=0;j<n;j++){
                if(i==j) continue;
                dy=ps[j].y-ps[i].y;
                dx=ps[j].x-ps[i].x;

                if(dy<0||(dy==0&&dx<0)) dx=-dx;
                if(dy<0) dy=-dy;

                int g=gcd(dx,dy); dx/=g; dy/=g;
                P[k].dx=dx; P[k++].dy=dy;
            }
            sort(P,P+k,comp);
            int ans1=1;
            for(j=1;j<k;j++){
				if(P[j].dx==P[j-1].dx&&P[j].dy==P[j-1].dy){
				    ans1++;
				    ans=maxi(ans,ans1);
				}
                else ans1=1;

            }


        }

        printf("Case %d: %d\n",t++,ans+1);

    }

    return 0;
}
