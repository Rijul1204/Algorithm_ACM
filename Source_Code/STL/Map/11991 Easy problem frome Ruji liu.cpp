#include<stdio.h>
#include<map>
#include<vector>
using namespace std;

map<int,int>my;
vector<int>v[100100];

int main(){

	int i,j,k,l,n,m;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2){
		my.clear();
		k=1;
		for(i=1;i<=n;i++){
			scanf("%d",&j);
			if(!my[j]){
				my[j]=k;
				v[k].clear();
				v[k].push_back(i);
				k++;
			}
			else v[my[j]].push_back(i);
		}		
		for(i=1;i<=m;i++){
			scanf("%d %d",&k,&l);
			//k--;			
			if(!my[l]){
				printf("0\n");
				continue;
			}
			else if(v[my[l]].size()<k){
				printf("0\n");
				continue;
			}
			printf("%d\n",v[my[l]][k-1]);


		}


	}


	return 0;
}
