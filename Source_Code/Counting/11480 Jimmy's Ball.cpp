#include<stdio.h>
#include<string.h>

#define maxm 1000
#define ii long long int
//#define ii __int64

int n;
ii bs(int i); 

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);
	while(scanf("%d",&n)&&n){

		ii ans=0,ad;

		for(i=1;i<n;i++){
			ad=bs(i);
			if(ad<=0) break;
			ans+=ad;
		}
		
		printf("Case %d: %lld\n",t++,ans);

	}

	return 0;
}

ii bs(int i){

	
	int j,k,l;
	int lo,hi,mid;
	int c=32;
	lo=i+1; hi=n;
	int prev=0;
	if((n-lo-i)<=lo) return 0;	
	while(lo<hi||c--){
		
		mid=lo+hi; mid/=2;
		
		if((n-mid-i)<mid){
			hi=mid-1;
		}
		else if((n-mid-i)>mid){
			if(mid==lo){
				mid++;
				if(n-mid-i>mid){
					lo=mid;
				}
				else return lo-i;
			}
			lo=mid;		
		}
		else if((n-mid-i)==mid){
			lo=mid-1;
			break;
		}
	}
	return lo-i;
}