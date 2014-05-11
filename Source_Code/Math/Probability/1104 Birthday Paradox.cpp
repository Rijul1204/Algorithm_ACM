#include<stdio.h>



int main(){

	int i,j,k,l,test,t=1,n;

//	freopen("in.txt","r",stdin);

	
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		if(n<=2){
			printf("Case %d: %d\n",t++,1);
			continue;
		}

		double ans=0;
		double kd=n-1,kdn=n;		
		ans=kd/kdn;		
		for(i=2,j=n-2;;j--){
			if(ans>.5){
				kd=j;
				kd/=kdn;
				ans*=kd;
				if(ans>.5) i++;
				else break;
			}
			else break;
		}
		printf("Case %d: %d\n",t++,i);

	}
	
	return 0;
}
