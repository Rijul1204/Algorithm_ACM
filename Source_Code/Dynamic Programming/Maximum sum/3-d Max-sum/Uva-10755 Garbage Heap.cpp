/*
Author : Rashedul Hasan Rijul ( Silent_coder ).
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define maxm 22
#define inf (1<<29)
#define ii long long int

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

ii on(ii n,ii k){ return (n|(1<<k)); }
ii off(ii n,ii k){ return (n-(n&(1<<k))); }
bool chck(ii n,ii k){ return (n&(1<<k)); }

ii mini(ii a,ii b){ if(a<b) return a;  return b;  }
ii maxi(ii a,ii b){ if(a>b) return a;  return b;  }

int a,b,c;
ii mat[maxm][maxm][maxm];
ii c_sum[maxm][maxm][maxm];

ii max_sum_3d(int a,int b,int c);
ii get_sum(int beg_i,int beg_j,int end_i,int end_j,int ind){
    return (c_sum[end_i][end_j][ind]-c_sum[beg_i-1][end_j][ind]-c_sum[end_i][beg_j-1][ind]
            +c_sum[beg_i-1][beg_j-1][ind]);
}

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&test);

    bool blank=false;

    while(test--){

        scanf("%d %d %d",&a,&b,&c);

        if(blank) puts("");
        blank=true;
        printf("%lld\n",max_sum_3d(a,b,c));
    }

    return 0;
}

ii max_sum_3d(int a,int b,int c){

    int i,j,k;
    ii ret=0;

    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            for(k=1;k<=c;k++){
                scanf("%lld",&mat[i][j][k]);
                c_sum[i][j][k]=mat[i][j][k];
                c_sum[i][j][k]+=(c_sum[i-1][j][k]+c_sum[i][j-1][k]-c_sum[i-1][j-1][k]);
            }
        }
    }
    ret=mat[a][b][c];

    for(int len_i=0;len_i<a;len_i++){
        for(int len_j=0;len_j<b;len_j++){
            for(i=1;i<=a;i++){
				if(i+len_i>a) break;
                for(j=1;j<=b;j++){
					if(j+len_j>b) break;
                    ii sum=0;
                    for(k=1;k<=c;k++){
                        sum+=get_sum(i,j,i+len_i,j+len_j,k);
                        if(sum>ret) ret=sum;
                        if(sum<0) sum=0;
                    }
                }
            }
        }
    }

    return ret;
}
