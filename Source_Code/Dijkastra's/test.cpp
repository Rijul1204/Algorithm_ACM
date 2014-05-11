/*
 *  Shafaetsplanet.com
 */ 
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)

#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define SDi(x) scanf("%d",&x)
#define SDii(x,y) scanf("%d%d",&x,&y)

#define SDl(x) scanf("%lld",&x)
#define SDs(x) scanf("%s",x)

using namespace std;

template<class T> inline T gcd(T a,T b) {if(a<0)return 
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return 
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }

//typedef long long i64;
//typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
//const i64 INF64 = (i64)1E16;

double _dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
int distsq(int x1,int y1,int x2,int y2){return sqr(x1-x2)+sqr(y1-y2);}

//i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return r;}
double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}
string itoa(i64 a){if(a==0) return "0";string ret;for(i64 i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(all(ret));return ret;}

vector< string > token( string a, string b ) {
	const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string > 
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), 
	*e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(), 
	b.end(), *q ) ) q++;}return oot;
}
int isvowel(char s){s=tolower(s); if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')return 1; return 0;}


//bool operator < ( const node& p ) const {      return dist > p.dist;   }

int fx[]={0,0,-1,+1,-1,-1,+1,+1};
int fy[]={-1,+1,0,0,-1,+1,-1,+1};

int SET(int N,int pos){return N=N | (1<<pos);}
int RESET(int N,int pos){return N= N & ~(1<<pos);}
int check(int N,int pos){return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=RESET(N,pos);return N=SET(N,pos);}
void PBIT(int N){	printf("("); for(int i=10;i>=0;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}





vector<int>G[1002];
int C[1002][1002];
int p[1002];

int pr[1002];
int find(int n)
{
	if(pr[n]==n) return n;
	else{
		pr[n]=find(pr[n]);
		return pr[n];
	}
}

struct node
{
	int first,second;
	int w;
	bool operator < ( const node& p ) const {      return w > p.w;   }

};
int inff=1<<30;
int f(int cap,int src,int des)
{
	
	int d[1001][101];
	bool vis[1001][101];
	mem(vis,0);
	mem(d,0);
	priority_queue< node >q;
	d[src][0]=0;
	node temp;
	temp.first=src; temp.second=0; temp.w=0;
	q.push(temp);
	int mn=inff;
	while(!q.empty())
	{
		node top=q.top(); q.pop();
		int u=top.first;
		if(top.first==des)
		{
			return d[top.first][top.second];
			
		}
		rep(i,G[u].size())
		{
			int v=G[u][i];
			int dv=C[u][v];
			
			if(dv<=top.second)
			{
				if(!vis[v][top.second-dv]){vis[v][top.second-dv]=1; d[v][top.second-dv]=inff;}
				int ls=d[top.first][top.second];
				if(ls<d[v][top.second-dv] and ls<mn)
				{
					d[v][top.second-dv]=d[top.first][top.second];
					if(v==des) {mn=min(mn,d[v][top.second-dv]);}
					temp.first=v; temp.second=top.second-dv; temp.w=d[v][top.second-dv];
					q.push(temp);
				}
			}
			
			
			
		}
		
		int add=1;
			if(top.second+add<=cap)
			{
				if(!vis[top.first][top.second+add]){vis[top.first][top.second+add]=add; d[top.first][top.second+add]=inff;}
				
				int ls=d[top.first][top.second]+p[top.first]*add;
				if(ls<d[top.first][top.second+add] and ls<mn)
				{
						
					d[top.first][top.second+add]=d[top.first][top.second]+p[top.first]*add;
					temp.first=top.first; temp.second=top.second+add; temp.w=d[top.first][top.second+add];				
			
					q.push(temp);
					
				}
				
			}
		
		
	}
	return mn;
}
int main()
{
	
	//READ("in");
	//WRITE("out");
	int n,e;
	while(SDii(n,e)==2)
	{
		rep(i,n)
		{
			SDi(p[i]);
			pr[i]=i;
			G[i].clear();
			
		}
	
		rep(i,e)
		{
			int u,v,c;
			SDii(u,v); SDi(c);
			int du=find(u);
			int dv=find(v);
			if(du!=dv)		pr[du]=dv;
			G[u].pb(v);
			G[v].pb(u);
			C[u][v]=c;
			C[v][u]=c;
			
			
		}
		//rep(i,n)		cout<<i<<" -> "<<minp[i]<<endl;
		
		int q;
		SDi(q);
		while(q--)
		{
			
			int cap,b,e;
			SDii(cap,b);
			SDi(e);
			if(find(b)!=find(e))
			puts("impossible");
			else
			{
				int mn=f(cap,b,e);
				if(mn==1<<28) puts("impossible");
				else
				printf("%d\n",mn);
			}
		}
		
	}
	
	
	
}

