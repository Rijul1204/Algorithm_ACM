#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define maxm 100100

struct node{
	int no,dia;
};
//node nodes[maxm];

vector<int>v[maxm];
int d[maxm],d1[maxm],col[maxm],col1[maxm],n,m,diam[maxm],b[maxm];
queue<int>q;
int bfs(int s);
bool comp(node a,node b){
	if(a.dia==b.dia) return a.no>b.no;
	return a.dia>b.dia;
}
node bfs1(int s1);


int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);
		for(i=0;i<=n;i++){
			v[i].clear();
		}
		
		for(i=1;i<=m;i++){
			scanf("%d %d",&j,&k);
			v[k].push_back(j);
			v[j].push_back(k);
		}
		
		int c=0;
		
		memset(col,0,sizeof(col));
		memset(col1,0,sizeof(col1));
		memset(diam,0,sizeof(diam));
		memset(d,-1,sizeof(d));
		memset(d1,-1,sizeof(d1));

		node temp;
		
		int di=0,tot=0;

		for(i=1;i<=n;i++){
			if(!col[i]){
			
				k=bfs(i);
				temp=bfs1(k);

				if(temp.dia>di) di=temp.dia;
				if(tot<temp.no) tot=temp.no;
				if(temp.dia>diam[temp.no]){
					if(diam[temp.no]==0) b[c++]=temp.no;
					diam[temp.no]=temp.dia;										
				}
			}
		}

		sort(b,b+c);

	//	sort(nodes,nodes+c,comp);

		int q1;
		scanf("%d",&q1);
		printf("Case %d:\n",t++);
		int l1,l2,ans;

		for(i=1;i<=q1;i++){
			scanf("%d",&k);
		
			if(k>tot){
				printf("impossible\n");
				continue;
			}
			
			k--;
			if(k<=di){
				printf("%d\n",k);
				continue;
			}
			int prev=-1;
			for(j=c-1;j>=0;j--){
				l=b[j];
				if(l<=k) break;
				if(diam[l]>prev) prev=diam[l];
			}
			printf("%d\n",prev+(k-prev)*2);
			
			/*
			ans=1<<28;			
			for(j=0;j<c;j++){
				if(nodes[j].no<=k) continue;
				k-=nodes[j].dia;
				k*=2;
				k+=nodes[j].dia;
				if(ans>k) ans=k;
			}
			if(ans>=1<<28) printf("impossible\n");
			else printf("%d\n",ans);
			*/
		}
	
		

	}

	return 0;
}

int bfs(int s){

	int i,j,k,l,max1=0,ret=s;
	
	d[s]=0;
	q.push(s); col[s]=1;
	
	while(!q.empty()){
		
		i=q.front(); q.pop();

		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(col[k]) continue;
			d[k]=d[i]+1;
			if(d[k]>max1){
				max1=d[k];
				ret=k;
			}
			col[k]=1;
			q.push(k);
		}
	}

	return ret;

}

node bfs1(int s){

	int i,j,k,l,max1=0;
	node ret;
	ret.dia=0; ret.no=1;
	d1[s]=0;
	q.push(s); col1[s]=1;
	
	while(!q.empty()){
		
		i=q.front(); q.pop();

		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(col1[k]) continue;
			ret.no++;
			d1[k]=d1[i]+1;
			if(d1[k]>max1){
				max1=d1[k];
				ret.dia=d1[k];
			}
			col1[k]=1;
			q.push(k);
		}
	}
	

	return ret;

}