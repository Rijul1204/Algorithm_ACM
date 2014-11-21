#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

#define maxm 200

struct node{
	int n;
	double pr;
};

bool operator<(const node &a,const node &b){
	return a.pr<b.pr;
}

vector<node>v[maxm];
priority_queue<node>pq;
int n,m,kk;
double s;
double pr,d[maxm];

double dij(int s);

int main(){
	
	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d %lf %d",&n,&m,&s,&kk);
		
		for(i=0;i<=n;i++){
			v[i].clear();
		}
		
		node temp,temp1;
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			double p=(double) j/(double) 100;
			temp.n=l; temp.pr=p;
			v[k].push_back(temp);
			temp.n=k;
			v[l].push_back(temp);
			
		}
		pr=dij(0);
		pr=d[n-1];
		double left=1;
		left=pr;
		double right=(double)2*(double)kk;
		double ans=s;
		right/=left;
		ans*=right;
		ans+=.0000000001;
		printf("Case %d: %lf\n",t++,ans);


	}

	return 0;
}

double dij(int s){

	int i,j,k,l;
	node temp,temp1;

	for(i=1;i<=n;i++){
		d[i]=-1;
	}
	d[s]=1;
	temp.n=0; temp.pr=1;
	pq.push(temp);

	while(!pq.empty()){

		temp=pq.top(); pq.pop();

//		if(temp.n==n-1){
//			return temp.pr;
//		}

		i=temp.n;

		for(j=0;j<v[i].size();j++){
			temp1=v[i][j];
			k=temp1.n;
			if(d[k]<d[i]*temp1.pr){
				d[k]=d[i]*temp1.pr;
				temp1.pr=d[k]; temp1.n=k;
				pq.push(temp1);
			}
		}
	}
	
	return 0;

}