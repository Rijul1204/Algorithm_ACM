#include<stdio.h>
#include<math.h>

//int H(int n);
long long int altH(int n);

int main(){

	long long int i,j,k,l,n;
	int test;

	scanf("%d",&test);

    //  freopen("in.txt","r",stdin);
    //  freopen("out.txt","w",stdout); 

	while(test--){
		scanf("%lld",&n);

		//printf("%d\n",H(n));
		if(n>0) printf("%lld\n",altH(n));
		else printf("0\n");

	}

	return 0;

}
/*
int  H(int n){

    int res = 0;
    int sq;
	sq=sqrt(n); 

     for( int i = 1; i <= n; i=i+1 ){

            res = (res + n/i);
			
      }
	// res+=n/2;
	// if(n%2) res++;

     return res;

} 
*/

long long int altH(int n){

	long long int res=0;
    long long int low,high,mid,temp;
	low=2;high=n;
	res=high;
	
	while(low<=high){
		mid=n/low;
		
		if(mid<low) temp=(high-low)*(low-1); 
		else temp=(high-mid)*(low-1);
		
		if(low!=high) res+=(mid+temp);
		else res+=mid;
		
		high=mid;
		low++;
	}


	return res;


}