#include<stdio.h>
#include<math.h>

#define maxm 66000
#define ii long long int

bool p[maxm+10];

int flag[75000];

bool check(int n);
ii bigmod(int n,int p,int m);
void gen(int n);

int main(){

	int i,j,k,l;

	flag[561]=1;
flag[1105]=1;
flag[1729]=1;
flag[2465]=1;
flag[2821]=1;
flag[6601]=1;
flag[8911]=1;
flag[10585]=1;
flag[15841]=1;
flag[29341]=1;
flag[41041]=1;
flag[46657]=1;
flag[52633]=1;
flag[62745]=1;
flag[63973]=1;


	while(scanf("%d",&i)&&i){
	//	if(check(i)&&p[i]==1) flag[i]=1;
		if(flag[i]) printf("The number %d is a Carmichael number.\n",i);
		else printf("%d is normal.\n",i);
	}



	return 0;
}

void gen(int n){

	int i,j,k,l,sq;
	sq=sqrt(n);

	p[0]=p[1]=1;

	for(i=4;i<=n;i+=2) p[i]=1;

	for(i=3;i<sq;i++){
		if(p[i]) continue;
		for(j=i*i;j<=n;j+=2*i){
			p[j]=1;
		}

	}

}

ii bigmod(int n,int p,int m){

	if(p==0) return 1;
	if(p==1) return n;
	
    ii ret;
	if(p%2==0){
		ret=bigmod(n,p/2,m)%m;
		ret*=ret;
		ret%=m;
	}	
	else{
		ret=bigmod(n,p/2,m)%m;
		ret*=ret;
		ret%=m;
		ret*=(n%m);
		ret%=m;
	}

	return ret;


}

bool check(int n){

	int i,j,k,l;

	for(i=2;i<n;i++){
		if(bigmod(i,n,n)!=i) return 0;
	}

	return 1;

}