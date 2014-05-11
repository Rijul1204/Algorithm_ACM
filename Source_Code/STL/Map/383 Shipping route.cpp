#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<queue>
using namespace std;

string str[40],temp1,temp2;
map<string,int>mymap;
int matrix[40][40];

void reset(int n);
void floyd(int n);
void bfs(int n);

int main(){
	
	int i,j,node,edge,req,num,data,test;

	freopen("in.txt","r",stdin);

	printf("SHIPPING ROUTES OUTPUT\n");

	scanf("%d",&data);
	
	for(test=0;test<data;test++){
		
		printf("\nDATA SET  %d\n\n",test+1);

		scanf("%d %d %d",&node,&edge,&req);
		
		reset(node);
		
		for(i=0;i<node;i++){
			cin>> str[i] ;
			mymap[str[i]]=i;
		}
		
		for(i=0;i<edge;i++){
			cin>>temp1;
			cin>>temp2;
			matrix[mymap[temp1]][mymap[temp2]]=1;
			matrix[mymap[temp2]][mymap[temp1]]=1;
		}
		
		floyd(node);

		for(i=0;i<req;i++){
			scanf("%d",&num);
			cin>>temp1;
			cin>>temp2;
			if(matrix[mymap[temp1]][mymap[temp2]]==10000){
				printf("NO SHIPMENT POSSIBLE\n");
				continue;
			}
			num*=matrix[mymap[temp1]][mymap[temp2]]*100;
			printf("$%d\n",num);
		}	
		
		
	}
	
	printf("\nEND OF OUTPUT\n");

	return 0;
	
}

void reset(int n){
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			matrix[i][j]=10000;
		}
	}
	
}

void floyd(int n){
	
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(matrix[i][j]>matrix[i][k]+matrix[k][j]){
					matrix[i][j]=matrix[i][k]+matrix[k][j];
				}
			}
		}
	}
	
}


