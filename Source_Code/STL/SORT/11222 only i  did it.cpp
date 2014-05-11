#include<stdio.h>
#include<algorithm>
using namespace std;

int player1[2000],player2[2000],player3[2000];
int problem[11000];

void reset();

int main(){

	int i,j,k,s1,s2,s3,test,t;
	int mark1,mark2,mark3,max;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	for(t=1;t<=test;t++){

		reset();
		
		scanf("%d",&s1);
		for(i=0;i<s1;i++){
			scanf("%d",&player1[i]);
			problem[player1[i]]++;
		}
		sort(player1,player1+s1);

		scanf("%d",&s2);
		for(i=0;i<s2;i++){
			scanf("%d",&player2[i]);
			problem[player2[i]]++;
		}
		sort(player2,player2+s2);

		scanf("%d",&s3);
		for(i=0;i<s3;i++){
			scanf("%d",&player3[i]);
			problem[player3[i]]++;
		}
		sort(player3,player3+s3);

		mark1=0;
		for(i=0;i<s1;i++){
			if(problem[player1[i]]==1)mark1++;
			
		}
		
		mark2=0;
		for(i=0;i<s2;i++){
			if(problem[player2[i]]==1)mark2++;
			
		}
		
		mark3=0;
		for(i=0;i<s3;i++){
			if(problem[player3[i]]==1)mark3++;
			
		}
		
		max=mark1;if(mark2>max) max=mark2;if(mark3>max) max=mark3;
		printf("Case #%d:\n",t);

		if(max==mark1){
			printf("1 %d",max);
			for(i=0;i<s1;i++){
				if(problem[player1[i]]==1)printf(" %d",player1[i]);
			}
			printf("\n");
		}

		if(max==mark2){
			printf("2 %d",max);
			for(i=0;i<s2;i++){
				if(problem[player2[i]]==1) printf(" %d",player2[i]);
			}
			printf("\n");
		}

		if(max==mark3){
			printf("3 %d",max);
			for(i=0;i<s3;i++){
				if(problem[player3[i]]==1)printf(" %d",player3[i]);
			}
			printf("\n");
		}		
			

	}

	return 0;

}

void reset(){

	for(int i=0;i<=10010;i++){
		problem[i]=0;
	}

}
		