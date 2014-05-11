#include<stdio.h>
#include<vector>
#include<map>
#include<ctype.h>
using namespace std;

vector<int>v[1000];
map<char,int>let;
char s[1000];
int ac,col[1000];

void dfs(int s);

int main(){

	int i,j,k,l,test,count1,accorn,tree;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){
		
		for(i=0;i<=50;i++) v[i].clear();

		let.clear();
		count1=1;

		while(1){
			scanf("%s",s);
			if(s[0]=='*') break;
			if(!let[s[1]]) let[s[1]]=count1++;
			if(!let[s[3]]) let[s[3]]=count1++;
			
			v[let[s[1]]].push_back(let[s[3]]);
			v[let[s[3]]].push_back(let[s[1]]);

		}

		scanf("%s",s);

		for(i=0;s[i];i++){
			if(isalpha(s[i])){
				if(!let[s[i]]){
				//	printf("  %d\n",v[count1].size());  
					let[s[i]]=count1++;
				}				
			}		
		}
		
		for(i=0;i<=count1;i++) col[i]=0;

		tree=0; accorn=0;

		for(i=1;i<count1;i++){
			if(!col[i]){
				//ac=1;
				dfs(i);
				//if(ac) accorn++;
				//else tree++;
				if(v[i].size()==0) accorn++;
				else tree++;

			}
		}

		printf("There are %d tree(s) and %d acorn(s).\n",tree,accorn);


	}


	return 0;
}


void dfs(int s){

	col[s]=1;

	for(int i=0;i<v[s].size();i++){
		if(!col[v[s][i]]) dfs(v[s][i]);

	}

}