#include<stdio.h>

struct tree{
	int min;
	int max;
};

tree m[2110000];

int a[110000];

void init(int node,int b,int e);
int querymax(int node,int b,int e,int i,int j);
int querymin(int node,int b,int e,int i,int j);

int main(){

	int i,j,k,l,test,n,d,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&d);

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		init(1,0,n-1);
		int diff=0;

		for(i=0;i<=n-d;i++){
			k=querymax(1,0,n-1,i,i+d-1);
			l=querymin(1,0,n-1,i,i+d-1);
			if(diff<k-l) diff=k-l;
		}
		if(d>=n) diff=m[1].max-m[1].min;        
		printf("Case %d: %d\n",t++,diff);


	}
	

	return 0;
}

void init(int node,int b,int e){

	if(b==e){
		m[node].max=a[b];
		m[node].min=a[e];
		return;
	}

	int mid=(b+e)/2;

	init(node*2,b,mid);
	init(node*2+1,mid+1,e);

	if(m[node*2].min<m[node*2+1].min){
		m[node].min=m[node*2].min;
	}
	else m[node].min=m[node*2+1].min;

	if(m[node*2].max>m[node*2+1].max){
		m[node].max=m[node*2].max;
	}
	else m[node].max=m[node*2+1].max;

}

int  querymin(int node,int b,int e,int i,int j){

if(i>e||j<b) return -1;	
	if(b>=i&&e<=j) return m[node].min;

	int p1,p2;

	int mid=(b+e)/2;

	p1=querymin(node*2,b,mid,i,j);
	p2=querymin(node*2+1,mid+1,e,i,j);


	if(p1==-1) return p2;
	else if(p2==-1) return p1;

	if(p1<p2) return p1;
	return p2;

}

int  querymax(int node,int b,int e,int i,int j){

	if(i>e||j<b) return -1;
	
	if(b>=i&&e<=j) return m[node].max;

	int p1,p2;

	int mid=(b+e)/2;

	p1=querymax(node*2,b,mid,i,j);
	p2=querymax(node*2+1,mid+1,e,i,j);


	if(p1==-1) return p2;
	else if(p2==-1) return p1;

	if(p1>p2) return p1;
	return p2;

}






	




