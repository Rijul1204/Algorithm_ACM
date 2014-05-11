#include<stdio.h>
#include<math.h>
#include<string.h>

#define maxm 1000

int n;

int main(){

	int i,j,k,l;

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){

		if(n<0) break;

		if(n<=2){
			printf("%d coconuts, no solution\n",n);
			continue;
		}
		/*
		if(n==2){
			printf("%d coconuts, %d people and 1 monkey\n",n,1);
			continue;
		}
		*/

		int n1=sqrt(n);
		n1++;
		
		int fl=0;

		while(n1){
			
			fl=0;
			l=n;
			if(n1>=l) continue;
			for(i=1;i<=n1;i++){
				//if(l<n1) break;
				if(l%n1!=1) break;
				l--;
				k=l/n1;
				l-=k;
			}
			
			if(l%n1||i<=n1){
				n1--;
				continue;
			}
			else{
				fl=1;
				break;
			}
		
		}

		if(fl)printf("%d coconuts, %d people and 1 monkey\n",n,n1);
		else printf("%d coconuts, no solution\n",n);

	}

	return 0;
}