#include<stdio.h>

struct tree{
	int sum;
	int max;
	int prefix;
	int suffix;
};

int a[20000];
tree m[250000];

void init(int node,int b,int e);
int maxi(int a,int b){ if(a>b) return a; return b; };
tree query(int node,int b,int e,int i,int j);

int main(){

	int i,j,k,l,n;

	while(scanf("%d",&n)==1){

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		init(1,0,n-1);

		scanf("%d",&m);

		for(k=0;k<m;k++){
			scanf("%d %d",&i,&j);
		}



	}


	return 0;
}

tree query(int node,int b,int e){


}



void init(int node,int b,int e){

	if(b==e){
		m[node].max=m[node].prefix=m[node].suffix=m[node].sum=a[b];
		return 0;
	}
	int mid,left,right;
	mid=b+e; mid/=2;
	left=1<<2; right=left+1;

	init(left,b,mid);
	init(right,mid+1,e);
	
	m[node].sum=m[left].sum+m[right].sum;

	m[node].prefix=maxi(m[left].prefix,m[left].sum+m[right].prefix);
	m[node].suffix=maxi(m[right].suffix,m[right].sum+m[left].suffix);
	m[node].max=maxi(maxi(m[node].prefix,m[node].suffix),maxi(m[left].max,m[right].max);
	m[node].max=maxi(m[node].max,m[left].suffix+m[right].prefix);


}