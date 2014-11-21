#include<stdio.h>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

struct node{
	int move;
	int room;
	int flag;
	int num;
};

struct node1{
	int flag;
	int num;
	int room;
	int prer;
	int pres;
	int no;
};

node1 pre[30][5010];

int on(int n,int k){
	return (n|(1<<k));
}
int off(int n,int k){
	return (n-(n&1<<k));
}
bool check(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}

int r,doo,m;
int vis[20][5000];
int d[20][5000];
vector<int>v[100],s[100];
queue<node>q;
void bfs(node so);
void print(node1 s);

int main(){

	int i,j,k,l,t=1;

	//freopen("in.txt","r",stdin);
	
	while(scanf("%d %d %d",&r,&doo,&m)==3){

		if(!r&&!doo&&!m) break;
		
		double p,q;
		q=r;
		p=pow(2,q);
		k=p;


		for(i=0;i<=r+1;i++){
			v[i].clear();
			s[i].clear();
			for(j=0;j<=5000;j++){
				vis[i][j]=0;
				d[i][j]=-1;
				pre[i][j].room=i;
				pre[i][j].num=j;
				pre[i][j].flag=0;
				pre[i][j].no=0; pre[i][j].prer=0; pre[i][j].pres=0;
			}
			
		}
		
		

		for(i=1;i<=doo;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
			v[l].push_back(k);
		}

		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			s[k].push_back(l);
		}
		node temp;
		temp.move=0;
		temp.num=2;
		temp.room=1;
		bfs(temp);
		
		k=p;
		printf("Villa #%d\n",t++);
		if(d[r][k]==-1){
			printf("The problem cannot be solved.\n");
		}
		else{
			printf("The problem can be solved in %d steps:\n",d[r][k]);
			print(pre[r][k]);
		}
		printf("\n");

	}


	return 0;
}
void print(node1 s){
	if(s.room<1) return;
	if(s.room==1&&s.num==2) return ;
	print(pre[s.prer][s.pres]);
	if(s.flag==1){
		printf("- Move to room %d.\n",s.room);
	}
	if(s.flag==2){
		printf("- Switch on light in room %d.\n",s.no);
	}
	if(s.flag==3){
		printf("- Switch off light in room %d.\n",s.no);
	}
	

	
}

void bfs(node so){

	int i,j,k,l,n;
	node temp,temp1;
	vis[so.room][so.num]=1;
	d[so.room][so.num]=0;
	q.push(so);

	while(!q.empty()){

		temp=q.front(); q.pop();
		i=temp.room;
		n=temp.num;
//		if(i==r){
//			printf("%d %d\n",temp1.move,temp1.num);
//		}
		for(j=0;j<v[i].size();j++){
			k=v[i][j];
			if(check(n,k)&&!vis[k][n]){
				temp1.move=temp.move+1;
				temp1.num=n;
				temp1.room=k;
				d[k][n]=temp1.move;
				pre[k][n].prer=i;
				pre[k][n].pres=n;
				pre[k][n].flag=1;
				pre[k][n].room=k;
				pre[k][n].num=n;
				vis[k][n]=1;
				q.push(temp1);
			}
		}
		for(j=0;j<s[i].size();j++){
			k=s[i][j];
			if(k==i) continue;
			if(check(n,k)){
				l=off(n,k);
				if(!vis[i][l]){
					vis[i][l]=1;
					temp1.move=temp.move+1;
					d[i][l]=temp1.move;
					temp1.num=l;
					temp1.room=temp.room;
					q.push(temp1);
					pre[i][l].prer=i;
     				pre[i][l].pres=n;
	     			pre[i][l].flag=3;
		    		pre[i][l].room=i;
			    	pre[i][l].num=l;
					pre[i][l].no=k;

				}
			}
			if(!check(n,k)){
				l=on(n,k);
				if(!vis[i][l]){
					vis[i][l]=1;
					temp1.move=temp.move+1;
					d[i][l]=temp1.move;
					temp1.num=l;
					temp1.room=temp.room;
					q.push(temp1);
					pre[i][l].prer=i;
     				pre[i][l].pres=n;
	     			pre[i][l].flag=2;
		    		pre[i][l].room=i;
			    	pre[i][l].num=l;
					pre[i][l].no=k;
				}
			}
		}
	}

}
