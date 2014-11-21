#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 100010
#define ii __int64

int sum[maxm],n,m,a[maxm];
vector<int>v[maxm]; 
int bs(int ind,int num);

int main(){
	
	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&n,&m);
		for(i=0;i<=m;i++){
			v[i].clear();
		}

		for(i=1;i<=n;i++){
			scanf("%d",&k);
			a[i]=k;
			sum[i]=sum[i-1]+k;
			sum[i]%=m;
			if(sum[i]<0) sum[i]+=m;		
			v[sum[i]].push_back(i);
		}
		
		int pivot=0;
		ii ans=0;
		for(i=1;i<=n;i++){
			ans+=bs(pivot,i);
			pivot+=a[i];
			if(pivot<0) pivot+=m;	
			pivot%=m;
		}
		printf("Case %d: %I64d\n",t++,ans);

	}

	return 0;
}

int bs(int ind,int num){

	int i,j,k,l,lo,hi,mid,tot;
	lo=0; tot=hi=v[ind].size()-1;
	if(tot<0||v[ind][tot]<num) return 0;
	tot++;
	
	while(lo<hi){

		mid=lo+hi; mid/=2;
		if(v[ind][mid]==num){
			return tot-mid;
		}
		if(v[ind][mid]<num){
			lo=mid+1;
		}
		else if(v[ind][mid]>num){
			if(hi==mid){
				if(v[ind][mid-1]>=num) return (tot-mid+1);
				return tot-mid;
			}
			hi=mid;
		}

	}
	
	return tot-hi;

}