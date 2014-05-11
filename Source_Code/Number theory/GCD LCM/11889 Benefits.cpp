#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int gcd(int a,int b);


int main(){

	int i,k,test,a,c,b,g,temp,sq;
	int count;
	int div[61000];


	scanf("%d",&test);

	while(test--){
		count=0;
		scanf("%d %d",&a,&c);
		if(c%a!=0){
			printf("NO SOLUTION\n");
			continue;
		}
		k=c/a;
		if(k==1){
			printf("1\n");
			continue;
		}
		sq=sqrt(c);
		
		for(i=1;i<=sq;i++){
			if(c%i==0){
				div[count++]=i;
				temp=c/i;
				div[count++]=temp;
			}
		}
		sort(div,div+count);
		
		for(i=0;i<count;i++){
				temp=div[i];
				g=gcd(a,temp);
				//printf("g=%d a=%d  temp=%d\n",g,a,temp);
				if(g*k==temp) break;
		}


		printf("%d\n",temp);

	}

	return 0;
}

int gcd(int a,int b){
	
	if(a%b==0) return b;
	
	else return gcd(b,a%b);

}
