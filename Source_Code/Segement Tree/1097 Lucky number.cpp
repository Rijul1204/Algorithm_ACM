#include<stdio.h>
#include<string.h>

#define maxm 1439431

struct tree{
	int sum;
};

tree m[3*maxm+100];
int n;

void build();
void init(int node,int b,int e);
void update(int node,int b,int e,int sum);
int query(int node,int b,int e,int sum);

int main(){

	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);

	scanf("%d",&test);
	
	n=1429440;
	
	build();

	while(test--){

		scanf("%d",&k);

		printf("Case %d: %d\n",t++,query(1,1,n,k));

	}

	return 0;

}

void build(){

	int i,j,k,l;

	init(1,1,n);
	l=2;

	k=query(1,1,n,l);
	for(i=1;i*k-(i-1)<=m[1].sum;i++){
		update(1,1,n,i*k-(i-1));
	}

	while(1){
		k=query(1,1,n,l);
		if(m[1].sum<k) break;
		for(i=1;i*k-(i-1)<=m[1].sum;i++){
			update(1,1,n,i*k-(i-1));
		}		
		l++;
	}
	//printf("%d\n",k);

}

void update(int node,int b,int e,int sum){
	
	if(b==e){
		m[node].sum=0; return ;
	}

	int left,right,mid,k,l;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	if(sum<=m[left].sum) update(left,b,mid,sum);
	else update(right,mid+1,e,sum-m[left].sum);

	m[node].sum=m[right].sum+m[left].sum;

}

int query(int node,int b,int e,int sum){

	if(b==e){
		return b;
	}

	int left,right,mid,k,l;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	if(sum<=m[left].sum) return query(left,b,mid,sum);
	else return query(right,mid+1,e,sum-m[left].sum);

}
void init(int node,int b,int e){

	if(b==e){
		m[node].sum=1; return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	init(left,b,mid);
	init(right,mid+1,e);

	m[node].sum=m[left].sum+m[right].sum;
}
