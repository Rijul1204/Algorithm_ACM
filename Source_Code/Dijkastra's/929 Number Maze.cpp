#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;

struct data{

	int i;
	int j;
	int dist;

//	bool operator < (const data& p)const{
//		return a>p.a;
//	}

};

class compare{
public:
	bool operator () (data& a,data& b){
		return a.dist>b.dist;
	}

};

//priority_queue<data>q;
priority_queue<data,vector<data>,compare>q;
//queue<data>q;
int a[1010][1010],d[1010][1010],row,col;

void dijkstra(data s);

int main(){

	int i,j,k,l,test;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&row,&col);
		for(i=0;i<=row;i++){
			for(j=0;j<=col;j++){
				d[i][j]=12345678;
			}
		}

		for(i=1;i<=row;i++){
			for(j=1;j<=col;j++){
				scanf("%d",&a[i][j]);
			}
		}
		data temp;
		temp.i=1; temp.j=1; temp.dist=a[1][1];
		dijkstra(temp);

		printf("%d\n",d[row][col]);


	}
	

	return 0;

}

void dijkstra(data s){

	while(!q.empty()) q.pop();
	d[s.i][s.j]=s.dist;
	q.push(s);

	while(!q.empty()){

		data t=q.top(); q.pop();
		data t1;

		int i,j;
		
		i=t.i; j=t.j;

		i=t.i+1;
		j=t.j;
		//printf("%d %d\n",t.i,t.j);
		if(i<=row){
			if(d[i][j]>d[t.i][t.j]+a[i][j]){
				d[i][j]=d[t.i][t.j]+a[i][j];
				//if(i==row&&j==col) break;
				t1.i=i; t1.j=j; t1.dist=d[i][j];
				q.push(t1);
			}
		}

		i=t.i-1;
		j=t.j;
		if(i>0){
			if(d[i][j]>d[t.i][t.j]+a[i][j]){
				d[i][j]=d[t.i][t.j]+a[i][j];
				t1.i=i; t1.j=j; t1.dist=d[i][j];
			//	if(i==row&&j==col) break;
				q.push(t1);
			}
		}
		
		i=t.i;
		j=t.j+1;
		if(j<=col){
			if(d[i][j]>d[t.i][t.j]+a[i][j]){
				d[i][j]=d[t.i][t.j]+a[i][j];
				t1.i=i; t1.j=j; t1.dist=d[i][j];
				//if(i==row&&j==col) break;
				q.push(t1);
			}
		}

		i=t.i;
		j=t.j-1;
		if(j>0){
			if(d[i][j]>d[t.i][t.j]+a[i][j]){
				d[i][j]=d[t.i][t.j]+a[i][j];
				t1.i=i; t1.j=j; t1.dist=d[i][j];
			//	if(i==row&&j==col) break;
				q.push(t1);
			}
		}
		if(d[row][col]!=12345678) break;


	}



}