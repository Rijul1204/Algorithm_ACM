#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;

vector<int>v[10000];
queue<int>qu;
int pre[10000],col[10000];

void bfs(int s);
void set(int n);
void print(int s);

int main(){

	int i,j,k,l,n,num,q,so,e;
	char s[50000],temp[1000];
	
//	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1){

		for(i=1;i<=n;i++){
			v[i].clear();
		}
		for(i=1;i<=n;i++){
			scanf("%d%s",&e,s);
			for(j=1;s[j];j++){
				l=0;
				while(s[j]!=','){
					if(!s[j]) break;
					temp[l++]=s[j++];
				}
				temp[l]='\0';
				num=atoi(temp);
				v[e].push_back(num);
				if(!s[j]) break;
			}
		}
		/*

		for(i=1;i<=n;i++){
			printf("\n%d->",i);
			for(j=0;j<v[i].size();j++){
				printf(" %d",v[i][j]);
			}
		}
		*/

		scanf("%d",&q);

		printf("-----\n");

		for(i=1;i<=q;i++){
			set(n);
			scanf("%d %d",&so,&e);
			bfs(so);
			if(so==e){
				printf("%d\n",so);
				continue;
			}
			if(pre[e]==e) printf("connection impossible");
			else print(e);
			printf("\n");
		}

	
	}		

	return 0;

}

void print(int s){
	if(pre[s]==s){
		printf("%d",s);
		return ;
	}
	print(pre[s]);
	printf(" %d",s);
}

void bfs(int s){

	int i,j,temp;

	qu.push(s);
	col[s]=1;

	while(!qu.empty()){
		temp=qu.front();
		qu.pop();
		col[temp]=2;
		for(i=0;i<v[temp].size();i++){
			if(col[v[temp][i]]==0){
				col[v[temp][i]]=1;
				pre[v[temp][i]]=temp;
				qu.push(v[temp][i]);
			}
		}
	}

}

void set(int n){
	
	for(int i=0;i<=n;i++){
		col[i]=0;
		pre[i]=i;
	}
}
			
			

					



