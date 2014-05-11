#include<stdio.h>
#include<math.h>

int a[1000][1000];

int main(){

	int i,j,k,l,n,start,end,sum,t=1;

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&n)&&n){
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
			}
		}
          start=1;
		 
		  end=n;          
		  double val=ceil((double)n/2.0);
		  int valn=val;

		  printf("Case %d:",t++);
		
		 for(k=1;k<=valn;k++){
			 
			 //printf("%d\n",k);
			
			sum=0;
			for(i=start;i<=end;i++){
				sum+=a[start][i];// printf("%d ->",a[start][i]);
			}
			for(i=start;i<=end;i++){
				sum+=a[end][i];
			}
			for(i=start+1;i<end;i++){
				sum+=a[i][start];
			}
			for(i=start+1;i<end;i++){
				sum+=a[i][end];
			}

			start++;
			end--;
			
			if(k==valn&&n%2) sum/=2;
			printf(" %d",sum);

		}
		 printf("\n");
	}


	return 0;
}
