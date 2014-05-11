#include<stdio.h>

char s[2000010];
int dp[2000010];
int min,count;

void set(int n);

int main(){

	int i,n;
	char dum,help[2];
    
	//freopen("in.txt","r",stdin);
	
	while(1){
		scanf("%d%c",&n,&dum);
        if(!n) break;

		set(n);

		for(i=0;i<n;i++){
			scanf("%c",&s[i]);
			if(s[i]=='Z') min=0;
			if(s[i]=='D'){
				dp[i]=0;
				count=1;
			}
			else if(s[i]=='.'){
				if(count<dp[i]) dp[i]=count;
				count++;
			}
			else if(s[i]=='R'){
				if(count<dp[i]) dp[i]=count;   
				if(dp[i]<min) min=dp[i];
				count++;
			}

		}
		gets(help);

		count=2010110;
		for(i=n-1;i>=0;i--){

			if(s[i]=='D'){
				dp[i]=0;
				count=1;
			}
			else if(s[i]=='.'){
				if(count<dp[i]) dp[i]=count;
				count++;
			}
			else if(s[i]=='R'){
                if(count<dp[i]) dp[i]=count;   
				if(dp[i]<min) min=dp[i];
				count++;
			}
		}

		printf("%d\n",min);

	}

	return 0;
}


void set(int n){

	int i;

	for(i=0;i<=n+2;i++){
		dp[i]=2010110;
	}
	
	min=2010110;
	count=2010110;

	return ;
}






