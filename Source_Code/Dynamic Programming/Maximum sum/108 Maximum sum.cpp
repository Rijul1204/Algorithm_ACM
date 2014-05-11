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
#define maxim 100
//#define LLD long long int
//#define LLU long long unsigned 
#define pi acos(-1.0)
#define inf (1<<29)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define eps 1e-9
#define rep(i,init,n) for(i=init;i<n;i++)
#define area(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define sqr(x) ((x)*(x))
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define spDist(lat1,long1,lat2,long2,r) ( r * acos( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1-long2) ) )
#define STR string
#define LF double
#define IT iterator
#define VI vector<int>
#define VLLD vector<LLD>
#define VS vector<STR>
#define VLF vector<LF>
#define MII map<int,int>
#define MIB map<int,bool>
#define MSI map<STR,int>
#define MSB map<STR,bool>
#define M2dII map<int,map<int,int> >
#define QI queue<int>
#define SI stack<int>
#define PII pair< int, int >
#define PPI pair< PII, int >
#define ff first
#define ss second
#define VPII vector<PII>

#define chkB(a,k) (bool)(a[k>>5] & (1<<(k&31)))
#define setB0(a,k) (a[k>>5] &= ~(1<<(k&31)))
#define setB1(a,k) (a[k>>5] |= (1<<(k&31)))

#define SD(a) scanf("%d",&a)
#define SHD(a) scanf("%hd",&a)
#define SLLD(a) scanf("%lld",&a)
#define SLLU(a) scanf("%llu",&a)
#define SF(a) scanf("%f",&a)
#define SLF(a) scanf("%lf",&a)
#define SC(a) scanf("%c",&a)
#define SS(a) scanf("%s",a)

int diru[] = {-1,-1,-1,0,0,1,1,1};
int dirv[] = {-1,0,1,-1,1,-1,0,1};

using namespace std;

template< class T > T sq(T n) { return n*n; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }
template< class T > T power(T N,T P){  return (P==1)?  N: N*power(N,P-1); }

int sum[200][200];

int calc(int n);
void reset(int n);

int main()
{
	int n,T,t,m,i,j,k,c,b,a;
	//scanf("%d",&T);
	//for(t=1;t<=T;t++)
	while(scanf("%d",&n)==1){
        
		reset(n);

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&a);
				sum[i][j]+=sum[i-1][j]+a;
			}
		}

		printf("%d\n",calc(n));

		
	}
	return 0;
}

void reset(int n){

	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			sum[i][j]=0;
		}
	}

}

int calc(int n){

	int max,i,j,k,l,t;

	max=sum[1][1];

	for(k=1;k<=n;k++){
		for(i=0;i<=n-k;i++){
			for(t=0,j=1;j<=n;j++){
				if(t>=0) t+=sum[i+k][j]-sum[i][j];
				else t=sum[i+k][j]-sum[i][j];
				
				if(t>max) max=t;
			}
		}
	}

	return max;

}

