#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

#define inf 1<<27
#define maxm 10100

struct path{
	int no;
	int tim;
};

struct node{
	int no;
	int rem;
	int nh;
};

bool operator<(const node &a,const node &b){
	return a.nh>b.nh;
}

vector<path>v[maxm];
int hotel[maxm],d[maxm][700],n,m,ans;
priority_queue<node>pq;

void dij(node s);

int main(){
	
	int i,j,k,l;

	//freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1){

		if(!n) break;
		
		for(i=0;i<=n;i++) v[i].clear();
		memset(hotel,0,sizeof(hotel));
		
		scanf("%d",&k);
		
		for(i=1;i<=k;i++){
			scanf("%d",&l);
			hotel[l]=1;
		}
		scanf("%d",&m);
		path temp;
		
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			temp.tim=j; temp.no=l;
			v[k].push_back(temp);
			temp.no=k;
			v[l].push_back(temp);
		}
		
		node temp1;
		temp1.no=1; temp1.nh=0; temp1.rem=600;
		ans=inf;
		
		dij(temp1);

		if(ans==inf) printf("-1\n");
		else printf("%d\n",ans);
		
	}
	
	return 0;
	
}

void dij(node s){
	
	int i,j,k,l;
	
	for(i=0;i<=n;i++){
		for(j=0;j<=607;j++){
			d[i][j]=inf;
		}
	}
	d[s.no][s.rem]=0;
	node temp,temp1;
	
	pq.push(s);
	
	while(!pq.empty()){
		
		temp=pq.top(); pq.pop();

		if(temp.no==n){
			if(ans>temp.nh) ans=temp.nh;
		}
		
		i=temp.no;
		
		for(j=0;j<v[i].size();j++){
			
			if(temp.rem>=v[i][j].tim){
				temp1.no=v[i][j].no;
				temp1.nh=temp.nh;
				temp1.rem=temp.rem-v[i][j].tim;
				if(d[temp1.no][temp1.rem]>temp1.nh){
					d[temp1.no][temp1.rem]=temp1.nh;
					pq.push(temp1);
				}
				if(hotel[temp1.no]==1){
					temp1.nh=temp.nh+1;
					temp1.rem=600;
					if(d[temp1.no][temp1.rem]>temp1.nh){
						d[temp1.no][temp1.rem]=temp1.nh;
						pq.push(temp1);						
					}
				}
			}					
		}
		
	}
	
	
}