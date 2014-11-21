#include<stdio.h>
#include<string.h>

#define maxm 110
#define ii long long int

int mat[maxm][maxm];

int main(){

	int i,j,k,l,test,t=1,m,n;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&m,&n);
		
		ii ans1,ans2=0;
		for(i=1;i<=m;i++){
			ans2=0;
			for(j=1;j<=n;j++){
				scanf("%d",&k);
				ans2+=k;				
			}
			if(i==1) ans1=ans2;
			else ans1=ans1^ans2;
		}

		if(ans1){
			printf("Case %d: Alice\n",t++);
		}
		else{
			printf("Case %d: Bob\n",t++);
		}


	}

	return 0;
}