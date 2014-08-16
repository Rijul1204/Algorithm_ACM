/*
Author  : Rashedul Hasan Rijul .
problem : Light OJ - 1253 ( Misere Nim) .
Algo    : Misere-Nim .
*/

#include<stdio.h>
#include<string.h>

#define maxm 1000
#define ii int

int a[maxm];

int main(){

	int i,j,k,l,test,t=1,n;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		ii ans=0,ans1;
		bool fl=0;
		l=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(k==1){
				l++;
				ans^=1;
			}
			else{
				ans^=k;
				fl=1;
			}
		}
		// Alice play first....

		if(!fl){
			if(l%2==1) printf("Case %d: Bob\n",t++);
			else printf("Case %d: Alice\n",t++);
			continue;
		}
		if(ans) printf("Case %d: Alice\n",t++); // Alice play first....
		else  printf("Case %d: Bob\n",t++);


	}

	return 0;
}
