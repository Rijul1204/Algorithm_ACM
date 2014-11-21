#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 110


double dp[maxm][15];
bool v[maxm][15];
int n,k;

double cal(int i,int j);

int main(){

	int i,j,l,test,t=1;

   // freopen("in.txt","r",stdin);

	while(scanf("%d %d",&k,&n)==2){
		
		double den=pow(k+1,n);
		memset(v,0,sizeof(v));
		
		double num=0;

		for(i=0;i<=k;i++){
			num+=cal(n,i);
		}

	//	printf("num=%.0lf\n",num);		
		double ans=num/den;
		
	//	ans+=.0000000000001;
		ans*=100.0;
		ans+=.000000001;
		printf("%.5lf\n",ans);

	}

	return 0;
}

double cal(int i,int j){

	if(j<0||j>k) return 0;
	if(i==1) return 1;

	if(v[i][j]) return dp[i][j];
	v[i][j]=1;
	
	dp[i][j]=cal(i-1,j);
	if(j==k) return dp[i][j]+=cal(i-1,j-1);
	else if(j==0) return dp[i][j]+=cal(i-1,j+1);	
	return dp[i][j]+=(cal(i-1,j+1)+cal(i-1,j-1));
}