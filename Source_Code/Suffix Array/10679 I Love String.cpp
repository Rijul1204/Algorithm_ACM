#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

// Suffix Array.............

const int MAXN =  100010;
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
//  end.

#define ii int
#define maxm 5010

char s[maxm];


int bs1(int b,int e,int ind);
int bs2(int b,int e,int ind);
int find(int b,int e,int ind);

int main(){

	int i,j,k,l,test,t=1;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

	    scanf("%s",str);

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

		//  suffix  array .........  end

		ii v; int q;

		scanf("%d",&q);

		for(i=1;i<=q;i++){
		    scanf("%s",s);
		    if(find(0,n-1,0)){
		        printf("y\n");
		    }
		    else printf("n\n");
		}


	}

	return 0;

}

int find(int b,int e,int ind){

    if(b>e) return 0;
    if(!s[ind]) return 1;

    int i,j,k;

    i=bs1(b,e,ind);
	j=bs2(b,e,ind);

    return find(i,j,ind+1);
}

int bs1(int b,int e,int ind){

    int mid,v,lo=b,hi=e;
	int flag=0;

    while(lo<=hi){

        mid=lo+hi; mid/=2;
        v=suffix[mid]+ind;
        if(v<n){
            if(str[v]>s[ind]){
                hi=mid-1;
            }
            else if(str[v]<s[ind]){
                lo=mid+1;
            }
            else if(str[v]==s[ind]){
				flag=1;
                if(hi==mid){
                    int v1=suffix[mid-1]+ind;
                    if(str[v1]==s[ind]) return mid-1;
                    else return mid;
                }
                hi=mid;
            }
        }
        else{
            lo=mid+1;
        }
    }
	if(!flag) return n;
    return hi;

}

int bs2(int b,int e,int ind){

    int mid,v,lo=b,hi=e;
	int flag=0;

    while(lo<=hi){

        mid=lo+hi; mid/=2;
        v=suffix[mid]+ind;
        if(v<n){
            if(str[v]>s[ind]){
                hi=mid-1;
            }
            else if(str[v]<s[ind]){
                lo=mid+1;
            }
            else if(str[v]==s[ind]){
				flag=1;
                if(lo==mid){
                    int v1=suffix[mid+1]+ind;
                    if(str[v1]==s[ind]) return mid+1;
                    else return mid;
                }
                lo=mid;
            }
        }
        else{
            lo=mid+1;
        }
    }
	if(!flag) return -1;
    return lo;

}
