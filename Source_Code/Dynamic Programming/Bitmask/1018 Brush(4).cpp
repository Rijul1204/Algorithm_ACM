
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 1<<17
#define eps  1e-7

struct point{
	int x,y;
};

point points[20];

int on(int n,int k){
	return n|(1<<k);
}
int off(int n,int k){
	return n-(n&(1<<k));
}
bool chck(int n,int k){
	return (1<<k)==(n&(1<<k));
}

int dp[maxm],dis[5],n;

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
int mini(int a,int b){
	if(a<b) return a;
	return b;
}
int dist(int a,int b,int c,int d){
	int k,l;
	k=a-c; k*=k; l=b-d; l*=l;
	return k+l;
}
int cal(int num);

int main(){
	
	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d",&n);
		
		for(i=0;i<n;i++){
			scanf("%d %d",&k,&l);
			points[i].x=k; points[i].y=l;
		}
		memset(dp,-1,sizeof(dp));
		
		printf("Case %d: %d\n",t++,cal(0));
		
	}
	
	return 0;
}

int cal(int num){
	
	if(num==(1<<n)-1) return 0;
	
	if(dp[num]!=-1) return dp[num];
	
	int ret,mask,j,k,l,i;
	
	bool fl[20];
	memset(fl,0,sizeof(fl));	
	
	for(i=0;i<n;i++){
		if(!chck(num,i)) break;
	}		
	int pivot=i;	
	mask=on(num,pivot);	
	ret=1+cal(mask);
	
	int x,x1,x2,y,y1,y2;
	x1=points[pivot].x; y1=points[pivot].y;
	
	for(i=pivot+1;i<n;i++){
		if(fl[i]) continue;
		if(!chck(num,i)){
			fl[i]=1;
			mask=on(num,pivot);
			mask=on(mask,i);
			x2=points[i].x; y2=points[i].y;
			for(j=i+1;j<n;j++){
				x=points[j].x; y=points[j].y;
				if((x2-x1)*(y-y1)==(y2-y1)*(x-x1)){
					fl[j]=1;
					mask=on(mask,j);
				}
			}
			ret=mini(ret,cal(mask)+1);
		}
	}
	
	return dp[num]=ret;
	
}

