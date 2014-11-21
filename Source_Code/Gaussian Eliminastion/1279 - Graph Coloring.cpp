#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

#define maxm 110
#define ii1 long long int
#define mod 1000000007


ii1 n,m,K;

///Gaussian  Elimination...............................................

#define eps (1e-9)
#define iseq(a,b) (fabs(a-b)<eps)

ii1 a[maxm][maxm];

ii1 big_mod(ii1 b,ii1 p,ii1 m){

    if(p==0) return 1;
    if(p==1) return b%m;

    ii1 ret;
    ret=big_mod(b,p/2,m);
    ret*=ret; ret%=m;
    if(p%2) ret*=b;
    ret%=m;
    return ret;

}
// Extended Euclid .....  for  finding  Modular inverse
struct node{
	ii1 x,y,g;
	node(){};
	node(ii1 xx,ii1 yy,ii1 gg){ x=xx; y=yy; g=gg;};
};
node euclid(ii1 a,ii1 b){

	if(!b) return node(1,0,a);
	node r=euclid(b,a%b);
	return node(r.y,r.x-(a/b)*r.y,r.g);
}

ii1 mod_inv(ii1 n,ii1 m){

    node t=euclid(n,m);
    if(t.g>1) return 0;
    ii1 ret=t.x%m;
    if(ret<0) ret+=m;
    return ret;
}

ii1 gauss(ii1 n,ii1 m,ii1 MOD){

    // m = number of equations
	// n = number of variables
	// MOD = the number to take MOD


	  int ii = 0 , i, j,ret=0;

	  for(i = 0; i < n ; i ++ ) {
		j = ii ;
		while ( j < m && a[j][i] == 0 )  j++ ;
		if (j == m)  continue ;

		ret++;
		for(ii1 i1=0;i1<n;i1++){
			swap (a[ii][i1], a[j][i1]) ;
		}


		ii1 t = a[ii][i] , k;
		ii1 md=mod_inv(t,MOD);
		for(k = 0; k < n ; k ++ ){
		   a[ii][k] = (a[ii][k] * md);
		   if(a[ii][k]>=MOD) a[ii][k]%=MOD;
		}

		for(j = 0; j < m ; j ++ )  if (j!=ii) {
			ii1 t = a[j][i] ;
			for(k = 0; k < n ; k ++ ){
               a[j][k] = (a[j][k] - t*a[ii][k]);
               if(a[j][k]>=MOD) a[j][k]%=MOD;
               if(a[j][k]<0){
                a[j][k]%=MOD;
                if(a[j][k]<0) a[j][k]+=MOD;
               }
			}
		  }
		ii++ ;
	}
	return n-ret;
	/*

	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        printf("%3d ",a[i][j]);
	    }
	    puts("");
	}
	*/


	return ret;
}

///   Gaussian  Elimination   Finish.....................


int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%lld %lld %lld",&n,&m,&K);

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                a[i][j]=0;
            }
            a[i][i]=-1+K;
        }

        for(i=1;i<=m;i++){
            scanf("%d %d",&k,&l);
            k--; l--;
            a[k][l]=a[l][k]=1;
        }


        ii1 ans=gauss(n,n,K);
        ans=big_mod(K,ans,mod);

        printf("Case %d: %lld\n",t++,ans);

    }

    return 0;
}
