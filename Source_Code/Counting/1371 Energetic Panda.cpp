#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define ii __int64
//#define ii long long int
#define maxm 1010
#define mod 1000000007

int p[maxm],cap[maxm],n;
ii bs(int val);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--){
		
		scanf("%d",&n);

		for(i=1;i<=n;i++){
			scanf("%d",&cap[i]);
		}

		for(i=1;i<=n;i++){
			scanf("%d",&p[i]);
		}
		sort(p+1,p+n+1);
		sort(cap+1,cap+n+1);

		ii ans=1;
		for(i=1;i<=n;i++){
			ans=(ans*(bs(p[i])-(i-1)))%mod;
		}

		printf("Case %d: %I64d\n",t++,ans);


	}

	return 0;
}

ii bs(int val){

	ii lo,hi,mid,i;

	lo=1; hi=n;

	if(cap[lo]>val) return 0;

	while(lo<hi){

		mid=lo+hi; mid/=2;

		if(cap[mid]>val){
			hi=mid-1;
		}		
		else if(cap[mid]<=val){
			if(mid==lo){
				if(cap[mid+1]<=val) return mid+1;
				else return mid;
			}
			lo=mid;
		}
	}
	
	return lo;

}