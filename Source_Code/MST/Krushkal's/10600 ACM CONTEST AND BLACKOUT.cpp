#include<stdio.h>
#include<algorithm>
using namespace std;

#define inf 10233203

struct edge{
	int x;int y;int cost;
};

edge edges[10000];
int pre[10000],select1[10000],count1,select2[10000];


void set(int n);
void Union(int a,int b);
int find(int x);

bool comp(edge a,edge b){
	return a.cost<b.cost;
}

int main(){

	int i,j,k,l,test,n,e,tot,min,min2;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&e);
		set(n);

		for(i=0;i<e;i++){
	       	scanf("%d %d %d",&edges[i].x,&edges[i].y,&edges[i].cost);
		}
		sort(edges,edges+e,comp);

		tot=0;
		count1=0;int num=0;
		for(i=0;i<e;i++){
			int a=find(edges[i].x);
			int b=find(edges[i].y);
			if(a!=b){
				select1[count1++]=i;
				Union(a,b);
				tot+=edges[i].cost;
			}			

		}

		
//		printf("%d\n",tot);
		
		min=tot;
		min2=inf;
	//	for(i=0;i<=n;i++) select1[i]=0;
		int flag,count2;
		count2=count1;

	
		for(i=0;i<count2;i++){
			set(n);
			tot=0;
			flag=0;
			count1=0;num=0;
			for(j=0;j<e;j++){
				if(select1[i]==j) continue;
				int a=find(edges[j].x);
				int b=find(edges[j].y);
				if(a!=b){
					select2[count1++]=j;
					Union(a,b);
					tot+=edges[j].cost;
				}
				
			}
			//printf("%d ",tot);
			sort(select2,select2+count1);
			flag=0;
			for(j=0;j<count1;j++){
				if(select2[j]!=select1[j]){
					flag=1;
					break;
				}
			}
			for(j=1;j<=n;j++){
				if(pre[j]==j){
					num++;
				}
			}

		//	printf("num-> %d-> ",num);
			
			if(min2>tot&&flag==1&&num<=1){
				min2=tot;
			}
		
		}

		printf("%d %d\n",min,min2);

	}

	return 0;
}

void set(int n){

	for(int i=0;i<=n;i++) pre[i]=i;
}

void Union(int a,int b){

	if(a!=b) pre[a]=b;

}

int find(int x){

	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);

}

