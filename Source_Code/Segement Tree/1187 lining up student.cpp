#include<stdio.h>
#include<string.h>

#define maxm 100100

struct tree{
	int sum;
};

tree m[3*maxm+1000];

int n,a[maxm];

void init(int node,int b,int e);
void update(int node,int b,int e,int sum);
int query(int node,int b,int e,int sum);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}

		init(1,1,n);

		for(i=n;i>1;i--){
			k=i-a[i];
			update(1,1,n,k);
		}
		printf("Case %d: %d\n",t++,query(1,1,n,1));

	}

	return 0;
}


int query(int node,int b,int e,int sum){

	if(b==e){
		return b;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	if(m[left].sum>=sum) return query(left,b,mid,sum);
	else query(right,mid+1,e,sum-m[left].sum);

}


void update(int node,int b,int e,int sum){

	if(b==e){
		m[node].sum=0;
		return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	if(m[left].sum>=sum) update(left,b,mid,sum);
	else update(right,mid+1,e,sum-m[left].sum);

	m[node].sum=m[left].sum+m[right].sum;

}


void init(int node,int b,int e){

	if(b==e){
		m[node].sum=1;
		return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	init(left,b,mid);
	init(right,mid+1,e);

	m[node].sum=m[left].sum+m[right].sum;

}