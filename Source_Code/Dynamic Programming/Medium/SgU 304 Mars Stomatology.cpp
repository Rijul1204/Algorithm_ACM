#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define maxm 700
#define inf 1<<29

struct node{
	int num,cost;
};

vector<node>v[maxm];
int a[maxm],val[maxm],n,p,sum[maxm][maxm],dp[maxm][maxm],pre[maxm][maxm];

int mini(int a,int b){
	if(a<b) return a;
	return b;
}
bool comp(node a,node b){
	return a.cost<b.cost;
}

int main(){

	int i,j,k,l;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d %d",&n,&k,&p)==3){

		for(i=1;i<=k;i++){
			v[i].clear();
			scanf("%d",&val[i]);
		}

		int gum=k;
		node temp;

		for(i=1;i<=n;i++){
			scanf("%d %d",&a[i],&k);
			temp.num=i; temp.cost=a[i];
			v[k].push_back(temp);
		}
		memset(sum,0,sizeof(sum));

		

		for(j=0;j<=gum;j++){
			for(i=1;i<=n;i++){
				dp[j][i]=inf;
			}
			dp[j][0]=0;
			pre[j][0]=0;
		}



		for(i=1;i<=gum;i++){

			sort(v[i].begin(),v[i].end(),comp);

			sum[i][0]=val[i];
			
			for(j=0;j<v[i].size();j++){
				
				temp=v[i][j];
				sum[i][j+1]=sum[i][j]+temp.cost;				
				
				for(k=n;k>=j+1;k--){
					if(dp[i][k]>dp[i-1][k-(j+1)]+sum[i][j+1]){
						dp[i][k]=dp[i-1][k-(j+1)]+sum[i][j+1];
						pre[i][k]=j+1;
					}					
				}
			}
			for(k=0;k<=n;k++){
				if(dp[i][k]>dp[i-1][k]){
					dp[i][k]=dp[i-1][k];
					pre[i][k]=0;
				}
			}

		}

		int ans=0,mark1=0,mark2=0,space=0;

		for(i=1;i<=gum;i++){
			for(j=1;j<=n;j++){
				if(j>ans&&dp[i][j]<=p){
					ans=j;
					mark1=i; mark2=j;
				}
			}
		}
		printf("%d\n",ans);
		k=ans;
		while(k){

			l=pre[mark1][k];
			for(i=0;i<l;i++){
				if(space) printf(" ");
				space=1;
				temp=v[mark1][i];
				printf("%d",temp.num);
			}
			mark1--; k-=l;		
		}
		printf("\n");
		

	}

	return 0;
}
