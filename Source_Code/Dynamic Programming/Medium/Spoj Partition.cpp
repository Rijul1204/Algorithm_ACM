#include<stdio.h>
#include<string.h>

#define maxm 400
#define ii long long int

ii num,kth,n;
ii dp[maxm][20][maxm];

ii cal(int num,int pos,int last);
void print(int num,int pos,int kth,int last);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	memset(dp,-1,sizeof(dp));
	scanf("%d",&test);

	while(test--){

		scanf("%lld %lld %lld",&num,&n,&kth);
		print(num,n,kth,1);

	}

	return 0;
}

void print(int num,int pos,int kth,int last){

	if(pos==1){
		printf("%d\n",num); return ;
	}

	ii val=0,val1;
	int i,j,k,l;

	for(i=last;i<=num;i++){
		val1=cal(num-i,pos-1,i);
		if(val+val1>=kth) break;
		val+=val1;
	}
	printf("%d ",i);
	print(num-i,pos-1,kth-val,i);

}

ii cal(int num,int pos,int last){

	if(num==0&&pos==0) return 1;
	if(num<=0||pos<0) return 0;

	if(dp[num][pos][last]!=-1) return dp[num][pos][last];

	int i,j,k,l;
	ii  ret=0;

	for(i=last;i<=num;i++){
		ret+=cal(num-i,pos-1,i);
	}

	return dp[num][pos][last]=ret;

}
