#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define eps 1e-9
#define sq(a) ((a)*(a))
#define dist(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define mini(a,b) a<b ? a:b
#define maxi(a,b) a>b ? a:b
#define maxm 100100
#define iseq(a,b) (fabs(a-b)<eps)

struct point{
	int x,y;
};

int n,nc;
point C[maxm],p[maxm];
double isleft(point p0,point p1,point p2);

template< class T > void swap1(T &a, T &b) { 
	T temp;
	temp=a; a=b; b=temp;
}

bool comp(point a,point b){
    double d = isleft(p[0], a, b);
    if(d<0) return false;
    if(iseq(d,0) && dist(p[0], b) < dist(p[0], a)) return false;
    return true;
}
bool comp1(point a,point b){
	if(a.y==b.y) return a.x<b.y;
	return a.y<b.y;
}
void convex_hull();
int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);
	printf("%d\n",test);

	while(test--){
		
		scanf("%d",&n);
		
		for(i=0;i<n;i++){
			scanf("%d %d",&p[i].x,&p[i].y);
		}
		convex_hull();
		printf("%d\n",nc+1);
		for(i=0;i<nc;i++){
			printf("%d %d\n",C[i].x,C[i].y);
		}
		printf("%d %d\n",C[0].x,C[0].y);
		
		scanf("%d",&n);
		if(test!=0) printf("%d\n",n);

	}

	return 0;
}

void convex_hull(){

	int i,pos = 0;
	for(i=1; i<n; i++)
		if(p[i].y<p[pos].y || (p[i].y==p[pos].y && p[i].x<p[pos].x))
            pos = i;
	swap(p[0], p[pos]);
	sort(p+1, p+n, comp);

	C[0] = p[0];
	if(n>=2)    C[1] = p[1];
	for(i=nc=2; i<n; i++) 
	{
		while(nc>=2 && isleft(C[nc-2], C[nc-1], p[i]) <= 0) nc--;
		C[nc++] = p[i];
	}
	if(n==1)  		nc=1;
	else if(nc==2)  
	{
		if(p[0].x == p[1].x && p[0].y == p[1].y)   nc=1;
	}
	

}
double isleft(point p0,point p1,point p2){
	return (((p1.x-p0.x)*(p2.y-p0.y))-((p1.y-p0.y)*(p2.x-p0.x)));
}