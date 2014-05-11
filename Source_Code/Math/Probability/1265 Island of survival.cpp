#include<stdio.h>
#include<string.h>

#define maxm 1060

double dp[maxm][maxm];
bool vis[maxm][maxm];

double maxi(double a,double b){
	if(a>b) return a;
	return b;
}
double cal(int i,int j); 

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&i,&j);

		printf("Case %d: %lf\n",t++,cal(i,j)+.000000001);

	}

	return 0;

}


double cal(int i,int j){
	
	if(i==0) return 1;
	if(i==1) return 0;
	
	if(vis[i][j]) return dp[i][j];
	vis[i][j]=1;

	double tot=i+j+1; double ret,ret1;
	double deno=(tot*(tot-1))/(double)2.0;
	double prtm=(i);
	double prd=(j*(j-1))/2;
	double prt=(i*(i-1))/2;
	double prdm=(j);
	double prtd=i*j;
	prtm/=deno; prd/=deno; prt/=deno; prdm/=deno; prtd/=deno;

	double sum=prtm+prd+prt+prdm+prtd;
		
	//if deer greater 1;
	if(j>1){
		
		// I will kill
		ret=cal(i,j-1)*prtd+cal(i,j-1)*prdm+cal(i-2,j)*prt;
		ret/=(1-prd);
	
		//i Won't kill
		ret1=cal(i,j-1)*prtd+cal(i-2,j)*prt;
		ret1/=(1-(prd+prdm));

		ret=maxi(ret,ret1);
	}

	else if(j==1){

		// I will kill
		ret=cal(i,j-1)*prtd+cal(i,j-1)*prdm+cal(i-2,j)*prt;
		
		ret1=cal(i,j-1)*prtd+cal(i-2,j)*prt;
		ret1/=(1-prdm);
		
		ret=maxi(ret,ret1);		
	}

	else{
	//	sum=prt+prtm;
	//	printf("%.0lf\n",sum);
		ret=cal(i-2,j)*prt;
	}
	
	return dp[i][j]=ret;
}

