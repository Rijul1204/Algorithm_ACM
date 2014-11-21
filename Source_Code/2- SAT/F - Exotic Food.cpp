
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

const int    inf = (1<<28);
const double pi  = (2.0*acos(0.0));
const double eps = 1e-9;

//typedef long long           lli;
//typedef __int64             lli;
//typedef unsigned long long  llu;
//typedef unsigned __int64    llu;
typedef pair < int , int >  pii;
typedef vector < int >      vi;
//typedef vector < string >   vs;

#define isp2( a ) (!(a & (a-1)))
#define CLR( a )  memset(a , 0  , sizeof (a))
#define SET( a , b)  memset(a , b , sizeof (a))
#define SZ( a )   ((int)a.size())
#define all( a )  a.begin(),a.end()


//#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define _rep( i, a, b, x )  for( i = ( a ) ; i <= ( b ) ; i += x )
#define rep( i, n )        _rep( i, 0, n - 1, 1 )
#define _rrep( i, a, b, x ) for( i = (a) ; i >= (b) ; i -= x )
#define rrep( i, a, b)     _rrep( i, a, b, 1)
#define xrep( i, a, b)     _rep( i, a, b, 1)

#define SD( a ) scanf("%d",&a)
#define SL( a ) scanf("%lld",&a)
#define SI( a ) scanf("%I64d",&a)
#define SS( a ) scanf("%s",a)
#define SF( a ) scanf("%lf",&a);

#define pb push_back
#define ff first
#define ss second

#define neg(x) ( ((x)<N) ? N+(x) : (x)-N )
#define neg1(x) ( ((x)<=N) ? N+(x) : (x)-N )

int N,n,m;// n relations ; m+m variable ; N=m, used for makring neg(x)
//******************************
int V,E;
const int mx= 10000 + 10000;
int mark[mx+10] , vis[mx+10] , color;
vi G[mx+10] , RG[mx+10];
vector < pii > Edge;
stack < int > S;
vi elem[mx+10];


void Tdfs(int u)
{
    int i,v,sz;
    vis[u]=1; sz=SZ(G[u]);
    rep(i,sz)
    {
        v= G[u][i];
        if(!vis[v]) Tdfs(v);
    }
    S.push(u);
    vis[u]=2;
}
void TopSortDfs(int n)
{
    int i , j;
    while(!S.empty())S.pop();
    CLR(vis);
    rep(i,n)
        if(!vis[i])
            Tdfs(i);
}
void Sdfs(int u)
{
    int i,v,sz;
    vis[u]=1; sz = SZ(RG[u]);
    rep(i,sz)
    {
        v = RG[u][i];
        if(!vis[v])
            Sdfs(v);
    }
    mark[u]=color;
    vis[u]=2;
}
void BuildScc()
{
    TopSortDfs(V);
    CLR(vis);
    color=0;
    int u,v,i;
    while(!S.empty())
    {
        u = S.top();
        if(!vis[u]) Sdfs(u) , color++;
        S.pop();
    }

    //Building New Graph of Components

    rep(i,V+2)G[i].clear();
    E= SZ(Edge);
    rep(i,E)
    {
        u = Edge[i].ff;
        v = Edge[i].ss;
        if(mark[u]!=mark[v])
            G[mark[u]].pb(mark[v]);
    }
}

void go(int u , int v)
{
    G[neg(u)].pb(v);
    RG[v].pb(neg(u));
    Edge.pb(pii (neg(u),v));
    E++;
    G[neg(v)].pb(u);
    RG[u].pb(neg(v));
    Edge.pb(pii (neg(v),u));
    E++;
}
void fixuv(int &u,int &v)
{
    if(u<0) u = neg1(-u);
    if(v<0) v = neg1(-v);
    u--,v--;
}

void inputG()
{
    //Set E and V // m= no of node  // n= no of edges
    scanf("%d %d",&m,&n);
    N=m;    V=m+m;
    int i,u,v,q;
    //Clearing
    SET(mark , -1) ;
    rep(i,V+2) G[i].clear() , RG[i].clear();
    Edge.clear();
    E=0;
    rep(i,n)
    {
        scanf("%d %d %d",&q,&u,&v);
        fixuv(u,v);
		if(q==1){
			go(u,v);
		}
		else if(q==2){
			go(neg(u),neg(v));
		}
		else if(q==3){
			go(u,neg(v));
		}
    }
    return;
}
//************************************


int main(void)
{
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,k,kase=0;
    int t; SD(t);
    while(t--)
    {
        inputG();
        BuildScc();
        TopSortDfs(color); // G is changed
        vi order;
        while(!S.empty()) order.pb(S.top()) , S.pop();

        rep(i,color+1) elem[i].clear();
        bool flag = true;
        //Checking validity
        rep(i,V)
        {
            if(mark[i]==mark[neg(i)])
            {
                printf("Case %d: no\n",++kase);
                flag = false; break;
            }
            elem[mark[i]].pb(i);
        }
        if(flag){
			printf("Case %d: yes\n",++kase);
			continue;
		}
		

    }
    return 0;
}
