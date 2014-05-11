#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

#define maxm 1000
#define maxval 100000
#define ii long long int
#define mod 1000000007

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
		sum%=mod;
	}
	return sum;
}
void update(int idx ,int val){

	while (idx <= maxval){
		tree[idx] += val;
		tree[idx]%=mod;
		idx += (idx & -idx);
	}
}
map<int,int>mm;
int n,a[maxval+100],b[maxval+100];

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
	    mm.clear();
		memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		for(i=1;i<=n;i++){
		    scanf("%d",&a[i]);
		    b[i]=a[i];
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
		    mm[a[i]]=i;
		}
		ii l1;
		for(i=1;i<=n;i++){
		    k=mm[b[i]];
			l1=read(k-1);
			update(k,l1+1);
		}
		printf("Case %d: %lld\n",t++,read(maxval));

	}

	return 0;
}
