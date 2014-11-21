#include<stdio.h>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;

#define p 1150

struct node{
	int num;
	int step;
};

bool operator<(const node &a,const node &b){
	return a.step>b.step;
}

int mat[1100][1100];
bool prime[p+10];
vector<int>v[1100];

priority_queue<node>q;

void gen(int n){

	int i,j,k;

	k=sqrt(n);

	
	prime[0]=prime[1]=1;

	for(i=4;i<=n;i+=2) prime[i]=1;

	for(i=3;i<=k;i+=2){
		if(prime[i]==0){
			for(j=i*i;j<=n;j+=2*i){
				prime[j]=1;
			}
		}
	}

}

void bfs(int s);

int main(){

	int i,j,k,l,t=1;

	gen(p);

//	freopen("in.txt","r",stdin);

	for(i=1;i<=100;i++) v[i].clear();

	for(i=1;i<=1000;i++){
		for(j=1;j<i;j++){
			if(prime[j]==0&&i%j==0){
				v[i].push_back(j);
			}
		}
	}
	for(i=1;i<=100;i++){
		for(j=1;j<=1005;j++){
			mat[i][j]=12345678;
		}
	}

	for(i=0;i<=100;i++){
		bfs(i);
	}



	while(scanf("%d %d",&i,&j)==2){

		if(!i&&!j) break;
		printf("Case %d: ",t++);

		if(j<i){
			printf("-1\n"); continue;

		}
		if(mat[i][j]>=12345678) printf("-1\n");
		else printf("%d\n",mat[i][j]);

	}





	return 0;
}

void bfs(int s){

	mat[s][s]=0;

	node temp,temp1;
	temp.num=s;
	temp.step=0;
	q.push(temp);
	int i,j,k,l;

	while(!q.empty()){

		temp1=q.top(); q.pop();
		i=temp1.num;

		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(i+k>1005) break;
			if(mat[s][i+k]>mat[s][i]+1){
				mat[s][i+k]=mat[s][i]+1;
				temp1.num=i+k;
		    	temp1.step=mat[s][i+k];
	    		q.push(temp1);				
			}
		}

	}

}