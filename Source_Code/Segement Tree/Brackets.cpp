#include<stdio.h>
#include<string.h>
#include<math.h>

char s[110000];
int a[110000];
int m[2000000];
int mi[2000000];
int flag;

void init(int node,int b,int e);
void update(int node,int b,int e,int n);

int main(){
	
	int i,j,k,l,n,q,t=1;

    //freopen("in.txt","r",stdin);
	int test=10;
	while(test--){
		scanf("%d",&n);
		
		memset(mi,0,sizeof(mi));
		scanf("%s",s);
		for(i=0;s[i];i++){
			if(s[i]=='('){
				a[i]=1;
			}
			else a[i]= -1;
		}
		flag=1;
		init(1,0,n-1);
		
		scanf("%d",&q);
		printf("Test %d:\n",t++);
		for(i=1;i<=q;i++){
			scanf("%d",&j);
			if(j==0){
				if(m[1]!=0||mi[1]!=0){
					printf("NO\n");
				}
				else printf("YES\n");
				
			}
			else{
				flag=1;
				update(1,0,n-1,j-1);
			}
			
		}
		
		
		
		
		
	}
	
	
	return 0;
}

void update(int node,int b,int e,int n){

	if(b==e){
		if(a[b]==1) a[b]=-1;
		else a[b]=1;

		if(a[b]==1){
			m[node]=1;
			mi[node]=0;
		}
		else {
			m[node]=0;
			mi[node]=1;
		}
		return ;
	}
	int mid=(b+e)/2;
	if(n<=mid){
		update(node*2,b,mid,n);
	}
	else update(node*2+1,mid+1,e,n);

	
	int sum1,sum2;
	sum1=m[node*2];
	sum2=mi[node*2+1];
	if(sum2>sum1){
		sum2-=sum1;
		sum1=0;
	}
	else{
		sum1-=sum2;
		sum2=0;
	}
	
	

	m[node]=m[node*2+1]+sum1;
	mi[node]=mi[node*2]+sum2;	


}



void init(int node,int b,int e){
	
	if(b==e){
		if(a[b]==1){
			m[node]=1;
			mi[node]=0;
		}
		else {
			m[node]=0;
			mi[node]=1;
		}
		return ;
	}

	int mid=floor((double)(b+e)/2.0);
	
	init(node*2,b,mid);
	init(node*2+1,mid+1,e);
	
	int sum1,sum2;
	sum1=m[node*2];
	sum2=mi[node*2+1];
	if(sum2>sum1){
		sum2-=sum1;
		sum1=0;
	}
	else{
		sum1-=sum2;
		sum2=0;
	}
	
	

	m[node]=m[node*2+1]+sum1;
	mi[node]=mi[node*2]+sum2;	

	
}