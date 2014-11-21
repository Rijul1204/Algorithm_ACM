#include<stdio.h>
#include<math.h>

#define pi acos(-1.0)
#define inf (1<<28)
#define eps 1e-9
#define area(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define sqr(x) ((x)*(x))
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define spDist(lat1,long1,lat2,long2,r) ( r * acos( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1-long2) ) )
#define isEq(a,b) (fabs(a-b)<eps)

int  on(int n,int k){
	return n | 1<<k;
}

int  off(int n,int k){
	return n - (1<<k);
}

bool check(int n,int k){
	if((n&(1<<k))==(1<<k)) return true;
	return false;
}

double dist[1000][1000];
int x[100],y[100];

int n;
double dp[111000];
int flag[111000];
double call(int mask);
double min(double a,double b){
	if(a<b) return a;
	return b;
}


int main(){

	int i,j,k,l,test,t=1;
	char name[2000];

	//freopen("in.txt","r",stdin);


	while(scanf("%d",&n)==1){
		if(!n) break;
		//memset(dp,-1.0,sizeof(dp));
		for(i=0;i<=75000;i++){
			flag[i]=-1;
		}

			
		
		for(i=0;i<2*n;i++){
			scanf("%s %d %d",&name,&x[i],&y[i]);

		}
		for(i=0;i<2*n;i++){
			for(j=i+1;j<2*n;j++){
				dist[i][j]=(x[i]-x[j])*(x[i]-x[j]);
				dist[i][j]+=(y[i]-y[j])*(y[i]-y[j]);
				dist[i][j]=sqrt(dist[i][j]);
				dist[j][i]=dist[i][j];
			//	printf("%lf\n",dist[i][j]);
			}
		}

		printf("Case %d: %.2lf\n",t++,call(0));
	}

	return 0;
}

double call(int mask){

	int i,j,k,l,mask2;
	double mini;
	bool one=0,found=0;

	
	if(flag[mask]!=-1) return dp[mask];

	for(i=0;i<2*n;i++){
		if(!check(mask,i)){
			if(!one){
				one=1;
				k=i;
				mask2=on(mask,i);
			}
			else{
				mask2=on(mask2,i);
				l=i;
				if(!found) mini=(dist[k][l]+call(mask2));
				else mini=min(dist[k][l]+call(mask2),mini);
				found=1;
				mask2=off(mask2,i);				
			}
		}
	}
	flag[mask]=1;

	if(!found) return dp[mask]=0.0;

	return dp[mask]=mini;

}







