#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

#define maxm 1000100

bool p[maxm];
int prime[maxm/3],primec,divi[maxm],N[maxm],a,b,tot;

void genprime(int n);
void takeprime(int n);
void gendiv(int n);
int cal(int n);
void gen(int n);
int bsl(int n);
int bsh(int n);

int main(){

	int i,j,k,l,test,t=1;

	genprime(maxm-90);
	takeprime(maxm-90);
//	gendiv(maxm-90);
	gen(maxm-90);

//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&a,&b);
		k=bsh(a); l=bsl(b);
		int ans=l-k+1;

		printf("Case %d: %d\n",t++,ans);

	}

	return 0;
}

int bsl(int n){

	int i,j,k,l;
	int lo,hi,mid;

	lo=0;
	hi=tot;

	while(lo<hi){

		mid=lo+hi;  mid/=2;

		if(N[mid]==n){
			return mid;
		}
		else if(N[mid]<n){
			if(mid==lo){
				if(N[lo+1]<=n){
					return lo+1;
				}
				else return lo;			
			}
			lo=mid;
		}		
		else if(N[mid]>n){
			hi=mid-1;
		}

		if(lo==hi) return lo;
	}

	return lo;
}

int bsh(int n){
	
	int i,j,k,l;
	int lo,hi,mid;

	lo=0;
	hi=tot;

	while(lo<hi){

		mid=lo+hi;  mid/=2;

		if(N[mid]==n){
			return mid;
		}
		else if(N[mid]<n){
			lo=mid+1;
		}		
		else if(N[mid]>n){
			if(mid==hi){
				if(N[hi-1]>=n){
					return hi-1;
				}
				else return hi;			
			}
			hi=mid;			
		}

		if(lo==hi) return hi;
	}

	return hi;
}
int cal(int n){

	int i,j,k,l,sq;

	if(n==1) return 1;

	sq=sqrt(n);
	int ret=1;
	for(i=0;prime[i]<=sq;i++){
				
		if(n%prime[i]==0){
			k=0;
			while(n%prime[i]==0){
				n/=prime[i];
				k++;
			}
			k++;
			ret*=k;
			if(n==1) break;
			sq=sqrt(n);
		}
	}
	
	if(n>1){
		ret*=2;
	}	
	return ret;
}

void gen(int n){

	N[0]=1;

	int i;

	for(i=1;;i++){
		N[i]=N[i-1]+cal(N[i-1]);
		if(N[i]>n) break;
	}
	tot=i;
}

void gendiv(int n){
	
	int i=0;
	divi[1]=1;

	for(i=2;i<=n;i++){
		divi[i]=cal(i);
	}
}

void takeprime(int n){

	prime[primec++]=2;

	for(int i=3;i<=n;i+=2){
		if(p[i]) continue;
		prime[primec++]=i;
	}
}

void genprime(int n){

	int i,j,k,l,sq;

	sq=sqrt(n);
	p[0]=p[1]=1;

	for(i=4;i<=n;i+=2) p[i]=1;

	for(i=3;i<=sq;i+=2){
		if(p[i]) continue;
		for(j=i*i;j<=n;j+=(2*i)){
			p[j]=1;
		}
	}
}