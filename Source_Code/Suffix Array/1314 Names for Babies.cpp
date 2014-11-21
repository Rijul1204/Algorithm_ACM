#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int MAXN = 10100;
const int MAXL = 30;
int n ,stp,mv,suffix[MAXN],tmp[MAXN];
int sum[MAXN],cnt[MAXN],rank[MAXL][MAXN];
char str[MAXN];

int LCP(int u,int v){
	int ret=0,i;
	for(i = stp; i >= 0; i--){
		if(rank[i][u]==rank[i][v]){
			ret += 1<<i;
			u += 1<<i;
			v += 1<<i;
		}
	}
	return ret;
}
bool equal(int u,int v){
	if(!stp)return str[u]==str[v];
	if(rank[stp-1][u]!=rank[stp-1][v]) return false;
	int a = u + mv < n ? rank[stp-1][u+mv] : -1;
	int b = v + mv < n ? rank[stp-1][v+mv] : -1;
	return a == b ;
}
void update(){
	int i;
	for(i = 0;i < n; i ++) sum[ i ] = 0;

	int rnk = 0;
	for(i = 0;i < n;i++){
		suffix[ i ] = tmp[ i ];
		if( i&&!equal(suffix[i],suffix[i-1])){
			rank[stp][suffix[i]]=++rnk;
			sum[rnk+1]=sum[rnk];
		}
		else rank[stp][suffix[i]]=rnk;
		sum[rnk+1]++;
	}
}
void Sort(){
	int i;
	for(i = 0; i < n; i ++ ) cnt[ i ] = 0;
	memset(tmp,-1,sizeof tmp);
	for(i = 0 ; i < mv; i ++){
		int idx = rank[ stp - 1 ][ n-i-1 ];
		int x = sum[ idx ];
		tmp[ x + cnt[ idx ] ] = n-i-1;
		cnt[ idx ]++;
	}
	for(i = 0;i < n; i ++ ){
		int idx = suffix[ i ] - mv;
		if(idx<0)continue;
		idx = rank[stp-1][idx];
		int x = sum[ idx ];
		tmp[ x + cnt[ idx ] ] = suffix[ i ] - mv;
		cnt[idx]++;
	}
	update();
	return;
}
bool cmp(const int &a,const int &b){
	if(str[a]!=str[b]) return str[a]<str[b];
	return false;
}
////////////*******************************///////////////

#define ii int

ii mini(ii a,ii b){
	if(a<b) return a;
	return b;
}
ii maxi(ii a,ii b){
	if(a>b) return a;
	return b;
}

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		scanf ( "%s", str  );
		n=strlen(str);
		for(i = 0;i < n;i++) tmp[ i ] = i ;

		sort(tmp,tmp+n,cmp);
		stp = 0;
		update();
		++stp;
		for( mv = 1; mv < n;  mv <<= 1){
			Sort();
			stp++;
		}
		stp--;

		for(i = 0;i<=stp; i++)	rank[ i ][ n ] = -1;

		//L-R= range >>> of query  of Length...
		ii L,R;
		//Taking range>>>
		scanf("%d %d",&L,&R);

		ii res=0,val,v,val1;

		val=n-suffix[0];
		val=mini(val,R);
		if(val>=L) res+=(val-L+1);

		for(i = 1; i < n; i ++){
			v=LCP(suffix[i],suffix[i-1]);
			if(R<=v) continue;
			val=n-suffix[i];
			val=mini(val,R);
			if(val>=L){
				val1=maxi(L-1,v);
				res+=(val-val1);
			}
		}

		printf("Case %d: %d\n",t++,res);

	}

	return 0;

}
