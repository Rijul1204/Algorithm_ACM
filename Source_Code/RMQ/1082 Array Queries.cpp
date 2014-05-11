#include<stdio.h>
#include<math.h>

int n,q;

int a[100110];
int m[100110][40];

int main(){

	int i,j,k,l,test,tot,t=1;

	//freopen("out.txt","r",stdin);

	scanf("%d",&test);


	while(test--){

		scanf("%d %d",&n,&q);
	
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		
		
		for(i=0;i<n;i++) m[i][0]=i;

		for(j=1;1<<j<=n;j++){
			for(i=0;i+(1<<(j-1))<n;i++){
				//printf("%d %d\n",j,i);
				if(a[m[i][j-1]]<=a[m[i+(1<<(j-1))][j-1]]) m[i][j]=m[i][j-1];
				else m[i][j]=m[i+(1<<(j-1))][j-1];
			}
		}

		printf("Case %d:\n",t++);

		for(i=1;i<=q;i++){
			scanf("%d %d",&k,&l);
			if(k>l){
				int te=k;
				k=l;
				l=te;
			}
			k--; l--;
			
			tot=l-k+1;
			for(j=1;1<<j<=tot;j++);
			j--;
			//j=log10(tot)/log10(2);
			if(a[m[k][j]]<=a[m[l-(1<<j)+1][j]]) printf("%d\n",a[m[k][j]]);
			else printf("%d\n",a[m[l-(1<<j)+1][j]]);

		}

		

	

		


	}


	return 0;
}

