#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include <iomanip>
using namespace std;

#define eps  1e-11
#define maxm 110
#define maxn (1<<11)
#define ii double
#define inf (1<<28)

ii maxi(ii a,ii b){
	if(a>b) return a;
	return b;
}
int on(int n,int k){
	return (n|(1<<k));
}
int off(int n,int k){
	return (n-(n&(1<<k)));
}
bool chck(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}

int n,n1,n2,n3;
int dp[maxn][15][15][15];
bool v[maxn][15][15][15];
int bt[maxm],bl[maxm],fl[maxm];
int pre[maxn][15][15][15];
vector<int>v1,v2,v3;
int cal(int ind,int n1,int n2,int n3);
void print(int ind,int n1,int n2,int n3);

int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	int blank=0;
	
	while(1){

		scanf("%d",&n); if(!n) break; v1.clear();v2.clear();v3.clear();

		if(blank) printf("\n");
		blank=1;

		for(i=0;i<n;i++){
			scanf("%d %d %d",&bt[i],&bl[i],&fl[i]);
		}
		scanf("%d %d %d",&n1,&n2,&n3);
		memset(v,0,sizeof(v));
		printf("Team #%d\nMaximum Effective Score = %d\n",t++,cal(0,n1,n2,n3));
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		sort(v3.begin(),v3.end());
		print(0,n1,n2,n3);
		printf("Batsmen :"); for(i=0;i<v1.size();i++) printf(" %d",v1[i]+1);
		printf("\n");
		printf("Bowlers :"); for(i=0;i<v2.size();i++) printf(" %d",v2[i]+1);
		printf("\n");
		printf("All-rounders :"); for(i=0;i<v3.size();i++) printf(" %d",v3[i]+1);
		printf("\n");

	}


	return 0;
}

void print(int ind,int n1,int n2,int n3){

	if(!n1&&!n2&&!n3) return ;
	if(ind>=n) return ;

	if(pre[ind][n1][n2][n3]==0) print(ind+1,n1,n2,n3);
	if(pre[ind][n1][n2][n3]==1){
		v1.push_back(ind);
		print(ind+1,n1-1,n2,n3);
	}
	if(pre[ind][n1][n2][n3]==2){
		v2.push_back(ind);
		print(ind+1,n1,n2-1,n3);
	}
	if(pre[ind][n1][n2][n3]==3){
		v3.push_back(ind);
		print(ind+1,n1,n2,n3-1);
	}

}

int cal(int ind,int n11,int n22,int n33){

	if(!n11&&!n22&&!n33) return 0;
	if(ind>=n) return -inf;

	if(v[ind][n11][n22][n33]) return dp[ind][n11][n22][n33];
	v[ind][n11][n22][n33]=1;

	int i,j,k,l,vv,vv1,v1,v2,v3;
	int ret=0,ret1;

	i=bt[ind]; j=bl[ind]; k=fl[ind];
	
	/*
	v1=  8* bt[ind] + 2 * fl[ind];
	if  (v1%10 >= 5) v1=v1/10+1;
    else v1=v1/10; */
	
	v1=  8* bt[ind] + 2 * fl[ind] + 5;
	v1/=10;

	v2=1*i+ 7*j + 2*k +5 ; v2/=10;
	/*
	if(v2%10 >=5) v2=v2/10+1;
	else v2=v2/10; */


	v3=4*i+ 4*j + 2*k + 5 ; v3/=10;
	/*
	if(v3%10 >=5) v3=v3/10+1;
	else v3=v3/10; */

	
	ret=cal(ind+1,n11,n22,n33);
	pre[ind][n11][n22][n33]=0;

	if(n11){
		ret1=cal(ind+1,n11-1,n22,n33)+v1;
		if(ret1>ret){
			ret=ret1;
			pre[ind][n11][n22][n33]=1;
		}
	}
	if(n22){
		ret1=cal(ind+1,n11,n22-1,n33)+v2;
		if(ret1>ret){
			ret=ret1;
			pre[ind][n11][n22][n33]=2;
		}
	}
	if(n33){
		ret1=cal(ind+1,n11,n22,n33-1)+v3;
		if(ret1>ret){
			ret=ret1;
			pre[ind][n11][n22][n33]=3;
		}
	}

	return dp[ind][n11][n22][n33]=ret;


}
