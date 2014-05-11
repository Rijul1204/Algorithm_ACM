#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;

#define ii long long int


map<ii,int>num;

ii x,n,ch;
ii power(ii n,ii p)
{
	ii i,j,sum;
	if(p==0)	return 1;
	else
	{
		sum=n;
		for(i=2;i<=p;i++)
		{
			sum*=n;
			if(sum>4294967298||sum<-4294967298) return 0;
		}
		return sum;
	}
}

int main(){

	ii i,j,k,l,ret;
	int t=1,test;
	for(i=-46350;i<=46343;i++){
		for(j=1;j<=32;j++){
			k=i; 
			if(k<i) k*=-1;
			if(k>100&&j>6) break;
			if(k>1000&&j>3) break;
			n=power(i,j);
			if(n==0) break;
			if(num[n]<j) num[n]=j;
		    l=num[n];
		}
	}	

//	freopen("in.txt","r",stdin);
     scanf("%d",&test); 

	 while(test--){
		 
		 scanf("%lld",&x);
		
	//	 if(!x) break;
	//	if(x<0) x*=-1;

		
		int l=num[x];

		double xd=x;
		double kd;
		kd=sqrt(xd);
		k=kd;
		
		if(num[x]==0){
			if(k*k==x) printf("Case %d: 2\n",t++);
			else printf("Case %d: 1\n",t++);
		}
	
		else  printf("Case %d: %d\n",t++,num[x]);
		


	}


	return 0;
}