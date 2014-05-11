#include<stdio.h>

#define maxm 1000000

char s[maxm+20];
int count1[maxm+20];

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
int mini (int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l,q,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%s",s)==1){
		if(!s[0]) break;

		count1[0]=1;
		for(i=1;s[i];i++){
			if(s[i]==s[i-1]) count1[i]=count1[i-1]+1;
			else count1[i]=1;
		}
		
		printf("Case %d:\n",t++);
	
		scanf("%d",&q);
		

		for(i=1;i<=q;i++){
			scanf("%d %d",&k,&l);
			j=maxi(k,l);
			k=mini(k,l);
			l=j;
			//printf("%d\n",count1[l]);
			if(count1[l]>=(l-k+1)){
				printf("Yes\n");
			}
			else printf("No\n");
		}

		
	}

	return 0;
}