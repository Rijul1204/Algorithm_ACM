#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct edge{
	int x;
	int y;
	int w1;
	double w;
};

edge edges[900000];
int x[10000],y[10000],pre[10000];
double mat[1000][1000];

bool comp(edge a,edge b){
	return a.w1<b.w1;
}

int find(int x){
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}

int main(){

	int i,j,k,l,n,c1,c2,m;
	double dis,sum,rest;
//	freopen("10397.txt","r",stdin);

	while(scanf("%d",&n)==1){
		
		for(i=1;i<=n;i++){
			pre[i]=i;
			scanf("%d %d",&x[i],&y[i]);
		}
		//memset(mat,0.sizeof(mat));
		
		k=0;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				edges[k].w1=dis;
				dis=sqrt(dis);
				edges[k].w=dis; edges[k].x=i; edges[k].y=j;
				k++;
				mat[i][j]=mat[j][i]=dis;
			}

		}
		int count1=k;
		scanf("%d",&m);
		sum=0;rest=0;
		sort(edges,edges+k,comp);
		reverse(edges,edges+k);
		
		for(i=1;i<=m;i++){
			scanf("%d %d",&c1,&c2);
			edges[k].x=c1;edges[k].y=c2;edges[k].w=mat[c1][c2];
			k++;
			//rest+=mat[c1][c2];
		}
		l=0;
		for(i=k-1;i>=0;i--){
			c1=find(edges[i].x); c2=find(edges[i].y);
			l++;
			if(c1!=c2){
				pre[c1]=c2;
				if(l>m) sum+=edges[i].w;
			}
		}
		sum-=rest;
		sum+=.00000001;
		
		printf("%.2lf\n",sum);
			


	}
	

	return 0;
}