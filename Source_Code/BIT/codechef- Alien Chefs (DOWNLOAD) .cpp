#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

#define maxm 6000000
#define maxval 300110
#define ii int


///////////////// ********** BIT ***************\\\\\\\\\\\\\\\\\\*/

ii tree[maxval+100];

int readSingle(int idx){
	int sum = tree[idx]; // sum will be decreased
	if (idx > 0){ // special case
		int z = idx - (idx & -idx); // make z first
		idx--; // idx is no important any more, so instead y, you can use idx
		while (idx != z){ // at some iteration idx (y) will become z
			sum -= tree[idx];
			// substruct tree frequency which is between y and "the same path"
			idx -= (idx & -idx);
		}
	}
	return sum;
}

ii read(int idx){
	ii sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=(idx& -idx);
	//	sum%=mod;
	}
	return sum;
}
void update(int idx ,int val){

	while (idx <= maxval){
		tree[idx] += val;
		//tree[idx]%=mod;
		idx += (idx & -idx);
	}
}
///////////////////////**************************\\\\\\\\\\\\\\\\\\\*/

struct node{
	int type,val,prev,ind;
};

node nodes[maxm];

bool comp(node a,node b){
	if(a.val==b.val) return a.type<b.type;
	return a.val<b.val;
}

map<int,int>num;
int n,q,a[50],nums[maxm],ans[10000];

int main(){

	int i,j,k,l;

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){

		//num.clear();
		int tot=0,totn=0;

		for(i=1;i<=n;i++){
			scanf("%d %d",&k,&l);

			/*
			if(!num[k]){
                nums[totn++]=k; num[k]=1;
			}
			if(!num[l]){
                nums[totn++]=l; num[l]=1;
			}
			*/

			nodes[tot].type=1; nodes[tot].val=k; tot++;
			nodes[tot].type=3; nodes[tot].val=l; nodes[tot].prev=k; tot++;
		}
		scanf("%d",&q);

		for(i=1;i<=q;i++){

			scanf("%d",&k);

			for(j=0;j<k;j++) scanf("%d",&a[j]);
			sort(a,a+k);

			for(j=0;j<k;j++){

				l=a[j];

			//	if(!num[l]) nums[totn++]=l;
			//  num[l]=1;

				nodes[tot].type=2; nodes[tot].val=l; nodes[tot].ind=i;
				if(j) nodes[tot].prev=a[j-1];
				else nodes[tot].prev=0;
				tot++;
			}

		}

	//	sort(nums,nums+totn); num.clear();

	//	for(i=0;i<totn;i++){
	//		num[nums[i]]=i+1;
	//	}
		sort(nodes,nodes+tot,comp);

		memset(ans,0,sizeof(ans));

		memset(tree,0,sizeof(tree));

		node temp; totn=1; num.clear();
		for(i=0;i<tot;i++){
		    if(i&&nodes[i].val!=nodes[i-1].val) totn++;
			temp=nodes[i];
			if(temp.type==1){
				//k=num[nodes[i].val];
				update(totn,1);
				num[nodes[i].val]=totn;
			}
			if(temp.type==3){
				k=num[nodes[i].prev];
				update(k,-1);
			}
			if(temp.type==2){
				//k=num[nodes[i].val];
				l=nodes[i].ind;
				ans[l]+=read(totn);
				num[nodes[i].val]=totn;
				k=num[nodes[i].prev];
				ans[l]-=read(k);
			}
		}

		for(i=1;i<=q;i++){
			printf("%d\n",ans[i]);
		}


	}

	return 0;
}
