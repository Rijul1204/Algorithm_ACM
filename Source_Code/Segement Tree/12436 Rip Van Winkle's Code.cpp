#include<stdio.h>
#include<string.h>

#define maxm 250000
#define ii long long int
struct tree{
	ii fl,st,val,sum;
};

tree m[4*maxm];
int n,q;
char s[5];

void init(int node,int b,int e);
void update(int node,int b,int e,int x,int y,int type,ii st,ii val);
ii query(int node,int b,int e,int x,int y);
ii data[250001];
void A( int st, int nd ) {
    for( int i = st; i <= nd; i++ ) data[i] = data[i] + (i - st + 1);
}
void B( int st, int nd ) {
    for( int i = st; i <= nd; i++ ) data[i] = data[i] + (nd - i + 1);
}
void C( int st, int nd, int x ) {
    for( int i = st; i <= nd; i++ ) data[i] = x;
}
ii S( int st, int nd ) {
    ii res = 0;
    for( int i = st; i <= nd; i++ ) res += data[i];
    return res;
}

int main(){
	int i;
	ii j,k,l,test,t=1;
	ii v;

   // freopen("in.txt","r",stdin);

	n=250003;
	scanf("%d",&q);

	init(1,1,n);

	//printf("Case %d:\n",t++);

	for(i=1;i<=q;i++){
		scanf("%s %lld %lld",s,&k,&l);
		if(s[0]=='A'){
		   // A(k,l);
			update(1,1,n,k,l,1,1,1);
		}
		else if(s[0]=='B'){
		   // B(k,l);
			update(1,1,n,k,l,1,(l-k+1),-1);
		}
		else if(s[0]=='C'){
		    scanf("%lld",&j);
			//C(k,l,j);
			update(1,1,n,k,l,2,j,0);
		}
		else{
			v=query(1,1,n,k,l);
           // printf("%lld ",S(k,l));
			printf("%lld\n",v);
		}
	}


	return 0;
}

ii query(int node,int b,int e,int x,int y){

	if(b==e){
		return m[node].sum;
	}

	ii k=e-b+1,l;
	if(b==x&&e==y){
		return m[node].sum;
	}

	int left,right,mid;
	ii ret=0;

	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(m[node].fl){
	    ii st1=m[node].st,val1=m[node].val;
	    if(m[node].fl==1||m[node].fl==3){
	    	update(left,b,mid,b,mid,m[node].fl,st1,val1);
			k=(mid-b+1);
            k=(st1+k*val1);
			update(right,mid+1,e,mid+1,e,m[node].fl,k,val1);
	    }
	    if(m[node].fl==2){
	        update(left,b,mid,b,mid,m[node].fl,m[node].st,0);
		    update(right,mid+1,e,mid+1,e,m[node].fl,m[node].st,0);
	    }
	    m[node].fl=0; m[node].st=0; m[node].val=0;
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

void update(int node,int b,int e,int x,int y,int type,ii st,ii val){

	if(b==e){
		m[node].fl=m[node].st=m[node].val=0;
		if(type==2||type==3) m[node].sum=st;
		else m[node].sum+=st;
		return ;
	}

	ii k=e-b+1,l;
	int fl=m[node].fl;

	int left,right,mid;

	left=node<<1; right=left+1; mid=b+e; mid/=2;

	if(b==x&&e==y){
		if(type==1){
			l=st+(k-1)*val;
			ii tw=2,v=(st+l)*k;
			m[node].sum+=(v/tw);
			if(fl==0){
				m[node].st=st; m[node].val=val;
				m[node].fl=1;
            }
			else if(fl==1){

				m[node].st+=st; m[node].val+=val;
				m[node].fl=1;
            }
			else if(fl==2){
				m[node].st=m[node].st+st; m[node].val=val;
				m[node].fl=3;
			}
			else if(fl==3){
				m[node].st=m[node].st+st; m[node].val+=val;
				m[node].fl=3;
			}

		}
		if(type==2){
			k=e-b+1; m[node].sum=(k*st);
		    m[node].st=st; m[node].fl=2; m[node].val=0;
		}
		if(type==3){
			l=st+(k-1)*val;
			ii tw=2,v=(st+l)*k;
			m[node].sum=(v/tw);

			m[node].st=st; m[node].val=val;
			m[node].fl=3;
		}

		return ;
	}



	if(m[node].fl){
	    ii st1=m[node].st,val1=m[node].val;
	    if(m[node].fl==1||m[node].fl==3){
	    	update(left,b,mid,b,mid,m[node].fl,st1,val1);
			k=(mid-b+1);
            k=(st1+k*val1);
			update(right,mid+1,e,mid+1,e,m[node].fl,k,val1);
	    }
	    if(m[node].fl==2){
	        update(left,b,mid,b,mid,m[node].fl,m[node].st,0);
		    update(right,mid+1,e,mid+1,e,m[node].fl,m[node].st,0);
	    }
	    m[node].fl=0; m[node].st=0; m[node].val=0;
	}

	if(y<=mid){
		update(left,b,mid,x,y,type,st,val);
	}
	else if(x>mid){
		update(right,mid+1,e,x,y,type,st,val);
	}
	else{
		if(type==1||type==3){
			k=(mid-x+1);
			k=st+(k*val);
            update(left,b,mid,x,mid,type,st,val);
			update(right,mid+1,e,mid+1,y,type,k,val);
		}
		else if(type==2){
		    update(left,b,mid,x,mid,type,st,val);
		    update(right,mid+1,e,mid+1,y,type,st,val);
		}
	}

	m[node].sum=m[left].sum+m[right].sum;

}

void init(int node,int b,int e){

	if(b==e){
		m[node].fl=m[node].sum=m[node].st=m[node].val=0;
		return ;
	}

	int left,right,mid;

	left=node<<1; right=left+1; mid=b+e; mid/=2;

	init(left,b,mid);
	init(right,mid+1,e);

    m[node].fl=m[node].sum=m[node].st=m[node].val=0;

}
