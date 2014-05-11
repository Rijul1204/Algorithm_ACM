#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

#define inf 1<<22

map<int,int>node;
vector<int>v[10000];
int in[11000],color[11000],flag;

void dfs(int s);

int main(){

	int i,j,k,l,a,b,t=1;
	int count1;

	//freopen("in.txt","r",stdin);

	while(1){
		
		scanf("%d %d",&a,&b);
		if(a<0&&b<0) break;
		if(!a&&!b){
			printf("Case %d is a tree.\n",t++);
			continue;
		}
		
		flag=1;count1=1;
		memset(in,0,sizeof(in)); node.clear(); memset(color,0,sizeof(color));
		for(i=0;i<=9998;i++) v[i].clear(); 
		
		if(a==b) flag=0;
		if(!node[a]) node[a]=count1++;
		if(!node[b]) node[b]=count1++;
		v[node[a]].push_back(node[b]);
		in[node[b]]++;
		while(1){
			scanf("%d %d",&a,&b);
			if(!a&&!b) break;
			if(a==b) flag=0;
		    if(!node[a]) node[a]=count1++;
	     	if(!node[b]) node[b]=count1++;
		    v[node[a]].push_back(node[b]);
     		in[node[b]]++;
		}
		int  sum=0;
		int root;
		for(i=1;i<count1;i++){
			//printf("%d ->%d \n",i,node[i]);
			if(in[i]==0){
				root=i;
				sum++;
			}		
		}
		if(sum>1) flag=0;

		if(flag==1) dfs(root);

		for(i=1;i<count1;i++){
			if(!color[i]){
				//printf("%d %d\n",root,i);
				flag=0;
			}
		
		}

		if(flag==0) printf("Case %d is not a tree.\n",t++);
		else printf("Case %d is a tree.\n",t++);

		


	}


	return 0;
}

void dfs(int s){

	color[s]=1;

	for(int i=0;i<v[s].size();i++){
		if(color[v[s][i]]==0){
			dfs(v[s][i]);
		}
		else flag=0;
	}

	color[s]=2;


}