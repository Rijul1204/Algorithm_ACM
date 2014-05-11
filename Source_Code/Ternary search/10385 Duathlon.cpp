#include<stdio.h>

#define maxm 30

double maxi(double a,double b){
	if(a>b) return a;
	return b;
}
double mini(double a,double b){
	if(a<b) return a;
	return b;
}
double rs[maxm],ks[maxm],t;
int n;
double ts();
double f(double a,double b);

int main(){
	
	int i,j,k,l,test;

//	freopen("in.txt","r",stdin);
	
	while(scanf("%lf",&t)==1){
		
		scanf("%d",&n);
	//	if(n<=1) continue;
		for(i=1;i<=n;i++){
			scanf("%lf %lf",&rs[i],&ks[i]);
		}
		
		double ans=ts();
		
		if(f(ans,t-ans)<0){
			printf("The cheater cannot win.\n");
			continue;
		}
		double anssd=f(ans,t-ans);
		anssd*=3600.00;
		int anss=anssd;
		printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n",anssd,ans,t-ans);
	}
	
	return 0;
}

double ts(){

	double min = 0;
	double max = t;
	int c=0;
	while(c<150){
		c++;
		double g = min + (max-min)/(double)3;
		double h = min + (double)2*(max-min)/(double)3;
		if(f(g,t-g) > f(h,t-h))
			max = h;     // or max = h - 1
		else
			min = g;     // or min = g + 1
	}

	return (max+min)/2;   // not always
	
}

double f(double a,double b){
	

	double ret=a/rs[1]+b/ks[1];
	int i;

	for(i=2;i<n;i++){
		ret=mini(a/rs[i]+b/ks[i],ret);
	}
	double ret1=a/rs[n]+b/ks[n];

	return ret-ret1;
}
