#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

// Suffix Array.............

const int MAXN = 200010;
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
#define maxm 100010

char s1[maxm];
int mark1,mark2;

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

        scanf("%d",&l);
	    scanf("%s",s1);

	    mark1=0;
	    strcpy(str,s1);

	    mark2=strlen(str);
	    strcat(str,s1);

		// Suffix  array............construction

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

		////////////********************************\\\\\\\\\\\\\\\\

		int ans=-1,v,val,mark=-1;

		v=suffix[0];
		if(v<mark2){
		    ans=v; mark=0;
		}

		for(i=1;i<n;i++){
		    v=suffix[i];
		    if(v<mark2){
		        if(ans==-1){
		            ans=v; mark=i; continue;
		        }
		        if(v>ans) continue;
		        val=LCP(ans,v);
		        if(val>=l){
		            ans=v; mark=i;
		        }
		    }
		}

		printf("%d\n",ans);

	}

	return 0;

}
