#include<stdio.h>
#include<string.h>

#define maxm 40

int dp[maxm][6][6][6][6][6][6],num[10];
int coin[]={1,2,3,4,5,6};
char s[maxm];

int cal(int num,int a,int b,int c,int d,int e,int f);

int main(){

	int i,j,k,l,test,t=1;
	
	memset(dp,-1,sizeof(dp));
//	freopen("in.txt","r",stdin);

	while(gets(s)){

		for(i=0;i<6;i++){
			num[i]=4;
		}
		int sum=0;
		for(i=0;s[i];i++){
			sum+=(s[i]-'0');
			num[s[i]-'0'-1]--;
		}
		int a,b,c,d,e,f; l=strlen(s);
		a=num[0]; b=num[1]; c=num[2]; d=num[3]; e=num[4]; f=num[5];
		sum=31-sum;
		if(s[0]) printf("%s ",s);
		if(cal(sum,a,b,c,d,e,f)==1){
			if((l%2)==0){
				printf("A\n");
			}
			else printf("B\n");
		}
		else{
			if((l%2)==0){
				printf("B\n");
			}
			else{
				printf("A\n");
			}
		}


	}


	return 0;
}

int cal(int num,int a,int b,int c,int d,int e,int f){

	if(num==0) return 0;
	if(num<0) return 1;

	if(dp[num][a][b][c][d][e][f]!=-1) return dp[num][a][b][c][d][e][f];

	if(a>0){
		if(cal(num-1,a-1,b,c,d,e,f)==0) return dp[num][a][b][c][d][e][f]=1;
	}
	
	if(b>0){
		if(cal(num-2,a,b-1,c,d,e,f)==0) return dp[num][a][b][c][d][e][f]=1;
	}
	
	if(c>0){
		if(cal(num-3,a,b,c-1,d,e,f)==0) return dp[num][a][b][c][d][e][f]=1;
	}
	
	if(d>0){
		if(cal(num-4,a,b,c,d-1,e,f)==0) return dp[num][a][b][c][d][e][f]=1;
	}
	
	if(e>0){
		if(cal(num-5,a,b,c,d,e-1,f)==0) return dp[num][a][b][c][d][e][f]=1;
	}
	
	if(f>0){
		if(cal(num-6,a,b,c,d,e,f-1)==0) return dp[num][a][b][c][d][e][f]=1;
	}

	return dp[num][a][b][c][d][e][f]=0;


}