#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxm 350

struct node{
	int x,y,z;
};
node nodes[maxm];

int n,d[maxm],x[maxm],y[maxm],z[maxm];

bool comp(node a,node b){
	if(a.x==b.x){
		if(a.y==b.y) return a.z>b.z;
		return a.y<b.y;
	}
	return a.x<b.x;
}

int main(){

	int i,j,k,l,c=0,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){
		if(!n) break;
		
		c=1;
		for(i=1;i<=n;i++){
			scanf("%d %d %d",&j,&k,&l);
			x[c]=j; y[c]=k; z[c++]=l;
			x[c]=l; y[c]=j; z[c++]=k;
			x[c]=k; y[c]=l; z[c++]=j;
			x[c]=j; y[c]=l; z[c++]=k;
			x[c]=k; y[c]=j; z[c++]=l;
			x[c]=l; y[c]=k; z[c++]=j;

		}
		n=c-1;
		int ans=-1;
		for(i=1;i<=n;i++){
			nodes[i].x=x[i]; 
			nodes[i].y=y[i];
			nodes[i].z=z[i]; 
		}
		
		sort(nodes+1,nodes+1+n,comp);
		
		for(i=1;i<=n;i++){
			d[i]=nodes[i].z;
	//		printf("%d %d %d\n",nodes[i].x,nodes[i].y,nodes[i].z);
			if(d[i]>ans) ans=d[i];
		}
		
	//	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i==j) continue;
				if(nodes[i].x>=nodes[j].x||nodes[i].y>=nodes[j].y) continue;
				if(d[j]<d[i]+nodes[j].z){
					d[j]=d[i]+nodes[j].z;
					if(d[j]>ans) ans=d[j];
				}
			}
		}
//		}

		printf("Case %d: maximum height = %d\n",t++,ans);

	}

	return 0;
}