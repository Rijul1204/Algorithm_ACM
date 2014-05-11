#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

#define maxm 905
#define maxn 10005

int dp[maxm][maxn];
bool v[maxm][maxn];
char pre[maxm][maxn];

void print(int s,int s1);
int cal(int sum,int sum1);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);
	memset(v,0,sizeof(v));
	memset(pre,-1,sizeof(pre));

	while(test--){

		scanf("%d %d\n",&k,&l);

		if(k>900||l<k){
			cout<<"No solution"<<endl;
			continue;
		}
		j=cal(k,l);
		if(j>100){
			cout<<"No solution"<<endl;
			continue;
		}
		print(k,l);
		printf("\n");

	}

	return 0;
}
void print(int s,int s1){
	
	if(s==0&&s1==0) return ;
	if(pre[s][s1]==-1){
		printf("No solution");
		return ;
	}
	printf("%c",pre[s][s1]);
	print(s-(pre[s][s1]-'0'),s1-((pre[s][s1]-'0')*(pre[s][s1]-'0')));
}

int cal(int sum,int sum1){

	if(sum==0&&sum1==0) return 0;
	else if(sum<0||sum1<0) return -2;

	if(v[sum][sum1]) return dp[sum][sum1];
	v[sum][sum1]=1;
	
	int ret=-2,ret1,ret2;	
	int i;

	for(i=1;i<=9;i++){
		ret1=cal(sum-i,sum1-(i*i));
		if(ret1==-2) continue;
		ret1++;
		if(ret==-2){
			pre[sum][sum1]=i+'0';
			ret=ret1;
		}
		else if(ret>ret1){
			pre[sum][sum1]=i+'0';
			ret=ret1;
		}
	}

	return dp[sum][sum1]=ret;

}
