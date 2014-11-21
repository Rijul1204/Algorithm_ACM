
#include<stdio.h>

typedef struct{
	int mark;
	int val;
}ma;
ma max; 

int a[30000],dp[30000],path[30000];

void set(int n);

int main(){

	int i,b,s,t,start,end;

//	freopen("in.txt","r",stdin);

	scanf("%d",&b);

	for(t=1;t<=b;t++){
		
		scanf("%d",&s);
		set(s+5);
		for(i=1;i<s;i++){
			scanf("%d",&a[i]);
			if(i==1){
				if(a[i]>0){
					dp[i]=a[i];
					path[i]+=1;
					max.val=dp[i];
					max.mark=i;
				}
				else{
					dp[i]=0;
				}
				continue;
			}
			if(dp[i-1]+a[i]<0){
				dp[i]=0;
				path[i]=0;
			}
			else if(dp[i-1]+a[i]>=0){
				dp[i]=dp[i-1]+a[i];
				path[i]+=path[i-1]+1;
				if(dp[i]>max.val){
					max.mark=i;
					max.val=dp[i];
				}
				else if(dp[i]==max.val){
					if(path[i]>path[max.mark]){
						max.mark=i;
						max.val=dp[i];
					}
				}	
			}

		}

		if(max.mark==-1) printf("Route %d has no nice parts\n",t);
		else {
			end=max.mark+1;
			start=end-path[max.mark];
			printf("The nicest part of route %d is between stops %d and %d\n",t,start,end);
		}
	

	}
		
	return 0;
	
}

void set(int n){

	int i;

	for(i=0;i<=n;i++){
		a[i]=0;
		dp[i]=0;
		path[i]=0;
	}
	max.val=0;
	max.mark=-1;

}





