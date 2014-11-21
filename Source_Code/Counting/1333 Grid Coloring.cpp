#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
//#include<map>
#include<set>
using namespace std;

#define maxm 1000100
#define ii long long int
#define mod 1000000000

struct cell{
	int x,y;
};

cell cells[660];
int bl[maxm];
int b;
ii kk,m,n;
bool comp(cell a,cell b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
ii big_mod(int b,ii p,int m);

int main(){

    int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

    scanf("%d",&test);

    while(test--){

        scanf("%lld %lld %lld %d",&m,&n,&kk,&b);

		int c=0,c1=0;

        for(i=0;i<b;i++){
            scanf("%d %d",&j,&l);
			cells[i].x=j; cells[i].y=l;
        }
		sort(cells,cells+b,comp);
		cells[b].x=-1; cells[b].y=-1;

        ii ans=1;
        ii prev=0,tot=(m-1)*n;
	    //tot%=mod;
		memset(bl,0,sizeof(bl));
		for(i=0;i<b;i++){
			k=cells[i].x; l=cells[i].y;
			bl[k]++; if(k!=1) tot--;
			if(k==m) continue;
			if(l==cells[i+1].y&&cells[i+1].x==k+1) continue;
			ans*=kk; ans%=mod; bl[k+1]++; tot--;
		}

        int k1=n,l1;
        for(i=1;i<=1;i++){
			k1=n-bl[i];
			ans*=big_mod(kk,k1,mod);
            ans%=mod; //tot-=k1;
        }

        ans*=big_mod(kk-1,tot,mod);
        ans%=mod;

        printf("Case %d: %lld\n",t++,ans);

    }

    return 0;

}

ii big_mod(int b,ii p,int m){

    if(p<=0) return 1;
    if(p==1) return b%m;

    ii ret;
    ret=big_mod(b,p/2,m);
    ret*=ret; ret%=m;
    if(p%2) ret*=b;
    ret%=m;
    return ret;

}
