#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int parent[30110];
int number[30110];
int rank[30110];
int count;

int find(int x);
void Union(int a,int b);

int main(){

	int i,j,n1,n2,test,per,pair;
	

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test--){

	    scanf("%d %d",&per,&pair);
		
		if(pair==0){
			printf("1\n");
			continue;
		}
		
		count=0;


		for(i=0;i<=per;i++){
			parent[i]=i;
			number[i]=1;
			rank[i]=0;
		}

		for(i=1;i<=pair;i++){

			scanf("%d %d",&n1,&n2);
			Union(find(n1),find(n2));
		}

		for(i=1;i<=per;i++)	if(count<number[i]) count=number[i];

        
		
		printf("%d\n",count);

		

	}

	return 0;

}

int find(int x){

	if(parent[x]!=x){
		 parent[x]=find(parent[x]);
	}

	return parent[x];

	

}

void Union(int a,int b){

	if(a==b) return ;
	
	parent[b]=a;
	number[b]=number[a]+=number[b];	
	
}



	


















