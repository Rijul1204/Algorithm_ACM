#include<stdio.h>
#include<string.h>

#define maxm 1050
#define ii long long int
#define mod 1000000007

// C=combination MD=modified dearrangement >> :)

ii dp1[maxm][maxm],dp2[maxm][maxm],fact[maxm];
int n,m,k;

void genfact(int n);
ii C(int i,int j);
ii MD(int i,int j);

int main(){

	int i,j,l,test,t=1;

//	freopen("in.txt","r",stdin);
	genfact(maxm-45);
	memset(dp1,-1,sizeof(dp1));
	memset(dp2,-1,sizeof(dp2));

	scanf("%d",&test);

	while(test--){

		scanf("%d %d %d",&n,&m,&k);
		ii ans=0;
		ans=C(m,k);
		ans=(ans*MD(n-k,m-k))%mod;

		printf("Case %d: %lld\n",t++,ans);

	}


	return 0;
}

void genfact(int n){

	int i;
	fact[0]=1; fact[1]=1;

	for(i=2;i<=n;i++){
		fact[i]=((fact[i-1]%mod)*i)%mod;
	}
}

ii MD(int i,int j){
	
	if(j<0) return 0;
	if(i==0) return 1;
	if(j==0) return fact[i];

	if(dp2[i][j]!=-1) return dp2[i][j];

	ii ret=0,right=i-j;

	ret=((j-1)*(MD(i-1,j-1)%mod+MD(i-2,j-2)%mod))%mod;
	ret=ret+(right*(MD(i-1,j-1)%mod))%mod;

	return dp2[i][j]=ret%mod;
	
}

ii C(int i,int j){

	if(i<j) return 0;
	if(i==j||i==0||j==0) return 1;

	if(dp1[i][j]!=-1) return dp1[i][j];

	return dp1[i][j]=(C(i-1,j-1)%mod+C(i-1,j)%mod)%mod;

}