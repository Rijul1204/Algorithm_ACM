#include<stdio.h>
#include<string.h>
#include<queue>
#include<ctype.h>
using namespace std;

#define inf 1<<29
#define maxm 34
#define ii long long int

struct node{
	int x,y,cost,no;
};

int col[maxm][maxm][maxm],n,ans,tot,d[maxm][maxm],d1[maxm];
ii dp[maxm][maxm][200][maxm],vis[maxm][maxm][200][maxm];
char grid[maxm][maxm];

void bfs(node s);

queue<node>q;

int maxi(int a,int b){
	if(a>b) return a;
	return b;
}

ii cal(int x,int y,int lev,int no);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);
	//scanf("%d",&test);
	
//	printf("%d\n",'.');

	while(scanf("%d",&n)==1){

	    if(!n) break;

		for(i=1;i<=n;i++) scanf("%s",grid[i]+1);

		k=0;
		ans=inf;
		node temp;

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(grid[i][j]=='A'){
					temp.cost=0; temp.no=1; temp.x=i; temp.y=j;
					//bfs(temp);
				}
				if(isalpha(grid[i][j])){
					k=maxi(k,grid[i][j]-'A'+1);
				}
			}
		}
		
		tot=k;
		
		if(tot==0){
			printf("Case %d: 0 0\n",t++);
			continue;			
		}
		
		d[0][1]=0;
		d1[1]=0;
		bfs(temp);

		memset(vis,0,sizeof(vis));
		

		if(ans==inf){
            printf("Case %d: Impossible\n",t++);
            continue;
		}

		ii totp=1;

		//printf("d-0> %d\n",d[2][3]);

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(isalpha(grid[i][j])){
				    if(tot!=grid[i][j]-'A'+1){
				      totp*=(cal(i,j,0,grid[i][j]-'A'+1));
				      totp%=20437;
					 //printf("%d %c\n",tot,grid[i][j]);
					// printf("maxi %c %lld\n",grid[i][j],totp);
					}
				}
			}
		}


		printf("Case %d: %d %lld\n",t++,ans,totp%20437);

	}

	return 0;
}

ii cal(int x,int y,int lev,int no){


    if(x<1||y<1||x>n||y>n||lev>d[no][no+1]) return 0;

    if(grid[x][y]=='#'||grid[x][y]-'A'>no) return 0;
   // if(no==3) printf("no- %d %c %d %d\n",lev,grid[x][y],grid[x][y]-'A',d[no][no+1]);
    if(grid[x][y]-'A'==no){
       // printf("vitor %d %d %d\n",no,lev,d[no][no+1]);
      //  if(no==0) printf("pais \n");
        if(lev==d[no][no+1]) return 1;
        else return 0;
    }

    if(vis[x][y][lev][no]) return dp[x][y][lev][no];
    vis[x][y][lev][no]=1;
    dp[x][y][lev][no]=0;
  //  if(no==0) printf("pais \n");
    dp[x][y][lev][no]+=cal(x-1,y,lev+1,no);
    dp[x][y][lev][no]+=cal(x,y+1,lev+1,no);
    dp[x][y][lev][no]+=cal(x,y-1,lev+1,no);
    dp[x][y][lev][no]+=cal(x+1,y,lev+1,no);

    return dp[x][y][lev][no]%20437;
}


void bfs(node s){

	int i,j,k,l,no;
	node temp,temp1;

	memset(col,0,sizeof(col));

    while(!q.empty()) q.pop();
	
	col[s.no][s.x][s.y]=1;

	q.push(s);

	while(!q.empty()){

		temp=q.front(); q.pop();

		if(temp.no==tot){
			
		    if(ans>temp.cost) ans=temp.cost;
		    break;
		}

		i=temp.x; j=temp.y;

		//left>>>>>>>>>

		k=i; l=j-1;

		if(l>0){

			if(grid[k][l]!='#'&&col[temp.no][k][l]==0){
				col[temp.no][k][l]=1;
				if(isalpha(grid[k][l])){
					if(grid[k][l]-'A'+1==temp.no+1){
						temp1.no=temp.no+1;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						d[temp.no][temp1.no]=temp1.cost-d1[temp.no];
						d1[temp1.no]=temp1.cost;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
					else if(grid[k][l]-'A'+1<temp.no+1){
						temp1.no=temp.no;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
				}
				else{
					temp1.no=temp.no;
					col[temp1.no][k][l]=1;
					temp1.cost=temp.cost+1;
					temp1.x=k; temp1.y=l;
					q.push(temp1);

				}

			}
		}

		//right>>>>>>>>>

		k=i; l=j+1;

		if(l<=n){

			if(grid[k][l]!='#'&&col[temp.no][k][l]==0){
				col[temp.no][k][l]=1;
				if(isalpha(grid[k][l])){
					if(grid[k][l]-'A'+1==temp.no+1){
						temp1.no=temp.no+1;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						d[temp.no][temp1.no]=temp1.cost-d1[temp.no];
						d1[temp1.no]=temp1.cost;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
					else if(grid[k][l]-'A'+1<temp.no+1){
						temp1.no=temp.no;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
				}
				else{
					temp1.no=temp.no;
					col[temp1.no][k][l]=1;
					temp1.cost=temp.cost+1;
					temp1.x=k; temp1.y=l;
					q.push(temp1);

				}

			}
		}



		//up>>>>>>>>>>>>


		k=i-1; l=j;

		if(k>0){

			if(grid[k][l]!='#'&&col[temp.no][k][l]==0){
				col[temp.no][k][l]=1;
				if(isalpha(grid[k][l])){
					if(grid[k][l]-'A'+1==temp.no+1){
						temp1.no=temp.no+1;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						d[temp.no][temp1.no]=temp1.cost-d1[temp.no];
						d1[temp1.no]=temp1.cost;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
					else if(grid[k][l]-'A'+1<temp.no+1){
						temp1.no=temp.no;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
				}
				else{
					temp1.no=temp.no;
					col[temp1.no][k][l]=1;
					temp1.cost=temp.cost+1;
					temp1.x=k; temp1.y=l;
					q.push(temp1);

				}

			}
		}


		//down>>>>>>>>>>>


		k=i+1; l=j;

		if(k<=n){

			if(grid[k][l]!='#'&&col[temp.no][k][l]==0){
				col[temp.no][k][l]=1;
				if(isalpha(grid[k][l])){
					if(grid[k][l]-'A'+1==temp.no+1){
						temp1.no=temp.no+1;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						//printf("Bfs %c %d %d\n",grid[k][l],temp1.cost,d[temp.no-1][temp.no]);
						d[temp.no][temp1.no]=temp1.cost-d1[temp.no];
						d1[temp1.no]=temp1.cost;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
					else if(grid[k][l]-'A'+1<temp.no+1){
						temp1.no=temp.no;
						col[temp1.no][k][l]=1;
						temp1.cost=temp.cost+1;
						temp1.x=k; temp1.y=l;
						q.push(temp1);
					}
				}
				else{
					temp1.no=temp.no;
					col[temp1.no][k][l]=1;
					temp1.cost=temp.cost+1;
					temp1.x=k; temp1.y=l;
					q.push(temp1);

				}

			}
		}



	}





}
