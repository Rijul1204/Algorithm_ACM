#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char input[500],output[500],temp[500];
int flag[500];
int num,start,len,fl;

void back(int count,int start);
void set();

int main(){

	int i,j;
	char dum;

//	freopen("in.txt","r",stdin);

	while(scanf("%s %d",input,&num)==2){
		scanf("%c",&dum);

		len=strlen(input);
		sort(input,input+len);
        set();
		back(0,0);
		
		

	}

	return 0;
}

void back(int count,int start){

	int i;
    if(count==num){
		output[count]='\0';
		puts(output);
	}
	else{
		for(i=start;i<len;i++){
			if(flag[i]==0){
				flag[i]=1;
				output[count]=input[i];
			    back(count+1,i+1);
				flag[i]=0;
											
			}
			while(input[i+1]&&input[i]==input[i+1]){
				i++;
			}
		}
	}

}

void set(){
	int i;

	for(i=0;i<=len;i++){
		flag[i]=0;
	}
	temp[0]='\0';
}
			



		