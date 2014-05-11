#include<stdio.h>
#include<map>
#include<queue>
using namespace std;

#define inf 9999999

int matrix[100][100],coun,dis[100],color[100];



void bfs(int n);
void set();
void setm();

int main(){
	
	int i,j,edge,temp1,temp2,len,num,t=1;

//	freopen("in.txt","r",stdin);
	
	
	
	while(scanf("%d",&edge)&&edge){

		map<int,int>first,second;
		
		coun=1;
		setm();

		
		for(i=1;i<=edge;i++){			
			scanf("%d %d",&temp1,&temp2);
			if(first[temp1]==0){
				first[temp1]=coun++;
				second[coun-1]=temp1;
			}
			if(first[temp2]==0){
				first[temp2]=coun++;
				second[coun-1]=temp2;
			}
			matrix[first[temp1]][first[temp2]]=matrix[first[temp2]][first[temp1]]=1;			
		}

		while(1){
			set();
			
			scanf("%d %d",&temp1,&len);
			if(temp1==0&&len==0) break;
			if(first[temp1]==0){
				num=coun-1;
			}
			else{
			num=0;
			bfs(first[temp1]);
			for(i=1;i<coun;i++){
				if(dis[i]>len) num++;
			}
			}
			
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",t++,num,temp1,len);
		}
			
				
	}
	
	return 0;
	
}

void set(){

	for(int i=0;i<=coun;i++){
		color[i]=0;
		dis[i]=inf;
	}
}

void setm(){

	for(int i=0;i<90;i++){
		for(int j=0;j<90;j++){
			matrix[i][j]=0;
		}
	}
}

void bfs(int n){

	int temp1;
    
	queue<int>first;

	first.push(n);
	dis[n]=0;

	while(!first.empty()){

		temp1=first.front();
		first.pop();
		color[temp1]=2;

		for(int i=1;i<coun;i++){
			if(matrix[temp1][i]||matrix[i][temp1]){
				if(color[i]==0){
					color[i]=1;
					dis[i]=dis[temp1]+1;
					first.push(i);
				}
			}
		}


	}

}
					









