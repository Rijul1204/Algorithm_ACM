#include<stdio.h>
#include<math.h>

int main(){
	
    int i,j,k,l,n,res,num1,num2,min,temp;
	
	//freopen("in.txt","r",stdin);
	
	while(scanf("%lld",&n)==1){
		
		if(n==0){
			printf("0\n");
			continue;
		}
		
		res=0;
		
		while(n>=1){
			if(n==3){
				n=2;
				res++;
				continue;
			}
			if(n%2){
				n--;
				temp=n/2;
				if(temp%2) n+=2;
			}
			else n/=2;
			res++;
		}
		printf("%lld\n",res);
		
		
		
	}
	
	return 0;
	
}




