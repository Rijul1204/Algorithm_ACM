#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct edge{
	int u;
	int v;
	int cost;
};

edge edges[1100000];
int x[11000],y[11000],pre[11000],state[11000],count1;

int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}
int findstate(int x){
	if(state[x]==x) return state[x];
	return state[x]=find(state[x]);
}

bool comp(edge a,edge b){
	return a.cost<b.cost;
}


int main(){

	int i,j,k,l,n,r,test,k1,k2,t=1;
	int dis;
	double sum,sum1,t1,t2;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&r);
		r*=r;

		for(i=1;i<=n;i++){
			pre[i]=i;
			state[i]=i;
			scanf("%d %d",&x[i],&y[i]);
		}
		count1=0;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				edges[count1].u=i;
				edges[count1].v=j;
				edges[count1++].cost=dis;
			}
		}
		sort(edges,edges+count1,comp);
		sum=0; sum1=0;

		for(i=0;i<count1;i++){
			k=edges[i].u; l=edges[i].v;
			k=find(k); l=find(l);
		    j=edges[i].cost;
			if(j<=r){
				k1=findstate(edges[i].u);
				k2=findstate(edges[i].v);
				if(k1!=k2) state[k1]=k2;
			}

			if(k!=l){
				t1=j;
				t1=sqrt(t1);
				//t1+=.00000001;
				pre[k]=l;
				if(j<=r) 	sum+=t1;
				else  sum1+=t1;				
			}

		}
	//	sum=ceil(sum);
	//	sum1=ceil(sum1);
	//	sum+=.000000001;
	//	sum1+=.000000001;
	
		
		int num=0;
		int sums,sums1;
	//	sums=sum;
	//	sums1=sum1;
	  //   if(sums-sum<.5)sums=sums;
//		else sums++;
//		if(sums1-sum1<.5)sums1=sums1;
//		else sums1++;
			

		for(i=1;i<=n;i++){
			if(state[i]==i) num++;
		}

		printf("Case #%d: %d %.lf %.lf\n",t++,num,sum,sum1);



	}
	


	return 0;
}
