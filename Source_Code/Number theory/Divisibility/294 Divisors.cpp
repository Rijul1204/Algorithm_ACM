#include<stdio.h>
#include<math.h>




int generatediv(long long int n);

int main(){

	long long int i,j,test,mark,max,l,u,no;

//	generatediv(d);

	scanf("%lld",&test);

	while(test--){

		scanf("%lld %lld",&l,&u);

		mark=l;
		max=generatediv(l);

		for(i=l+1;i<=u;i++){
			no=generatediv(i);
			if(no>max){
				mark=i;
				max=no;
			}
		}

		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,u,mark,max);

	}

	return 0;

}

int generatediv(long long int n){

	long long int j,k,count;
	
		k=sqrt(n);
		count=0;
		for(j=k;j>=1;j--){
			if(n%j==0){
				count+=2;
				if(j*j==n) count--;
			}
		}	
		
		return count;
	

}
		



