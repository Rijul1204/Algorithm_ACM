#include<stdio.h>
#include<string.h>
#include<math.h>
#define maxm 550
#define ii long long int
#define mod 1000000007

bool p[100100];
int prime[maxm],tot;
ii dp[maxm][maxm];
//prime generation
void gen(int n);
//big mod
ii big_mod(int b,int p,int m);
ii cal(int k,int p);

int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);

	gen(100000-10); tot=1;
	for(i=2;i<=100000;i++){
		if(p[i]) continue;
		prime[tot++]=i; if(tot>502) break;
	}

	memset(dp,-1,sizeof(dp));

	scanf("%d",&test);

	while(test--){

		scanf("%d %d",&k,&l);
		printf("Case %d: %lld\n",t++,cal(k,l));
	}

	return 0;
}

ii cal(int k,int p){

	if(k==0&&p==0) return 1;
	if(k<p||p<0||k<0) return 0;

	if(dp[k][p]!=-1) return dp[k][p];

	ii ret=0,val;
	int i;
	ii j,l;
	j=prime[p]; ii val1=1;
	for(i=1;i<=k;i++){
	    if(k-i<p-1) break;
		//val=big_mod(j,i-1,mod)*(j-1); val%=mod;
		if(i>1) val1*=j; val1%=mod;
		val=val1*(j-1); val%=mod;
		ret+=(val*cal(k-i,p-1));
		ret%=mod;
	}

	return dp[k][p]=ret;

}

ii big_mod(int b,int p,int m){

    if(p<=0) return 1;
    if(p==1) return b%m;

    ii ret;
    ret=big_mod(b,p/2,m);
    ret*=ret; ret%=m;
    if(p%2) ret*=b;
    ret%=m;
    return ret;

}


void gen(int n){

	int i,j,k,l,sq;
	double sqd,nd=n;

	sqd=sqrt(nd); sq=sqd;

	p[0]=p[1]=1;

	for(i=4;i<=n;i+=2) p[i]=1;

	for(i=3;i<=sq;i+=2){
		if(p[i]) continue;
		for(j=i*i;j<=n;j+=(2*i)){
			p[j]=1;
		}
	}
}
