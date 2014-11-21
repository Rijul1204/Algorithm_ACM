#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;

#define maxm 1000000
#define ii __int64

ii fib1[maxm],fib2[maxm],fibsum1[maxm],fibsum2[maxm];
int n;

void print(int ind,int num);
ii cal1(int ind);
ii cal2(int ind);


int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	memset(fib1,-1,sizeof(fib1));
	memset(fib2,-1,sizeof(fib2));

	for(i=1;;i++){
		fibsum1[i]=fibsum1[i-1]+cal1(i);
		if(fibsum1[i]>1000000000) break;
	}
	
	for(i=1;;i++){
		fibsum2[i]=fibsum2[i-1]+cal2(i);
		if(fibsum2[i]>1000000000) break;
	}

	scanf("%d",&test);
	
	while(test--){

		scanf("%d",&n);
		
		if(n==1){
			printf("Case %d: 1\n",t++);
			continue;
		}
		
		printf("Case %d: 10",t++);
		

			
		for(i=1;;i++){
			if(fibsum1[i]>=n) break;
		}
		
		n-=fibsum1[i-1];
		print(i-2,n);
		printf("\n");
		

	}

	return 0;
}

void print(int ind,int num){

	if(ind<=0) return ;
	if(num==0){
		printf("0");
		print(ind-1,0);
		return ;
	}
	if(cal2(ind-1)<num){
		if(ind>1) printf("10"); else printf("1");
 		print(ind-2,num-cal2(ind-1));
	}
	else{
		printf("0");
		print(ind-1,num);
	}

}

ii cal2(int ind){

	if(ind==1||ind==0) return ind+1;

	if(fib2[ind]!=-1) return fib2[ind];

	return fib2[ind]=cal2(ind-1)+cal2(ind-2);

}

ii cal1(int ind){

	if(ind==1||ind==2) return 1;

	if(fib1[ind]!=-1) return fib1[ind];

	return fib1[ind]=cal1(ind-1)+cal1(ind-2);

}
