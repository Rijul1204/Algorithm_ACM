#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct edge{
	int x;
	int y;
	int cost;
};

edge edges[135000],selected[135000];
int pre[10000];
int x1[10000],y2[10000];

void set(int n);
int find(int x);
void Union(int a,int b);

bool comp(edge a,edge b){
	return a.cost<b.cost;

}

int main(){

	int i,j,k,l,test,n,e,count1;

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&e);

		set(e);

		for(i=1;i<=e;i++){
			scanf("%d %d",&x1[i],&y2[i]);
		}

		count1=0;
		for(i=1;i<e;i++){
			for(j=i+1;j<=e;j++){
				edges[count1].x=i;
				edges[count1].y=j;
				edges[count1].cost=((x1[i]-x1[j])*(x1[i]-x1[j]))+((y2[i]-y2[j])*(y2[i]-y2[j]));
				count1++;
			}
		}

		sort(edges,edges+count1,comp);
		int count2=0;

		for(i=0;i<count1;i++){
			int a;
			int b;
			a=find(edges[i].x);
			b=find(edges[i].y);
			if(a!=b){
				Union(a,b);
				//printf("%d %d %d\n",edges[i].x,edges[i].y,edges[i].cost);
				selected[count2]=edges[i];
				count2++;
			}
		}
		n--;
		int ans=0;
		double ret=0.0;
		if(count2-n-1>=0) ans=selected[count2-n-1].cost;

		ret=sqrt(ans);
		
		printf("%.2lf\n",ret);



	}

	return 0;
}



void set(int n){

	for(int i=0;i<=n;i++){
		pre[i]=i;
	}

}

int find(int x){
	if(pre[x]==x) return x;
    return pre[x]=find(pre[x]);
}

void Union(int a,int b){

	if(pre[a]!=pre[b]){
		pre[a]=b;
	}
}