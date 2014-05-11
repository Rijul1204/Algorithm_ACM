#include<stdio.h>

#define maxm 10000

int h[maxm],w[maxm];
int li[maxm],ld[maxm];

int main(){

	int i,j,k,l,test,n,t=1;

	//freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=1;i<=n;i++){
			scanf("%d",&h[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&w[i]);
		}

		int mlis=-1; int mlds=-1;
		int maxi=-1; int maxd=-1;

		for(i=1;i<=n;i++){
			li[i]=w[i];
			ld[i]=w[i];
			if(maxd<ld[i]) maxd=ld[i];
			if(maxi<li[i]) maxi=li[i];
		}
	

		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(h[j]>h[i]){
					if(w[j]+li[i]>li[j]){
						li[j]=li[i]+w[j];
						if(maxi<li[j]) maxi=li[j];
					}
				}

				if(h[j]<h[i]){
					if(w[j]+ld[i]>ld[j]){
						ld[j]=ld[i]+w[j];
						if(maxd<ld[j]) maxd=ld[j];
					}
				}
			}
		}

		if(maxi>=maxd) printf("Case %d. Increasing (%d). Decreasing (%d).\n",t++,maxi,maxd);
		else printf("Case %d. Decreasing (%d). Increasing (%d).\n",t++,maxd,maxi);

		
	}

	return 0;
}