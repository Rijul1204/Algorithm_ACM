#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;


#define ii  long long int
#define inf 1<<28

int on(int n,int k){
	return (n|(1<<k));
}

int  off(int n,int k){
	return n - (1<<k);
}

bool check(int n,int k){
	return ((1<<k)==(n&(1<<k)));
}

ii mini(ii a,ii b){
	if(a<b) return a;
	return b;
}

int mat[20][20],deg[20];
int n,m,st;
ii dp1[75536];
int flag[75536];

ii call(int mask);


int main(){

	int i,j,k,l,test,t=1;

//	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		scanf("%d",&n);
		
		scanf("%d",&m);

		for(i=1;i<=n;i++){
			deg[i]=0;
			for(j=1;j<=n;j++){
				mat[i][j]=inf;
			}
			mat[i][i]=0;
		}
	 ii	sum=0;

		for(i=1;i<=m;i++){
			scanf("%d %d %d",&k,&l,&j);
			sum+=j;
			mat[k][l]=mini(mat[k][l],j);
			mat[l][k]=mat[k][l];
			deg[k]++; deg[l]++;
		}

		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					mat[i][j]=mini(mat[i][j],mat[i][k]+mat[k][j]);
				}
			}
		}
		k=0;

		for(i=1;i<=n;i++){
			if(deg[i]%2==0) {
				k=on(k,i);
			}
		}


		ii j1=inf;
		//memset(vis,0,sizeof(vis));
		memset(flag,0,sizeof(flag));
		
		if(k==((1<<(n+1))-2)) j1=0;

	/*	for(i=1;i<=n;i++){
			st=i;
			if(deg[i]%2==1){
				j1=mini(j1,run(i,k));
			}
		}
		
	*/
		
		else j1=call(k);
		printf("Case %d: %lld\n",t++,sum+j1);


	}

	return 0;
}

ii call(int mask){

	if(mask==((1<<(n+1))-2)){
		return 0;
	}

	if(flag[mask]) return dp1[mask];

	flag[mask]=1;

	int i,j,k,l,mask2;
	ii ret=inf;
	int one;
	one=0; 
	for(i=1;i<=n;i++){
		if(check(mask,i)) continue;
		if(!one){
			mask2=on(mask,i);
			k=i;
			one=1;
		}
		else{
			mask2=on(mask2,i);
			l=i;
			ret=mini(ret,call(mask2)+mat[k][l]);
			mask2=off(mask2,i);
		}		
	}

	return dp1[mask]=ret;

}

