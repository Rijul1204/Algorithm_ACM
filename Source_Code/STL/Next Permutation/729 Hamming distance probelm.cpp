#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){

	int i,j,test,h,n;
	bool blank=false;
	char num[100];

	scanf("%d",&test);

	while(test--){
		
		scanf("%d %d",&n,&h);
		for(i=0;i<n-h;i++){
			num[i]='0';
		}
		for(j=i;j<i+h;j++){
			num[j]='1';
		}
		num[j]='\0';
		if(blank) printf("\n");
		blank=true;	
			
		puts(num);
		while(next_permutation(num,num+strlen(num))){
			puts(num);
		}	

	}

	return 0;
}
