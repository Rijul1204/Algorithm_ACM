#pragma warning (disable: 4786)
#pragma comment (linker, "/STACK:0x800000")


#include<stdio.h>
#include<string.h>

#define maxm 1024100

struct tree{
	int one;
	int ex;
};

tree m[4*maxm+1000];
char a[2*maxm];
char s[100000];

void init(int node,int b,int e);
void update(int node,int b,int e,int i,int j,int ex);
int query(int node,int b,int e,int i,int j);

int main(){
	
	int i,j,k,l,test,p,n,q,t=1;
	
    //freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		a[0]=a[1]='\0';
		
		scanf("%d",&p);
		int len=0;		
		
		for(i=1;i<=p;i++){
			scanf("%d",&l);
			scanf("%s",s);
			j=strlen(s);		
			for(k=1;k<=l;k++){
				strcpy(a+len,s);
				len+=j;
			}
		}
		a[len]='\0';
	//	puts(a);
		n=len;
		
		init(1,1,n);
		
		scanf("%d",&q);
		int q1=1;
		printf("Case %d:\n",t++);

		for(k=1;k<=q;k++){
		
			scanf("%s %d %d\n",s,&i,&j);
			i++; j++;
			if(s[0]=='F') update(1,1,n,i,j,1);
   			else if(s[0]=='E') update(1,1,n,i,j,2);
			else if(s[0]=='I') update(1,1,n,i,j,3);
			else if(s[0]=='S'){
				int ans=query(1,1,n,i,j);
			    printf("Q%d: %d\n",q1++,ans);
			}
		}
		
		
	}
	
	
	return 0;
}

int query(int node,int b,int e,int i,int j){

	if(b==e){
		return m[node].one;
	}

	if(b==i&&e==j){
		return m[node].one;
	}

	int left,right,mid,ret=0;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(m[node].ex!=0){
		update(left,b,mid,b,mid,m[node].ex);
		update(right,mid+1,e,mid+1,e,m[node].ex);
		m[node].ex=0;
	}

	if(j<=mid) return query(left,b,mid,i,j);
	else if(i>mid) return query(right,mid+1,e,i,j);
	else {
		ret=query(left,b,mid,i,mid);
		ret+=query(right,mid+1,e,mid+1,j);
	}
	return ret;

}

void update(int node,int b,int e,int i,int j,int ex){

	
	if(b==e){
		if(ex==1) m[node].one=1;
		else if(ex==2) m[node].one=0;
		else m[node].one=e-b+1-m[node].one;
		m[node].ex=0;
		return ;
	}

	int left,right,mid;
	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(b==i&&e==j){
		if(ex==3){
			if(m[node].ex==3){
				m[node].one=e-b+1-m[node].one; 
				m[node].ex=0; return;
			}
			else if(m[node].ex==1){
				m[node].one=0;				
				m[node].ex=2;
			}
			else if(m[node].ex==2){
				m[node].one=e-b+1;
				m[node].ex=1;
			}
			else{
				m[node].one=e-b+1-m[node].one;
				m[node].ex=3;
			}
			return ;
		}		
		else if(ex==1)m[node].one=e-b+1;
		else if(ex==2) m[node].one=0;		
		m[node].ex=ex;
		return ;
	}


	if(m[node].ex!=0){
		update(left,b,mid,b,mid,m[node].ex);
		update(right,mid+1,e,mid+1,e,m[node].ex);
		m[node].ex=0;
	}

	if(j<=mid) update(left,b,mid,i,j,ex);
	else if(i>mid) update(right,mid+1,e,i,j,ex);
	else {
		update(left,b,mid,i,mid,ex);
		update(right,mid+1,e,mid+1,j,ex);
	}
	m[node].one=m[left].one+m[right].one;
}

void init(int node,int b,int e){

	if(b>e) return ;
	
	if(b==e){
		if(a[b-1]=='1'){
			m[node].one=1;
		}
		else{
			m[node].one=0;
		}
		m[node].ex=0;
		return ;
	}
	
	int mid,left,right;
	
	mid=b+e;
	mid/=2;
	left=node<<1; right=left+1;
	
	init(left,b,mid);
	init(right,mid+1,e);
	
	m[node].one=m[left].one+m[right].one; m[node].ex=0;
	
	
}
