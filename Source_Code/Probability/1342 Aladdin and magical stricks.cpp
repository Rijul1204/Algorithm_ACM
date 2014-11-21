#include<stdio.h>
#include<string.h>

#define maxm 5100

double avga,avgb;
double dp1[maxm],dp2[maxm];
int n,n1,n2;

int main(){
	
	int i,j,k,l,test,t=1,i1,j1;
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		
		scanf("%d",&n);
		double sum1,sum2,k1,l1;
		sum1=sum2=k1=l1=0;
		
		for(i=1;i<=n;i++){
			scanf("%d %d",&k,&l);
			if(l==1){
				sum1=sum1+k;
				k1++;
			}
			else {
				sum2=sum2+k;
				l1++;
			}
		}
		n1=k=k1; n2=l=l1;
		if(k1!=0) avga=sum1/k1; if(l1!=0) avgb=sum2/l1;
		
		
				
		dp1[0]=dp2[0]=0;
		double ret,ret1,pr1,pr2,pr3,ans=0;
		int i1,j1;
		
		for(i=1,j=0;i<=k;i++){
			pr1=(double) i/(double)(i+n2);
			ret=pr1*(avga+dp2[i-1]);
			pr2=(double) j/(double)(i+n2);
			pr3=(double) (n2-j)/(double)(i+n2);
			ret1=ret+avgb*pr3;
			ret1=ret1/(double)(1-pr3);
			ans=ret1;
			dp2[i]=ret1;		
		}
		
		for(i=0,j=1;j<=l;j++){
			pr1=(double) i/(double)(i+n2);
			pr2=(double) j/(double)(i+n2);
			pr3=(double) (n2-j)/(double)(i+n2);
			ret=0;			
			ret1=ret+(avgb+dp1[j-1])*pr2+avgb*pr3;
			ret1=ret1/(double)(1-pr3);		
			dp1[j]=ret1;
			ans=ret1;
		}
		
		for(i=1;i<=k;i++){			
			pr1=(double) i/(double)(i+n2);
			for(j=1;j<=l;j++){
		//		ret=pr1*(avga+dp[i-1][j]);
				ret=pr1*(avga+dp1[j]);
				pr2=(double) j/(double)(i+n2);
				pr3=(double) (n2-j)/(double)(i+n2);
			//  ret1=ret+(avgb+dp[i][j-1])*pr2+avgb*pr3;
				ret1=ret+(avgb+dp2[i])*pr2+avgb*pr3;
				ret1=ret1/(double)(1-pr3);
				//dp[i][j]=ret1;
				dp2[i]=ret1;
				dp1[j]=ret1;
				ans=ret1;
			}
		}
		printf("Case %d: %lf\n",t++,ans);
		
		
		
	}
	
	return 0;
}

