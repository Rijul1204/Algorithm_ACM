/*
Author  : Silent_coder.
Algo    : Green Hackenbush.
problem : spoj (play with tree ).
*/
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 100100

int n,m,root=0;
int col[maxm],disc[maxm],low[maxm],tim,par[maxm],comp[maxm],comp_c;
vector<int>G[maxm],G2[maxm];

int dp[maxm];
int fl[maxm],kas=1;

int pre[maxm];

int find(int x){
    if(pre[x]==x) return x;
    return pre[x]=find(pre[x]);
}

int mini(int a,int b){ if(a<b) return a; return b;}
void dfs(int s,int pre);
int is_bridge(int u,int v);
void add_edge(int s,int pre);
int cal(int s,int pre);

// Fast....... reader.............

const int BUFFSIZE = 10240;
char BUFF[BUFFSIZE + 1], *ppp = BUFF;
int RR, CHAR, SIGN, BYTES = 0;
#define GETCHAR(c) { \
        if(ppp-BUFF==BYTES && (BYTES==0 || BYTES==BUFFSIZE)) { BYTES = fread(BUFF,1,BUFFSIZE,stdin); ppp=BUFF; } \
        if(ppp-BUFF==BYTES && (BYTES>0 && BYTES<BUFFSIZE)) { BUFF[0] = 0; ppp=BUFF; } \
        c = *ppp++; \
}

#define DIGIT(c) (((c) >= '0') && ((c) <= '9'))
#define MINUS(c) ((c)== '-')
#define GETNUMBER(n) { \
        n = 0; SIGN = 1; do { GETCHAR(CHAR); } while(!(DIGIT(CHAR) || MINUS(CHAR))); \
        if(MINUS(CHAR)) { SIGN = -1; GETCHAR(CHAR); } \
        while(DIGIT(CHAR)) { n = 10*n + CHAR-'0'; GETCHAR(CHAR); } if(SIGN == -1) { n = -n; } \
}
//////////////*******************************/////////////

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
	//freopen("out1.txt","w",stdout);

    GETNUMBER(test);
    //scanf("%d",&test);

    while(test--){

         GETNUMBER(n);
        //scanf("%d",&n);

        for(i=0;i<=n+1;i++){
            pre[i]=i;
            comp[i]=0;
            G[i].clear();
            G2[i].clear();
        }

        memset(col,0,sizeof(col));
        tim=0;

        root=-1;
        for(i=1;i<=n;i++){
             GETNUMBER(k);
            //scanf("%d",&k);
            if(k){
                if(root==-1){
                    root=i;
                    continue;
                }
                else{
                    pre[i]=root;
                }
                //G[0].push_back(i);
                //G[i].push_back(0);
            }
        }

        for(i=1;i<n;i++){
            GETNUMBER(k);
            GETNUMBER(l);
            //scanf("%d %d",&k,&l);
            k=find(k); l=find(l);
            G[k].push_back(l);
            G[l].push_back(k);
        }

        if(root==-1){
			puts("0");
			continue;
		}

        dfs(root,root);

        comp_c=0; memset(col,0,sizeof(col));
        add_edge(root,root);

		for(i=1;i<=n;i++){
			for(j=0;j<G[i].size();j++){
				k=G[i][j];
				G2[comp[i]].push_back(comp[k]);
			}
		}


        if(cal(0,-1)) puts("1");
        else puts("0");
        kas++;

    }

    return 0;
}

int cal(int s,int pre){

    if(fl[s]==kas) return dp[s];
    fl[s]=kas;

    int i,j,k,l;
    int ret=0,loop=0;

    for(i=0;i<G2[s].size();i++){
        k=G2[s][i];
        if(k==pre) continue;
        if(k==s) loop++;
        else{
			ret^=(1+cal(k,s));
        }
    }
	loop/=2;
    loop%=2; ret^=loop;

    return dp[s]=ret;
}

void dfs(int s,int pre){

    disc[s]=low[s]=tim++;
    col[s]=1;
    par[s]=pre;

    int i,j,k;
    int pre_count=0;

    for(i=0;i<G[s].size();i++){
        k=G[s][i];
        if(k==pre){
            if(pre_count) low[s]=mini(low[s],disc[k]);
            pre_count++;
            continue;
        }
        if(col[k]==1){
            low[s]=mini(low[s],disc[k]);
        }
        else{
            dfs(k,s);
            low[s]=mini(low[s],low[k]);
        }
    }

}

int is_bridge(int u,int v){

    if(par[v]!=u || u==v) return 0;
    return (low[v]==disc[v]);
}

void add_edge(int s,int pre){

    if(col[s]) return ;
    col[s]=1;

    int i,j,k;
    int pre_count=0;

    if(is_bridge(pre,s)) comp[s]=++comp_c;
    else comp[s]=comp[pre];

    for(i=0;i<G[s].size();i++){
        k=G[s][i];
        add_edge(k,s);
    }

}
