#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

#define maxm 30100


struct node{
	int no;
	int cost;
	int pre;
};

bool operator<(const node &a,const node &b){
	return a.cost<b.cost;
}

priority_queue<node>pq;

vector<node>v[maxm];
int d1[maxm],d[maxm],n;

int dij(int s);
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);	
	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);

		for(i=0;i<=n;i++) v[i].clear();
		
		node temp;
		
		for(i=1;i<n;i++){
			scanf("%d %d %d",&k,&l,&j);
			temp.cost=j; temp.no=k;
			v[l].push_back(temp);
			temp.no=l;
			v[k].push_back(temp);
		}

		k=dij(0);
		l=dij(k);
		
		for(i=0;i<n;i++) d1[i]=d[i];
		l=dij(l);
		
		printf("Case %d:\n",t++);
		for(i=0;i<n;i++){
			printf("%d\n",maxi(d[i],d1[i]));
		}
		

	}


	return 0;
}

int dij(int s){

	int i,j,k,l;
	node temp,temp1;

	temp.cost=0;
	temp.no=s;
	temp.pre=-1;
	memset(d,-1,sizeof(d));
	d[s]=0;
	pq.push(temp);

	while(!pq.empty()){

		temp=pq.top(); pq.pop();
		i=temp.no;

		for(j=0;j<v[i].size();j++){
			temp1=v[i][j];
			if(d[temp1.no]<d[i]+temp1.cost&&temp.pre!=temp1.no){
				d[temp1.no]=d[i]+temp1.cost;
				temp1.cost=d[temp1.no];
				temp1.pre=i;
				pq.push(temp1);
			}			
		}
	}

	k=-1;
	l=0;

	for(i=0;i<n;i++){
		if(k<d[i]){
			k=d[i];
			l=i;
		}
	}

	return l;

}


