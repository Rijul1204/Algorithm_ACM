#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<string.h>
using namespace std;

#define maxm 50

int s,d,tot;
vector<int>v[maxm];
int mat[maxm][maxm];
int col[maxm],out[maxm],c;
map<int,int>num;
void traverse(int s);
void dfs(int s,int count1);

int main(){

	int i,j,k,l,t=1;

	freopen("in.txt","r",stdin);

	while(scanf("%d",&d)==1){

		for(i=0;i<=25;i++) v[i].clear();
		memset(col,0,sizeof(col));
		memset(mat,0,sizeof(mat));
        num.clear();
		
		tot=0;
		c=2;
		num[1]=1;

		while(scanf("%d %d",&k,&l)==2){
			if(!k&&!l) break;
			
			if(!num[k]) num[k]=c++;
			if(!num[l]) num[l]=c++;

			i=num[k]; j=num[l];
			
			mat[k][l]=mat[l][k]=1;
			
			v[k].push_back(l);
			v[l].push_back(k);
			//v[num[k]].push_back(num[l]);
			//v[num[l]].push_back(num[k]);
		}

		
		
		traverse(d);

		for(i=1;i<c;i++){
			sort(v[i].begin(),v[i].end());		
		}
		
		
		col[1]=0;
		out[0]=1;
		
		printf("CASE %d:\n",t++);
		
		dfs(1,1);
		
		printf("There are %d routes from the firestation to streetcorner %d.\n",tot,d);


	}


	return 0;
}

void traverse(int s){

	int i,j,k;
	col[s]=1;

	for(j=0;j<v[s].size();j++){
		
		i=v[s][j];
		if(!col[i]){
			traverse(i);
		}
	}


}


void dfs(int s,int count1){

	int i,j,k;

	if(s==d){
		tot++;
		for(i=0;i<count1;i++){
			if(i) printf(" ");
			printf("%d",out[i]);
		}
		printf("\n");
		return ;
	}

	for(i=1;i<=25;i++){
		if(mat[s][i]==1){
			if(col[i]){
	     		col[i]=0;
		    	out[count1]=i;
    			dfs(i,count1+1);
	    		col[i]=1;
			}

		}

	}

	/*for(j=0;j<v[s].size();j++){
		
		i=v[s][j];

		if(col[i]){
			col[i]=0;
			out[count1]=i;
			dfs(i,count1+1);
			col[i]=1;
		}

	}

  */


}