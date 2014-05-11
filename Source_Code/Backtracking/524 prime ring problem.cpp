#include<stdio.h>
#include<math.h>

#define p 1000

bool prime[p+10],flag[p+10];


int soln[60];

void generate(int n);

void back(int n,int count);

int main(){

	int i,n,test=1;
    bool blank=false;
	
	generate(p);
	
	while(scanf("%d",&n)==1){

		if(blank) printf("\n");
		blank=true;

		printf("Case %d:\n",test++);
		soln[0]=1;
		flag[1]=1;
		back(n,1);
		
	}
	

	return 0;

}

void back(int n,int count){

	if(count==n){
		for(int i=0;i<n-1;i++){
			printf("%d ",soln[i]);
		}
		printf("%d\n",soln[n-1]);

		return ;
	}

	else{
		for(int i=2;i<=n;i++){
			if(prime[soln[count-1]+i]==0&&flag[i]==0){
				if(count==n-1)	if(prime[i+1]!=0) continue;
				soln[count]=i;
				flag[i]=1;
				back(n,count+1);
				flag[i]=0;
			}
		}
	}

}
				


void generate(int n){

	int i,j,k;

	k=sqrt(n);

	prime[0]=prime[1]=1;

	for(i=4;i<=n;i+=2) prime[i]=1;

	for(i=3;i<=k;i+=2){
		if(prime[i]==0){
			for(j=i*i;j<=n;j+=2*i){
				prime[j]=1;
			}
		}
	}

}

