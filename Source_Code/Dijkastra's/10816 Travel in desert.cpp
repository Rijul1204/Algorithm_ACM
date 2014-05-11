#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define maxm 1000
#define maxe 11000
#define inf 1<<27
#define ii double

struct node{
	int n;
	double tem;
	double len;
};

bool operator<(const node &a,const node &b){
	return a.len>b.len;
}
int n,m,s,t,pre[maxm],pre1[maxm];
double a[maxe];
double d[maxm];
ii maxi(ii a,ii b){
	if(a>b) return a;
	return b;
}
priority_queue<node>pq;
vector<node>v[maxm];
node dij(int s,double lim);
void bin(int lo,int hi);
void print(int n);

int main(){

	int i,k,l,test;
	double j,tem;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){
		
		for(i=0;i<=n;i++){
			v[i].clear();
		}

		scanf("%d %d",&s,&t);
		node temp;
		for(i=1;i<=m;i++){
			scanf("%d %d %lf %lf",&k,&l,&tem,&j);
			a[i-1]=tem;
			temp.len=j; temp.tem=tem; temp.n=k;
			v[l].push_back(temp);
			temp.n=l;
			v[k].push_back(temp);			
		}
		sort(a,a+m);
		bin(0,m-1);
	}


	return 0;
}

void bin(int lo,int hi){

	
	int i,j,k;
	double l,prev;
	int mid;
	node l1,prev1;
	int c=0;
	
	while(lo<=hi){

		c++;
		if(c>35){
//			lo/=0;
//			mid/=0;
//			hi/=0;
//			j=2;
//			j/=0;
		//	printf("%d",d[-1]);
		}

		mid=lo+hi;
		mid/=2;
		
		l1=dij(s,a[mid]);
		l=l1.tem;
		
		if(l<0){
			lo=mid+1;
		}
		else {
			hi=mid-1;
			prev=mid;
			prev1=l1;
			for(i=0;i<=n;i++){
				pre1[i]=pre[i];
			}
		}
	}
	print(t);
	printf("\n%.1lf %.1lf\n",prev1.len,prev1.tem);
}

void print(int n){
	if(pre1[n]==n){
		printf("%d",n);
		return ;
	}
	print(pre1[n]);
	printf(" %d",n);

}

node dij(int s,double lim){

	int i,j,k,l;
	node temp,temp1;
	
	for(i=0;i<=n;i++){
		d[i]=inf;
		pre[i]=i;	
	}
	d[s]=0;

	while(!pq.empty()) pq.pop();

	temp.n=s;
	temp.len=0;
	temp.tem=0;
	pq.push(temp);
	
	while(!pq.empty()){
		
		temp=pq.top(); pq.pop();

		if(temp.n==t){
			return temp;
		}
		
		i=temp.n;

		for(j=0;j<v[i].size();j++){
			temp1=v[i][j];
			k=temp1.n;
			if(temp1.tem>lim) continue;
			if(d[k]>temp.len+temp1.len){
				d[k]=temp.len+temp1.len;
				temp1.tem=maxi(temp1.tem,temp.tem);
				temp1.n=k;
				temp1.len=d[k];
				pre[k]=i;
				pq.push(temp1);
			}
		}	

	}
	temp.tem=-2;

	return temp;
}

