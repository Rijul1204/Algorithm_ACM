#include<stdio.h>
#include<string.h>

#define maxm 110
#define ii long long int
#define mod 1000000007

ii dp[maxm][maxm][maxm];
char s[maxm],s1[maxm],s2[maxm],s3[maxm];
ii cal(int i,int j,int k);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%s %s %s",s1,s2,s3);
/*		
		strcpy(s,s1); strcat(s,s2);
		k=strlen(s); l=strlen(s3);
	//	printf("%s\n",s);
		
		memset(dp,-1,sizeof(dp));
		ii ans=cal(k-1,l-1);

		for(i=0;s1[i];i++){
			strcpy(s,s1); strcpy(s+i,s2); strcat(s,s1+i);
		//	printf("%s\n",s);
			memset(dp,-1,sizeof(dp));
			ans+=cal(k-1,l-1);
			ans%=mod;
		}
		
		/*
		strcpy(s,s2); strcat(s,s1);
		memset(dp,-1,sizeof(dp));
		ans+=cal(k-1,l-1);
		ans%=mod;
		*/
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %lld\n",t++,cal(strlen(s1)-1,strlen(s2)-1,strlen(s3)-1));

	}

	return 0;
}

ii cal(int i,int j,int k){
	
	ii ret=0;
	if(k<0) return 1;
    if(i<0&&j<0) return 0;
	if(dp[i+1][j+1][k+1]!=-1) return dp[i+1][j+1][k+1];
	if(i<0&&j>=0){
		if(s2[j]==s3[k]){
			ret=cal(i,j-1,k-1);
		}
		ret+=cal(i,j-1,k); ret%=mod;
		return dp[i+1][j+1][k+1]=ret;
	}
	if(j<0&&i>=0){		
		if(s1[i]==s3[k]){
			ret=cal(i-1,j,k-1);
		}
		ret+=cal(i-1,j,k); ret%=mod;
		return dp[i+1][j+1][k+1]=ret;
	}
	
	if(dp[i+1][j+1][k+1]!=-1) return dp[i+1][j+1][k+1];

	

	if(s1[i]==s3[k]){
		ret+=cal(i-1,j,k-1);
		ret%=mod;
	}
	
	if(s2[j]==s3[k]){
		ret+=cal(i,j-1,k-1);
		ret%=mod;
	}

 // if(s3[j]!=s3[k])
        ret+=cal(i-1,j,k);
	ret%=mod;
		
//	if(s1[j]!=s3[k])
        ret+=cal(i,j-1,k);
	ret%=mod;

	if(s1[i]==s3[k]){
	    ret-=(cal(i-1,j-1,k-1)); if(ret<0) ret+=mod;
    	    ret%=mod;
	}
	if(s2[j]==s3[k]){
		ret-=cal(i-1,j-1,k-1); if(ret<0) ret+=mod;
		ret%=mod;
	}	

   	ret-=cal(i-1,j-1,k);  if(ret<0) ret+=mod;
        ret%=mod;

	return dp[i+1][j+1][k+1]=ret;

}
