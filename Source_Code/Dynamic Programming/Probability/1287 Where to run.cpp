#include<stdio.h>
#include<string.h>

#define maxm 20
#define maxn 1<<17

int on(int n,int k){
	return n|(1<<k);
}
int off(int n,int k){
	return n-(n&(1<<k));
}
bool chck(int n,int k){
	return (1<<k)==(n&(1<<k));
}

int mat[maxm][maxm],n,m;
bool dp1[maxm][maxn],fl[maxm][maxn],fl1[maxm][maxn];
double dp[maxm][maxn];

double cal(int ind,int num);
bool cal1(int ind,int num);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&n,&m);
		
		memset(mat,0,sizeof(mat));
		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			mat[k][l]=mat[l][k]=j;
		}
		memset(fl,0,sizeof(fl)); memset(fl1,0,sizeof(fl));

		printf("Case %d: %lf\n",t++,cal(0,1)+.0000001);


	}

	return 0;
}

double cal(int ind,int num){

	if(num==(1<<n)-1) return 0;

	if(fl[ind][num]) return dp[ind][num];
	fl[ind][num]=1;
	
	int i,k;
	double ret=0,ej=0;
	bool flag[20];
	memset(flag,0,sizeof(flag));

	for(i=0;i<n;i++){
		if(chck(num,i)||!mat[ind][i]) continue;
		k=on(num,i);
		if(cal1(i,k)){
			ej++;
			flag[i]=1;
		}
	}
	if(ej==0) return 0;
	double pr=ej+1;
	pr=1/pr;

	for(i=0;i<n;i++){
		if(flag[i]){
			k=on(num,i);
			ret+=(cal(i,k)+mat[ind][i])*pr;			
		}
	}
	ret+=(double)5.0*pr;
	ret/=(double)(1.0-pr);
	return dp[ind][num]=ret;	

}

bool cal1(int ind,int num){

	if(num==(1<<n)-1) return 1;
	
	if(fl1[ind][num]) return dp1[ind][num];
	fl1[ind][num]=1;
	
	int i,k;
	for(i=0;i<n;i++){
		if(chck(num,i)||!mat[ind][i]) continue;
		k=on(num,i);
		if(cal1(i,k)) return dp1[ind][num]=1;
	}
	return dp1[ind][num]=0;
}