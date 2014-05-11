#include<stdio.h>

struct tree{
	int one;
	int two;
	int three;
	int zero;
	int ex;
};

tree  m[810010];
//int a[100100];

void init(int node,int b,int e);
void update(int node,int b,int e,int i,int j,int ex);
int query(int node,int b,int e,int i,int j); 

int main(){
	
	int i,j,k,l,test,n,q,ch,t=1;

//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d %d",&n,&q);
		
		init(1,0,n-1);
		printf("Case %d:\n",t++);
		for(k=1;k<=q;k++){
			scanf("%d %d %d",&ch,&i,&j);
			if(ch==0) update(1,0,n-1,i,j,1);
			else {
				printf("%d\n",query(1,0,n-1,i,j));
			}
		}
		
		
	}
	
	
	return 0;
}

int query(int node,int b,int e,int i,int j){

	
	if(b==e){
		if(m[node].zero) return 0;
		return m[node].three;
	}

	int left,right,mid,ret,p1,p2;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
	
	if(m[node].zero==0){
		m[left].zero=0;
		m[right].zero=0;
	}

	if(b==i&&e==j){
		if(m[node].zero) return 0;
		return m[node].three;
	}
	
	update(left,b,mid,b,mid,m[node].ex);
	update(right,mid+1,e,mid+1,e,m[node].ex);
	m[node].ex=0;

	if(j<=mid) return query(left,b,mid,i,j);
	else if(i>mid) return query(right,mid+1,e,i,j);
	
	p1=query(left,b,mid,i,mid);
	p2=query(right,mid+1,e,mid+1,j);

	ret=p1+p2;
	return ret;


	

}

void update(int node,int b,int e,int i,int j,int ex){
	
	int temp;
	if(ex==0) return ;
	
	if(b==e){
		m[node].ex=0;
		m[node].zero=0;
		if(ex==1){
			temp=m[node].one;
    		m[node].one=m[node].three;
    		m[node].three=m[node].two;
	    	m[node].two=temp;
		    return ;
		}
		if(ex==2){
			temp=m[node].one;
    		m[node].one=m[node].two;
    		m[node].two=m[node].three;
	    	m[node].three=temp;
		    return ;
		}
	}

    int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;
		
	if(m[node].zero==0){
		m[left].zero=0;
		m[right].zero=0;
	}
	
	if(b==i&&e==j){
		m[node].ex=(m[node].ex+ex)%3;
		m[node].zero=0;
		if(ex==1){
			temp=m[node].one;
    		m[node].one=m[node].three;
    		m[node].three=m[node].two;
	    	m[node].two=temp;
		    return ;
		}
		if(ex==2){
			temp=m[node].one;
    		m[node].one=m[node].two;
    		m[node].two=m[node].three;
	    	m[node].three=temp;
		    return ;
		}
		return;
	}
	

	m[node].zero=0;
	update(left,b,mid,b,mid,m[node].ex);
	update(right,mid+1,e,mid+1,e,m[node].ex);
	m[node].ex=0;

	if(j<=mid) update(left,b,mid,i,j,ex);
	else if(i>mid) update(right,mid+1,e,i,j,ex);
	else {
		update(left,b,mid,i,mid,ex);
		update(right,mid+1,e,mid+1,j,ex);
	}
	
	m[node].one=m[left].one+m[right].one;
	m[node].two=m[left].two+m[right].two;
	m[node].three=m[left].three+m[right].three;
	
}


void init(int node,int b,int e){
	
	if(b==e){
		m[node].one=0;
		m[node].three=1;
		m[node].two=0;
		m[node].zero=1;
		m[node].ex=0;
		return ;
	}
	int left,right,mid;
	left=node*2; right=left+1; mid=b+e; mid/=2;
	
	init(node*2,b,(b+e)/2);
	init(node*2+1,(b+e)/2+1,e);

	m[node].one=m[left].one+m[right].one;
	m[node].two=m[left].two+m[right].two;
	m[node].three=m[left].three+m[right].three;
	m[node].zero=1;
	m[node].ex=0;
	
}