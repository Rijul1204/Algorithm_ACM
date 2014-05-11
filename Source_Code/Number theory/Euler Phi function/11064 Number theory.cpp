#include<stdio.h>
#include<math.h>


int getdivis(int n);
double geteuler(int n);

int main(){

	int i,j,n;

      
	while(scanf("%d",&n)==1){
        if(n<=1){
			printf("0\n");
			continue;
		}
	    i=geteuler(n);
		j=getdivis(n);
		i=n-(i+j);
		printf("%d\n",i-1);
	}

	return 0;

}

double geteuler(int n){

	double num=n;
	int sq=sqrt(num);
	double result=num;
	double temp;

	if(!(n%2)){
		result*=.5;
		while(n%2==0) n/=2; 
	}
        
	for(int i=3;i<=sq;i+=2){
		if(!(n%i)){
            temp=i;
			result*=((temp-1)/temp);
			while(!(n%i)) n/=i;
		}
	}
	if(n!=1){
		temp=n;
		result*=((temp-1)/temp);
	}

	return result;

}

int getdivis(int n){

	int sq=sqrt(n);
	int c=0;
	int i;
                    
	for(i=2;i<=sq;i++){
		if(n%i==0){ 
			c+=2;
			if((i*i)==n) c--;
		}
	}

	return c;

}







	













