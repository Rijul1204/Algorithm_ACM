#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxm 10100

int n,H,tree[maxm][4];

int dfs(int beg,int end,int h);
void pre(int ind);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&H)==2){

		if(!n&&!H) break;
		k=pow(2,H);
		k--;		
		printf("Case %d:",t++);
		if(k<n){
			printf(" Impossible.\n");
			continue;
		}
		int root=dfs(1,n,H);	 
	    pre(root);
		printf("\n");

	}
	return 0;
}

void pre(int ind){
	
	if(ind==0) return ;	
	printf(" %d",ind);
	pre(tree[ind][1]);
	pre(tree[ind][2]);
}

int dfs(int beg,int end,int h){
	
	if(beg>end) return 0;
	if(h==0) return 0;

	int i,j,k;

	for(i=beg;i<=end;i++){
		k=pow(2,h-1);
		if((k-1)>=(end-i)) break;
	}
	
//	printf("%d\n",i);
	tree[i][1]=dfs(beg,i-1,h-1);
	tree[i][2]=dfs(i+1,end,h-1);

	return i;
}