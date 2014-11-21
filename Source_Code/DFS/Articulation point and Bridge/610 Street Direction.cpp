#include<stdio.h>
#include<vector>
using namespace std;

vector<int>v[1100];
int bridge[1100][1100],col[11000],d[11000],low[1100],time,flag[1100][1100];
void dfs(int s,int pre);
int min(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	
	int i,j,k,l,n,e,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&e)==2){
	
		if(!n&&!e) break;
		for(i=0;i<=n;i++){
			v[i].clear();
			col[i]=0;
			d[i]=0;
			low[i]=0;
			for(j=0;j<=n;j++){
				bridge[i][j]=0;
				flag[i][j]=0;
			}
		}
		time=1;

		for(i=1;i<=e;i++){
			scanf("%d %d",&k,&l);
			v[k].push_back(l);
			v[l].push_back(k);
		}

		for(i=1;i<=n;i++){
			if(!col[i]) dfs(i,0);
		}
		printf("%d\n\n",t++);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
    			if(flag[i][j]==0) continue;
				printf("%d %d\n",i,j);
				if(bridge[i][j]) printf("%d %d\n",j,i);
				
			}
		}
		printf("#\n");
				

					
	
	}
	

	return 0;
}

void dfs(int s,int pre){

	col[s]=1;
	d[s]=time++;
	low[s]=d[s];

	for(int i=0;i<v[s].size();i++){
		int j=v[s][i];
		if(col[j]==1&&j!=pre){
			low[s]=min(low[s],d[j]);
			flag[j][s]=1;
			flag[s][j]=0;
		}
		else if(col[j]==0){
			flag[s][j]=1;
			dfs(j,s);
			low[s]=min(low[s],low[j]);
			if(low[j]>d[s]){
				bridge[s][j]=bridge[j][s]=1;
			}

		}


	}

}

