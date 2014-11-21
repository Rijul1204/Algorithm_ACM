#include<stdio.h>
#define ii long long int

ii a[1000][1000];

int main(){

	int i,j,k,l,test,n,t=1;
	int ch;


//a	freopen("in.txt","r",stdin);

	scanf("%d%c",&test,&ch);

	while(test--){

		scanf("%c = %d",&ch,&n);
		
		int flag=1;

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%lld%c",&a[i][j],&ch);
				if(a[i][j]<0) flag=0;
			}
		}


		for(i=1,k=n;i<=n;i++,k--){
			for(j=i,l=n-i+1;j<=n;j++,l--){
				//printf("%2d ",a[i][j]);
				if(a[i][j]!=a[k][l]){
					flag=0;
					break;
				}
			}
		//	printf("\n");
		}
		if(flag) printf("Test #%d: Symmetric.\n",t++);
		else printf("Test #%d: Non-symmetric.\n",t++);



	}

	return 0;
}
