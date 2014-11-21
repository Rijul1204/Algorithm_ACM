#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxm 50010

struct node{
	int x,y;
};

node nodes[maxm];

bool comp(node a,node b){
	return a.y<b.y;
}

int main(){

	int i,j,k,l,test,t=1,n,w;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&w);

		for(i=0;i<n;i++){
			scanf("%d %d",&nodes[i].x,&nodes[i].y);
		}
		sort(nodes,nodes+n,comp);
		int ans=1,last;
		last=nodes[0].y+w;
		for(i=1;i<n;i++){
			if(nodes[i].y<=last) continue;
			last=nodes[i].y+w;
			ans++;
		}
		
		printf("Case %d: %d\n",t++,ans);


	}


	return 0;
}