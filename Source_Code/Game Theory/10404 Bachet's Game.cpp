#include<stdio.h>
#include<string.h>

#define maxm 1000010

int a[15],n,m;
bool fl[maxm];

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){
		
		for(i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		memset(fl,0,sizeof(fl));
		fl[0]=0;

		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(i-a[j]<0) continue;
				if(fl[i-a[j]]==0){
					fl[i]=1;
					break;
				}
			}
			if(j==m+1) fl[i]=0;
		}

		if(!fl[n]) printf("Ollie wins\n");
		else printf("Stan wins\n");
	}


	return 0;
}