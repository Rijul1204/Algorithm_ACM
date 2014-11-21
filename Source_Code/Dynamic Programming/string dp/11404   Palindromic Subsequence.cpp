#include<stdio.h>
#include<string.h>

#define maxm 1050

char s[maxm],ans[maxm];
int len,pref[50][maxm],preb[50][maxm],dp[maxm][maxm],pre[maxm][maxm],tot;

int cal(int i,int j);
void init();
void print(int i,int j);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);	

	while(scanf("%s",s)==1){
		
		len=strlen(s);
		init();
		memset(dp,-1,sizeof(dp));
		//printf("%d\n",cal(0,len-1));
		tot=0; cal(0,len-1);
		print(0,len-1);
		
		for(i=0;i<tot;i++){
			if(i%2==0) printf("%c",ans[i]);
		}
		
		for(i=tot-1;i>=0;i--){
			if(i%2) printf("%c",ans[i]);
		}

		printf("\n");
	}

	return 0;
}

void init(){

	int i,j,k,l;

	for(i=0;i<=26;i++){
		pref[i][len-1]=len;
		preb[i][0]=-1;
	}
	for(i=0;i<=26;i++){
		if(s[0]==i+'a') preb[i][0]=0;
		else preb[i][0]=-1;
		if(s[len-1]==i+'a') pref[i][len-1]=len-1;
		else preb[i][len-1]=len;
	}


	for(i=0;i<=26;i++){
		for(j=len-2;j>=0;j--){
			if(s[j]==i+'a') pref[i][j]=j;
			else pref[i][j]=pref[i][j+1];
		}
		for(j=1;j<len;j++){
			if(s[j]==i+'a') preb[i][j]=j;
			else preb[i][j]=preb[i][j-1];
		}
	}

}

void print(int i,int j){
	
	if(i>j) return ;
	if(i==j){
		ans[tot++]=s[i];
		return ;
	}
	if(s[i]==s[j]){
		ans[tot++]=s[i]; ans[tot++]=s[i]; 
		print(i+1,j-1);
		return ;
	} 
	int i1=pre[i][j];
	print(pref[i1][i],preb[i1][j]);

}

int cal(int i,int j){

	if(i>j) return 0;
	if(i==j) return 1;

	if(dp[i][j]!=-1) return dp[i][j];

	if(s[i]==s[j]){
		return dp[i][j]=cal(i+1,j-1)+2;
	}
	int ret=0,i1,k,l;
	 
	for(i1=0;i1<26;i1++){
		if(ret<cal(pref[i1][i],preb[i1][j])){
			ret=cal(pref[i1][i],preb[i1][j]); 
			pre[i][j]=i1;
		}
	}		

	return dp[i][j]=ret;

}