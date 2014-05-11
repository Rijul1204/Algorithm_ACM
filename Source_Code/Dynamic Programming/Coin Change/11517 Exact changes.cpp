#include<stdio.h>

#define inf 99999999

int nway[1001000],flag[1001000];

void set(int n,int sum);

int main(){
	
	int i,j,k,test,total,n,c,sum;
	int coin[1500];
	
	//freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d",&total);
		
		scanf("%d",&n);
		
		sum=0;

		for(i=1;i<=n;i++){
			scanf("%d",&coin[i]);
			sum+=coin[i];
		}
		set(n,sum);
		
		nway[0]=0;
		flag[0]=1;
		
		for(i=1;i<=n;i++){
			c=coin[i];
			for(j=sum;j>=c;j--){
				if(flag[j-c]==1){
					flag[j]=1;
					if(nway[j-c]+1<nway[j]) nway[j]=nway[j-c]+1;
				}
			}
		}

		for(i=total;i<=sum;i++){
			if(flag[i]==1){
				printf("%d %d\n",i,nway[i]);
				break;
			}
		}
		
			
				
	}
	
	return 0;
	
}

void set(int n,int sum){

	for(int i=0;i<=sum;i++){
		nway[i]=inf;
		flag[i]=0;
	}
	

	
}






