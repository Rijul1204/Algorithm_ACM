#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 10
#define ii long long int

ii n,mod;
ii base[4][4]={{1,1,1,1},{1,0,0,0},{0,0,1,1},{0,0,1,0}};
ii unit[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}},res[4][4],mem[100][4][4];

//big mod
ii big_mod(ii b,ii p,int m);

void cal(ii a[4][4],ii b[4][4],ii ret1[4][4]){

    int i,j,k;
    ii ret[4][4];
	memset(ret,0,sizeof(ret));

	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				ret[i][j]+=(a[i][k]*b[k][j]);
				if(ret[i][j]>mod) ret[i][j]%=mod;
			}
		}
	}

	memcpy(ret1,ret,sizeof(ret));

}


void exp(ii r[4][4],ii n){

	ii b[4][4];
	memcpy(r,unit,sizeof(unit));
	memcpy(b,base,sizeof(base));

	int j=0;
	while(n>0){
		if(n%2==1) cal(r,mem[j],r);
		n/=2; j++;
		//cal(b,b);
	}
}

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);
	mod=1000000007;

	memcpy(mem[0],base,sizeof(base));
	for(i=1;i<=62;i++){
	    cal(mem[i-1],mem[i-1],mem[i]);
    }

	while(test--){
	    scanf("%lld",&n);

		if(n==0){
			printf("0\n"); continue;
		}
		if(n==1){
			printf("0\n"); continue;
		}

		exp(res,n-2);
		ii ans=0;
		ans+=(res[0][0]*5)%mod+(res[0][2]*8)%mod+(res[0][3]*5)%mod;
		ans%=mod;
		printf("%lld\n",ans);

	}

	return 0;
}
