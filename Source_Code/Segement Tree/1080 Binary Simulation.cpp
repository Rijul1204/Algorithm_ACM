#include<stdio.h>
#include<string.h>

struct tree{
	int sum;
	int flag;
};

tree m[901111];
char a[300000];

void init(int node,int beg,int end);
void update(int node,int b,int e,int i,int j);
int query(int node,int b,int e,int i,int j);

int main(){
	
	int i,j,k,l,test,n,q,t=1;
	char s[1000];
	
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%s",a);
		n=strlen(a);
		init(1,0,n-1);
		
		scanf("%d",&q);
		
		printf("Case %d:\n",t++);
		
		for(k=1;k<=q;k++){
			scanf("%s",s);
			if(s[0]=='I'){
				scanf("%d %d",&i,&j);
				update(1,0,n-1,i-1,j-1);
				
			}
			else {
				scanf("%d",&i);
				int ans=query(1,0,n-1,i-1,i-1);
				printf("%d\n",ans);
				
			}
			
		}
		
		
	}
	
	
	return 0;
}

void init(int node,int beg,int end){
	
	if(beg==end){
		if(a[beg]=='1') m[node].sum=1;
		else m[node].sum=0;
		m[node].flag=0;
		return ;
	}
	
	m[node].flag=0;
	
	int left,right,mid;
	left=node<<1; right=left+1; 
	
	mid=beg+end; 
	mid/=2;
	
	init(left,beg,mid);
	init(right,mid+1,end);
	m[node].sum=m[node*2].sum+m[node*2+1].sum;
	
}

int query(int node,int b,int e,int i,int j){

	//int p1,p2;
	
	if(b==e){
		if(m[node].flag==1){
			if(m[node].sum==1){
				a[b]='0';
				m[node].sum=0;
			}
			else {
				a[b]='1'; 
				m[node].sum=1;
			}
		}
		m[node].flag=0;
		return m[node].sum;
	}

	int mid=b+e; 
	mid/=2;
	
	if(m[node].flag){
		m[node].flag=0;
		m[node].sum=e-b+1-m[node].sum;
		m[node*2].flag=!m[node*2].flag;
		m[node*2+1].flag=!m[node*2+1].flag;
	}

	if(i<=mid) return query(node*2,b,mid,i,j);
	else return query(node*2+1,mid+1,e,i,j);

}
/*
int query(int node,int b,int e,int i,int j){
	
	int p1,p2;
	
	if(i>e||j<b) return 0;
	
	if(b>=i&&e<=j){
		
		if(b==e){
			if(m[node].flag){
				if(m[node].sum==1) m[node].sum=0;
				else if(m[node].sum==0) m[node].sum=1;
				m[node].flag=0;
				return m[node].sum;
			}
			else return m[node].sum;
		}
		
		else if(m[node].flag){
			m[node].flag=0;
			m[node*2].flag=!m[node*2].flag;
			m[node*2+1].flag=!m[node*2].flag;
			p1=query(node*2,b,(b+e)/2,i,j);
			p2=query(node*2+1,(b+e)/2+1,e,i,j);
			return m[node].sum=p1+p2;
		}
		else return m[node].sum;
	}
	
	if(m[node].flag){
		m[node].flag=0;
		m[node*2].flag=!m[node*2].flag;
		m[node*2+1].flag=!m[node*2+1].flag;
	}
	p1=query(node*2,b,(b+e)/2,i,j);
	p2=query(node*2+1,(b+e)/2+1,e,i,j);
	
	return m[node].sum=p1+p2;	
	
}

*/
void update(int node,int b,int e,int i,int j){

	if(b==e){	
		m[node].flag=!m[node].flag;
		if(m[node].flag==1){
			if(m[node].sum==1){
				a[b]='0';
				m[node].sum=0;
			}
			else {
				a[b]='1'; 
				m[node].sum=1;
			}		
		}
		m[node].flag=0;
		return;
	}

	if(b==i&&e==j){
		if(m[node].flag){
			m[node].flag=0;
			return;
		}
		m[node].sum=e-b+1-m[node].sum;
		m[node*2].flag=!m[node*2].flag;
		m[node*2+1].flag=!m[node*2+1].flag;
		return;
	}

	if(m[node].flag){
		m[node].flag=0;
		m[node*2].flag=!m[node*2].flag;
		m[node*2+1].flag=!m[node*2+1].flag;
	}
	int mid=b+e; 
	mid/=2;
	if(j<=mid) update(node*2,b,mid,i,j); 
	else if(i>mid) update(node*2+1,mid+1,e,i,j);
	else {
		update(node*2,b,mid,i,mid);
		update(node*2+1,mid+1,e,mid+1,j);
	}
	m[node].sum=m[node*2].sum+m[node*2+1].sum;
	
}
/*
int update(int node,int b,int e,int i,int j){
	
	int p1,p2;
	
	if(i<b||j>e) return 0;
	
	if(b==e){
		m[node].flag=!m[node].flag;
		if(m[node].flag){
			if(m[node].sum==1) m[node].sum=0;
			else if(m[node].sum==0) m[node].sum=1;
			m[node].flag=0;
			return m[node].sum;
		}
		else return m[node].sum;	
	}
	
	if(b==i&&e==j){
		m[node].flag=!m[node].flag;
		m[node*2].flag=!m[node*2].flag;
		m[node*2+1].flag=!m[node*2].flag;
		
		
	}
	
	
	//		m[node].flag=!m[node].flag;
	if(b==e){
		
	}	
	
	//	m[node*2].flag=!m[node*2].flag;
	//	m[node*2+1].flag=!m[node*2+1].flag;
	//		return m[node].sum=e-b+1-m[node].sum;		
	
	if(m[node].flag){
		m[node].flag=!m[node].flag;
		m[node*2].flag=!m[node*2].flag;
		m[node*2+1].flag=!m[node*2+1].flag;
	}
	
	p1 = update(2*node,b,(b + e)/2,i,(b+e)/2);
    p2 = update(2*node+1,(b + e)/2+1,e,(b+e)/2+1,j);
    if(p1==-1)
		p1=0;
    if(p2==-1)
		p2=0;
	
	return p1+p2;
	
}
*/