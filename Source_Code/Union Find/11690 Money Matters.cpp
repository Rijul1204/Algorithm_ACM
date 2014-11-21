#include<stdio.h>

#define maxm 10100

int pre[maxm],sum[maxm];

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

int n,m;

int main(){

	int i,j,k,l,test;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);

		for(i=0;i<n;i++){
			scanf("%d",&sum[i]);
			pre[i]=i;
		}

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			k=find(k);
			l=find(l);
			
			if(k!=l){
				pre[k]=l;
				sum[l]=sum[k]+=sum[l];
			}
		}

		int flag=1;

		for(i=0;i<n;i++){
			if(pre[i]==i){
				if(sum[i]!=0) flag=0;
			}
		}

		if(flag) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");




	}

	return 0;

}