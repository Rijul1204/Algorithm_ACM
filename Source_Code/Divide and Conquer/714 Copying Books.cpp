#include<stdio.h>
#include<string.h>

#define maxm 1100
#define inf 1<<30
#define ii long long int

ii a[maxm],mr[maxm][maxm],n,m,sum;
int br[maxm],temp[maxm];
ii maxi(ii a,ii b){
	if(a>b) return a;
	return b;
}
int mini(int a,int b){
	if(a<b) return a;
	return b;
}
ii bs(ii beg,ii end);
ii chck(ii x);

int main(){

	ii i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%lld %lld",&n,&m);

		sum=0;
		k=-1;

		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
			k=maxi(k,a[i]);
		}		
		
		l=bs(k,sum);
		
	
		
		br[0]=0;
		bool fl=0;
		for(j=1;j<=m;j++){
			for(i=br[j-1]+1;i<=br[j];i++){
				if(fl) printf(" ");
				fl=1;
				printf("%d",a[i]);
			}
			if(j<m) printf(" /");
		}
		printf("\n");

	}

	return 0;
}

ii bs(ii beg,ii end){
	
	ii i,j,k,l;
	
	ii lo=beg;
	ii hi=end;
	ii mid;
	ii prev=hi;
	
	int c=0;

	while(lo<=hi){
		
		c++;

		if(c>=1000){
			return prev;
		}

		mid=lo+hi;
		mid/=2;

		//mid++;
		l=chck(mid);
		
		//if(l==prev) return l;
				
		if(l==-1){
			lo=mid+1;
		}
		else{
			prev=l;
			hi=l-1;
		}
	}
	
	
	return prev;
}

ii chck(ii x){

	ii i,j;
	ii k=-1;

	ii sum=0;
	j=m;
	temp[m]=n;

	for(i=n;i>=1;i--){		
		if(sum+a[i]>x||i<j){
			temp[j-1]=i;
			j--;
			if(j<1) return -1;
			sum=a[i];
			if(sum>x) return -1;
		}
		else sum+=a[i];
		k=maxi(k,sum);
	}

	if(i>=1) return -1;

	for(i=1;i<=m;i++){
		br[i]=temp[i];
	}
	
	return k;
	
}