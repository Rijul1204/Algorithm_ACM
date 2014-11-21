#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 50100

struct node{
	int tim,fl;
};
node nodes[2*maxm];
int n;
bool comp(node a,node b){
	if(a.tim==b.tim) return a.fl<b.fl;
	return a.tim<b.tim;
}

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		int c=0;
		for(i=0;i<n;i++){
			scanf("%d %d",&k,&l);
			nodes[c].tim=k; nodes[c++].fl=1;
			nodes[c].tim=l; nodes[c++].fl=2;
		}
		sort(nodes,nodes+c,comp);
		int ans=1;
		k=0;
		for(i=0;i<c;i++){
			if(nodes[i].fl==1){
				k++;
				if(k>ans) ans=k;
			}
			else k--;
		}

		printf("Case %d: %d\n",t++,ans);


	}

	return 0;
}