#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

#define inf 1<<28

struct node{
	int dis;
	int day;
	int no;
	int sum;
};

int d[800][400];
int mat[800],n,da;
queue<node>q;
int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
int mini(int a,int b){
	if(a<b) return a;
	return b;
}

void bfs(int s);

int main(){

	int i,j,k,l;
//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&da)==2){
		
		for(i=1;i<=n+1;i++){
			scanf("%d",&mat[i]);
		}
		for(i=1;i<=n+1;i++){
			for(j=1;j<=da+1;j++){
				d[i][j]=inf;
			}
		}
		d[0][0]=0;
//		for(i=1;i<=n+1;i++){
//			d[i][1]=d[i-1][1]+mat[i];
//		}
		

		bfs(1);
		int ans=d[n+1][1];
		for(i=1;i<=da+1;i++){
			if(ans>d[n+1][i]) ans=d[n+1][i];
		}

		printf("%d\n",ans);

	}

	return 0;
}

void bfs(int s){

	int i,j,k,l;
	node temp,temp1;
	temp.day=1;
	temp.dis=mat[s];
	temp.no=s;
	temp.sum=mat[s];

	d[s][1]=mat[s];
	q.push(temp);

	while(!q.empty()){

		temp=q.front(); q.pop();
		i=temp.no;
		k=temp.day;
		if(i==n+1) continue;
		j=i+1;

		if(d[j][k]>maxi(temp.dis,temp.sum+mat[j])){
			d[j][k]=maxi(temp.dis,temp.sum+mat[j]);
			temp1.day=k;
			temp1.dis=d[j][k];
			temp1.no=j;
			temp1.sum=temp.sum+mat[j];
			q.push(temp1);
		}
		
		if(k>da) continue;
		k++;
		if(d[j][k]>maxi(mat[j],temp.dis)){
			d[j][k]=maxi(mat[j],temp.dis);
			temp1.day=k;
			temp1.dis=d[j][k];
			temp1.no=j;
			temp1.sum=mat[j];
			q.push(temp1);
		}
		
		


	}
	
	

}

