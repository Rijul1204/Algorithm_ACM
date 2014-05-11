#include<stdio.h>

#define ii long long int

void gen(int n);

ii humble[5950];
int prime[4]={2,3,5,7};

ii min(ii a,ii b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l,n;

	gen(5843);

	while(scanf("%d",&n)==1){
		if(!n) break;

		if(n%100>10&&n%100<20){
			printf("The %dth humble number is %lld.\n",n,humble[n]);
		}
		else if(n%10==1){
			printf("The %dst humble number is %lld.\n",n,humble[n]);
		}
		else if(n%10==2){
			printf("The %dnd humble number is %lld.\n",n,humble[n]);
		}
		else if(n%10==3){
			printf("The %drd humble number is %lld.\n",n,humble[n]);
		}
		else printf("The %dth humble number is %lld.\n",n,humble[n]);
		


	}

	return 0;

}


void gen(int n){

	int i=1,j=1,k=1,l=1;

	ii mini,max=1,count=2;
	humble[1]=1;
    ii num1,num2,num3,num4;

	while(count<n){
		num1=humble[i]*2;
		num2=humble[j]*3;
		num3=humble[k]*5;
		num4=humble[l]*7;

		mini=min(min(num1,num2),min(num3,num4));


		if(humble[i]*2==mini){
			if(humble[i]*2>max){
				humble[count++]=humble[i]*2;
				max=humble[i]*2;
				i++;
				
			}
			else i++;
		}
		else if(humble[j]*3==mini){
			if(humble[j]*3>max){
				humble[count++]=humble[j]*3;
				max=humble[j]*3;
				j++;
				
			}
			else j++;
		}
		else if(humble[k]*5==mini){
			if(humble[k]*5>max){
				humble[count++]=humble[k]*5;
				max=humble[k]*5;
				k++;
			}
			else k++;
		}
		else if(humble[l]*7==mini){
			if(humble[l]*7>max){
				humble[count++]=humble[l]*7;
				max=humble[l]*7;
				l++;
			}
			else l++;
		}

	}

}





