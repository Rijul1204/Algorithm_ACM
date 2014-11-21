#include<stdio.h>
#include<math.h>

int gcd(int a,int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}


int main(){

	int i,j,k,l,n,c1,c;
	int a[100];
	double pi,n1,n2;

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){

		if(!n) break;

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		
		c=0;c1=0;
		for(i=1;i<n;i++){
			for(j=i+1;j<=n;j++){
				c++;
				if(gcd(a[i],a[j])==1) c1++;
			
			}
		}

		if(c1==0){
			printf("No estimate for this data set.\n");
			continue;
		}

		n1=c1;
		n1=6.0/n1;
		n2=c;
		n2*=n1;
		
		pi=sqrt(n2);

		printf("%.6lf\n",pi);
		

	}


	return 0;

}