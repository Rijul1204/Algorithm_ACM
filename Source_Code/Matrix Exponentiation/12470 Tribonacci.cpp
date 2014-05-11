#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 10
#define ii long long int

ii n,mod;
ii base[3][3]={{1,1,1},{1,0,0},{0,1,0}};
ii unit[3][3]={{1,0,0},{0,1,0},{0,0,1}},res[3][3];

void cal(ii a[3][3],ii b[3][3]){

	ii ret[3][3]; int i,j,k;
	memset(ret,0,sizeof(ret));

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				ret[i][j]+=(a[i][k]*b[k][j]);
				ret[i][j]%=mod;
			}
		}
	}

	memcpy(a,ret,sizeof(ret));

}


void exp(ii r[3][3],ii n){

	ii b[3][3];
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

	mod=1000000009;

	while(scanf("%lld",&n)==1){

		if(!n) break;
		if(n==1){
			printf("0\n"); continue;
		}
		if(n==2){
			printf("1\n"); continue;
		}
		if(n==3){
			printf("2\n"); continue;
		}

		exp(res,n-3);
		ii ans=0;
		ans+=(res[0][0]*2+res[0][1]*1);
		ans%=mod;

		printf("%lld\n",ans);


	}

	return 0;
}
