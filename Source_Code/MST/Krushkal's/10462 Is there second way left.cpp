#include<stdio.h>
#include<algorithm>
using namespace std;

#define inf 1<<30

struct edge{
	int x;
	int y;
	int cost;
};

edge edges[1000];

int pre[1000];
int taken[1000];


int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}

bool comp(edge a,edge b){
	return a.cost<b.cost;
}

void set(int n){
	
	for(int i=0;i<=n;i++) pre[i]=i;
	
}

int main(){
	
	int i,j,k,l,test,n,m,mini,t=1;
	
	//freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	while(test--){
		
		scanf("%d %d",&n,&m);
		for(i=0;i<=n;i++){
			pre[i]=i;
		}
		
		
		for(i=0;i<m;i++){
			scanf("%d %d %d",&edges[i].x,&edges[i].y,&edges[i].cost);
		}
		sort(edges,edges+m,comp);
		int sum=0;
		int l1=0;
		for(i=0;i<m;i++){
			k=find(edges[i].x); l=find(edges[i].y);
			if(k!=l){
				sum+=edges[i].cost;
				pre[k]=l;
				taken[l1++]=i;
				
			}
		}
		j=0;
		for(i=1;i<=n;i++) if(pre[i]==i) j++;
		printf("Case #%d : ",t++);
		if(j>1){
			printf("No way\n");
			continue;
		}
		
		mini=inf;		
		for(j=0;j<l1;j++){
			set(n);
			sum=0;
			for(i=0;i<m;i++){
				if(i==taken[j]) continue;
				k=find(edges[i].x); l=find(edges[i].y);
				if(k!=l){
					sum+=edges[i].cost;
					pre[k]=l;
					
				}
			}
			k=0;
			for(i=1;i<=n;i++) if(pre[i]==i) k++;
			if(k>1){
				//printf("No way\n");
				continue;
			}
			else if(sum<mini) mini=sum;
		}
		if(mini==inf) printf("No second way\n");
		else printf("%d\n",mini);
		
		
	}
	
	
	
	return 0;
}



