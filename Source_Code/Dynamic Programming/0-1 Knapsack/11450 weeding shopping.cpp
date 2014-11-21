#include<stdio.h>
#include<algorithm>
using namespace std;

int dp[50][250];

void set(int m,int c);

int main(){
	
	int i,j,k,m,c,test,flag=0,flagm=0,min;
	int model[50][250];
	
	//freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	
	while(test--){
		
		scanf("%d %d",&m,&c);
		
		for(j=1;j<=c;j++){
			scanf("%d",&model[j][0]);
			for(i=1;i<=model[j][0];i++){
				scanf("%d",&model[j][i]);
			}
			sort(model[j]+1,model[j]+(1+model[j][0]));
		}
		set(m,c);
        
		min=0;flagm=0;
		for(i=1;i<=c;i++){
			min+=model[i][1];
		}
		if(min>m) flagm=1;

		


		for(i=0;i<=m;i++) dp[0][i]=0;
		for(i=0;i<=c;i++) dp[i][0]=0;
		if(!flagm)
		for(i=1;i<=c;i++){
			for(j=1;j<=m;j++){
				flag=0;
				for(k=1;k<=model[i][0];k++){
					if(model[i][k]>j) continue;
					else{
						if(dp[i-1][j-model[i][k]]+model[i][k]>dp[i][j-1]){
							dp[i][j]=dp[i-1][j-model[i][k]]+model[i][k];
						}
						else if(dp[i][j-1]>dp[i][j]) dp[i][j]=dp[i][j-1];
						flag=1;
					}
				}
				if(flag==0) dp[i][j]=dp[i][j-1];
			}			
		}		
		
		if(flagm) printf("no solution\n");
		else  printf("%d\n",dp[c][m]);
		
	}
	
	return 0;
}

void set(int m,int c){
	
	for(int i=1;i<=c;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=0;
		}
	}
	
}




