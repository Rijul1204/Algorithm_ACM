#include<stdio.h>

int input[20],output[20],flag[20];
int n;

void back(int count,int start);
void set();

int main(){

	int i,j=0;

//	freopen("in.txt","r",stdin);

	while(1){
		scanf("%d",&n);
		if(n==0) break;

		for(i=0;i<n;i++){
			scanf("%d",&input[i]);
		}
		if(j==1) printf("\n");
		back(0,0);
		j=1;

	}

	return 0;

}

void back(int count,int start){

	int i;

	if(count==6){
		for(i=0;i<6;i++){
			if(i==5) printf("%d",output[i]);
			else printf("%d ",output[i]);
		}
		printf("\n");
	}

	else {

		for(i=start;i<n;i++){
			if(flag[i]==0){
				output[count]=input[i];
				flag[i]=1;
				back(count+1,i+1);
				flag[i]=0;
			}
		}
	}

}

void set(){

	int i;

	for(i=0;i<=n;i++){
		flag[i]=0;
	}
}







