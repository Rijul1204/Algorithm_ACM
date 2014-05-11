#include<stdio.h>
#include<string.h>

#define maxm 110

char s1[maxm],s2[maxm];
int dp[maxm][maxm],pre[maxm][maxm],ind,c,bl;

void print(int i,int j);
int cal(int i,int j);
int mini(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int i,j,k,l;

	bl=0;

//	freopen("in.txt","r",stdin);

	while(gets(s1)){
		gets(s2);

		k=strlen(s1); l=strlen(s2);
		memset(dp,-1,sizeof(dp));
		if(bl) printf("\n");
		bl=1;
		printf("%d\n",cal(k-1,l-1));
		
		/*
		for(i=0;i<k;i++){
			for(j=0;j<l;j++){
				printf(" %d ",pre[i][j]);
			}
			printf("\n");
		}
		*/
		c=1;
		ind=1;
		print(k-1,l-1);
		
	}

	return 0;
}

void print(int i,int j){

	int k;
	
	if(i<0){
		for(k=0;k<=j;k++){
			printf("%d Insert %d,%c\n",c++,ind,s2[ind-1]);
			ind++;
		}
		return ;
	}
	if(j<0){
		for(k=0;k<=i;k++){
			printf("%d Delete %d\n",c++,ind);
		}
		return ;
	}

	if(pre[i][j]==0){
		print(i-1,j-1);
	}

	else if(pre[i][j]==1){
		print(i-1,j);
		printf("%d Delete %d\n",c++,ind);
	}
	else if(pre[i][j]==2){
		print(i,j-1);
		printf("%d Insert %d,%c\n",c++,ind,s2[ind-1]);
	}
	else {
		print(i-1,j-1);
		printf("%d Replace %d,%c\n",c++,ind,s2[ind-1]);
	}

	if(pre[i][j]!=1) ind++;
}

int cal(int i,int j){

	if(i<0||j<0){
		if(i<j) return j-i;
		return i-j;
	}
	int ret;
	
	if(dp[i][j]!=-1) return dp[i][j];

	if(s1[i]==s2[j]){
		pre[i][j]=0;
		ret=cal(i-1,j-1);
		return dp[i][j]=cal(i-1,j-1);
	}

	pre[i][j]=1;
	ret=cal(i-1,j)+1;

	if(ret>cal(i,j-1)+1){
		pre[i][j]=2;
		ret=cal(i,j-1)+1;
	}
	if(ret>cal(i-1,j-1)+1){
		pre[i][j]=3;
		ret=cal(i-1,j-1)+1;
	}

	/*
	ret=mini(cal(i-1,j)+1,cal(i,j-1)+1);
	ret=mini(ret,cal(i-1,j-1)+1);
	*/

	return dp[i][j]=ret;

}