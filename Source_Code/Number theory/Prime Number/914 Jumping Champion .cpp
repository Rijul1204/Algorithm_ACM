#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;


#define maxm 1000100

bool p[maxm+100];
int prime[maxm];
int count1;
map<int,int>freq;

void gen(int n){

	int i,j,k,l,sq;
	double sqd;

	sqd=sqrt(n);

	sq=sqd;
	p[0]=p[1]=1;

	for(i=4;i<=n;i+=2) p[i]=1;

	for(i=3;i<=sq;i+=2){
		if(p[i]==1) continue;
		for(j=i*i;j<=n;j+=(2*i)){
			p[j]=1;
		}

	}

}

void take(int n){
	
	int i,j,k,l;

	prime[1]=2;
	k=2;

	for(i=3;i<=n;i+=2){
		if(!p[i]){
			//if(i<100) printf("%6d  ",i);
			prime[k++]=i;
		}
	}

	count1=k-1;
	


}


int main(){

	int i,j,k,l,test;

	gen(maxm+5);
	take(maxm);


	//printf("%d\n",count1);

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&k,&l);
		
		if(k>l){
			k=k+l; l=k-l; k=k-l;
		}

		freq.clear();

		for(i=1;i<=count1;i++){
			if(prime[i]>=k) break;
		}
		int flag,maxi,mark;
		maxi=0;
		flag=0;

		for(i=i+1;i<=count1;i++){
			if(prime[i]>l) break;
			j=prime[i]-prime[i-1];
			freq[j]++;
			if(maxi<freq[j]){
				flag=1;
				maxi=freq[j]; mark=j;
			}
			else if(maxi==freq[j]){
				flag=0;
			}
		}

		if(flag) printf("The jumping champion is %d\n",mark);
		else printf("No jumping champion\n");


	}


	return 0;
}