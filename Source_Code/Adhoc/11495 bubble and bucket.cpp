#include<stdio.h>


#define maxm 100100

int a[maxm],left[maxm],right[maxm],count1;

void mergesort(int beg,int end);
void merge(int beg,int mid,int end);

int main(){

	int i,j,k,l,n;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		if(n<=0) break;

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}

		count1=0;
		mergesort(1,n);

		for(i=1;i<=n;i++){
	//		printf("%d ",a[i]);
		}

		if(count1%2) printf("Marcelo\n");
		else printf("Carlos\n");


	}
	
	return 0;
}

void mergesort(int beg,int end){

	int mid=beg+end;
	mid/=2;
	if(beg>=end) return;

	mergesort(beg,mid);
	mergesort(mid+1,end);

	merge(beg,mid,end);
	
}

void merge(int beg,int mid,int end){

	int i,j,k,l;
	int b1,b2;

	for(i=beg,j=1;i<=mid;i++,j++) left[j]=a[i];
	b1=j-1;

	for(j=1,i=mid+1;i<=end;i++,j++) right[j]=a[i];

	b2=end-mid;
	k=1; l=1;
	i=beg;

	while(1){
		if(k>b1||l>b2) break;

		if(left[k]<=right[l]){
			a[i++]=left[k++];
		}
		else {
			a[i++]=right[l++];
			count1+=(b1-k+1);
		}
	}

	if(k<=b1){
		for(;k<=b1;k++){
			a[i++]=left[k];
		}
	}

	if(l<=b2){		
		for(;l<=b2;l++){
			a[i++]=right[l];
	//		count1++;
	
		}
	}

}