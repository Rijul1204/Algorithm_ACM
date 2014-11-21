#include<stdio.h>
#include<string.h>
#include<math.h>

#define mod 10007
#define ii long long int

ii base[4][4]={{1,0,1,1},{1,0,0,0},{0,1,0,0},{0,0,0,1}},unit[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
ii res[4][4],n,a,b,c;

void cal(ii a[4][4],ii b[4][4]){

	ii ret[4][4]; int i,j,k;
	memset(ret,0,sizeof(ret));

	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				ret[i][j]+=(a[i][k]*b[k][j]);
				ret[i][j]%=mod;
			}
		}
	}

	memcpy(a,ret,sizeof(ret));

}


void exp(ii r[4][4],ii n){

    ii b[4][4];
    memcpy(r,unit,sizeof(unit));
    memcpy(b,base,sizeof(base));

    while(n>0){
        if(n%2) cal(r,b);
        n/=2;
        cal(b,b);
    }
}

int main(){

    int i,j,k,l,test,t=1;

   // freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%lld %lld %lld %lld",&n,&a,&b,&c);

        if(n<=2){
            printf("Case %d: 0\n",t++);
            continue;
        }
        ii ans=0;

        base[0][0]=a; base[0][2]=b;
        exp(res,n-2);

        ans=c*res[0][3];
        ans%=mod;

        printf("Case %d: %lld\n",t++,ans);

    }

    return 0;

}
