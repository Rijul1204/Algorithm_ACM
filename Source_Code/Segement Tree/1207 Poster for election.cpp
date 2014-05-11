#include<stdio.h>
#include<string.h>

#define maxm 600100

struct tree{
	int num;
};
struct query{
	int k,l;
};

query q[100010];
tree m[maxm];
int n;
void init(int node,int b,int e);
int update(int node,int b,int e,int x,int y);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d",&n);
		init(1,1,2*n);		
		for(i=1;i<=n;i++){
			scanf("%d %d",&k,&l);
			q[i].k=k; q[i].l=l;		
		//	update(1,1,2*n+1,k,l,i);
		}
		int ans=0;
		for(i=n;i>=1;i--){
			k=q[i].k; l=q[i].l;
			if(update(1,1,2*n,k,l)) ans++;
		}
		printf("Case %d: %d\n",t++,ans);

	}

	return 0;
}
int update(int node,int b,int e,int x,int y){
	
	if(m[node].num==e-b+1) return 0;

	if(b==e){
		m[node].num=1;
		return 1;
	}

	int left,right,mid,ret=0;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(b==x&&e==y){
		m[node].num=e-b+1;
//		update(left,b,mid,b,mid);		
//		update(right,mid+1,e,mid+1,e);
		return 1;
	}

		

	if(y<=mid){
		ret=update(left,b,mid,x,y);
	}
	else if(x>mid){
		ret=update(right,mid+1,e,x,y);
	}
	else{
		ret=update(left,b,mid,x,mid);
		if(update(right,mid+1,e,mid+1,y)) ret=1;
	}
		
	m[node].num=m[left].num+m[right].num;
	return ret;
}

void init(int node,int b,int e){

	if(b==e){
		m[node].num=0;	
		return ;
	}
	
	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	init(left,b,mid);
	init(right,mid+1,e);	

	m[node].num=0;

}