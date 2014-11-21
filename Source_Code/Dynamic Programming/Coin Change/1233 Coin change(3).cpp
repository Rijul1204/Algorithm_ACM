#include<stdio.h>
#include<string.h>

#define maxm 100100
#define maxn 110

bool fl[maxm];
int cc[maxm],a[maxn],c[maxn],n,m;

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);
		
		memset(fl,0,sizeof(fl));

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&c[i]);
		}
		fl[0]=1;

		for(i=1;i<=n;i++){
			memset(cc,0,sizeof(cc));
			k=a[i];
			for(j=k;j<=m;j++){
				if(fl[j]) continue;
				if(fl[j-k]&&cc[j-k]<c[i]){
					fl[j]=1;
					cc[j]=cc[j-k]+1;
				}
			}
		}
		int ans=0;
		for(i=1;i<=m;i++){
			if(fl[i]) ans++;
		}

		printf("Case %d: %d\n",t++,ans);
		
	}

	return 0;
}
