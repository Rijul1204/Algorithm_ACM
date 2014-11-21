#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 10
#define ii long long int

ii n,mod,m;
ii base[2][2]={{2,2},{1,0}};
ii unit[2][2]={{1,0},{0,1}},res[2][2];

void cal(ii a[2][2],ii b[2][2]){

	ii ret[2][2]; int i,j,k;
	memset(ret,0,sizeof(ret));

	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				ret[i][j]+=(a[i][k]*b[k][j]);
				ret[i][j]%=mod;
			}
		}
	}

	memcpy(a,ret,sizeof(ret));

}


void exp(ii r[2][2],ii n){

	ii b[2][2];
	memcpy(r,unit,sizeof(unit));
	memcpy(b,base,sizeof(base));

	while(n>0){
		if(n%2==1) cal(r,b);
		n/=2;
		cal(b,b);
	}
}

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	mod=1000000007;

	scanf("%d",&test);

	while(test--){

	    scanf("%lld",&n);

		ii ans=0;

		if(n==1){
		    ans=1; ans%=mod;
			printf("%lld\n",ans); continue;
		}
		if(n==2){
		    ans=3; ans%=mod;
			printf("%lld\n",ans); continue;
		}


		exp(res,n-2);

		ans+=(res[0][0]*3+res[0][1]*1);
		ans%=mod;

		printf("%lld\n",ans);


	}

	return 0;
}
