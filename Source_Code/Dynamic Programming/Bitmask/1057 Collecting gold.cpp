#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std; 

#define maxm 25
#define maxn 1<<17
#define inf 1<<27

int on(int n,int k){
	return n|1<<k;
}
int off(int n,int k){
	return n-(n&1<<k);
}
bool chck(int n,int k){
	return (1<<k)==(n&1<<k);
}

struct node{
	int x,y,d;
};
node nodes[maxm];
queue<node>q;
char s[maxm][maxm];
int d[maxm][maxm],map[maxm][maxm],col[maxm][maxm];
int dp[maxm-5][maxn],r,c,c1;
int dir[][8]={1,0,-1,0,1,1,-1,-1,0,1,0,-1,1,-1,1,-1};
int cal(int ind,int num);
void bfs(node s,int ind);
int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;
	
//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&r,&c);
		
		for(i=1;i<=r;i++){
			scanf("%s",s[i]+1);
		}
		c1=0;

		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				if(s[i][j]=='x'){
					map[i][j]=0;
					nodes[0].x=i; nodes[0].y=j;
				}
				else if(s[i][j]=='g'){
					map[i][j]=++c1;
					nodes[c1].x=i; nodes[c1].y=j;
				}
			}
		}

		for(i=0;i<=c1;i++){
			bfs(nodes[i],i);
		}
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",t++,cal(0,0));

	}

	return 0;
}

int cal(int ind,int num){

	if(num==(1<<c1)-1) return d[ind][0];
	
	if(dp[ind][num]!=-1) return dp[ind][num];

	int i,k,ret=inf;
	
	for(i=1;i<=c1;i++){
		if(!chck(num,i-1)){
			k=on(num,i-1);
			ret=mini(ret,cal(i,k)+d[ind][i]);
		}
	}

	return dp[ind][num]=ret;

}


void bfs(node s1,int ind){

	int i,j,k,l,i1;
	node temp,temp1;
	memset(col,0,sizeof(col));
	d[ind][ind]=0;
	col[s1.x][s1.y]=1;
	q.push(s1);

	while(!q.empty()){

		temp=q.front(); q.pop();
		i=temp.x; j=temp.y;
		if(i<1||j<1||i>r||j>c) continue;
		if(s[i][j]=='g'){
			k=map[i][j];
			d[ind][k]=temp.d;
		}
		if(s[i][j]=='x'){
			k=0;
			d[ind][k]=temp.d;
		}

		for(i1=0;i1<8;i1++){
			k=i+dir[0][i1];
			l=j+dir[1][i1];
			if(!col[k][l]){
				temp1.x=k; temp1.y=l; temp1.d=temp.d+1; col[k][l]=1;
				q.push(temp1);
			}			
		}		

	}	

}