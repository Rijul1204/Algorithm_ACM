#include<stdio.h>
#include<stdlib.h>

int parent[1000];
int node[150];
char s[100000];

void reset(int n);

int main(){

	int i,j,k,test,count,n,res1,temp;
	bool blank=false;
	char dum,help[5],bfr[100];

    

	scanf("%d%c",&test,&dum);
	getchar();

	while(test--){

		do{
			gets(bfr);
		}while(!bfr[0]);

		n=bfr[0];

		reset(n);

		while(gets(s)){

			if(!s[0]) break;
			
             temp=parent[s[1]];
			for(i=65;i<=n;i++){
				
				if(parent[i]==temp) parent[i]=parent[s[0]];
			}
			
		}

		count=0;

		for(i=65;i<=n;i++){
			if(i==parent[i])
				count++;				
			
		}

		if(blank) printf("\n");
		blank=true;
		printf("%d\n",count);
	}

	return 0;

}



void reset(int n){

	for(int i=65;i<=n;i++){
		parent[i]=i;
		
	}

}


				









		
