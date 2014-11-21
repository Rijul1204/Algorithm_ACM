#include<stdio.h>
#include<string.h>

#define maxm 100100

struct tree{
	int fl,sum1,sum0;
};

tree m[4*maxm];
int n,q;

void init(int node,int b,int e);
void update(int node,int b,int e,int x,int y);
int query(int node,int b,int e,int x,int y);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&q)==2){

		init(1,1,n);

		for(i=1;i<=q;i++){
			scanf("%d %d %d",&j,&k,&l);
			if(j==0){
				update(1,1,n,k,l);
			}
			else{
				printf("%d\n",query(1,1,n,k,l));
			}
		}

	}

	return 0;
}

int query(int node,int b,int e,int x,int y){

	int temp,ret=0;

	if(b==e){
		return m[node].sum1;
	}

	if(b==x&&e==y){
		return m[node].sum1;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	if(m[node].fl){
		update(left,b,mid,b,mid);
		update(right,mid+1,e,mid+1,e);
		m[node].fl=0;
		m[node].sum0=m[left].sum0+m[right].sum0;
		m[node].sum1=m[left].sum1+m[right].sum1;
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

void update(int node,int b,int e,int x,int y){

	int temp;

	if(b==e){			
		temp=m[node].sum0;
		m[node].sum0=m[node].sum1;
		m[node].sum1=temp;
		return ;
	}

	if(b==x&&e==y){
		m[node].fl=!m[node].fl;
		temp=m[node].sum0;
		m[node].sum0=m[node].sum1;
		m[node].sum1=temp;
		return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	if(m[node].fl){
		update(left,b,mid,b,mid);
		update(right,mid+1,e,mid+1,e);
		m[node].fl=0;
	}

	if(y<=mid){
		update(left,b,mid,x,y);
	}
	else if(x>mid){
		update(right,mid+1,e,x,y);
	}
	else{
		update(left,b,mid,x,mid);
		update(right,mid+1,e,mid+1,y);
	}

	m[node].sum0=m[left].sum0+m[right].sum0;
	m[node].sum1=m[left].sum1+m[right].sum1;

}

void init(int node,int b,int e){

	if(b==e){
		m[node].fl=m[node].sum1=0;
		m[node].sum0=1;
		return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	init(left,b,mid);
	init(right,mid+1,e);
	
	m[node].fl=m[node].sum1=0;
	m[node].sum0=e-b+1;

}