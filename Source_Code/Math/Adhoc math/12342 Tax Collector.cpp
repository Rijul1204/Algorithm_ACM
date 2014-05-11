#include<stdio.h>
#include<math.h>

double ans,nd;

int main(){
	
	int i,j,k,l,test,t=1,n;
	
//	freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		
		printf("Case %d: ",t++);

		if(n<=180000){
			printf("0\n");
			continue;
		}
		
		ans=0;
		n-=180000;

		if(n<=300000){
			nd=n;
			ans+=(nd*.1);
			if(ans<2000) printf("2000\n");
			else printf("%.0lf\n",ceil(ans));
			continue;
		}

		ans=30000;
		n-=300000;

		if(n<=400000){
			nd=n;
			ans+=(nd*.15);
			if(ans<2000) printf("2000\n");
			else printf("%.0lf\n",ceil(ans));
			continue;
		}
		
		double temp=400000.0;
		ans+=(temp*.15);
		n-=400000;
		if(n<=300000){
			nd=n;
			ans+=(nd*.2);
			if(ans<2000) printf("2000\n");
			else printf("%.0lf\n",ceil(ans));
			continue;
		}
		temp=300000.0;
		ans+=(temp*.2);
		n-=300000;
		
		nd=n;
		ans+=(nd*.25);
		printf("%.0lf\n",ceil(ans));


	}


	return 0;
}