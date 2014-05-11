#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 62500+100
#define inf maxm+300

int a[maxm],b[maxm],c[maxm],L[maxm],n1,p,q,n,num[maxm],ind[maxm],d[maxm];

bool comp(int i,int value){
	if(d[i]<value) return 1;
	return 0;
}

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d %d",&n1,&p,&q);
		p++; q++;
	
		memset(num,0,sizeof(num));
		memset(ind,-1,sizeof(ind));
		for(i=1;i<=p;i++){
			scanf("%d",&a[i]);
			num[a[i]]++;
		}
		for(i=1;i<=q;i++){
			scanf("%d",&b[i]);
			num[b[i]]++;
			ind[b[i]]=i;
		}

		j=1;
		for(i=1;i<=p;i++){
			if(num[a[i]]==2){
				d[j]=ind[a[i]];
				c[j++]=a[i];
			}
		}
		n=j-1;

		int pos;
		l=1;
		L[0]=0;
		c[0]=0;
		d[0]=-inf;
		bool f;

	/*	for(i=1;i<=n;i++){
			printf("%2d ",d[i]);			
		}
	*/	
		for(i=1;i<=n;i++){

			pos=lower_bound(L,L+l,d[i],comp)-L;
			f=(pos==l);
			if(f||d[L[pos]]>d[i]){
				L[pos]=i;
				if(f) l++;
			}
		}
		l--;

		printf("Case %d: %d\n",t++,l);


	}

	return 0;
}