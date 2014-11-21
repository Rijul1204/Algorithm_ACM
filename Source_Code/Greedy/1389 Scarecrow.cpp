#include<stdio.h>
#include<string.h>

#define maxm 110

char s[maxm];

int main(){

	int i,j,k,l,test,t=1,n;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		
		scanf("%s",s);
		
		int ans=0;
		k=0;
		for(i=0;i<n;i++){
			if(s[i]=='.'){
				ans++;
				i+=2;		
			}
		}

		printf("Case %d: %d\n",t++,ans);


	}

	return 0;
}