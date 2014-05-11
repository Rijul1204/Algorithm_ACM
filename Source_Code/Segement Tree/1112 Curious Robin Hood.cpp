#include<stdio.h>

struct tree{
	int sum;
};

tree m[2000000];
int a[100100];

void init(int node,int b,int e);
int update(int node,int b,int e,int n,int ex,int v);
int query(int node,int b,int e,int i,int j);

int main(){

	int i,j,k,l,test,n,q,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&q);

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		init(1,0,n-1);

		printf("Case %d:\n",t++);

		for(k=1;k<=q;k++){
			scanf("%d",&l);
			if(l==1){
				scanf("%d",&i);
				printf("%d\n",update(1,0,n-1,i,1,0));
			}
			else if(l==2){
				scanf("%d %d",&i,&j);
				update(1,0,n-1,i,2,j);
			}
			else if(l==3){
				scanf("%d %d",&i,&j);
				printf("%d\n",query(1,0,n-1,i,j));

			}


		}




	}

	return 0;
}

int update(int node,int b,int e,int n,int ex,int v){

	if(b==e){
		if(ex==1){
			int ret=a[b];
			a[b]=0;
			m[node].sum=0;
			return ret;
		}
		else if(ex==2){
			a[b]+=v;
			m[node].sum=a[b];
			return 0;
		}		
	}

	int left,right,mid,ret;
	
	mid=b+e; mid/=2;
	left=node<<1;
	right=left+1;

	if(n<=mid) ret=update(left,b,mid,n,ex,v);
	else if(n>mid) ret=update(right,mid+1,e,n,ex,v);

	m[node].sum=m[left].sum+m[right].sum;

	return ret;

}

int query(int node,int b,int e,int i,int j){

	if(b==e){
		return m[node].sum;
	}
	else if(b==i&&e==j) return m[node].sum;

	if(b>=i&&e<=j) return m[node].sum;

	int mid,left,right,ret,p1,p2;
	mid=b+e; mid/=2;
	left=node<<1; right=left+1;
	if(j<=mid) return query(left,b,mid,i,j);
	else if(i>mid) return query(right,mid+1,e,i,j);

	p1=query(left,b,mid,i,mid);
	p2=query(right,mid+1,e,mid+1,j);

	ret=p1+p2;

	return ret;

}

void init(int node,int b,int e){

	if(b==e){
		m[node].sum=a[b];
		return ;
	}

	int mid,left,right;
	mid=b+e;
	mid/=2;
	left=node<<1;
	right=left+1;
	
	init(left,b,mid);
	init(right,mid+1,e);

	m[node].sum=m[left].sum+m[right].sum;

}
