#include<stdio.h>

int pre[1000000];

void set(int n){
	for(int i=0;i<=n;i++){
		pre[i]=i;
	}
}

int find(int x){
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}
void Union(int a,int b){
	if(a!=b) pre[a]=b;
}

int main(){

	int i,j,k,l,n,m,count1,t=1;

	while(scanf("%d %d",&n,&m)==2){

		if(!n&&!m) break;

		set(n);

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			Union(find(k),find(l));
		}
		count1=0;

		for(i=1;i<=n;i++){
			if(pre[i]==i) count1++;
		}

		printf("Case %d: %d\n",t++,count1);

	}

	return 0;

}
