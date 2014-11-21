#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 100100
#define inf 1<<28
#define mini(a,b) ((a)<(b))?a:b
#define maxi(a,b) ((a)>(b))?a:b

struct tree{
	int min1,max1;
};

tree m[3*maxm+100];
vector<tree>v,temp;
int n,range,a[maxm];

void init(int node,int b,int e);
void update(int node,int b,int e,int x,int val);
tree query(int node,int b,int e,int x,int y);
int bs();
int f(int d);

int main(){
	
	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);


	scanf("%d %d",&n,&range);

	init(1,1,n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		update(1,1,n,i,a[i]);
	}
	
	printf("%d",bs());
	k=0;
	for(i=0;i<v.size();i++){
		k++;
	}
	printf(" %d\n",k);
	for(i=0;i<v.size();i++){
		printf("%d %d\n",v[i].max1,v[i].min1);
	}

	return 0;
}

int bs(){

	int i,j,k,l;
	int lo=1,hi=n,mid;
	f(1);

	while(lo<hi){

		mid=lo+hi; mid/=2;

		if(f(mid)){
			if(lo==mid){
				if(f(mid+1)) return mid+1;
		    	return mid;
			}
			lo=mid;
		}
		else hi=mid-1;
	}

	return lo;

}

int f(int d){

	temp.clear();
	int i,j,k,l;
	tree val;
	
	for(i=1;i<=n;i++){
		if(i+d-1>n) break;
		val=query(1,1,n,i,i+d-1);
		k=val.max1; l=val.min1;
		if(k-l>range) continue;
		// here  tree.max1=starting day tree.min1=ending day... 
		val.max1=i; val.min1=i+d-1;
		temp.push_back(val);
	}

	if(temp.size()==0) return 0;
	v.clear();
	for(i=0;i<temp.size();i++){
		v.push_back(temp[i]);
	}
	
	return 1;
}

tree query(int node,int b,int e,int x,int y){

	if(b==e){		
		return m[node];
	}

	if(b==x&&e==y) return m[node];

	int left,right,mid,k,l;
	tree ret,ret1;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(y<=mid) return query(left,b,mid,x,y);
	else if(x>mid) return query(right,mid+1,e,x,y);
	else{
		ret=query(left,b,mid,x,mid);
		ret1=query(right,mid+1,e,mid+1,y);
	}
	ret.max1=maxi(ret.max1,ret1.max1);
	ret.min1=mini(ret.min1,ret1.min1);
	
	return ret;

}
void update(int node,int b,int e,int x,int val){

	if(b==e){
		m[node].max1=val;
		m[node].min1=val;
		return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(x<=mid) update(left,b,mid,x,val);
	else update(right,mid+1,e,x,val);
	
	m[node].max1=maxi(m[left].max1,m[right].max1);
	m[node].min1=mini(m[left].min1,m[right].min1);

}

void init(int node,int b,int e){

	if(b==e){
		m[node].max1=-inf;
		m[node].min1=inf;
		return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	init(left,b,mid);
	init(right,mid+1,e);
	
	m[node].max1=-inf;
	m[node].min1=inf;
}