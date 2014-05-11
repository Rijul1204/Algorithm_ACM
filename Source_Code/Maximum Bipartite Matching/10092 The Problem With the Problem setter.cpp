#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 1700

vector<int>v[maxm];
int col[maxm],left[maxm],right[maxm],nk,np,c[maxm],st[maxm],tot;

void match(int n);
bool dfs(int s);

int main(){

	int i,j,k,l,ii;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&nk,&np)==2){

		if(!nk&&!np) break;

		tot=1;
		for(i=1;i<=nk;i++){
			st[i]=tot;
			scanf("%d",&c[i]);
			tot+=c[i];
		}
		st[nk+1]=tot;

		for(i=0;i<=tot;i++){
			v[i].clear();

		}

		for(i=1;i<=np;i++){
			scanf("%d",&j);
			for(k=1;k<=j;k++){
				scanf("%d",&l);
				for(ii=st[l];ii<st[l+1];ii++){
					v[ii].push_back(i);
				}
			}		
		}

		match(tot-1);

	}

	return 0;
}

void match(int n){

	memset(left,-1,sizeof(left));
	memset(right,-1,sizeof(right));

	int i,j,k,l,done=0;

	do{

		memset(col,0,sizeof(col));
		done=1;

		for(i=1;i<=n;i++){
			if(right[i]==-1 &&dfs(i)) done=0;
		}

	}while(!done);

	k=0;
	for(i=1;i<=n;i++){
		if(right[i]==-1) k++;
	}

	if(k) printf("0\n");
	else{
		printf("1\n");
		for(i=1;i<=nk;i++){
			for(j=st[i],l=0;j<st[i+1];j++,l++){
				if(l) printf(" ");
				printf("%d",right[j]);
			}
			printf("\n");
		}

	}


}

bool dfs(int s){

	if(col[s]) return 0;
	col[s]=1;

	int i,j,k,l;

	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		if(left[k]==-1){
			right[s]=k;
			left[k]=s;
			return 1;
		}
		else if(dfs(left[k])){
			right[s]=k;
			left[k]=s;
			return 1;
		}

	}
	
	return 0;
}