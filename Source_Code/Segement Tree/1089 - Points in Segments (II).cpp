#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

#define maxm 701100

struct node{
	int k,l;
};

struct tree{
	int num,rem;
};

map<int,int>num;
tree m[maxm];
node que[50110]; 
int n,q,a[50100],b[maxm],c=0;

int query(int node,int b,int e,int p);
void update(int node,int b,int e,int x,int y,int val);
void init(int node,int b,int e);


int main(){

	int i,j,k,l,test,t=1;

   // freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&n,&q);
		num.clear(); c=0;

		for(i=1;i<=n;i++){
			scanf("%d %d",&k,&l);
			que[i].k=k; que[i].l=l;
			if(!num[k]){
				b[c++]=k; num[k]=1;
			}
			if(!num[l]){
				b[c++]=l; num[l]=1;
			}
		}
		for(i=1;i<=q;i++){
			scanf("%d",&a[i]);
			if(!num[a[i]]){
				b[c++]=a[i]; num[a[i]]=1;
			}
		}

		sort(b,b+c); num.clear();

		for(i=0;i<c;i++){
			num[b[i]]=i+1;
		}
		init(1,1,c);		
		for(i=1;i<=n;i++){
			k=que[i].k; l=que[i].l;
			k=num[k]; l=num[l];
			update(1,1,c,k,l,1);
		}
		printf("Case %d:\n",t++);
		for(i=1;i<=q;i++){
			k=num[a[i]];
			printf("%d\n",query(1,1,c,k));
		}

	}

	return 0;
}

int query(int node,int b,int e,int p){

	if(b==e){
		return m[node].num;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	if(m[node].rem!=0){
		update(left,b,mid,b,mid,m[node].rem);
		update(right,mid+1,e,mid+1,e,m[node].rem);
		m[node].rem=0;
	}

	if(p<=mid){
		return query(left,b,mid,p);
	}
	else{
		return query(right,mid+1,e,p);
	}
}

void update(int node,int b,int e,int x,int y,int val){

	if(b==e){
		m[node].num+=val; m[node].rem=0;
		return ;
	}
	if(b==x&&e==y){
		m[node].num+=val; m[node].rem+=val;
		return ;
	}
	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	if(m[node].rem!=0){
		update(left,b,mid,b,mid,m[node].rem);
		update(right,mid+1,e,mid+1,e,m[node].rem);
		m[node].rem=0;
	}

	if(y<=mid){
		update(left,b,mid,x,y,val);
	}
	else if(x>mid){
		update(right,mid+1,e,x,y,val);
	}
	else{
		update(left,b,mid,x,mid,val);
		update(right,mid+1,e,mid+1,y,val);
	}
	m[node].num=m[left].num+m[right].num;
}

void init(int node,int b,int e){

	if(b==e){
		m[node].num=0;
		m[node].rem=0;
		return ;
	}
	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	init(left,b,mid);
	init(right,mid+1,e);

	m[node].num=m[node].rem=0;

}