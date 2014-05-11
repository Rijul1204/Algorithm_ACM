#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

#define maxm 15

struct node{
	int a;
	int b;
	int c;
	int d;
	int step;
};

int d[maxm][maxm][maxm][maxm],col[maxm][maxm][maxm][maxm];
int add[maxm],l,u,r;
queue<node>q;
void bfs(node s);

int main(){

	int i,j,k,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d %d",&l,&u,&r)==3){
		
		if(!l&&!u&&!r) break;
		for(i=1;i<=r;i++){
			scanf("%d",&add[i]);
		}
		node temp;
		k=l;
		
		temp.d=k%10; k/=10;
		temp.c=k%10; k/=10;
		temp.b=k%10; k/=10;
		temp.a=k%10; k/=10;
		temp.step=0;

		bfs(temp);
		
		k=u;

		temp.d=k%10; k/=10;
		temp.c=k%10; k/=10;
		temp.b=k%10; k/=10;
		temp.a=k%10; k/=10;
		temp.step=0;

		printf("Case %d:",t++); 
		if(col[temp.a][temp.b][temp.c][temp.d]==0) printf(" Permanently Locked\n");
		else printf(" %d\n",d[temp.a][temp.b][temp.c][temp.d]);

	}

	return 0;
}

void bfs(node s){

	int i,j,k,num;
	node temp,temp1;
	temp=s;

	memset(col,0,sizeof(col));

	col[temp.a][temp.b][temp.c][temp.d]=1;
	d[temp.a][temp.b][temp.c][temp.d]=0;

	q.push(temp);

	while(!q.empty()){

		temp1=q.front(); q.pop();
		
		num=temp1.a*1000+temp1.b*100+temp1.c*10+temp1.d;

		for(i=1;i<=r;i++){
			j=add[i];
			k=num+j;

			temp.d=k%10; k/=10;
	     	temp.c=k%10; k/=10;
    		temp.b=k%10; k/=10;
	    	temp.a=k%10; k/=10;
	    	temp.step=temp1.step+1;

			if(col[temp.a][temp.b][temp.c][temp.d]==1) continue;
			col[temp.a][temp.b][temp.c][temp.d]=1;
			d[temp.a][temp.b][temp.c][temp.d]=temp.step;

			q.push(temp);
		}


	}



	

}