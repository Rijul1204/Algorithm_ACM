#include<stdio.h>

struct tree{
	int sum;
	int max;
	int prefix;
	int suffix;
	int valid;
};

tree m[250000];
int a[80000];

void init(int node,int b,int e);
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
tree query(int node,int b,int e,int i,int j);

int main(){

	int i,j,k,l,n,q;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		init(1,0,n-1);
		scanf("%d",&q);
		
		tree ans;
		
		for(k=1;k<=q;k++){
			scanf("%d %d",&i,&j);
			ans=query(1,0,n-1,i-1,j-1);
			printf("%d\n",ans.max);
		};

	}


	return 0;
}

void init(int node,int b,int e){

	if(b==e){
		m[node].max=m[node].prefix=m[node].suffix=m[node].sum=a[b];
		return ;
	}

	int mid=b+e;
	mid/=2;
	int left,right;
	
	left=node<<1;
	right=left+1;

	init(left,b,mid);
	init(right,mid+1,e);

	m[node].sum=m[left].sum+m[right].sum;
	
	m[node].prefix=maxi(m[left].prefix,m[left].sum+m[right].prefix);
	m[node].suffix=maxi(m[right].suffix,m[right].sum+m[left].suffix);
	
	m[node].max=maxi(maxi(m[node].prefix,m[node].suffix),maxi(m[left].max,m[right].max));
	m[node].max=maxi(m[node].max,m[left].suffix+m[right].prefix);
	m[node].max=maxi(m[node].max,m[node].sum);

}

tree query(int node,int b,int e,int i,int j){

	tree ret,p1,p2;
	
	if(j<b||i>e){
		ret.valid=-1;
		return ret;
	}

	if(b>=i&&e<=j){
		return m[node];
	}

	int left,mid,right;
	mid=(b+e)/2;
	left=node<<1; right=left+1;

	p1=query(left,b,mid,i,j);
	p2=query(right,mid+1,e,i,j);

	if(p1.valid==-1) return p2;
	else if(p2.valid==-1) return p1;

	ret.sum=p1.sum+p2.sum;
	
	ret.prefix=maxi(p1.prefix,p1.sum+p2.prefix);
	ret.suffix=maxi(p2.suffix,p2.sum+p1.suffix);

	ret.max=maxi(maxi(p1.max,p2.max),maxi(ret.prefix,ret.suffix));
	ret.max=maxi(ret.max,maxi(ret.sum,p1.suffix+p2.prefix));


	return ret;

}
