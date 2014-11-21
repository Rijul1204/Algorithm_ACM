#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

/****** Suffix Array ***********/

const int MAXN = 50100;
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

//////////******KMP****************//////////////

#define maxm 50100

char s[maxm],p[maxm];
int pre[maxm];
bool match[maxm];
vector<int>shift;

void prefix(){

	int i,j,k,l;

	l=strlen(p);
	pre[1]=0;
	k=0;

	for(i=2;i<=l;i++){
		while(k>0 && p[k]!=p[i-1]) k=pre[k];
		if(p[k]==p[i-1]) k++;
		pre[i]=k;
	}

}

int kmp(){

	int i,j,k,l,ret=0;
	int n,m;
	n=strlen(s); m=strlen(p);
	prefix();
	k=0;

	for(i=1;i<=n;i++){
		while(k>0 && s[i-1]!=p[k]) k=pre[k];
		if(s[i-1]==p[k]) k++;
		if(k==m){
			match[i-1]=1;
			shift.push_back(i-m);
			ret++;
			k=pre[k];
		}
	}

	return ret;
}

//////////////////***********************///////////////////////

#define ii int

int bs(int val);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

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

		scanf("%s",p);
		//l = length of pattern
		l=strlen(p);
		strcpy(s,str);

		//Kmp string=s,str;  pattern=p>>>>>>>>
		shift.clear();
		kmp();


		ii res=0,val,v,val1;

		val1=bs(suffix[0]);
		if(val1!=-1) val1=shift[val1]+l-1;
		else val1=n;
		val=val1-suffix[0];
		res+=val;

		for(i = 1; i < n; i ++){
			v=LCP(suffix[i],suffix[i-1]);
			val1=bs(suffix[i]);
			if(val1!=-1) val1=shift[val1]+l-1; //l =length of pattern;
			else val1=n;
			val=val1-suffix[i];
			val-=v;
			if(val>0) res+=val;
		}

		printf("Case %d: %d\n",t++,res);

	}

	return 0;

}

int bs(int val){

	int mid,lo=0,hi;

	hi=shift.size()-1;
	if(shift[hi]<val) return -1;

	while(lo<hi){

		mid=lo+hi; mid/=2;

		if(shift[mid]<val){
			lo=mid+1;
		}
		else{
			if(hi==mid){
				if(shift[mid-1]<val) return mid;
				return mid-1;
			}
			hi=mid;
		}
	}

	return hi;

}
