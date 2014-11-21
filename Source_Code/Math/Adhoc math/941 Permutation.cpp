#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define ii long long int

ii fact[30];

void gen(int n);

int main(){

	int i,j,k,l,test,len;
	ii n,a,b,c,n1;
	char s[1000];
	int out[1000];

	gen(20);

	scanf("%d",&test);

	while(test--){

		scanf("%s",s);
		scanf("%lld",&n);

		len=strlen(s);
		 
		if(n>=fact[len]) n=fact[len]-1;
		k=0;
		for(i=len;i>=1;i--){
			a=n;
			b=fact[i-1];
			c=(a/b);
			n1=c;
			n=n%fact[i-1];
			out[k++]=n1;
			
		}
		int ind;
		
		for(i=0;i<k;i++){
			sort(s,s+len);
			ind=out[i];
			printf("%c",s[ind]);
			s[ind]='{';			
		}
		printf("\n");
		
	}

	

	return 0;
}

void gen(int n){
	
	fact[0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=i*fact[i-1];
	}
	
}

