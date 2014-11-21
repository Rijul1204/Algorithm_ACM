#include<stdio.h>
//#include<math.h>

int dp[50][1050],pre[1010][1050],mark[50][1050];

int max(int a,int b);

int main(){

	int i,j,n,time,w,count,soln[60];
	int d[50],v[50],flag;

	bool blank=false;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&time,&w)==2){
        
		flag=0;
		time/=(3*w);
		count=0;
	
		scanf("%d",&n);
		
		for(i=1;i<=n;i++){
			scanf("%d %d",&d[i],&v[i]);
			d[i]=d[i];
		}

		for(i=0;i<=time;i++) dp[0][i]=0;
		for(j=0;j<=n;j++) dp[j][0]=0;

		for(i=1;i<=n;i++){
			for(j=1;j<=time;j++){
				if(d[i]>j){
					dp[i][j]=dp[i-1][j];
					pre[i][j]=j;
					mark[i][j]=0;
				}
				else {
					if(dp[i-1][j-d[i]]+v[i]>dp[i-1][j]){
						dp[i][j]=dp[i-1][j-d[i]]+v[i];
						pre[i][j]=j-d[i];
						mark[i][j]=1;
					}
					else{
						dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
						if(dp[i-1][j]>=dp[i][j-1]) pre[i][j]=j;
						else pre[i][j]=j-1;
						mark[i][j]=0;
					}
				}
			}
		}
        j=time;
		count=0;
		for(i=n;i>=0;i--){
			if(mark[i][j]==1){
				soln[count++]=i;
			}
			j=pre[i][j];
		}

		if(blank) printf("\n");
		blank=true;

        printf("%d\n%d\n",dp[n][time],count);
		
		for(i=count-1;i>=0;i--){
			printf("%d %d\n",d[soln[i]],v[soln[i]]);
		}		

	}

	return 0;

}

int max(int a,int b){
	if(a>b) return a;
	else return b;
}



