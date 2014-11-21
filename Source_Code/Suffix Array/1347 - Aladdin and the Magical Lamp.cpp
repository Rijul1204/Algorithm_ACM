#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

// Suffix Array.............

const int MAXN = 20500;
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
#define maxm 5010

char s1[maxm],s2[maxm],s3[maxm];
int mark1,mark2,mark3,now[4];

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

	    scanf("%s",s1);
	    scanf("%s",s2);
	    scanf("%s",s3);

	    mark1=0;
	    strcpy(str,s1);
	    strcat(str,"*");

	    mark2=strlen(str);
	    strcat(str,s2);
	    strcat(str,"#");

	    mark3=strlen(str);
	    strcat(str,s3);


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


		int pb,pe,v,ans=0;
		memset(now,0,sizeof(now));

        //pb=  begining pointer
        //pe= ending pointer
		pb=pe=0;

	    // flag indicating  which pointer increased  before..
		int flag=1;

		while(1){
			if(pb>=n||pe>=n) break;

		    if(str[suffix[pb]]=='*'||str[suffix[pb]]=='#'){
		        if(pb==pe) pe++;
				pb++; continue;
		    }
		    if(str[suffix[pe]]=='*'||str[suffix[pe]]=='#'){
		            pe++; continue;
		    }

			if(flag){
				if(suffix[pe]<mark2-1) now[0]++;
				else if(suffix[pe]<mark3-1) now[1]++;
				else now[2]++;
			}

			if(now[0]&&now[1]&&now[2]){
		        v=LCP(suffix[pb],suffix[pe]);
		        if(v>ans) ans=v;

		        if(suffix[pb]<mark2-1) now[0]--;
		        else if(suffix[pb]<mark3-1) now[1]--;
		        else now[2]--;

		        pb++;  flag=0;	continue;
		    }

			pe++; flag=1;
			if(pe>=n) break;

		}

		printf("Case %d: %d\n",t++,ans);

	}

	return 0;

}
