#include<stdio.h>
#include<algorithm>
using namespace std;

#define ii long long int

struct edge{
	int u;
	int v;
	int c;
};

edge edges[100100];

int pre[20000];

bool comp(edge a,edge b);
int find(int x);
void set(int n);



int main(){

	int i,j,k,l,test,t=1,count,n,m,a;
	ii sum;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d %d",&n,&m,&a);

		set(n);
		for(i=0;i<m;i++){
			scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].c);
		}
		sort(edges,edges+m,comp);

		sum=0;

		for(i=0;i<m;i++){
		//	printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].c);
			if(edges[i].c<a){
				k=find(edges[i].u);
				l=find(edges[i].v);
				if(k!=l){
					pre[k]=l;
					sum+=edges[i].c;
				}
			}
		}
		

		count=0;
		for(i=1;i<=n;i++){
			if(pre[i]==i){
				count++;
				sum+=a;
			}		
		}
            
		printf("Case #%d: %lld %d\n",t++,sum,count);

	}

	return 0;
}


void set(int n){

	for(int i=0;i<=n;i++){
		pre[i]=i;
	}

}

bool comp(edge a,edge b){
	if(a.c<b.c) return 1;
	return 0;
}

int find(int x){
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}
