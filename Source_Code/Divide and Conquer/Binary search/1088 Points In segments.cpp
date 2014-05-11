#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 100100

int a[maxm],n,q;

int bsl(int num);
int bsh(int num);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&q);

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int ans;
		printf("Case %d:\n",t++);
		for(i=1;i<=q;i++){
			scanf("%d %d",&k,&l);
			if(a[0]>l||a[n-1]<k){
				printf("0\n");
				continue;
			}
			ans=bsh(l)-bsl(k)+1;
			printf("%d\n",ans);
		}


	}

	return 0;
}

int bsh(int num){

	int i,lo,hi,mid;

	lo=0; hi=n-1;
	
	while(lo<hi){

		mid=lo+hi; mid/=2;

		if(a[mid]==num){
			while(mid+1<n){
				if(a[mid+1]==num) mid++;
				else break;
			}
			return mid;
		}
		if(a[mid]>num){
			hi=mid-1;
		}
		else{
			if(mid==lo){
				if(mid==n-1) return n-1;
				if(a[mid+1]<=num) return mid+1;
				return mid;
			}
			lo=mid;
		}

	}

	return lo;
}
int bsl(int num){

	
	int i,lo,hi,mid;

	lo=0; hi=n-1;

	while(lo<hi){

		mid=lo+hi; mid/=2;

		if(a[mid]==num){
			while(mid-1>0){
				if(a[mid-1]==num) mid--;
				else break;
			}
			return mid;
		}
		if(a[mid]<num){
			lo=mid+1;
		}
		else{
			if(mid==hi){
				if(mid==0) return 0;
				if(a[mid-1]>=num) return mid-1;
				return mid;
			}
			hi=mid;
		}

	}

	return hi;

}