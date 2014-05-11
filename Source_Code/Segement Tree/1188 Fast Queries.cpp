#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 100100

struct tree{
	int sum;
};

struct node{
	int type,beg,end,ind;
};
node nodes[2*maxm];
tree m[3*maxm+1000];
bool comp(node a,node b){
	if(a.end==b.end) return a.type<b.type;
	return a.end<b.end;
}

int n,q,ans[50100],a[maxm];

void init(int node,int b,int e);
void update(int node,int b,int e,int x,int fl);
int query(int node,int b,int e,int x,int y);


int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&q);

		int c=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			nodes[c].beg=k; nodes[c].end=i; nodes[c].type=1; nodes[c].ind=i;
			c++;
		}
		for(i=1;i<=q;i++){
			scanf("%d %d",&k,&l);
			nodes[c].beg=k; nodes[c].end=l; nodes[c].type=2; nodes[c].ind=i;
			c++;
		}
		sort(nodes,nodes+c,comp);
		
		memset(a,-1,sizeof(a));
		init(1,1,n);

		for(i=0;i<c;i++){
			k=nodes[i].beg; l=nodes[i].end;
			if(nodes[i].type==1){
				if(a[k]==-1){
					a[k]=l;
					update(1,1,n,l,1);
				}
				else{
					update(1,1,n,a[k],0);
					a[k]=l;
					update(1,1,n,l,1);
				}
			}
			else{
				ans[nodes[i].ind]=query(1,1,n,k,l);
			}
		}

		printf("Case %d:\n",t++);
		for(i=1;i<=q;i++){
			printf("%d\n",ans[i]);
		}
	}

	return 0;
}

int query(int node,int b,int e,int x,int y){

	if(b==e){
		return m[node].sum;
	}

	if(b==x&&e==y) return m[node].sum;

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

void update(int node,int b,int e,int x,int fl){

	if(b==e){
		m[node].sum=fl;
		return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(x<=mid) update(left,b,mid,x,fl);
	else update(right,mid+1,e,x,fl);

	m[node].sum=m[left].sum+m[right].sum;

}

void init(int node,int b,int e){

	if(b==e){
		m[node].sum=0;
		return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	init(left,b,mid);
	init(right,mid+1,e);

	m[node].sum=0;
}