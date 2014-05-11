#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctype.h>
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
#define LLD long long int
#define LLU long long unsigned 
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

map<char,int>ma;
char in[1000],input[10000],out[10000];
int mat[1000][1000],flag[1000];

void reset(int n);
void back(int num,int counter);

int main(){

	int i,j,k,l,n,p,sum,para,test,counter,c;
	bool blank=false;
	char s[1000],ch;
	//freopen("in.txt","r",stdin);

	while(gets(s)){

		counter=0;
		for(i=0;s[i];i++){
			if(isalpha(s[i])){
			      in[counter++]=s[i];
			}
		}
		gets(s);
		reset(counter);
		n=counter;
		sort(in,in+counter);
		c=0;
		for(i=0;i<counter;i++){
		//	printf("%c ",in[i]);
			ma[in[i]]=c++;
		}

		counter=0;
		for(i=0;s[i];i++){
			if(isalpha(s[i])){
				input[counter++]=s[i];
			}
		}
		for(i=0;i<counter;i+=2){
			mat[ma[input[i]]][ma[input[i+1]]]=1;
		}
		
	//	for(i=0;i<n;i++){
	//		for(j=0;j<n;j++){
	//			printf("%d ",mat[i][j]);
	//		}
	//		printf("\n");
	//	}

		if(blank) printf("\n");
		blank=true;

		back(0,n);





	}



	return 0;

}

void reset(int n){
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			mat[i][j]=0;
		}
	}
}

void back(int num,int counter){
	if(num==counter){
		for(int i=0;i<num;i++){
			printf("%c",out[i]);
		}
		printf("\n");
	}

	for(int i=0;i<counter;i++){
		if(flag[i]==0){
			if(num==0){
				out[num]=in[i];
				flag[i]=1;
				back(num+1,counter);
				flag[i]=0;
			}
			else{
				bool take=true;
				for(int j=num-1;j>=0;j--){
					if(mat[ma[in[i]]][ma[out[j]]]==1){
						take=false;
					}
				}
				if(!take) continue;
				out[num]=in[i];
				flag[i]=1;
				back(num+1,counter);
				flag[i]=0;
			}
		}
	}
			

}