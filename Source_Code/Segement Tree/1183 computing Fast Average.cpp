/*
Author  : Rashedul Hasan Rijul ( Silent_coder) .
Problem : LOJ 1183 ( Computing Fase Average) .
Algo    : Segment_Tree .
*/

#include<stdio.h>
#include<string.h>

#define maxm 400100

struct tree{
	int sum,fl;
};

tree m[maxm];
int n,q;

int gcd(int a,int b){
	if(a%b==0) return b;
	return gcd(b,a%b);
}
void init(int node,int b,int e);
void update(int node,int b,int e,int x,int y,int val);
int query(int node,int b,int e,int x,int y);

int main(){

	int i,j,k,l,v,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&q);

		init(1,1,n);

		printf("Case %d:\n",t++);

		for(i=1;i<=q;i++){
			scanf("%d %d %d",&j,&k,&l);
			k++; l++;
			if(j==1){
				scanf("%d",&v);
				update(1,1,n,k,l,v);
			}
			else{
				v=query(1,1,n,k,l);
				j=l-k+1;
				k=gcd(v,j);
				if((j/k)!=1) printf("%d/%d\n",v/k,j/k);
				else printf("%d\n",v/k);
			}
		}

	}

	return 0;
}

int query(int node,int b,int e,int x,int y){

	if(b==e){
		return m[node].sum;
	}

	int k=e-b+1,l;
	if(b==x&&e==y){
		return m[node].sum;
	}

	int left,right,mid,ret=0;

	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(m[node].fl==1){
		l=m[node].sum/k; m[node].fl=0;
		update(left,b,mid,b,mid,l);
		update(right,mid+1,e,mid+1,e,l);
	}

	if(y<=mid){
		return query(left,b,mid,x,y);
	}
	else if(x>mid){
		return query(right,mid+1,e,x,y);
	}
	else{
		ret+=query(left,b,mid,x,mid);
		ret+=query(right,mid+1,e,mid+1,y);
	}

	return ret;
}

void update(int node,int b,int e,int x,int y,int v){

	if(b==e){
		m[node].fl=0;
		m[node].sum=v;
		return ;
	}

	int k=e-b+1,l;
	if(b==x&&e==y){
		m[node].sum=k*v; m[node].fl=1;
		return ;
	}

	int left,right,mid;

	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(m[node].fl==1){
		l=m[node].sum/k; m[node].fl=0;
		update(left,b,mid,b,mid,l);
		update(right,mid+1,e,mid+1,e,l);
	}

	if(y<=mid){
		update(left,b,mid,x,y,v);
	}
	else if(x>mid){
		update(right,mid+1,e,x,y,v);
	}
	else{
		update(left,b,mid,x,mid,v);
		update(right,mid+1,e,mid+1,y,v);
	}

	m[node].sum=m[left].sum+m[right].sum;

}

void init(int node,int b,int e){

	if(b==e){
		m[node].fl=m[node].sum=0;
		return ;
	}

	int left,right,mid;

	left=node<<1; right=left+1; mid=b+e; mid/=2;

	init(left,b,mid);
	init(right,mid+1,e);

	m[node].fl=m[node].sum=0;

}
