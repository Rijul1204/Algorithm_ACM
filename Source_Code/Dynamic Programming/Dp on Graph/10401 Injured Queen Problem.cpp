#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define ii long long int


int flag[30][30];
ii dp[30][30];
int vis[30][30];
int len;
char s[30];

void mark(int i,int c);
void unmark(int i,int c);
ii  back(int r,int c);

int main(){
	
	int i,j,k,l;
	
	
	
	while(scanf("%s",s)==1){

		
		
		
		len=strlen(s);
		if(len==1){
			printf("%d\n",1);
			continue;
		}
		ii ret=0;

		for(i=0;i<=len;i++){
			for(j=0;j<=len;j++){
				flag[i][j]=0;
				vis[i][j]=0;
				dp[i][j]=0;
			}
		}


		
		if(s[0]=='?'){
			for(i=1;i<=len;i++){
					mark(i,1);
					ret+=back(i,2);
					unmark(i,1);
			}
		}
		else {
			if(isalpha(s[0])) j=10+s[0]-'A';
			else j=s[0]-'0';
			
			mark(j,1);
			ret=back(j,2);
			unmark(j,1);
			
		}
		
		printf("%lld\n",ret);
	}
	
	
	return 0;
}

ii back(int r,int c){
	
	int i,j,k;
	ii ret;
	
	if(c==len){
		ret=0;
		
		if(s[c-1]=='?'){
			for(i=1;i<=len;i++){
				if(flag[i][c]==0) ret++;
			}
			return ret;
		}
		else{
			
			if(isalpha(s[c-1])) j=10+s[c-1]-'A';
			else j=s[c-1]-'0';

			if(flag[j][c]!=0) return 0;
			else return 1;
			
		}
		
	}
	//return dp[r][c]==1;
	
	if(s[c-1]=='?'){
		
		ret=0;

		for(i=1;i<=len;i++){
			if(flag[i][c]==0){
				if(vis[i][c]==0){
					vis[i][c]=1;
					mark(i,c);
					ret+=dp[i][c]=back(i,c+1);
					unmark(i,c);
				}
				else ret+=dp[i][c];
			}		
		}	
	}
	else{
		
		if(isalpha(s[c-1])) j=10+s[c-1]-'A';
		else j=s[c-1]-'0';
		
		if(flag[j][c]!=0) return 0;
		if(vis[j][c]==0){
			vis[j][c]=1;
			mark(j,c);
			ret=dp[j][c]=back(j,c+1);
			unmark(j,c);
		}
		else ret=dp[j][c];
	}
	
	
	return ret;
	
	
}

void mark(int i,int c){
	
	int j,k,l;
	
	//	for(j=1;j<=len;j++){
	//		flag[j][c]++;
	//	}
	//	if(c>1) flag[i][c-1]++;
	if(c<len) flag[i][c+1]++;
	//	if(i>1||c>1) flag[i-1][c-1]++;
	if(i>1&&c<len) flag[i-1][c+1]++;
	if(i<len&&c<len) flag[i+1][c+1]++;
	//	if(i<len||c>1) flag[i+1][c-1]++;
	
}

void unmark(int i,int c){
	
	int j;
	
	//	for(j=1;j<=len;j++){
	//		flag[j][c]--;
	//	}
	//	if(c>1) flag[i][c-1]--;
	if(c<len) flag[i][c+1]--;
	//	if(i>1||c>1) flag[i-1][c-1]--;
	if(i>1&&c<len) flag[i-1][c+1]--;
	if(i<len&&c<len) flag[i+1][c+1]--;
	//	if(i<len||c>1) flag[i+1][c-1]--;
	
}
