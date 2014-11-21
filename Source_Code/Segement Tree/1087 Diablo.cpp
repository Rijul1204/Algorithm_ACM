#include<stdio.h>
#include<string.h>

#define maxm 600100

struct tree{
	int num;
};
tree m[maxm];
int a[150000],n,q,tot,now,c;
char s[10];

void init(int node,int b,int e);
void update(int node,int b,int e,int ind);
int query(int node,int b,int e,int k);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&n,&q);
		
		tot=n+q; now=0; c=1;
		init(1,1,tot);		
		
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			a[c++]=k; now++;
			update(1,1,tot,c-1);
		}
		
		printf("Case %d:\n",t++);
		
		for(i=1;i<=q;i++){
			scanf("%s %d",s,&k);
			if(s[0]=='a'){
				now++;
				a[c++]=k;
				update(1,1,tot,c-1);
			}
			else{
				if(k>now){
					printf("none\n");
					continue;
				}
				printf("%d\n",query(1,1,tot,k));
				now--;
			}
		}

	}

	return 0;
}

int query(int node,int b,int e,int k){

	if(b==e){
		m[node].num=0;
		return a[b];
	}

	
	int left,right,mid,ret=0;
	left=node<<1; right=left+1; mid=b+e; mid/=2;		

	if(k<=m[left].num){
		ret=query(left,b,mid,k);
	}
	else{
		ret=query(right,mid+1,e,k-m[left].num);
	}		
	m[node].num=m[left].num+m[right].num;
	
	return ret;
}

void update(int node,int b,int e,int k){

	if(b==e){
		m[node].num=1;
		return ;
	}

	int left,right,mid,ret=0;
	left=node<<1; right=left+1; mid=b+e; mid/=2;		

	if(k<=mid){
		update(left,b,mid,k);
	}
	else{
		update(right,mid+1,e,k);
	}		
	m[node].num=m[left].num+m[right].num;

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
