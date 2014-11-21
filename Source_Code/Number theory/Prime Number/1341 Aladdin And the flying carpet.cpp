#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;

#define maxm 1000100
#define ii __int64
//#define ii long long int

struct node{
	ii num;
	int count;
};


bool p[maxm];
int prime[maxm/3],c,tot,totn;
vector<node>v;
ii area,lim,arean,lims,ans;

void back(int count,ii res);
void fact(ii n);
void take(int n);
void gen(int n);

int main(){

	int i,j,k,l,test,t=1;

	gen(maxm-90);
	take(maxm-90);

	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%I64d %I64d",&area,&lim);
		lims=sqrt(area);
		fact(area);
		totn=v.size();
		ans=0;

		back(0,1);
		printf("Case %d: %I64d\n",t++,ans);

	}

	return 0;
}

void back(int count,ii res){
	
	if(res>lims) return;
	if(count==totn){
	//	printf("%I64d ",res);
		ii resi=area/res;
		if(res>=lim&&resi>=lim&&res!=resi){
			ans++;
		}
		return ;
	}

	int i,j,k;
	ii l;
	node temp;	
	temp=v[count];
	k=temp.count;	
	for(i=0;i<=k;i++){
		l=pow(temp.num,i);
		back(count+1,res*l);
	}
}

void fact(ii n){

	int i,j,k,l;
	node temp;
	ii sq;
	double nd=n;

	sq=sqrt(nd);
	v.clear();

	for(i=0;prime[i]<=sq;i++){
		if(n%prime[i]) continue;
		k=0;
		while(n%prime[i]==0){
			n/=prime[i];
			k++;
		}
		sq=sqrt(n);
		temp.count=k; temp.num=prime[i];
		v.push_back(temp);
		if(n==1) break;		
	}

	if(n>1){
		temp.count=1; temp.num=n;
		v.push_back(temp);
	}


}

void take(int n){

	prime[c++]=2;

	for(int i=3;i<=n;i++){
		if(!p[i]) prime[c++]=i;
	}
	tot=c;
}

void gen(int n){

	int i,j,k,l,sq;

	p[0]=p[1]=1;

	sq=sqrt(n);

	for(i=4;i<=n;i+=2) p[i]=1;

	for(i=3;i<=sq;i+=2){
		if(p[i]) continue;
		for(j=i*i;j<=n;j+=(2*i)){
			p[j]=1;
		}
	}
}