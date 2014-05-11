#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 100110
#define ii long long int

struct tree{
	ii val,ind;
};
tree m[4*maxm+100];

struct tree1{
	int sum;
};
tree1 m1[4*maxm+100];

struct quer{
	ii beg,end,type,ind;
	ii val;
};

quer q[3*maxm];
int n,tot;
ii h[maxm];
int a[maxm],c[maxm];

int query(int node,int b,int e,int x,int y);
void update1(int node,int b,int e,int x,int fl);
ii query1(int node,int b,int e,int x,int y,int val);
ii query2(int node,int b,int e,int x,int y,int val);
void init(int node,int b,int e);
void init1(int node,int b,int e);
bool comp(quer a,quer b){
	if(a.end==b.end) return a.type<b.type;
	return a.end<b.end;
}
ii maxi(ii a,ii b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&tot)==2){

		if(!n&&!tot) break;

		for(i=1;i<=n;i++){
			scanf("%lld",&h[i]);
		}
		if(n==1){
		    scanf("%d",&c[1]);
		    if(tot==1) printf("%lld\n",h[1]);
		    else printf("0\n");
		    continue;
		}



		init(1,1,n);

		k=query1(1,1,n,2,n,h[1]);
		q[0].beg=1; q[0].end=k-1;
		q[0].val=h[1]; q[0].type=2; q[0].ind=0;

		k=query2(1,1,n,1,n-1,h[n]);
		q[1].beg=k+1; q[1].end=n; q[1].ind=n;
		q[1].val=h[n]; q[1].type=2;

		for(i=2;i<n;i++){
			k=query2(1,1,n,1,i-1,h[i]);
			l=query1(1,1,n,i+1,n,h[i]);
			q[i].beg=k+1; q[i].end=l-1;
			q[i].val=h[i]; q[i].type=2; q[i].ind=i;
		}
		for(i=1;i<=n;i++){
			scanf("%d",&c[i]);
			q[n+i-1].beg=i; q[n+i-1].end=i; q[n+i-1].type=1;
			q[n+i-1].val=c[i]+1;
		}
		sort(q,q+(2*n),comp);

		init1(1,1,n);

		quer q1;
		ii ans=0;

		memset(a,0,sizeof(a));

		for(i=0;i<2*n;i++){
			q1=q[i];
			if(q1.type==1){
				k=q1.val;
				if(a[k]!=0){
					update1(1,1,n,a[k],0);
				}
				update1(1,1,n,q1.end,1);
				a[k]=q1.end;
			}
			else{
				k=query(1,1,n,q1.beg,q1.end);
				if(k!=tot) continue;
				ii val=(q1.end-q1.beg+1)*q1.val;
				ans=maxi(ans,val);
			}
		}

		printf("%lld\n",ans);

	}

	return 0;
}

int query(int node,int b,int e,int x,int y){

	if(b==e) return m1[node].sum;

	if(b==x&&e==y) return m1[node].sum;

	int left,right,mid,ret=0;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(y<=mid) return query(left,b,mid,x,y);
	else if(x>mid) return query(right,mid+1,e,x,y);
	else{
		ret=query(left,b,mid,x,mid);
		ret+=query(right,mid+1,e,mid+1,y);
	}

	return ret;
}

void update1(int node,int b,int e,int x,int fl){

	if(b==e){
		m1[node].sum=fl; return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(x<=mid) update1(left,b,mid,x,fl);
	else update1(right,mid+1,e,x,fl);

	m1[node].sum=m1[left].sum+m1[right].sum;

}

//Immediate left
ii query2(int node,int b,int e,int x,int y,int val){

	if(m[node].val>=val) return b-1;

	if(b==e){
		if(m[node].val>=val) return b-1;
		return m[node].ind;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(b==x&&e==y){
		if(m[right].val<val) return query2(right,mid+1,e,mid+1,e,val);
		return query2(left,b,mid,b,mid,val);
	}

	if(y<=mid) return query2(left,b,mid,x,y,val);
	if(x>mid) return query2(right,mid+1,e,x,y,val);
	else{
		ii ret=query2(right,mid+1,e,mid+1,y,val);
		if(ret<=mid) return query2(left,b,mid,x,mid,val);
		return ret;
	}


}

//Immediate right
ii query1(int node,int b,int e,int x,int y,int val){

	if(m[node].val>=val) return e+1;

	if(b==e){
		if(m[node].val>=val) return e+1;
		return m[node].ind;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(b==x&&e==y){
		if(m[left].val<val) return query1(left,b,mid,b,mid,val);
		return query1(right,mid+1,e,mid+1,e,val);
	}

	if(y<=mid) return query1(left,b,mid,x,y,val);
	if(x>mid) return query1(right,mid+1,e,x,y,val);
	else{
		ii ret=query1(left,b,mid,x,mid,val);
		if(ret>mid) return query1(right,mid+1,e,mid+1,e,val);
		return ret;
	}

}



void init1(int node,int b,int e){

	if(b==e){
		m1[node].sum=0;
		return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	init1(left,b,mid);
	init1(right,mid+1,e);

	m1[node].sum=0;

}

void init(int node,int b,int e){

	if(b==e){
		m[node].ind=b; m[node].val=h[b];
		return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	init(left,b,mid);
	init(right,mid+1,e);

	if(m[left].val<m[right].val){
		m[node]=m[left];
	}
	else{
		m[node]=m[right];
	}

}
