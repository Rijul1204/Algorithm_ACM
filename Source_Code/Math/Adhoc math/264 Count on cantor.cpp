#include<stdio.h>

#define maxm 10000110

int num[maxm+10],den[maxm+10],n;

int main(){

	int i,j,k,l;

	k=1;
	int flag=0;

	for(i=1;k<=10000000;i++){
		for(j=1;j<=i;j++){
			if(k>10000000) break;
			if(flag){
				num[k]=j;
	    		den[k]=i-j+1;
		    	k++;
			}
			if(!flag){
			    den[k]=j;
	        	num[k]=i-j+1;
		    	k++;		
			}
		}
		flag=!flag;
	}

	while(scanf("%d",&n)==1){

		printf("TERM %d IS %d/%d\n",n,num[n],den[n]);
	}

	return 0;
}