#include<stdio.h>
#include<ctype.h>
#include<algorithm>
using namespace std;

struct node{
	char ch;
	int num;
};
node nodes[90000];

int r,c,sum;
char grid[1000][1000];

void flood(int i,int j,char ch);

bool comp(node a,node b){
	if(a.num==b.num) return a.ch<b.ch;
	return a.num>b.num;
}

int main(){

	int i,j,k,l,t=1;

//	freopen("in.txt","r",stdin);

	while(scanf("%d %d",&r,&c)==2){
		if(!r&&!c) break;
		for(i=0;i<r;i++){
			scanf("%s",grid[i]);
		}
		l=0;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(isalpha(grid[i][j])){
					nodes[l].ch=grid[i][j];
					sum=0;
					flood(i,j,grid[i][j]);
					nodes[l].num=sum;
					l++;

				}
			}
		}
		sort(nodes,nodes+l,comp);

		printf("Problem %d:\n",t++);
		for(i=0;i<l;i++){
			printf("%c %d\n",nodes[i].ch,nodes[i].num);
		}


	}

	



	return 0;
}

void flood(int i,int j,char ch){

	if(i<0||j<0||i>=r||j>=c) return;
	if(grid[i][j]!=ch) return;
	sum++;
    grid[i][j]='.';

	flood(i+1,j,ch);
	flood(i,j+1,ch);
	flood(i-1,j,ch);
	flood(i,j-1,ch);
	//flood(i-1,j-1,ch);
	//flood(i+1,j-1,ch);
//	flood(i-1,j+1,ch);
//	flood(i+1,j+1,ch);

}
