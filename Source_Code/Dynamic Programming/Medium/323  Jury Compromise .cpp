#include<stdio.h>
#include<string.h>

#define maxm 250
#define ii int
#define inf 1<<28

struct node{
	ii sum,diff;
	node(){} 
	node(ii a,ii b){sum=a; diff=b;}
};
struct node1{
	int i,j,k,l;
};

bool v[maxm][25][405][5];
node dp[maxm][25][405][5];
node1 pre[maxm][25][405][5];
int a[maxm],b[maxm],n,m,ans[25],ans1,ans2,tot;
node cal(int ind,int m,int diff,int fl);
int chck(node a,node b){
	if(a.diff==b.diff){
		if(a.sum>b.sum) return 1;
		return 0;
	}
	if(a.diff<b.diff) return 1;
	return 0;
}
void print(int i,int j,int k,int l);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){

		if(!n&&!m) break;

		for(i=1;i<=n;i++){
			scanf("%d %d",&a[i],&b[i]);
		}
		
		memset(v,0,sizeof(v));

		node ans3=cal(n,m,0,0);
		ans1=ans2=0; tot=0;
		print(n,m,0,0);
		printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",t++,ans1,ans2);
		for(i=tot-1;i>=0;i--){
			printf(" %d",ans[i]);
		}
		printf("\n\n");
		

	}	

	return 0;
}

void print(int i,int j,int k,int l){

	if(j==0) return ;
	if(i<=0) return ;
	int i1=pre[i][j][k][l].i; 
	int j1=pre[i][j][k][l].j;
	int k1=pre[i][j][k][l].k;
	int l1=pre[i][j][k][l].l;
	if(j1<j){
		ans1+=a[i]; ans2+=b[i];
		ans[tot++]=i;
	}
	print(i1,j1,k1,l1);
}

node cal(int ind,int m,int diff,int fl){

	if(m==0) return node(0,diff);
	if(ind<=0) return node(-inf,inf);

	if(v[ind][m][diff][fl]) return dp[ind][m][diff][fl];
	v[ind][m][diff][fl]=1;
	
	int val,val1,i,j,k,l,fl1;
	node ret,ret1;

	val=a[ind]-b[ind]; 
	if(fl==0){
		val1=diff+val;
	}
	else{
		val1=diff-val;
	}

	if(val1<0){
		fl1=!fl; val1*=-1;
	}
	else fl1=fl;

	ret1=cal(ind-1,m-1,val1,fl1);
	ret1.sum+=(a[ind]+b[ind]);
	ret=cal(ind-1,m,diff,fl);	

	if(chck(ret1,ret)){
		ret=ret1;
		pre[ind][m][diff][fl].i=ind-1;
		pre[ind][m][diff][fl].j=m-1;
		pre[ind][m][diff][fl].k=val1;
		pre[ind][m][diff][fl].l=fl1;
	}
	else{
		pre[ind][m][diff][fl].i=ind-1;
		pre[ind][m][diff][fl].j=m;
		pre[ind][m][diff][fl].k=diff;
		pre[ind][m][diff][fl].l=fl;
	}
	
	return dp[ind][m][diff][fl]=ret;
}