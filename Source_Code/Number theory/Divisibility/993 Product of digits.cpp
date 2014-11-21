#include<stdio.h>
#include<algorithm>
using namespace std;


int main(){


	int i,n,num,t,test,temp,count,flag;
    int soln[100];
	
	scanf("%d",&test);

	for(t=1;t<=test;t++){
		
		scanf("%d",&num);
		if(num<10){
			printf("%d\n",num);
			continue;
		}

		temp=num;
		count=0;
		flag=1;
		//soln[0]=num;
       
		while(temp>1){

			
			flag=0;
			for(i=9;i>1;i--){
				if(temp%i==0){
					temp/=i;
					soln[count++]=i;
					flag=1;
					break;
				}				
			}

			if(!flag) break;
		}
        
		if(!flag)printf("-1\n",t); 
		else{ 
			
			sort(soln,soln+count);
			for(i=0;i<count-1;i++){
				printf("%d",soln[i]);
			}
			printf("%d\n",soln[count-1]);
		
		}
				

	}

	return 0;

}
