#include<stdio.h>
#include<math.h>

#define s 50100

int ans[s];
double phi[s];
bool prime[s];

void geneuler(int n);
void genans(int n);

int main(){
	
	int i,n;
	
	geneuler(s-10);
    genans(s-10);
	
	
	while(scanf("%d",&n)&&n){
		
		printf("%d\n",ans[n]);
	}
	
	return 0;
	
}

void geneuler(int n){
	
	
	double temp;
    phi[0]=0;
	phi[2]=1;
	int sq=sqrt(n);
	int i,j;
	
	for(i=4;i<=n;i+=2){
		prime[i]=1;
		temp=i;
		phi[i]=temp*.5;
	}
	for(i=3;i<=n;i+=2) phi[i]=i;
	
	for(i=3;i<=n;i+=2){		
		if(prime[i]==0){
			phi[i]=i-1;			
			for(j=2*i;j<=n;j+=i){
				prime[j]=1;
				temp=i;
				phi[j]*=((temp-1)/temp);
			}			
		}
	}
	
}

void genans(int n){
	
	ans[1]=1;
	ans[0]=1;
	int temp;
	
	for(int i=2;i<=n;i++){
        temp=phi[i];
		ans[i]=ans[i-1]+2*temp;
		
	}
	
}












