#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 10
#define ii unsigned long long int
#define maxn 2

ii n,mod,p,q;
ii base[2][2];
ii unit[2][2]={{1,0},{0,1}},res[2][2];

void cal(ii a[2][2],ii b[maxn][maxn]){

	ii ret[maxn][maxn]; int i,j,k;
	memset(ret,0,sizeof(ret));

	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			for(k=0;k<maxn;k++){
				ret[i][j]+=(a[i][k]*b[k][j]);
				//ret[i][j]%=mod;
			}
		}
	}

	memcpy(a,ret,sizeof(ret));

}


void exp(ii r[maxn][maxn],ii n){

	ii b[maxn][maxn];
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

	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

	    printf("Case %d: ",t++);

	    scanf("%llu %llu %llu",&p,&q,&n);

		ii ans=0;
		ii ans1=p*p-(2*q);

		if(n==0){
			printf("2\n"); continue;
		}
		if(n==1){
		    ans=p;
			printf("%llu\n",ans); continue;
		}
		if(n==2){
			ans=ans1;
			printf("%llu\n",ans); continue;
		}

		base[0][0]=p; base[0][1]=-q;
		base[1][0]=1; base[1][1]=0;

		exp(res,n-2);

		ii pu=p;
		ans+=(res[0][0]*ans1+res[0][1]*pu);
		printf("%llu\n",ans);


	}

	return 0;
}
