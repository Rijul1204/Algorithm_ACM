#include<stdio.h>

int track[400];
int dp[400][20000];
int soln[40],num;
bool flag[40],flagm;

void knapsack(int n,int num);
void backtracking(int max,int count,int sum,int mark);
int max(int a,int b);
void reset(int n);

int main(){
	
	int i,j,n;
	
//	freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1){
		
		scanf("%d",&num);
			
		for(i=1;i<=num;i++){
			
			scanf("%d",&track[i]);
		}

		reset(num);
		
		knapsack(n,num);
		
		//printf("%d\n",dp[num][n]);
		
		backtracking(dp[num][n],1,0,0);
		
	}
	
	return 0;
}

void knapsack(int n,int num){
	
	int i,j;
	
	for(i=0;i<=num;i++) dp[i][0]=0;
	for(j=0;j<=n;j++) dp[0][j]=0;
	
	for(i=1;i<=num;i++){
		for(j=1;j<=n;j++){
			if(track[i]>j){
				dp[i][j]=dp[i-1][j];
			}
			else dp[i][j]=max(dp[i-1][j-track[i]]+track[i],dp[i-1][j]);
			
			
		}
	}
}

void backtracking(int max,int count,int sum,int mark){
	
	if(!flagm) return ;
	if(sum==max){
		for(int i=1;i<count;i++){
			printf("%d ",soln[i]);
		}
		printf("sum:%d\n",max);
		flagm=false;

		return ;
	}
	else {
		
		for(int i=mark+1;i<=num;i++){
			if(flag[i]==true){
				if(sum+track[i]<=max){
					soln[count]=track[i];
					flag[i]=false;
					backtracking(max,count+1,sum+track[i],i);
					flag[i]=true;
				}
			}
		}
	}
	
	
}

void reset(int n){

	for(int i=0;i<=n;i++){
		flag[i]=true;
	}
	flagm=true;
}



int max(int a,int b){
	
	if(a>b) return a;
	return b;
}



