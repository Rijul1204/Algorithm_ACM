#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;

#define maxm 500100

bool p[maxm+100],fl[maxm],col[maxm];
int prime[maxm/4],countp,tot;
vector<int>v[maxm],in;
int r[maxm],l[maxm],a[maxm];
void take(int n);

void gen(int n){

	int i,j,k,l,sq;

	p[0]=p[1]=1;

	sq=sqrt(n);
//	v[1].push_back(2);
//	v[2].push_back(1);
	for(i=4;i<=n;i+=2){
		p[i]=1;
//		v[i/2].push_back(i);
//		v[i].push_back(i/2);
	}

	for(i=3;i<=sq;i+=2){
		if(p[i]){
			continue;
		}
		for(j=i*i;j<=n;j+=(2*i)){
//			v[j/i].push_back(j);
//			v[j].push_back(j/i);
			p[j]=1;
		}
	}
/*	for(i=3;i<=n;i+=2){
		if(!p[i]){
			v[1].push_back(i);
			v[i].push_back(1);			
		}
	}
	*/
}

int match(int n);
bool dfs(int s);

int main(){

	int i,j,k,l,test,t=1,n;

//	freopen("in.txt","r",stdin);	

	gen(maxm);
	take(maxm);
//	for(i=1;i<10;i++){
//		printf("%d ",prime[i]);
//	}
//	printf("\n\n%d\n",countp);

	scanf("%d",&test);
	

	while(test--){

		in.clear();
		memset(fl,0,sizeof(fl));
		scanf("%d",&n);
		tot=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			a[i]=k; if(k>tot) tot=k;
			fl[k]=1;
			v[k].clear();
			in.push_back(k);
		}		
		
		for(i=1;i<=n;i++){
			for(k=1;k<countp;k++){
				j=prime[k];
				if(a[i]*j>tot) break;
				if(fl[a[i]*j]){
					v[a[i]].push_back(a[i]*j);
					v[a[i]*j].push_back(a[i]);
				}
			}
		}

		int ans=match(n);
		printf("Case %d: %d\n",t++,ans);

		
	}

	return 0;
}

int match(int n){

	memset(r,-1,sizeof(r));
	memset(l,-1,sizeof(l));

	int i,j,k,done=0;

	do{

		done=1;
		memset(col,0,sizeof(col));
		for(j=0;j<in.size();j++){
			i=in[j];
			if(r[i]==-1&&dfs(i)) done=0;
		}

	}while(!done);
	
	k=0;
	for(j=0;j<in.size();j++){
		i=in[j];
		if(r[i]!=-1) k++;
	}
	k/=2;
	return n-k;

}

bool dfs(int s){

	if(col[s]) return 0;
	col[s]=1;

	int i,j,k;

	for(j=0;j<v[s].size();j++){
		k=v[s][j];
		if(!fl[k]) continue;
		if(l[k]==-1){
			l[k]=s;
			r[k]=s;
			l[s]=k;
			r[s]=k;
			col[k]=1;
			return 1;
		}
		if(dfs(l[k])){
			l[k]=s;
			r[k]=s;
			l[s]=k;
			r[s]=k;
			col[k]=1;
			return 1;
		}

	}
	
	return 0;

}

void take(int n){
	
	int i,j,k,l;
	
	prime[1]=2;
	countp=2;
	
	for(i=3;i<=n;i+=2){
		if(p[i]==0) prime[countp++]=i;
	}
	
}