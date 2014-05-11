#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 60
#define inf 1<<29

#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

double dp[maxm][maxm],d1[maxm],c[maxm],d,cap,mpg,lim;
int n,vis[maxm][maxm];
double mini(double a,double b){
	if(a<b) return a;
	return b;
}
double cal(int ind,int last,double rem);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%lf",&d)==1){

		if(d<0) break;
		scanf("%lf %lf %lf %d",&cap,&mpg,&c[0],&n);
		d1[0]=0;
		lim=2.0;
		lim=cap/lim;
		for(i=1;i<=n;i++){
			scanf("%lf %lf",&d1[i],&c[i]);
		}
		d1[n+1]=d; c[n+1]=inf;
		memset(vis,0,sizeof(vis));
		double ans=cal(1,0,cap-d1[1]/mpg)+c[0]*100;
		int ans2;
		//ans=ans2;
		double ans1=ans/100;
		printf("Data Set #%d\nminimum cost = $%.2lf\n",t++,ans/100);

	}

	return 0;
}

double cal(int ind,int last,double rem){

	if(rem<0) return inf;
	if(d1[ind]>d) return 0;
	if(iseq(d1[ind],d)) return 0;

	if(vis[ind][last]) return dp[ind][last];
	vis[ind][last]=1;
	
	double ret=inf,ret1,req,dis;
	int i,val;
	double val1;
	dis=d1[ind+1]-d1[ind];
	req=dis/mpg;
	if(req>rem){
		req=cap-rem;
		val1=(c[ind]*req)+200;
		val1*=10;
		val=val1;
		if(val%10>=5) val+=10;
		val1=val/10;
		ret=cal(ind+1,ind,cap-dis/mpg)+val1;
	}
	ret=mini(ret,cal(ind+1,last,rem-dis/mpg));
	if(rem>lim){
		return dp[ind][last]=ret;
	}
	req=cap-rem;
	
	val1=(c[ind]*req)+200;
	val1*=10;
	val=val1;
	if(val%10>=5) val+=10;
	val1=val/10;
	
	ret=mini(ret,cal(ind+1,ind,cap-dis/mpg)+val1);

	return dp[ind][last]=ret;

}