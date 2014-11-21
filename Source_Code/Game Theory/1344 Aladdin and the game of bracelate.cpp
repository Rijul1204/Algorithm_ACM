#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

#define maxm 60

struct node{
	int no,pos;
};

node nodes[maxm*maxm];
int a[maxm][maxm],tot[maxm],p[maxm][maxm],g1[maxm][maxm];
int dp[maxm][maxm][maxm],n,fl,g[maxm];
int v[maxm][maxm];
int cal(int ind,int beg,int end,int turn);
bool comp(node a,node b){
	if(a.no==b.no) return a.pos<b.pos;
	return a.no<b.no;
}

int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d",&n);

		for(i=1;i<=n;i++){
			scanf("%d",&k);
			tot[i]=k;
			for(j=1;j<=k;j++){
				scanf("%d",&l);
				a[i][j]=l;
			}
		}
		k=0;
		memset(dp,-1,sizeof(dp));
		for(i=1;i<=n;i++){
			fl=0;
			k^=cal(i,1,tot[i],1);
		}
		if(k){
			printf("Case %d: Aladdin\n",t++);
		}
		else{
			printf("Case %d: Genie\n",t++);
			continue;
		}
		
		int ans;
		for(i=1;i<=n;i++){
			ans=0;
			for(j=1;j<=n;j++){
				if(i==j) continue;
				ans^=cal(j,1,tot[j],3);
			}
			g[i]=ans;
		}
		int c=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=tot[i];j++){
				if((p[i][j]^g[i])==0){
					//printf("%d %d\n",i,a[i][j]);
					nodes[c].no=i;
					nodes[c++].pos=a[i][j];
				}
			}
		}
		sort(nodes,nodes+c,comp);
		printf("(%d %d)",nodes[0].no,nodes[0].pos);
		for(i=1;i<c;i++){
			if(nodes[i].no==nodes[i-1].no&&nodes[i].pos==nodes[i-1].pos) continue;
			printf(" (%d %d)",nodes[i].no,nodes[i].pos);		
		}
		printf("\n");
		
		

	}

	return 0;
}

int cal(int ind,int beg,int end,int turn){

	if(ind<0||beg>end) return 0;
	if(beg==end) return 1;

	if(dp[ind][beg][end]!=-1) return dp[ind][beg][end];

	set<int>s;
	int i,j,k,l,ans;

	for(i=beg;i<=end;i++){
		ans=0;
		k=beg;
		for(j=beg;j<=end;j++){
			if(a[ind][j]>=a[ind][i]){
				ans^=cal(ind,k,j-1,turn+1);
				k=j+1;
			}			
		}
		ans^=cal(ind,k,end,turn+1);
		if(turn==1){
			p[ind][i]=ans;
		}
		s.insert(ans);
	}
	if(turn==1){
		
		for(i=beg;i<=end;i++){
			k=0;
			for(j=beg;j<=end;j++){
				if(a[ind][i]==a[ind][j]) continue;
				k^=p[ind][i];
			}
			g1[ind][i]=k;
		}
	}

	int ret=0;

	while(s.find(ret)!=s.end()){
		ret++;
	}

	return dp[ind][beg][end]=ret;

}