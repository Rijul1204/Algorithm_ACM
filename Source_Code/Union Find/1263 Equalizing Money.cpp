#include<stdio.h>
#include<string.h>

#define maxm 1020

int pre[maxm],count1[maxm],tot[maxm],n,m;

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}


int main(){

	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);
	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);
		
		for(i=1;i<=n;i++){
			scanf("%d",&j);
			pre[i]=i;
			count1[i]=1;
			tot[i]=j;
		}

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			k=find(k); l=find(l);
			if(k!=l){
				if(count1[k]>count1[l]) pre[k]=l;
				else pre[l]=k;
				count1[k]=count1[l]+=count1[k];
				tot[k]=tot[l]+=tot[k];
			}
		}

		int flag=1;
		int eq=-1;

		for(i=1;i<=n;i++){
			if(pre[i]==i){
				if(tot[i]%count1[i]==0){
					if(eq==-1) eq=tot[i]/count1[i];
					else {
						if(eq!=tot[i]/count1[i]){
							flag=0;
							break;
						}
					}
				}
				else{
					flag=0;
					break;
				}
			}
		}

		if(flag) printf("Case %d: Yes\n",t++);
		else printf("Case %d: No\n",t++);

	}

	return 0;

}
