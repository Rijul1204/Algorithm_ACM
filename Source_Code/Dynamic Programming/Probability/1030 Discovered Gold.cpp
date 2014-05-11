#include<stdio.h>
#include<string.h>

#define eps .0000000001
#define maxm 120

int n;
double dp[maxm],a[maxm];
bool v[maxm];

double cal(int n);

int main(){
	
	int i,j,k,l,test,t=1;
	
	//freopen("in.txt","r",stdin);
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d",&n);
		
		for(i=1;i<=n;i++){
			scanf("%lf",&a[i]);
		}

		memset(v,0,sizeof(v));

		printf("Case %d: %lf\n",t++,cal(1));
		
		
	}
	
	
	return 0;
}

double cal(int i){
	
	if(i>n) return 0;
	if(i==n) return a[i];
	if(v[i]) return dp[i];
	v[i]=1;
	int j;

	if(n-i<6){
		double ret=a[i];
		double k=n-i;
		k=(double) 1.0/k;
		for(j=i+1;j<=n;j++){
			ret+=cal(j)*k;
		}
		ret+=eps;
		return dp[i]=ret;
	}
	
	double ret=a[i];
	double l=(double)1.0/(double)6.0;
	for(j=i+1;j<=i+6;j++){
		ret+=cal(j)*l;
	}
	
	ret+=eps;
	return dp[i]=ret;	
	
}