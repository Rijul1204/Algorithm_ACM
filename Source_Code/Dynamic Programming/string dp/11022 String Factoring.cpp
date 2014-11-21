#include<stdio.h>
#include<string.h>

#define maxm 200

char s[maxm],temp[maxm],pre[maxm];
int dp[maxm][maxm];

int compute(int b,int e);
int cal(int b,int e);
void prefix(char p[]);
int kmp(char s[],char p[]);

int mini(int a,int b){
	if(a<b) return a; return b;
}

int main(){

	int i,j,k,l;

//	freopen("in.txt","r",stdin);

	while(scanf("%s",s)==1){

		if(s[0]=='*') break;

		memset(dp,-1,sizeof(dp));

		l=strlen(s);

		printf("%d\n",cal(0,l-1));

	}

	return 0;
}

int cal(int b,int e){

	if(b>e) return 0;
	if(b==e) return 1;

	if(dp[b][e]!=-1) return dp[b][e];

	int i,j,k,l,ret=e-b+1,mm;
	
	mm=compute(b,e); 	
	if(mm!=(e-b+1)){
		ret=cal(b,b+mm-1);
	}

	for(i=b;i<e;i++){
		ret=mini(ret,cal(b,i)+cal(i+1,e));
	}

	return dp[b][e]=ret;

}



int compute(int b,int e){

	char temp[100],temp1[200];
	int i,j,k,l;

	for(i=0,j=b;j<=e;j++,i++){
		temp[i]=s[j];
	}
	temp[i]='\0'; l=i;		
	
	strcpy(temp1,temp); strcat(temp1,temp);

	int match=kmp(temp1,temp);
	
	match-=l;
	
	return match;
}

int kmp(char s[],char p[]){

	int i,j,k,l,ret=0;
	int n,m,fl=0;
	n=strlen(s); m=strlen(p);
	prefix(p);
	k=0;

	for(i=1;i<=n;i++){
		while(k>0 && s[i-1]!=p[k]) k=pre[k];
		if(s[i-1]==p[k]) k++;
		if(k==m){
			if(fl) return i;
			fl=1;
			ret++;
			k=pre[k];
		}
	}
	
	return i;
}

void prefix(char p[]){

	int i,j,k,l;
	
	l=strlen(p);
	pre[1]=0;
	k=0;

	for(i=2;i<=l;i++){
		while(k>0 && p[k]!=p[i-1]) k=pre[k];
		if(p[k]==p[i-1]) k++;
		pre[i]=k;
	}

}