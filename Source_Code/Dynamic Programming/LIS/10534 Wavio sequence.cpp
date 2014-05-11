#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

#define maxm 1000100

int a[maxm],n,d[maxm],d1[maxm],L[maxm],p[maxm];
bool com(int i,int val){
	if(a[i]<val) return 1;
	return 0;
}

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l;

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}

		L[0]=0;
		a[0]=-2147483648;
		l=1;
		int pos;
		bool f;
		
		for(i=1;i<=n;i++){
			pos=lower_bound(L,L+l,a[i],com)-L;
			f=(pos==l);
			d[i]=pos;				
			if(f||a[L[pos]]>a[i]){
				p[i]=L[pos-1];
				L[pos]=i;
				if(f) l++;
			}
		}

		reverse(a+1,a+n+1);

		L[0]=0;
		a[0]=-2147483648;
		l=1;
	 	
		for(i=1;i<=n;i++){
			pos=lower_bound(L,L+l,a[i],com)-L;
			f=(pos==l);
			d1[i]=pos;
			if(f||a[L[pos]]>a[i]){
				p[i]=L[pos-1];
				L[pos]=i;
				if(f) l++;
			}
		}

		reverse(d1+1,d1+n+1);

		int ans=-1;

		for(i=1;i<=n;i++){
			ans=maxi(ans,mini(d[i],d1[i]));
		}

		printf("%d\n",2*ans-1);


	}

	return 0;
}