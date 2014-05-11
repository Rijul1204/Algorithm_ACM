#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<map>
using namespace std;

#define maxm 10000
#define ii __int64
//#define ii long long int

ii fib[maxm];
map<int,int>fibo;
char in[maxm],out[maxm];
int num[maxm];

bool isvalid(char ch){
	if(ch>='A'&&ch<='Z') return 1;
	return 0;
}

int main(){

	int i,j,k,test,n;
	ii range;

	range=pow(2,31);

	fib[0]=1; fib[1]=1;
	fibo[1]=1;

	for(i=2;i<=100;i++){
		fib[i]=fib[i-1]+fib[i-2];
		//printf("%d %I64d\n",i,fib[i]);
		if(fib[i]>range) break;
		fibo[fib[i]]=i;
	}

	//printf("%I64d %d\n",fib[i],i);

//	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&test);

	while(test--){
		
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&num[i]);
		gets(out);
		gets(in);
		for(i=0;i<=5000;i++) out[i]=' ';
		k=1;
		int l;
		int maxi=0;
		for(i=0;in[i];i++){
			if(!isvalid(in[i])) continue;
			l=num[k++];
			l=fibo[l];
			if(maxi<l) maxi=l;
			out[l-1]=in[i];
			if(k>n) break;
		}
		out[maxi]='\0';

		puts(out);
		
		
		
	}

	return 0;
}