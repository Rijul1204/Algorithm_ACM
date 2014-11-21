#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define inf 1<<28
#define maxm 10010

int a[maxm],pr,n;

int bs();

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	
	while(scanf("%d",&n)==1){

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		scanf("%d",&pr);
		int ans=bs();
		
		printf("Peter should buy books whose prices are %d and %d.\n\n",ans,pr-ans);

	}

	return 0;
}

int bs(){

	int i,j,k,l,gap=inf;
	int lo,hi,mid,ret;
	
	for(i=0;i<n;i++){
		lo=i+1;
		hi=n-1;
		k=a[i];
		l=pr-k;
		if(l<k) break;
		if(l-k>gap) continue;
		while(lo<=hi){

			mid=lo+hi; mid/=2;			
			if(a[mid]==l){
				gap=l-k;
				ret=k;
				break;
			}
			if(a[mid]<l){
				lo=mid+1;
			}
			if(a[mid]>l){
				hi=mid-1;
			}
		}
	}
	
	return ret;

}