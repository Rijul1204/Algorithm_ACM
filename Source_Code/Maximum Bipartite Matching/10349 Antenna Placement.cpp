#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 800
#define maxe 500000

vector<int>v[maxe];

int left[maxe],right[maxe],col[maxe];
int r,c,tot;
int mark[maxm][maxm];
char s[maxm][maxm];


int match(int n);
bool dfs(int n);

int main(){

	int i,j,k,l,test;

	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

		for(i=0;i<=450000;i++) v[i].clear();

		scanf("%d %d",&r,&c);

		for(i=0;i<r;i++){
			scanf("%s",s[i]);
		}
		
		k=1;
		
		for(i=0;i<r;i++){ 
			for(j=0;j<c;j++){
				if(s[i][j]=='*') mark[i][j]=k++;
				else mark[i][j]=0;				
			}
		}

		tot=k-1;

		
		for(i=0;i<r;i++){ 
			for(j=0;j<c;j++){
				if(s[i][j]=='*'){
					k=mark[i][j];
					if(j+1<c){
						if(s[i][j+1]=='*'){
							l=mark[i][j+1];
							v[k].push_back(l); v[l].push_back(k);							
						}
					}
					if(i+1<r){
						if(s[i+1][j]=='*'){
							l=mark[i+1][j];
							v[k].push_back(l); v[l].push_back(k);
						}
					}
				}
			}
		}

		printf("%d\n",match(tot));


	}

	return 0;
}

int match(int n){

	memset(left,-1,sizeof(left));
	memset(right,-1,sizeof(right));

	int i,j,k,l;
	int done;

	do{
		done=1;
		memset(col,0,sizeof(col));
		for(i=1;i<=n;i++){
			if(left[i]==-1&&dfs(i)) done=0;
		}


	}while(!done);

	k=0;

	for(i=1;i<=n;i++){
		if(left[i]==-1) k++;
	}

	l=n-k; l/=2;

	return k+l;

}

bool dfs(int s){

	if(col[s]) return 0;
	col[s]=1;

	int i,j,k,l;

	for(j=0;j<v[s].size();j++){
		i=v[s][j];
		if(right[i]==-1){
			right[i]=s;
			left[s]=i;
			right[s]=i;
			left[i]=s;
			return true;
		}
		if(dfs(left[i])){
			right[i]=s;
			left[s]=i;
			right[s]=i;
			left[i]=s;
			return true;			
		}
	}

	return false;

}