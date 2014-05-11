#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 2100

int a[maxm],n;

int bs(int num,int lo);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d",&n);

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		int ans=0;
		for(i=1;i<n;i++){
			for(j=i+1;j<n;j++){
				ans+=bs(a[i]+a[j],j+1);
			}
		}
		printf("Case %d: %d\n",t++,ans);

	}
	
	return 0;
}

int bs(int num,int lo){

	int i,j,k,hi,mid,base;
	base=lo; hi=n; mid=lo+hi; mid/=2;
	if(a[lo]>=num) return 0;

	while(lo<hi){

		mid=lo+hi; mid/=2;

		if(a[mid]>=num){
			hi=mid-1;
		}
		else{
			if(lo==mid){
				if(a[mid+1]<num) return (mid-base+2);
				else return (mid-base+1);
			}
			lo=mid;
		}

	}
	
	return lo-base+1;

}