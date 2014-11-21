#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct{
	int value;
	char ch;
}node;

node nodes[500];

char world[10000][10000];
int w,h;
int counte[230];

void reset();
void flood(int i,int j,char ch);
bool comp(node a,node b);

int main(){
	
	int i,j,m,test,t;

	//freopen("in.txt","r",stdin);
	
	scanf("%d",&test);
	
	for(t=1;t<=test;t++){
		scanf("%d %d",&h,&w);
		
		reset();
		
		for(i=0;i<h;i++){
			scanf("%s",world[i]);
		}
		
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(isalpha(world[i][j])){
					counte[world[i][j]]++;
					flood(i,j,world[i][j]);
				}
			}
		}
		m=0;
		
		for(i=95;i<=125;i++){
			if(counte[i]>0){
				nodes[m].value=counte[i];
				nodes[m].ch=i;
				m++;
			}
		}
		sort(nodes,nodes+m,comp);
		printf("World #%d\n",t);
		
		for(i=0;i<m;i++){
			printf("%c: %d\n",nodes[i].ch,nodes[i].value);
		}

	}

	return 0;

	
}

bool comp(node a,node b){

	if(a.value>b.value) return true;
	else return false;
}

void flood(int i,int j,char ch){

	if(world[i][j]!=ch) return;

	world[i][j]='.';

	if((i+1)<h) flood(i+1,j,ch);
	if((j+1)<w) flood(i,j+1,ch);
	if(i>0) flood(i-1,j,ch);
	if(j>0) flood(i,j-1,ch);

}


void reset(){

	int i;

	for( i=95;i<=125;i++){
		counte[i]=0;
	}

}

