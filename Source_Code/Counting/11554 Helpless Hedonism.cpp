#include<stdio.h>
#include<algorithm>
using namespace std;

#define N 1000000
#define ii long long int

ii ans[N+30];
void gen(int n);

int main(){

	int i,j,k,l,n,test;

	gen(N+5);

	scanf("%d",&test);

	while(test--){
		scanf("%d",&n);
	

		printf("%lld\n",ans[n]);

	}


	return 0;

}

void gen(int n){

    ii i,j,k,l,c;

	ans[3]=0;
	ans[4]=1;
	k=2;
	c=0;
	l=k;

	for(i=5;i<=n;i++){
		ans[i]=ans[i-1]+l;
		l+=k;
		c++;
		if(c==2){
			c=0;
			k++;
		}
	}

}

